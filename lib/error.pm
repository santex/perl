package error;
use strict;
use warnings;
use Hash::Util::FieldHash 'fieldhash';
use Scalar::Util 'blessed';
our $VERSION = 0.001;

# XXX This is a proof of concept implemented in Perl for clarity.  It
# must be converted to XS and compiled into the core, as we cannot
# depend on being able to load error.pm in order to throw an exception

fieldhash my %MESSAGE;    # string or coderef 'promise'
fieldhash my %CONTEXT;    # arbitrary user data
fieldhash my %TRACE;      # trace with CORE::GLOBAL::caller
fieldhash my %RAW_TRACE;  # trace with CORE::caller

use overload (
  q{""} => 'message',
  fallback => 1, # XXX is this what we want?
);

# Accessors must be callable as $@->message() or as error->message($@).
# The latter is preferred to avoid method name conflicts if $@ happens
# to be an facade over an existing exception class
#
# XXX real code should do something smarter about $_[1] being undef
sub context   { return $CONTEXT{    ref($_[0]) ? $_[0] : $_[1] }  }
sub trace     { return $TRACE{      ref($_[0]) ? $_[0] : $_[1] }  }
sub raw_trace { return $RAW_TRACE{  ref($_[0]) ? $_[0] : $_[1] }  }

# If message is coderef, invoke it to generate stringified form.
# This allows stringification based on context (or stack trace)
# without requiring creation of subclasses with their own
# stringification overload
sub message   {
  my $self = ref($_[0]) ? $_[0] : $_[1];
  my $message = $MESSAGE{ $self };
  return ref($message) eq 'CODE' ? $message->($self) : $message;
}

# %FACADES contains HoH associating a given error class/subclass and
# a given foreign class with a facade class that inherits from both
my %FACADES;

sub new {
  my ($class, $message, $context, $options) = @_;
  $options->{uplevel} //= 0;

  # create the object based on the argument type; foreign objects
  # are wrapped in a facade; unblessed refs are blessed; otherwise
  # the object is an empty reference
  my $self;
  if ( ref $message) {
    if ( my $foreign = blessed $message ) {
      $class = $FACADES{$class}{$foreign} || $class->_create_facade($foreign);
    }
    $self = bless $message, $class;
    $MESSAGE{ $self } = "$message"; # stringify original, possibly overloaded
  }
  else {
    $message //= 'Died';
    $self = bless \(my $scalar), $class;
    $MESSAGE{ $self } = $message;
  }

  # raw trace is based only on CORE::caller
  {
    my @raw_trace;
    my $i = 1 + $options->{uplevel}; # skip our own frame or more 
    while (my @frame = CORE::caller($i++)) {
      push @raw_trace, \@frame;
    }
    $RAW_TRACE{ $self } = \@raw_trace;
  }

  # trace is subject to CORE::GLOBAL::caller overrides
  {
    no warnings 'once';
    if ( defined *CORE::GLOBAL::caller ) {
      no strict 'refs';
      my @trace;
      my $i = 1 + $options->{uplevel}; # skip our own frame or more 
      while (my @frame = &{"CORE::GLOBAL::caller"}($i++)) {
        push @trace, \@frame;
      }
      $TRACE{ $self } = \@trace;
    }
    else {
      $TRACE{ $self } = $RAW_TRACE{ $self };
    }
  }

  # we only get context if invoked as error->new($msg, $context);
  # when invoked via die(), the context is undef
  $CONTEXT{ $self } = $context;

  return $self;
}

# creates a subclass with correct inheritance to act as a facade
# to the original class
sub _create_facade {
  no strict 'refs';
  my ($class, $foreign) = @_;
  my $facade  = "$class\::facade::$foreign";
  @{ $facade . "::ISA" } = ($foreign, $class);
  return $FACADES{$class}{$foreign} = $facade;
}

# $class->throw( $message, $context )
#
sub throw { die $_[0]->new( $_[1], $_[2], { uplevel => 1 } ) }

1;

__END__

=head1 NAME

error -- Perl exception object

=head1 SYNOPSIS

  use 5.010; use strict; use warnings;
  use error;

  # throwing an error
  sub dies_here {
    error->throw( "Can't continue" );
  }

  # throwing an error with context
  sub dies_with_context {
    error->throw( "Can't continue", why_not() );
  }

  # catching an error
  eval { dies_here() };
  if ( $@ ) {
    say error->message( $@ );
  }

  # accessing context
  eval { dies_with_context() };
  if ( $@ ) {
    say error->message( $@ );
    explain( error->context( $@ ) );
  }

  # works with die(), too
  eval { die "Goodbye world!" };
  if ( $@ ) {
    say error->message( $@ );
  }

  # examine a stack trace
  my $caller = error->trace( $@ )->[0];

=head1 DESCRIPTION

Write something here!

=head1 ATTRIBUTES

=head2 message

=head2 context

=head2 trace

=head2 raw_trace

=head1 METHODS

=head2 new

=head2 throw

=head1 CAVEATS

Write something here!

=head2 Exception objects are transparently subclassed

Note how this breaks if anything tests (ref $obj eq 'foo') instead
of $obj->isa('foo')

=head2 Unblessed reference exceptions converted to objects

Note how this might break stuff

=head1 AUTHOR

David A. Golden E<lt>dagolden@cpan.orgE<gt>

=head1 LICENSE

Copyright (c) 2011 by David A. Golden

This program is free software; you can redistribute it and/or modify it
under the same terms as Perl itself.

See http://www.perl.com/perl/misc/Artistic.html

=cut

