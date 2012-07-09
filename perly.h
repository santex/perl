/* -*- buffer-read-only: t -*-
   !!!!!!!   DO NOT EDIT THIS FILE   !!!!!!!
   This file is built by regen_perly.pl from perly.y.
   Any changes made here will be lost!
 */

#ifdef PERL_CORE
/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     GRAMPROG = 258,
     GRAMEXPR = 259,
     GRAMBLOCK = 260,
     GRAMBARESTMT = 261,
     GRAMFULLSTMT = 262,
     GRAMSTMTSEQ = 263,
     WORD = 264,
     METHOD = 265,
     FUNCMETH = 266,
     THING = 267,
     PMFUNC = 268,
     PRIVATEREF = 269,
     QWLIST = 270,
     FUNC0OP = 271,
     FUNC0SUB = 272,
     UNIOPSUB = 273,
     LSTOPSUB = 274,
     PLUGEXPR = 275,
     PLUGSTMT = 276,
     LABEL = 277,
     FORMAT = 278,
     SUB = 279,
     ANONSUB = 280,
     PACKAGE = 281,
     USE = 282,
     WHILE = 283,
     UNTIL = 284,
     IF = 285,
     UNLESS = 286,
     ELSE = 287,
     ELSIF = 288,
     CONTINUE = 289,
     FOR = 290,
     GIVEN = 291,
     WHEN = 292,
     DEFAULT = 293,
     LOOPEX = 294,
     DOTDOT = 295,
     YADAYADA = 296,
     FUNC0 = 297,
     FUNC1 = 298,
     FUNC = 299,
     UNIOP = 300,
     LSTOP = 301,
     RELOP = 302,
     EQOP = 303,
     MULOP = 304,
     ADDOP = 305,
     DOLSHARP = 306,
     DO = 307,
     HASHBRACK = 308,
     NOAMP = 309,
     LOCAL = 310,
     MY = 311,
     MYSUB = 312,
     REQUIRE = 313,
     COLONATTR = 314,
     FORMLBRACK = 315,
     FORMRBRACK = 316,
     PREC_LOW = 317,
     DOROP = 318,
     OROP = 319,
     ANDOP = 320,
     NOTOP = 321,
     ASSIGNOP = 322,
     DORDOR = 323,
     OROR = 324,
     ANDAND = 325,
     BITOROP = 326,
     BITANDOP = 327,
     SHIFTOP = 328,
     MATCHOP = 329,
     REFGEN = 330,
     UMINUS = 331,
     POWOP = 332,
     POSTDEC = 333,
     POSTINC = 334,
     PREDEC = 335,
     PREINC = 336,
     ARROW = 337,
     PEG = 338
   };
#endif
/* Tokens.  */
#define GRAMPROG 258
#define GRAMEXPR 259
#define GRAMBLOCK 260
#define GRAMBARESTMT 261
#define GRAMFULLSTMT 262
#define GRAMSTMTSEQ 263
#define WORD 264
#define METHOD 265
#define FUNCMETH 266
#define THING 267
#define PMFUNC 268
#define PRIVATEREF 269
#define QWLIST 270
#define FUNC0OP 271
#define FUNC0SUB 272
#define UNIOPSUB 273
#define LSTOPSUB 274
#define PLUGEXPR 275
#define PLUGSTMT 276
#define LABEL 277
#define FORMAT 278
#define SUB 279
#define ANONSUB 280
#define PACKAGE 281
#define USE 282
#define WHILE 283
#define UNTIL 284
#define IF 285
#define UNLESS 286
#define ELSE 287
#define ELSIF 288
#define CONTINUE 289
#define FOR 290
#define GIVEN 291
#define WHEN 292
#define DEFAULT 293
#define LOOPEX 294
#define DOTDOT 295
#define YADAYADA 296
#define FUNC0 297
#define FUNC1 298
#define FUNC 299
#define UNIOP 300
#define LSTOP 301
#define RELOP 302
#define EQOP 303
#define MULOP 304
#define ADDOP 305
#define DOLSHARP 306
#define DO 307
#define HASHBRACK 308
#define NOAMP 309
#define LOCAL 310
#define MY 311
#define MYSUB 312
#define REQUIRE 313
#define COLONATTR 314
#define FORMLBRACK 315
#define FORMRBRACK 316
#define PREC_LOW 317
#define DOROP 318
#define OROP 319
#define ANDOP 320
#define NOTOP 321
#define ASSIGNOP 322
#define DORDOR 323
#define OROR 324
#define ANDAND 325
#define BITOROP 326
#define BITANDOP 327
#define SHIFTOP 328
#define MATCHOP 329
#define REFGEN 330
#define UMINUS 331
#define POWOP 332
#define POSTDEC 333
#define POSTINC 334
#define PREDEC 335
#define PREINC 336
#define ARROW 337
#define PEG 338




#ifdef PERL_IN_TOKE_C
static bool
S_is_opval_token(int type) {
    switch (type) {
    case FUNC0OP:
    case FUNC0SUB:
    case FUNCMETH:
    case LSTOPSUB:
    case METHOD:
    case PLUGEXPR:
    case PLUGSTMT:
    case PMFUNC:
    case PRIVATEREF:
    case QWLIST:
    case THING:
    case UNIOPSUB:
    case WORD:
	return 1;
    }
    return 0;
}
#endif /* PERL_IN_TOKE_C */
#endif /* PERL_CORE */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
    I32	ival; /* __DEFAULT__ (marker for regen_perly.pl;
				must always be 1st union member) */
    char *pval;
    OP *opval;
    GV *gvval;
#ifdef PERL_IN_MADLY_C
    TOKEN* p_tkval;
    TOKEN* i_tkval;
#else
    char *p_tkval;
    I32	i_tkval;
#endif
#ifdef PERL_MAD
    TOKEN* tkval;
#endif
}
/* Line 1529 of yacc.c.  */
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif




/* Generated from:
 * 38ce4bf3d0e9f8cfd35795d89907c7d03583b561b55406230d749c80d62d5e06 perly.y
 * 4a3ced51fe6585f6ec59e65e1ffd74bc976c498b0e6992eaab337219fee72e51 regen_perly.pl
 * ex: set ro: */
