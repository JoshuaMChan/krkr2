#include "tjsCommHead.h"
#pragma hdrstop
/* A Bison parser, made by GNU Bison 1.875b.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003 Free Software Foundation, Inc.

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
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_COMMA = 258,
     T_EQUAL = 259,
     T_AMPERSANDEQUAL = 260,
     T_VERTLINEEQUAL = 261,
     T_CHEVRONEQUAL = 262,
     T_MINUSEQUAL = 263,
     T_PLUSEQUAL = 264,
     T_PERCENTEQUAL = 265,
     T_SLASHEQUAL = 266,
     T_BACKSLASHEQUAL = 267,
     T_ASTERISKEQUAL = 268,
     T_LOGICALOREQUAL = 269,
     T_LOGICALANDEQUAL = 270,
     T_RARITHSHIFTEQUAL = 271,
     T_LARITHSHIFTEQUAL = 272,
     T_RBITSHIFTEQUAL = 273,
     T_QUESTION = 274,
     T_LOGICALOR = 275,
     T_LOGICALAND = 276,
     T_VERTLINE = 277,
     T_CHEVRON = 278,
     T_AMPERSAND = 279,
     T_NOTEQUAL = 280,
     T_EQUALEQUAL = 281,
     T_DISCNOTEQUAL = 282,
     T_DISCEQUAL = 283,
     T_SWAP = 284,
     T_LT = 285,
     T_GT = 286,
     T_LTOREQUAL = 287,
     T_GTOREQUAL = 288,
     T_RARITHSHIFT = 289,
     T_LARITHSHIFT = 290,
     T_RBITSHIFT = 291,
     T_PERCENT = 292,
     T_SLASH = 293,
     T_BACKSLASH = 294,
     T_ASTERISK = 295,
     T_EXCRAMATION = 296,
     T_TILDE = 297,
     T_DECREMENT = 298,
     T_INCREMENT = 299,
     T_NEW = 300,
     T_DELETE = 301,
     T_TYPEOF = 302,
     T_PLUS = 303,
     T_MINUS = 304,
     T_SHARP = 305,
     T_DOLLAR = 306,
     T_ISVALID = 307,
     T_INVALIDATE = 308,
     T_INSTANCEOF = 309,
     T_LPARENTHESIS = 310,
     T_DOT = 311,
     T_LBRACKET = 312,
     T_THIS = 313,
     T_SUPER = 314,
     T_GLOBAL = 315,
     T_RBRACKET = 316,
     T_CLASS = 317,
     T_RPARENTHESIS = 318,
     T_COLON = 319,
     T_SEMICOLON = 320,
     T_LBRACE = 321,
     T_RBRACE = 322,
     T_CONTINUE = 323,
     T_FUNCTION = 324,
     T_DEBUGGER = 325,
     T_DEFAULT = 326,
     T_CASE = 327,
     T_EXTENDS = 328,
     T_FINALLY = 329,
     T_PROPERTY = 330,
     T_PRIVATE = 331,
     T_PUBLIC = 332,
     T_PROTECTED = 333,
     T_STATIC = 334,
     T_RETURN = 335,
     T_BREAK = 336,
     T_EXPORT = 337,
     T_IMPORT = 338,
     T_SWITCH = 339,
     T_IN = 340,
     T_INCONTEXTOF = 341,
     T_FOR = 342,
     T_WHILE = 343,
     T_DO = 344,
     T_IF = 345,
     T_VAR = 346,
     T_CONST = 347,
     T_ENUM = 348,
     T_GOTO = 349,
     T_THROW = 350,
     T_TRY = 351,
     T_SETTER = 352,
     T_GETTER = 353,
     T_ELSE = 354,
     T_CATCH = 355,
     T_OMIT = 356,
     T_SYNCHRONIZED = 357,
     T_WITH = 358,
     T_INT = 359,
     T_REAL = 360,
     T_STRING = 361,
     T_OCTET = 362,
     T_FALSE = 363,
     T_NULL = 364,
     T_TRUE = 365,
     T_VOID = 366,
     T_NAN = 367,
     T_INFINITY = 368,
     T_UPLUS = 369,
     T_UMINUS = 370,
     T_EVAL = 371,
     T_SYMBOL = 372,
     T_POSTDECREMENT = 373,
     T_POSTINCREMENT = 374,
     T_SUBSTANCE = 375,
     T_ARG = 376,
     T_INLINEARRAY = 377,
     T_ARRAYARG = 378,
     T_INLINEDIC = 379,
     T_DICELM = 380,
     T_REGEXP = 381,
     T_WITHDOT = 382,
     T_THIS_PROXY = 383,
     T_WITHDOT_PROXY = 384,
     T_CONSTVAL = 385
   };
#endif
#define T_COMMA 258
#define T_EQUAL 259
#define T_AMPERSANDEQUAL 260
#define T_VERTLINEEQUAL 261
#define T_CHEVRONEQUAL 262
#define T_MINUSEQUAL 263
#define T_PLUSEQUAL 264
#define T_PERCENTEQUAL 265
#define T_SLASHEQUAL 266
#define T_BACKSLASHEQUAL 267
#define T_ASTERISKEQUAL 268
#define T_LOGICALOREQUAL 269
#define T_LOGICALANDEQUAL 270
#define T_RARITHSHIFTEQUAL 271
#define T_LARITHSHIFTEQUAL 272
#define T_RBITSHIFTEQUAL 273
#define T_QUESTION 274
#define T_LOGICALOR 275
#define T_LOGICALAND 276
#define T_VERTLINE 277
#define T_CHEVRON 278
#define T_AMPERSAND 279
#define T_NOTEQUAL 280
#define T_EQUALEQUAL 281
#define T_DISCNOTEQUAL 282
#define T_DISCEQUAL 283
#define T_SWAP 284
#define T_LT 285
#define T_GT 286
#define T_LTOREQUAL 287
#define T_GTOREQUAL 288
#define T_RARITHSHIFT 289
#define T_LARITHSHIFT 290
#define T_RBITSHIFT 291
#define T_PERCENT 292
#define T_SLASH 293
#define T_BACKSLASH 294
#define T_ASTERISK 295
#define T_EXCRAMATION 296
#define T_TILDE 297
#define T_DECREMENT 298
#define T_INCREMENT 299
#define T_NEW 300
#define T_DELETE 301
#define T_TYPEOF 302
#define T_PLUS 303
#define T_MINUS 304
#define T_SHARP 305
#define T_DOLLAR 306
#define T_ISVALID 307
#define T_INVALIDATE 308
#define T_INSTANCEOF 309
#define T_LPARENTHESIS 310
#define T_DOT 311
#define T_LBRACKET 312
#define T_THIS 313
#define T_SUPER 314
#define T_GLOBAL 315
#define T_RBRACKET 316
#define T_CLASS 317
#define T_RPARENTHESIS 318
#define T_COLON 319
#define T_SEMICOLON 320
#define T_LBRACE 321
#define T_RBRACE 322
#define T_CONTINUE 323
#define T_FUNCTION 324
#define T_DEBUGGER 325
#define T_DEFAULT 326
#define T_CASE 327
#define T_EXTENDS 328
#define T_FINALLY 329
#define T_PROPERTY 330
#define T_PRIVATE 331
#define T_PUBLIC 332
#define T_PROTECTED 333
#define T_STATIC 334
#define T_RETURN 335
#define T_BREAK 336
#define T_EXPORT 337
#define T_IMPORT 338
#define T_SWITCH 339
#define T_IN 340
#define T_INCONTEXTOF 341
#define T_FOR 342
#define T_WHILE 343
#define T_DO 344
#define T_IF 345
#define T_VAR 346
#define T_CONST 347
#define T_ENUM 348
#define T_GOTO 349
#define T_THROW 350
#define T_TRY 351
#define T_SETTER 352
#define T_GETTER 353
#define T_ELSE 354
#define T_CATCH 355
#define T_OMIT 356
#define T_SYNCHRONIZED 357
#define T_WITH 358
#define T_INT 359
#define T_REAL 360
#define T_STRING 361
#define T_OCTET 362
#define T_FALSE 363
#define T_NULL 364
#define T_TRUE 365
#define T_VOID 366
#define T_NAN 367
#define T_INFINITY 368
#define T_UPLUS 369
#define T_UMINUS 370
#define T_EVAL 371
#define T_SYMBOL 372
#define T_POSTDECREMENT 373
#define T_POSTINCREMENT 374
#define T_SUBSTANCE 375
#define T_ARG 376
#define T_INLINEARRAY 377
#define T_ARRAYARG 378
#define T_INLINEDIC 379
#define T_DICELM 380
#define T_REGEXP 381
#define T_WITHDOT 382
#define T_THIS_PROXY 383
#define T_WITHDOT_PROXY 384
#define T_CONSTVAL 385




/* Copy the first part of user declarations.  */
#line 1 "..\bison\tjs.y"

/*---------------------------------------------------------------------------*/
/*
	TJS2 Script Engine
	Copyright (C) 2000-2004  W.Dee <dee@kikyou.info>

	See details of license at "license.txt"
*/
/*---------------------------------------------------------------------------*/
/* tjs.y */
/* TJS2 bison input file */


#include <malloc.h>


#include "tjsInterCodeGen.h"
#include "tjsScriptBlock.h"
#include "tjsError.h"

#define YYERROR_VERBOSE 1

/* param */
#define YYPARSE_PARAM pm
#define YYLEX_PARAM pm

/* script block */
#define sb ((tTJSScriptBlock*)pm)

/* current context */
#define cc (sb->GetCurrentContext())

/* current node */
#define cn (cc->GetCurrentNode())

/* lexical analyzer */
#define lx (sb->GetLexicalAnalyzer())


namespace TJS {

/* yylex/yyerror prototype decl */
#define YYLEX_PROTO_DECL int yylex(YYSTYPE *yylex, void *pm);

int __yyerror(char * msg, void *pm);


#define yyerror(msg) __yyerror(msg, pm);



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 56 "..\bison\tjs.y"
typedef union YYSTYPE {
	tjs_int			num;
	tTJSExprNode *		np;
} YYSTYPE;
YYLEX_PROTO_DECL

/* Line 191 of yacc.c.  */
#line 392 "tjs.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 404 "tjs.tab.c"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1293

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  131
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  94
/* YYNRULES -- Number of rules. */
#define YYNRULES  227
/* YYNRULES -- Number of states. */
#define YYNSTATES  389

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   385

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,     5,     6,     9,    10,    13,    17,    19,
      21,    23,    26,    28,    30,    32,    34,    36,    39,    42,
      44,    46,    48,    50,    52,    54,    56,    58,    60,    62,
      63,    68,    69,    70,    78,    79,    80,    90,    91,    92,
     100,   101,   106,   116,   117,   118,   121,   123,   124,   126,
     127,   129,   132,   135,   138,   140,   144,   146,   150,   151,
     157,   158,   163,   164,   168,   169,   171,   175,   177,   181,
     182,   189,   191,   194,   195,   202,   203,   207,   211,   213,
     214,   220,   221,   224,   225,   231,   233,   237,   239,   242,
     246,   247,   254,   255,   262,   266,   269,   270,   276,   278,
     282,   287,   291,   293,   295,   299,   301,   305,   307,   311,
     315,   319,   323,   327,   331,   335,   339,   343,   347,   351,
     355,   359,   363,   367,   371,   373,   379,   381,   385,   387,
     391,   393,   397,   399,   403,   405,   409,   411,   415,   419,
     423,   427,   429,   433,   437,   441,   445,   447,   451,   455,
     459,   461,   465,   469,   471,   475,   479,   483,   487,   489,
     492,   495,   498,   501,   504,   507,   510,   513,   516,   519,
     522,   525,   528,   531,   534,   538,   543,   546,   551,   554,
     559,   562,   564,   568,   570,   574,   579,   581,   582,   587,
     590,   593,   596,   597,   601,   603,   605,   607,   609,   611,
     613,   615,   617,   619,   620,   624,   625,   629,   634,   636,
     638,   642,   643,   645,   646,   651,   653,   657,   658,   660,
     661,   668,   669,   671,   675,   679,   683,   684
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     132,     0,    -1,   133,    -1,    -1,   134,   135,    -1,    -1,
     135,   136,    -1,   135,     1,    65,    -1,   137,    -1,   138,
      -1,    65,    -1,   191,    65,    -1,   146,    -1,   149,    -1,
     140,    -1,   143,    -1,   151,    -1,    81,    65,    -1,    68,
      65,    -1,   156,    -1,   160,    -1,   167,    -1,   174,    -1,
     180,    -1,   181,    -1,   183,    -1,   185,    -1,   186,    -1,
     189,    -1,    -1,    66,   139,   135,    67,    -1,    -1,    -1,
      88,   141,    55,   191,    63,   142,   136,    -1,    -1,    -1,
      89,   144,   136,    88,    55,   191,    63,   145,    65,    -1,
      -1,    -1,    90,    55,   147,   191,   148,    63,   136,    -1,
      -1,   146,    99,   150,   136,    -1,    87,    55,   152,    65,
     154,    65,   155,    63,   136,    -1,    -1,    -1,   153,   157,
      -1,   191,    -1,    -1,   191,    -1,    -1,   191,    -1,   157,
      65,    -1,    91,   158,    -1,    92,   158,    -1,   159,    -1,
     158,     3,   159,    -1,   117,    -1,   117,     4,   190,    -1,
      -1,    69,   117,   161,   164,   138,    -1,    -1,    69,   163,
     164,   138,    -1,    -1,    55,   165,    63,    -1,    -1,   166,
      -1,   165,     3,   166,    -1,   117,    -1,   117,     4,   190,
      -1,    -1,    75,   117,    66,   168,   169,    67,    -1,   170,
      -1,   169,   170,    -1,    -1,    97,    55,   117,    63,   171,
     138,    -1,    -1,   173,   172,   138,    -1,    98,    55,    63,
      -1,    98,    -1,    -1,    62,   117,   175,   176,   138,    -1,
      -1,    73,   190,    -1,    -1,    73,   190,     3,   177,   178,
      -1,   179,    -1,   178,     3,   179,    -1,   190,    -1,    80,
      65,    -1,    80,   191,    65,    -1,    -1,    84,    55,   191,
      63,   182,   138,    -1,    -1,   103,    55,   191,    63,   184,
     136,    -1,    72,   191,    64,    -1,    71,    64,    -1,    -1,
      96,   187,   136,   188,   136,    -1,   100,    -1,   100,    55,
      63,    -1,   100,    55,   117,    63,    -1,    95,   191,    65,
      -1,   193,    -1,   192,    -1,   192,    90,   191,    -1,   193,
      -1,   192,     3,   193,    -1,   194,    -1,   194,    29,   193,
      -1,   194,     4,   193,    -1,   194,     5,   193,    -1,   194,
       6,   193,    -1,   194,     7,   193,    -1,   194,     8,   193,
      -1,   194,     9,   193,    -1,   194,    10,   193,    -1,   194,
      11,   193,    -1,   194,    12,   193,    -1,   194,    13,   193,
      -1,   194,    14,   193,    -1,   194,    15,   193,    -1,   194,
      18,   193,    -1,   194,    17,   193,    -1,   194,    16,   193,
      -1,   195,    -1,   195,    19,   194,    64,   194,    -1,   196,
      -1,   195,    20,   196,    -1,   197,    -1,   196,    21,   197,
      -1,   198,    -1,   197,    22,   198,    -1,   199,    -1,   198,
      23,   199,    -1,   200,    -1,   199,    24,   200,    -1,   201,
      -1,   200,    25,   201,    -1,   200,    26,   201,    -1,   200,
      27,   201,    -1,   200,    28,   201,    -1,   202,    -1,   201,
      30,   202,    -1,   201,    31,   202,    -1,   201,    32,   202,
      -1,   201,    33,   202,    -1,   203,    -1,   202,    34,   203,
      -1,   202,    35,   203,    -1,   202,    36,   203,    -1,   204,
      -1,   203,    48,   204,    -1,   203,    49,   204,    -1,   205,
      -1,   204,    37,   205,    -1,   204,    38,   205,    -1,   204,
      39,   205,    -1,   204,    40,   205,    -1,   206,    -1,    41,
     205,    -1,    42,   205,    -1,    43,   205,    -1,    44,   205,
      -1,    45,   213,    -1,    53,   205,    -1,    52,   205,    -1,
     206,    52,    -1,    46,   205,    -1,    47,   205,    -1,    50,
     205,    -1,    51,   205,    -1,    48,   205,    -1,    49,   205,
      -1,    40,   205,    -1,   206,    54,   205,    -1,    55,   104,
      63,   205,    -1,   104,   205,    -1,    55,   105,    63,   205,
      -1,   105,   205,    -1,    55,   106,    63,   205,    -1,   106,
     205,    -1,   207,    -1,   207,    86,   206,    -1,   210,    -1,
      55,   191,    63,    -1,   207,    57,   191,    61,    -1,   213,
      -1,    -1,   207,    56,   208,   117,    -1,   207,    44,    -1,
     207,    43,    -1,   207,    41,    -1,    -1,    56,   209,   117,
      -1,   130,    -1,   117,    -1,    58,    -1,    59,    -1,   162,
      -1,    60,    -1,   111,    -1,   216,    -1,   220,    -1,    -1,
      11,   211,   126,    -1,    -1,    38,   212,   126,    -1,   207,
      55,   214,    63,    -1,   101,    -1,   215,    -1,   214,     3,
     215,    -1,    -1,   190,    -1,    -1,    57,   217,   218,    61,
      -1,   219,    -1,   218,     3,   219,    -1,    -1,   190,    -1,
      -1,    37,    57,   221,   222,   224,    61,    -1,    -1,   223,
      -1,   222,     3,   223,    -1,   190,     3,   190,    -1,   117,
      64,   190,    -1,    -1,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   211,   211,   216,   216,   222,   224,   225,   232,   233,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   261,
     261,   268,   269,   268,   275,   278,   275,   284,   285,   284,
     291,   291,   297,   307,   308,   308,   310,   316,   317,   322,
     323,   328,   332,   333,   340,   341,   346,   348,   354,   354,
     364,   364,   377,   379,   383,   385,   386,   390,   392,   399,
     398,   407,   408,   412,   412,   420,   420,   429,   430,   436,
     436,   443,   445,   446,   446,   451,   452,   456,   461,   462,
     469,   468,   476,   475,   482,   483,   488,   488,   495,   496,
     497,   503,   508,   512,   513,   518,   519,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   545,   546,   554,   555,   559,   560,
     565,   566,   570,   571,   575,   576,   580,   581,   582,   583,
     584,   588,   589,   590,   591,   592,   596,   597,   598,   599,
     604,   605,   606,   610,   611,   612,   613,   614,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   628,   629,
     630,   631,   632,   633,   634,   635,   636,   637,   638,   639,
     640,   644,   645,   650,   651,   652,   653,   654,   654,   658,
     659,   660,   661,   661,   669,   671,   674,   675,   676,   677,
     678,   679,   680,   681,   681,   684,   684,   692,   697,   698,
     699,   703,   704,   710,   710,   719,   720,   725,   726,   731,
     731,   741,   743,   744,   749,   750,   757,   759
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\",\"", "\"=\"", "\"&=\"", "\"|=\"", 
  "\"^=\"", "\"-=\"", "\"+=\"", "\"%=\"", "\"/=\"", "\"\\\\=\"", "\"*=\"", 
  "\"||=\"", "\"&&=\"", "\">>>=\"", "\"<<=\"", "\">>=\"", "\"?\"", 
  "\"||\"", "\"&&\"", "\"|\"", "\"^\"", "\"&\"", "\"!=\"", "\"==\"", 
  "\"!==\"", "\"===\"", "\"<->\"", "\"<\"", "\">\"", "\"<=\"", "\">=\"", 
  "\">>\"", "\"<<\"", "\">>>\"", "\"%\"", "\"/\"", "\"\\\\\"", "\"*\"", 
  "\"!\"", "\"~\"", "\"--\"", "\"++\"", "\"new\"", "\"delete\"", 
  "\"typeof\"", "\"+\"", "\"-\"", "\"#\"", "\"$\"", "\"isvalid\"", 
  "\"invalidate\"", "\"instanceof\"", "\"(\"", "\".\"", "\"[\"", 
  "\"this\"", "\"super\"", "\"global\"", "\"]\"", "\"class\"", "\")\"", 
  "\":\"", "\";\"", "\"{\"", "\"}\"", "\"continue\"", "\"function\"", 
  "\"debugger\"", "\"default\"", "\"case\"", "\"extends\"", "\"finally\"", 
  "\"property\"", "\"private\"", "\"public\"", "\"protected\"", 
  "\"static\"", "\"return\"", "\"break\"", "\"export\"", "\"import\"", 
  "\"switch\"", "\"in\"", "\"incontextof\"", "\"for\"", "\"while\"", 
  "\"do\"", "\"if\"", "\"var\"", "\"const\"", "\"enum\"", "\"goto\"", 
  "\"throw\"", "\"try\"", "\"setter\"", "\"getter\"", "\"else\"", 
  "\"catch\"", "\"...\"", "\"synchronized\"", "\"with\"", "\"int\"", 
  "\"real\"", "\"string\"", "\"octet\"", "\"false\"", "\"null\"", 
  "\"true\"", "\"void\"", "\"NaN\"", "\"Infinity\"", "T_UPLUS", 
  "T_UMINUS", "T_EVAL", "T_SYMBOL", "T_POSTDECREMENT", "T_POSTINCREMENT", 
  "T_SUBSTANCE", "T_ARG", "T_INLINEARRAY", "T_ARRAYARG", "T_INLINEDIC", 
  "T_DICELM", "T_REGEXP", "T_WITHDOT", "T_THIS_PROXY", "T_WITHDOT_PROXY", 
  "T_CONSTVAL", "$accept", "program", "global_list", "@1", "def_list", 
  "block_or_statement", "statement", "block", "@2", "while", "@3", "@4", 
  "do_while", "@5", "@6", "if", "@7", "@8", "if_else", "@9", "for", 
  "for_first_clause", "@10", "for_second_clause", "for_third_clause", 
  "variable_def", "variable_def_inner", "variable_id_list", "variable_id", 
  "func_def", "@11", "func_expr_def", "@12", "func_decl_arg_opt", 
  "func_decl_arg_list", "func_decl_arg", "property_def", "@13", 
  "property_handler_def_list", "property_handler_def", "@14", "@15", 
  "property_getter_handler_head", "class_def", "@16", "class_extender", 
  "@17", "extends_list", "extends_name", "return", "switch", "@18", 
  "with", "@19", "case", "try", "@20", "catch", "throw", "expr_no_comma", 
  "expr", "comma_expr", "assign_expr", "cond_expr", "logical_or_expr", 
  "logical_and_expr", "inclusive_or_expr", "exclusive_or_expr", 
  "and_expr", "identical_expr", "compare_expr", "shift_expr", 
  "add_sub_expr", "mul_div_expr", "unary_expr", "incontextof_expr", 
  "priority_expr", "@21", "@22", "factor_expr", "@23", "@24", 
  "func_call_expr", "call_arg_list", "call_arg", "inline_array", "@25", 
  "array_elm_list", "array_elm", "inline_dic", "@26", "dic_elm_list", 
  "dic_elm", "dic_dummy_elm_opt", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,   131,   132,   134,   133,   135,   135,   135,   136,   136,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   139,
     138,   141,   142,   140,   144,   145,   143,   147,   148,   146,
     150,   149,   151,   152,   153,   152,   152,   154,   154,   155,
     155,   156,   157,   157,   158,   158,   159,   159,   161,   160,
     163,   162,   164,   164,   165,   165,   165,   166,   166,   168,
     167,   169,   169,   171,   170,   172,   170,   173,   173,   175,
     174,   176,   176,   177,   176,   178,   178,   179,   180,   180,
     182,   181,   184,   183,   185,   185,   187,   186,   188,   188,
     188,   189,   190,   191,   191,   192,   192,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   194,   194,   195,   195,   196,   196,
     197,   197,   198,   198,   199,   199,   200,   200,   200,   200,
     200,   201,   201,   201,   201,   201,   202,   202,   202,   202,
     203,   203,   203,   204,   204,   204,   204,   204,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   206,   206,   207,   207,   207,   207,   208,   207,   207,
     207,   207,   209,   207,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   211,   210,   212,   210,   213,   214,   214,
     214,   215,   215,   217,   216,   218,   218,   219,   219,   221,
     220,   222,   222,   222,   223,   223,   224,   224
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     0,     2,     0,     2,     3,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       4,     0,     0,     7,     0,     0,     9,     0,     0,     7,
       0,     4,     9,     0,     0,     2,     1,     0,     1,     0,
       1,     2,     2,     2,     1,     3,     1,     3,     0,     5,
       0,     4,     0,     3,     0,     1,     3,     1,     3,     0,
       6,     1,     2,     0,     6,     0,     3,     3,     1,     0,
       5,     0,     2,     0,     5,     1,     3,     1,     2,     3,
       0,     6,     0,     6,     3,     2,     0,     5,     1,     3,
       4,     3,     1,     1,     3,     1,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     5,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     3,     4,     2,     4,     2,     4,
       2,     1,     3,     1,     3,     4,     1,     0,     4,     2,
       2,     2,     0,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     3,     0,     3,     4,     1,     1,
       3,     0,     1,     0,     4,     1,     3,     0,     1,     0,
       6,     0,     1,     3,     3,     3,     0,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       3,     0,     2,     5,     1,     0,     0,   203,     0,   205,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   192,   213,   196,   197,   199,
       0,    10,    29,     0,    60,     0,     0,     0,     0,     0,
       0,     0,    31,    34,     0,     0,     0,     0,    96,     0,
       0,     0,     0,   200,   195,   194,     6,     8,     9,    14,
      15,    12,    13,    16,    19,     0,    20,   198,    21,    22,
      23,    24,    25,    26,    27,    28,     0,   103,   105,   107,
     124,   126,   128,   130,   132,   134,   136,   141,   146,   150,
     153,   158,   181,   183,   186,   201,   202,     7,     0,   219,
       0,    60,   173,   159,   160,   161,   162,     0,     0,   163,
     167,   168,   171,   172,   169,   170,   165,   164,     0,     0,
       0,     0,     0,   217,    79,     5,    18,    58,    62,    95,
       0,     0,    88,     0,    17,     0,    44,     0,     0,    37,
      56,    52,    54,    53,     0,     0,     0,   176,   178,   180,
      40,    51,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   166,     0,   191,   190,   189,   211,
     187,     0,     0,   204,   221,   206,     0,     0,     0,   184,
     193,   218,   102,     0,   215,    81,     0,    62,    64,     0,
      94,    69,    89,     0,     0,     0,    46,     0,     0,     0,
       0,     0,   101,     0,     0,     0,   106,   104,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     123,   122,   121,   108,     0,   127,   129,   131,   133,   135,
     137,   138,   139,   140,   142,   143,   144,   145,   147,   148,
     149,   151,   152,   154,   155,   156,   157,   174,   208,   212,
       0,   209,     0,     0,   182,   195,     0,   226,   222,   175,
     177,   179,   217,   214,     0,     0,    30,     0,    67,     0,
      65,    61,     0,    90,    47,    45,     0,     0,    38,    57,
      55,    98,     0,    92,    41,     0,   211,   207,   188,   185,
       0,     0,   227,     0,   216,    82,    80,    59,     0,     0,
      63,     0,    78,     0,    71,    75,     0,     0,    48,    32,
       0,     0,     0,    97,     0,   125,   210,   225,   224,   223,
     220,    83,    68,    66,     0,     0,    70,    72,     0,    91,
      49,     0,     0,     0,    99,     0,    93,     0,     0,    77,
      76,     0,    50,    33,    35,    39,   100,    84,    85,    87,
      73,     0,     0,     0,     0,    42,    36,    86,    74
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     1,     2,     3,     5,    56,    57,    58,   125,    59,
     137,   361,    60,   138,   382,    61,   229,   341,    62,   235,
      63,   224,   225,   337,   371,    64,    65,   141,   142,    66,
     217,    67,   128,   219,   299,   300,    68,   302,   333,   334,
     384,   358,   335,    69,   215,   295,   367,   377,   378,    70,
      71,   336,    72,   344,    73,    74,   145,   312,    75,   211,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,   282,   122,    93,
      98,   100,    94,   280,   281,    95,   123,   213,   214,    96,
     204,   287,   288,   323
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -212
static const short yypact[] =
{
    -212,     5,  -212,  -212,  -212,   253,   -56,  -212,   -44,  -212,
    1029,  1029,  1029,  1029,  1029,    96,  1029,  1029,  1029,  1029,
    1029,  1029,  1029,  1029,  1072,  -212,  -212,  -212,  -212,  -212,
     -96,  -212,  -212,   -35,   -85,   -14,  1029,   -43,   531,    -8,
      23,    26,  -212,  -212,    30,   -26,   -26,  1029,  -212,    51,
    1029,  1029,  1029,  -212,  -212,  -212,  -212,  -212,  -212,  -212,
    -212,    24,  -212,  -212,  -212,    66,  -212,  -212,  -212,  -212,
    -212,  -212,  -212,  -212,  -212,  -212,    67,     0,  -212,   597,
      80,   114,   122,   113,   121,    -9,    -4,    36,    61,    58,
    -212,   -30,    32,  -212,  -212,  -212,  -212,  -212,    31,  -212,
      33,  -212,  -212,  -212,  -212,  -212,  -212,  1029,    83,   125,
    -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,   622,   713,
     804,    85,    41,  1029,  -212,  -212,  -212,  -212,    95,  -212,
      99,    98,  -212,   102,  -212,  1029,   847,   116,   440,  -212,
     170,   172,  -212,   172,   111,   440,  1029,  -212,  -212,  -212,
    -212,  -212,  -212,  1029,  1029,  1029,  1029,  1029,  1029,  1029,
    1029,  1029,  1029,  1029,  1029,  1029,  1029,  1029,  1029,  1029,
    1029,  1029,  1029,  1029,  1029,  1029,  1029,  1029,  1029,  1029,
    1029,  1029,  1029,  1029,  1029,  1029,  1029,  1029,  1029,  1029,
    1029,  1029,  1029,  1029,  -212,  1029,  -212,  -212,  -212,   938,
    -212,  1029,    96,  -212,  1163,  -212,  1029,  1029,  1029,  -212,
    -212,  -212,  -212,     7,  -212,   106,   349,    95,    70,   123,
    -212,  -212,  -212,   127,   126,    22,  -212,  1029,   104,  1029,
    1029,   -26,  -212,    93,   132,   440,  -212,  -212,  -212,  -212,
    -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,
    -212,  -212,  -212,  -212,   133,   114,   122,   113,   121,    -9,
      -4,    -4,    -4,    -4,    36,    36,    36,    36,    61,    61,
      61,    58,    58,  -212,  -212,  -212,  -212,  -212,  -212,  -212,
       3,  -212,    79,   140,  -212,   138,   205,   206,  -212,  -212,
    -212,  -212,  1029,  -212,  1029,   123,  -212,   123,   207,     4,
    -212,  -212,    19,  -212,  1029,  -212,   149,   159,  -212,  -212,
    -212,   160,   440,  -212,  -212,  1029,  1029,  -212,  -212,  -212,
    1029,  1029,  1163,   155,  -212,   214,  -212,  -212,  1029,    70,
    -212,   163,   164,   -18,  -212,  -212,   123,   156,  -212,  -212,
    1029,   157,   -48,  -212,   440,  -212,  -212,  -212,  -212,  -212,
    -212,  -212,  -212,  -212,   105,   161,  -212,  -212,   123,  -212,
    1029,   440,   162,   440,  -212,   165,  -212,  1029,   167,  -212,
    -212,   168,  -212,  -212,  -212,  -212,  -212,   220,  -212,  -212,
    -212,   440,   171,  1029,   123,  -212,  -212,  -212,  -212
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -212,  -212,  -212,  -212,   115,  -134,  -212,  -211,  -212,  -212,
    -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,
    -212,  -212,  -212,  -212,  -212,  -212,    13,   193,    10,  -212,
    -212,  -212,  -212,    25,  -212,   -86,  -212,  -212,  -212,   -89,
    -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -137,  -212,
    -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -179,
     -24,  -212,  -122,  -169,  -212,    84,    78,    81,    77,    82,
     -75,     2,   -66,   -60,    42,    55,   244,  -212,  -212,  -212,
    -212,  -212,   245,  -212,   -54,  -212,  -212,  -212,   -29,  -212,
    -212,  -212,   -57,  -212
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -187
static const short yytable[] =
{
     121,   212,   254,   153,   228,     4,   316,   329,   301,    97,
     292,   233,   130,    99,   133,   364,   177,   178,   179,   180,
     279,   124,   194,   144,   195,   286,   181,   182,   183,   184,
     126,   236,   127,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   356,
     129,   309,   102,   103,   104,   105,   106,   134,   110,   111,
     112,   113,   114,   115,   116,   117,   317,   330,   293,   365,
     185,   186,   187,   196,   131,   197,   198,   212,   135,   331,
     332,   136,   212,   121,   326,   139,   327,   199,   200,   201,
     154,   140,   147,   148,   149,   190,   191,   192,   193,   171,
     172,   314,   260,   261,   262,   263,   146,     7,   212,   188,
     189,   223,   226,    45,    46,   325,   331,   332,   202,   268,
     269,   270,   234,   150,   196,   359,   197,   198,   271,   272,
     237,   151,   152,     8,     9,   173,   175,   279,   199,   200,
     201,   347,   348,   286,   174,   176,   345,   370,   209,   352,
     218,   107,    25,    26,    27,    28,    29,   203,   210,   205,
     147,   148,   149,   220,   221,   101,  -186,   222,  -186,  -186,
     212,   227,   212,   388,   230,   231,   232,   283,   343,   294,
    -186,  -186,  -186,   264,   265,   266,   267,   298,   379,    32,
     303,   304,   307,   311,   212,   313,   318,   315,   212,   212,
     212,   319,   320,   306,   379,   308,   212,    53,   321,   322,
     366,   328,   339,    54,   340,   342,   350,   351,   354,   355,
     363,   360,   368,   383,   369,   374,    55,   373,   376,   375,
     380,   381,   273,   274,   275,   276,   386,   277,   305,   143,
     216,   310,   297,   353,   357,   212,   387,   385,   289,   290,
     291,   256,   258,    -4,     6,   257,   255,   284,   259,   108,
     109,   212,   346,   324,     7,   349,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     338,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       8,     9,     0,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,     0,    24,    25,
      26,    27,    28,    29,     0,    30,   362,     0,    31,    32,
       0,    33,    34,     0,    35,    36,     0,     0,    37,     0,
       0,     0,     0,    38,    39,     0,   372,    40,     0,     0,
      41,    42,    43,    44,    45,    46,     0,     0,    47,    48,
       6,     0,     0,     0,     0,     0,    49,    50,    51,    52,
       7,     0,     0,     0,    53,     0,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,     0,     0,     8,     9,     0,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,     0,    24,    25,    26,    27,    28,    29,
       0,    30,     0,     0,    31,    32,   296,    33,    34,     0,
      35,    36,     0,     0,    37,     0,     0,     0,     0,    38,
      39,     0,     0,    40,     0,     0,    41,    42,    43,    44,
      45,    46,     0,     0,    47,    48,     0,     0,     0,     0,
       0,     7,    49,    50,    51,    52,     0,     0,     0,     0,
      53,     0,     0,     0,     0,     0,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     8,     9,    55,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,     0,    24,    25,    26,    27,    28,
      29,     0,    30,     0,     0,    31,    32,     0,    33,    34,
       0,    35,    36,     0,     0,    37,     0,     0,     0,     0,
      38,    39,     0,     0,    40,     0,     0,    41,    42,    43,
      44,    45,    46,     0,     0,    47,    48,     0,     0,     0,
       0,     0,     7,    49,    50,    51,    52,     0,     0,     0,
       0,    53,     0,     0,     0,     0,     0,    54,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     8,     9,
      55,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,     0,    24,    25,    26,    27,
      28,    29,     0,     0,     0,     0,   132,     0,     0,     0,
     101,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   170,     0,     0,     0,
       0,     0,     0,     7,     0,    50,    51,    52,     0,     0,
       0,     0,    53,     0,     0,     0,     0,     0,    54,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     8,
       9,    55,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,     0,    24,    25,    26,
      27,    28,    29,     0,     0,   206,     0,     0,     0,     0,
       0,   101,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     0,    50,    51,    52,     0,
       0,     0,     0,    53,     0,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       8,     9,    55,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,     0,    24,    25,
      26,    27,    28,    29,     0,     0,   207,     0,     0,     0,
       0,     0,   101,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     0,    50,    51,    52,
       0,     0,     0,     0,    53,     0,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     8,     9,    55,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,     7,    24,
      25,    26,    27,    28,    29,     0,     0,   208,     0,     0,
       0,     0,     0,   101,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     8,     9,     0,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,     0,    24,    25,    26,    27,    28,    29,    50,    51,
      52,     0,   -43,     0,     0,    53,   101,     0,     0,     0,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    55,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       0,    50,    51,    52,     0,     0,     0,     0,    53,     0,
       0,     0,     0,     0,    54,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     8,     9,    55,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,     0,    24,    25,    26,    27,    28,    29,     0,
       0,     0,     0,     0,     0,     0,     0,   101,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   278,
       7,     0,    50,    51,    52,     0,     0,     0,     0,    53,
       0,     0,     0,     0,     0,    54,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     8,     9,    55,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,     7,    24,    25,    26,    27,    28,    29,
       0,     0,     0,     0,     0,     0,     0,     0,   101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     8,
       9,     0,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,     0,    24,    25,    26,
      27,    28,    29,    50,    51,    52,     0,     0,     0,     0,
      53,   101,     0,     0,     0,     0,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     0,   118,   119,   120,     0,
       0,     0,     0,    53,     0,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       8,     9,    55,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,     0,    24,    25,
      26,    27,    28,    29,     0,     0,     0,     0,     0,     0,
       0,     0,   101,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    50,    51,    52,
       0,     0,     0,     0,    53,     0,     0,     0,     0,     0,
     285,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55
};

static const short yycheck[] =
{
      24,   123,   171,     3,   138,     0,     3,     3,   219,    65,
       3,   145,    36,    57,    38,    63,    25,    26,    27,    28,
     199,   117,    52,    47,    54,   204,    30,    31,    32,    33,
      65,   153,   117,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,    67,
      64,   230,    10,    11,    12,    13,    14,    65,    16,    17,
      18,    19,    20,    21,    22,    23,    63,    63,    61,   117,
      34,    35,    36,    41,   117,    43,    44,   199,    55,    97,
      98,    55,   204,   107,   295,    55,   297,    55,    56,    57,
      90,   117,    50,    51,    52,    37,    38,    39,    40,    19,
      20,   235,   177,   178,   179,   180,    55,    11,   230,    48,
      49,   135,   136,    91,    92,   294,    97,    98,    86,   185,
     186,   187,   146,    99,    41,   336,    43,    44,   188,   189,
     154,    65,    65,    37,    38,    21,    23,   316,    55,    56,
      57,   320,   321,   322,    22,    24,   315,   358,    63,   328,
      55,    55,    56,    57,    58,    59,    60,   126,   117,   126,
     118,   119,   120,    64,    66,    69,    41,    65,    43,    44,
     292,    55,   294,   384,     4,     3,    65,   201,   312,    73,
      55,    56,    57,   181,   182,   183,   184,   117,   367,    66,
      63,    65,    88,   100,   316,    63,   117,    64,   320,   321,
     322,    61,    64,   227,   383,   229,   328,   111,     3,     3,
     344,     4,    63,   117,    55,    55,    61,     3,    55,    55,
      63,    65,   117,     3,    63,    63,   130,   361,    63,   363,
      63,    63,   190,   191,   192,   193,    65,   195,   225,    46,
     125,   231,   217,   329,   333,   367,   383,   381,   206,   207,
     208,   173,   175,     0,     1,   174,   172,   202,   176,    15,
      15,   383,   316,   292,    11,   322,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     304,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    38,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    -1,    62,   340,    -1,    65,    66,
      -1,    68,    69,    -1,    71,    72,    -1,    -1,    75,    -1,
      -1,    -1,    -1,    80,    81,    -1,   360,    84,    -1,    -1,
      87,    88,    89,    90,    91,    92,    -1,    -1,    95,    96,
       1,    -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,
      11,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   130,    -1,    -1,    37,    38,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      -1,    62,    -1,    -1,    65,    66,    67,    68,    69,    -1,
      71,    72,    -1,    -1,    75,    -1,    -1,    -1,    -1,    80,
      81,    -1,    -1,    84,    -1,    -1,    87,    88,    89,    90,
      91,    92,    -1,    -1,    95,    96,    -1,    -1,    -1,    -1,
      -1,    11,   103,   104,   105,   106,    -1,    -1,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,   130,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    -1,    62,    -1,    -1,    65,    66,    -1,    68,    69,
      -1,    71,    72,    -1,    -1,    75,    -1,    -1,    -1,    -1,
      80,    81,    -1,    -1,    84,    -1,    -1,    87,    88,    89,
      90,    91,    92,    -1,    -1,    95,    96,    -1,    -1,    -1,
      -1,    -1,    11,   103,   104,   105,   106,    -1,    -1,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
     130,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,
      69,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    11,    -1,   104,   105,   106,    -1,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,   117,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      38,   130,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    11,    -1,   104,   105,   106,    -1,
      -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,   117,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    38,   130,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    11,    -1,   104,   105,   106,
      -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    38,   130,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    11,    55,
      56,    57,    58,    59,    60,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,   104,   105,
     106,    -1,    65,    -1,    -1,   111,    69,    -1,    -1,    -1,
      -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,
      -1,   104,   105,   106,    -1,    -1,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    38,   130,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,
      11,    -1,   104,   105,   106,    -1,    -1,    -1,    -1,   111,
      -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,   130,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    11,    55,    56,    57,    58,    59,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      38,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,   104,   105,   106,    -1,    -1,    -1,    -1,
     111,    69,    -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    11,    -1,   104,   105,   106,    -1,
      -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,   117,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    38,   130,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,   105,   106,
      -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   130
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,   132,   133,   134,     0,   135,     1,    11,    37,    38,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    55,    56,    57,    58,    59,    60,
      62,    65,    66,    68,    69,    71,    72,    75,    80,    81,
      84,    87,    88,    89,    90,    91,    92,    95,    96,   103,
     104,   105,   106,   111,   117,   130,   136,   137,   138,   140,
     143,   146,   149,   151,   156,   157,   160,   162,   167,   174,
     180,   181,   183,   185,   186,   189,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   210,   213,   216,   220,    65,   211,    57,
     212,    69,   205,   205,   205,   205,   205,    55,   207,   213,
     205,   205,   205,   205,   205,   205,   205,   205,   104,   105,
     106,   191,   209,   217,   117,   139,    65,   117,   163,    64,
     191,   117,    65,   191,    65,    55,    55,   141,   144,    55,
     117,   158,   159,   158,   191,   187,    55,   205,   205,   205,
      99,    65,    65,     3,    90,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      29,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    30,    31,    32,    33,    34,    35,    36,    48,    49,
      37,    38,    39,    40,    52,    54,    41,    43,    44,    55,
      56,    57,    86,   126,   221,   126,    63,    63,    63,    63,
     117,   190,   193,   218,   219,   175,   135,   161,    55,   164,
      64,    66,    65,   191,   152,   153,   191,    55,   136,   147,
       4,     3,    65,   136,   191,   150,   193,   191,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   194,   196,   197,   198,   199,   200,
     201,   201,   201,   201,   202,   202,   202,   202,   203,   203,
     203,   204,   204,   205,   205,   205,   205,   205,   101,   190,
     214,   215,   208,   191,   206,   117,   190,   222,   223,   205,
     205,   205,     3,    61,    73,   176,    67,   164,   117,   165,
     166,   138,   168,    63,    65,   157,   191,    88,   191,   190,
     159,   100,   188,    63,   136,    64,     3,    63,   117,    61,
      64,     3,     3,   224,   219,   190,   138,   138,     4,     3,
      63,    97,    98,   169,   170,   173,   182,   154,   191,    63,
      55,   148,    55,   136,   184,   194,   215,   190,   190,   223,
      61,     3,   190,   166,    55,    55,    67,   170,   172,   138,
      65,   142,   191,    63,    63,   117,   136,   177,   117,    63,
     138,   155,   191,   136,    63,   136,    63,   178,   179,   190,
      63,    63,   145,     3,   171,   136,    65,   179,   138
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrlab1


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)         \
  Current.first_line   = Rhs[1].first_line;      \
  Current.first_column = Rhs[1].first_column;    \
  Current.last_line    = Rhs[N].last_line;       \
  Current.last_column  = Rhs[N].last_column;
#endif

/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)

# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)

# define YYDSYMPRINTF(Title, Token, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Token, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (cinluded).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short *bottom, short *top)
#else
static void
yy_stack_print (bottom, top)
    short *bottom;
    short *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
# define YYDSYMPRINTF(Title, Token, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    {
      YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
    }
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yytype, yyvaluep)
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */






/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  /* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;

  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 216 "..\bison\tjs.y"
    { sb->PushContextStack(TJS_W("global"),
												ctTopLevel); ;}
    break;

  case 4:
#line 218 "..\bison\tjs.y"
    { sb->PopContextStack(); ;}
    break;

  case 7:
#line 225 "..\bison\tjs.y"
    { if(sb->CompileErrorCount>20)
												YYABORT;
											  else yyerrok; ;}
    break;

  case 11:
#line 239 "..\bison\tjs.y"
    { cc->CreateExprCode(yyvsp[-1].np); ;}
    break;

  case 17:
#line 245 "..\bison\tjs.y"
    { cc->DoBreak(); ;}
    break;

  case 18:
#line 246 "..\bison\tjs.y"
    { cc->DoContinue(); ;}
    break;

  case 29:
#line 261 "..\bison\tjs.y"
    { cc->EnterBlock(); ;}
    break;

  case 30:
#line 263 "..\bison\tjs.y"
    { cc->ExitBlock(); ;}
    break;

  case 31:
#line 268 "..\bison\tjs.y"
    { cc->EnterWhileCode(false); ;}
    break;

  case 32:
#line 269 "..\bison\tjs.y"
    { cc->CreateWhileExprCode(yyvsp[-1].np, false); ;}
    break;

  case 33:
#line 270 "..\bison\tjs.y"
    { cc->ExitWhileCode(false); ;}
    break;

  case 34:
#line 275 "..\bison\tjs.y"
    { cc->EnterWhileCode(true); ;}
    break;

  case 35:
#line 278 "..\bison\tjs.y"
    { cc->CreateWhileExprCode(yyvsp[-1].np, true); ;}
    break;

  case 36:
#line 279 "..\bison\tjs.y"
    { cc->ExitWhileCode(true); ;}
    break;

  case 37:
#line 284 "..\bison\tjs.y"
    { cc->EnterIfCode(); ;}
    break;

  case 38:
#line 285 "..\bison\tjs.y"
    { cc->CreateIfExprCode(yyvsp[0].np); ;}
    break;

  case 39:
#line 286 "..\bison\tjs.y"
    { cc->ExitIfCode(); ;}
    break;

  case 40:
#line 291 "..\bison\tjs.y"
    { cc->EnterElseCode(); ;}
    break;

  case 41:
#line 292 "..\bison\tjs.y"
    { cc->ExitElseCode(); ;}
    break;

  case 42:
#line 301 "..\bison\tjs.y"
    { cc->ExitForCode(); ;}
    break;

  case 43:
#line 307 "..\bison\tjs.y"
    { cc->EnterForCode(false); ;}
    break;

  case 44:
#line 308 "..\bison\tjs.y"
    { cc->EnterForCode(true); ;}
    break;

  case 46:
#line 310 "..\bison\tjs.y"
    { cc->EnterForCode(false);
											  cc->CreateExprCode(yyvsp[0].np); ;}
    break;

  case 47:
#line 316 "..\bison\tjs.y"
    { cc->CreateForExprCode(NULL); ;}
    break;

  case 48:
#line 317 "..\bison\tjs.y"
    { cc->CreateForExprCode(yyvsp[0].np); ;}
    break;

  case 49:
#line 322 "..\bison\tjs.y"
    { cc->SetForThirdExprCode(NULL); ;}
    break;

  case 50:
#line 323 "..\bison\tjs.y"
    { cc->SetForThirdExprCode(yyvsp[0].np); ;}
    break;

  case 56:
#line 346 "..\bison\tjs.y"
    { cc->AddLocalVariable(
												lx->GetString(yyvsp[0].num)); ;}
    break;

  case 57:
#line 348 "..\bison\tjs.y"
    { cc->InitLocalVariable(
											  lx->GetString(yyvsp[-2].num), yyvsp[0].np); ;}
    break;

  case 58:
#line 354 "..\bison\tjs.y"
    { sb->PushContextStack(
												lx->GetString(yyvsp[0].num),
											  ctFunction);
											  cc->EnterBlock();;}
    break;

  case 59:
#line 359 "..\bison\tjs.y"
    { cc->ExitBlock(); sb->PopContextStack(); ;}
    break;

  case 60:
#line 364 "..\bison\tjs.y"
    { sb->PushContextStack(
												TJS_W("(anonymous)"),
											  ctExprFunction);
											  cc->EnterBlock(); ;}
    break;

  case 61:
#line 369 "..\bison\tjs.y"
    { cc->ExitBlock();
											  tTJSVariant v(cc);
											  sb->PopContextStack();
											  yyval.np = cc->MakeNP0(T_CONSTVAL);
											  yyval.np->SetValue(v); ;}
    break;

  case 67:
#line 390 "..\bison\tjs.y"
    { cc->AddFunctionDeclArg(
												lx->GetString(yyvsp[0].num), NULL); ;}
    break;

  case 68:
#line 392 "..\bison\tjs.y"
    { cc->AddFunctionDeclArg(
												lx->GetString(yyvsp[-2].num), yyvsp[0].np); ;}
    break;

  case 69:
#line 399 "..\bison\tjs.y"
    { sb->PushContextStack(
												lx->GetString(yyvsp[-1].num),
												ctProperty); ;}
    break;

  case 70:
#line 403 "..\bison\tjs.y"
    { sb->PopContextStack(); ;}
    break;

  case 73:
#line 412 "..\bison\tjs.y"
    { sb->PushContextStack(
												TJS_W("(setter)"),
												ctPropertySetter);
											  cc->EnterBlock();
											  cc->SetPropertyDeclArg(
												lx->GetString(yyvsp[-1].num)); ;}
    break;

  case 74:
#line 418 "..\bison\tjs.y"
    { cc->ExitBlock();
	  										  sb->PopContextStack(); ;}
    break;

  case 75:
#line 420 "..\bison\tjs.y"
    { sb->PushContextStack(
												TJS_W("(getter)"),
												ctPropertyGetter);
											  cc->EnterBlock(); ;}
    break;

  case 76:
#line 424 "..\bison\tjs.y"
    { cc->ExitBlock();
	  										  sb->PopContextStack(); ;}
    break;

  case 79:
#line 436 "..\bison\tjs.y"
    { sb->PushContextStack(
												lx->GetString(yyvsp[0].num),
												ctClass); ;}
    break;

  case 80:
#line 440 "..\bison\tjs.y"
    { sb->PopContextStack(); ;}
    break;

  case 82:
#line 445 "..\bison\tjs.y"
    { cc->CreateExtendsExprCode(yyvsp[0].np, true); ;}
    break;

  case 83:
#line 446 "..\bison\tjs.y"
    { cc->CreateExtendsExprCode(yyvsp[-1].np, false); ;}
    break;

  case 87:
#line 456 "..\bison\tjs.y"
    { cc->CreateExtendsExprCode(yyvsp[0].np, false); ;}
    break;

  case 88:
#line 461 "..\bison\tjs.y"
    { cc->ReturnFromFunc(NULL); ;}
    break;

  case 89:
#line 462 "..\bison\tjs.y"
    { cc->ReturnFromFunc(yyvsp[-1].np); ;}
    break;

  case 90:
#line 469 "..\bison\tjs.y"
    { cc->EnterSwitchCode(yyvsp[-1].np); ;}
    break;

  case 91:
#line 470 "..\bison\tjs.y"
    { cc->ExitSwitchCode(); ;}
    break;

  case 92:
#line 476 "..\bison\tjs.y"
    { cc->EnterWithCode(yyvsp[-1].np); ;}
    break;

  case 93:
#line 477 "..\bison\tjs.y"
    { cc->ExitWithCode(); ;}
    break;

  case 94:
#line 482 "..\bison\tjs.y"
    { cc->ProcessCaseCode(yyvsp[-1].np); ;}
    break;

  case 95:
#line 483 "..\bison\tjs.y"
    { cc->ProcessCaseCode(NULL); ;}
    break;

  case 96:
#line 488 "..\bison\tjs.y"
    { cc->EnterTryCode(); ;}
    break;

  case 97:
#line 491 "..\bison\tjs.y"
    { cc->ExitTryCode(); ;}
    break;

  case 98:
#line 495 "..\bison\tjs.y"
    { cc->EnterCatchCode(NULL); ;}
    break;

  case 99:
#line 496 "..\bison\tjs.y"
    { cc->EnterCatchCode(NULL); ;}
    break;

  case 100:
#line 497 "..\bison\tjs.y"
    { cc->EnterCatchCode(
												lx->GetString(yyvsp[-1].num)); ;}
    break;

  case 101:
#line 503 "..\bison\tjs.y"
    { cc->ProcessThrowCode(yyvsp[-1].np); ;}
    break;

  case 102:
#line 508 "..\bison\tjs.y"
    { yyval.np = yyvsp[0].np; ;}
    break;

  case 103:
#line 512 "..\bison\tjs.y"
    { yyval.np = yyvsp[0].np; ;}
    break;

  case 104:
#line 513 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_IF, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 105:
#line 518 "..\bison\tjs.y"
    { yyval.np = yyvsp[0].np; ;}
    break;

  case 106:
#line 519 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_COMMA, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 107:
#line 524 "..\bison\tjs.y"
    { yyval.np = yyvsp[0].np; ;}
    break;

  case 108:
#line 525 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_SWAP, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 109:
#line 526 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_EQUAL, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 110:
#line 527 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_AMPERSANDEQUAL, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 111:
#line 528 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_VERTLINEEQUAL, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 112:
#line 529 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_CHEVRONEQUAL, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 113:
#line 530 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_MINUSEQUAL, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 114:
#line 531 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_PLUSEQUAL, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 115:
#line 532 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_PERCENTEQUAL, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 116:
#line 533 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_SLASHEQUAL, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 117:
#line 534 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_BACKSLASHEQUAL, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 118:
#line 535 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_ASTERISKEQUAL, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 119:
#line 536 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_LOGICALOREQUAL, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 120:
#line 537 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_LOGICALANDEQUAL, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 121:
#line 538 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_RARITHSHIFTEQUAL, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 122:
#line 539 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_LARITHSHIFTEQUAL, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 123:
#line 540 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_RBITSHIFTEQUAL, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 124:
#line 545 "..\bison\tjs.y"
    { yyval.np = yyvsp[0].np; ;}
    break;

  case 125:
#line 548 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP3(T_QUESTION, yyvsp[-4].np, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 126:
#line 554 "..\bison\tjs.y"
    { yyval.np = yyvsp[0].np; ;}
    break;

  case 127:
#line 555 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_LOGICALOR, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 128:
#line 559 "..\bison\tjs.y"
    { yyval.np = yyvsp[0].np; ;}
    break;

  case 129:
#line 561 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_LOGICALAND, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 130:
#line 565 "..\bison\tjs.y"
    { yyval.np = yyvsp[0].np; ;}
    break;

  case 131:
#line 566 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_VERTLINE, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 132:
#line 570 "..\bison\tjs.y"
    { yyval.np = yyvsp[0].np; ;}
    break;

  case 133:
#line 571 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_CHEVRON, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 134:
#line 575 "..\bison\tjs.y"
    { yyval.np = yyvsp[0].np; ;}
    break;

  case 135:
#line 576 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_AMPERSAND, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 136:
#line 580 "..\bison\tjs.y"
    { yyval.np = yyvsp[0].np; ;}
    break;

  case 137:
#line 581 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_NOTEQUAL, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 138:
#line 582 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_EQUALEQUAL, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 139:
#line 583 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_DISCNOTEQUAL, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 140:
#line 584 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_DISCEQUAL, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 141:
#line 588 "..\bison\tjs.y"
    { yyval.np = yyvsp[0].np; ;}
    break;

  case 142:
#line 589 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_LT, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 143:
#line 590 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_GT, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 144:
#line 591 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_LTOREQUAL, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 145:
#line 592 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_GTOREQUAL, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 146:
#line 596 "..\bison\tjs.y"
    { yyval.np = yyvsp[0].np; ;}
    break;

  case 147:
#line 597 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_RARITHSHIFT, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 148:
#line 598 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_LARITHSHIFT, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 149:
#line 599 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_RBITSHIFT, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 150:
#line 604 "..\bison\tjs.y"
    { yyval.np = yyvsp[0].np; ;}
    break;

  case 151:
#line 605 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_PLUS, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 152:
#line 606 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_MINUS, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 153:
#line 610 "..\bison\tjs.y"
    { yyval.np = yyvsp[0].np; ;}
    break;

  case 154:
#line 611 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_PERCENT, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 155:
#line 612 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_SLASH, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 156:
#line 613 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_BACKSLASH, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 157:
#line 614 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_ASTERISK, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 158:
#line 618 "..\bison\tjs.y"
    { yyval.np = yyvsp[0].np; ;}
    break;

  case 159:
#line 619 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP1(T_EXCRAMATION, yyvsp[0].np); ;}
    break;

  case 160:
#line 620 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP1(T_TILDE, yyvsp[0].np); ;}
    break;

  case 161:
#line 621 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP1(T_DECREMENT, yyvsp[0].np); ;}
    break;

  case 162:
#line 622 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP1(T_INCREMENT, yyvsp[0].np); ;}
    break;

  case 163:
#line 623 "..\bison\tjs.y"
    { yyval.np = yyvsp[0].np; yyval.np->SetOpecode(T_NEW); ;}
    break;

  case 164:
#line 624 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP1(T_INVALIDATE, yyvsp[0].np); ;}
    break;

  case 165:
#line 625 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP1(T_ISVALID, yyvsp[0].np); ;}
    break;

  case 166:
#line 626 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP1(T_ISVALID, yyvsp[-1].np); ;}
    break;

  case 167:
#line 627 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP1(T_DELETE, yyvsp[0].np); ;}
    break;

  case 168:
#line 628 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP1(T_TYPEOF, yyvsp[0].np); ;}
    break;

  case 169:
#line 629 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP1(T_SHARP, yyvsp[0].np); ;}
    break;

  case 170:
#line 630 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP1(T_DOLLAR, yyvsp[0].np); ;}
    break;

  case 171:
#line 631 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP1(T_UPLUS, yyvsp[0].np); ;}
    break;

  case 172:
#line 632 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP1(T_UMINUS, yyvsp[0].np); ;}
    break;

  case 173:
#line 633 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP1(T_SUBSTANCE, yyvsp[0].np); ;}
    break;

  case 174:
#line 634 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_INSTANCEOF, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 175:
#line 635 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP1(T_INT, yyvsp[0].np); ;}
    break;

  case 176:
#line 636 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP1(T_INT, yyvsp[0].np); ;}
    break;

  case 177:
#line 637 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP1(T_REAL, yyvsp[0].np); ;}
    break;

  case 178:
#line 638 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP1(T_REAL, yyvsp[0].np); ;}
    break;

  case 179:
#line 639 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP1(T_STRING, yyvsp[0].np); ;}
    break;

  case 180:
#line 640 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP1(T_STRING, yyvsp[0].np); ;}
    break;

  case 181:
#line 644 "..\bison\tjs.y"
    { yyval.np = yyvsp[0].np; ;}
    break;

  case 182:
#line 646 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_INCONTEXTOF, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 183:
#line 650 "..\bison\tjs.y"
    { yyval.np = yyvsp[0].np; ;}
    break;

  case 184:
#line 651 "..\bison\tjs.y"
    { yyval.np = yyvsp[-1].np; ;}
    break;

  case 185:
#line 652 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_LBRACKET, yyvsp[-3].np, yyvsp[-1].np); ;}
    break;

  case 186:
#line 653 "..\bison\tjs.y"
    { yyval.np = yyvsp[0].np; ;}
    break;

  case 187:
#line 654 "..\bison\tjs.y"
    { lx->SetNextIsBareWord(); ;}
    break;

  case 188:
#line 655 "..\bison\tjs.y"
    { tTJSExprNode * node = cc->MakeNP0(T_CONSTVAL);
												  node->SetValue(lx->GetValue(yyvsp[0].num));
												  yyval.np = cc->MakeNP2(T_DOT, yyvsp[-3].np, node); ;}
    break;

  case 189:
#line 658 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP1(T_POSTINCREMENT, yyvsp[-1].np); ;}
    break;

  case 190:
#line 659 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP1(T_POSTDECREMENT, yyvsp[-1].np); ;}
    break;

  case 191:
#line 660 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP1(T_EVAL, yyvsp[-1].np); ;}
    break;

  case 192:
#line 661 "..\bison\tjs.y"
    { lx->SetNextIsBareWord(); ;}
    break;

  case 193:
#line 662 "..\bison\tjs.y"
    { tTJSExprNode * node = cc->MakeNP0(T_CONSTVAL);
												  node->SetValue(lx->GetValue(yyvsp[0].num));
												  yyval.np = cc->MakeNP1(T_WITHDOT, node); ;}
    break;

  case 194:
#line 669 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP0(T_CONSTVAL);
												  yyval.np->SetValue(lx->GetValue(yyvsp[0].num)); ;}
    break;

  case 195:
#line 671 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP0(T_SYMBOL);
												  yyval.np->SetValue(tTJSVariant(
													lx->GetString(yyvsp[0].num))); ;}
    break;

  case 196:
#line 674 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP0(T_THIS); ;}
    break;

  case 197:
#line 675 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP0(T_SUPER); ;}
    break;

  case 198:
#line 676 "..\bison\tjs.y"
    { yyval.np = yyvsp[0].np; ;}
    break;

  case 199:
#line 677 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP0(T_GLOBAL); ;}
    break;

  case 200:
#line 678 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP0(T_VOID); ;}
    break;

  case 201:
#line 679 "..\bison\tjs.y"
    { yyval.np = yyvsp[0].np; ;}
    break;

  case 202:
#line 680 "..\bison\tjs.y"
    { yyval.np = yyvsp[0].np; ;}
    break;

  case 203:
#line 681 "..\bison\tjs.y"
    { lx->SetStartOfRegExp(); ;}
    break;

  case 204:
#line 682 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP0(T_REGEXP);
												  yyval.np->SetValue(lx->GetValue(yyvsp[0].num)); ;}
    break;

  case 205:
#line 684 "..\bison\tjs.y"
    { lx->SetStartOfRegExp(); ;}
    break;

  case 206:
#line 685 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP0(T_REGEXP);
												  yyval.np->SetValue(lx->GetValue(yyvsp[0].num)); ;}
    break;

  case 207:
#line 692 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_LPARENTHESIS, yyvsp[-3].np, yyvsp[-1].np); ;}
    break;

  case 208:
#line 697 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP0(T_OMIT); ;}
    break;

  case 209:
#line 698 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP1(T_ARG, yyvsp[0].np); ;}
    break;

  case 210:
#line 699 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_ARG, yyvsp[0].np, yyvsp[-2].np); ;}
    break;

  case 211:
#line 703 "..\bison\tjs.y"
    { yyval.np = NULL; ;}
    break;

  case 212:
#line 704 "..\bison\tjs.y"
    { yyval.np = yyvsp[0].np; ;}
    break;

  case 213:
#line 710 "..\bison\tjs.y"
    { tTJSExprNode *node =
										  cc->MakeNP0(T_INLINEARRAY);
										  cc->PushCurrentNode(node); ;}
    break;

  case 214:
#line 714 "..\bison\tjs.y"
    { yyval.np = cn; cc->PopCurrentNode(); ;}
    break;

  case 215:
#line 719 "..\bison\tjs.y"
    { cn->Add(yyvsp[0].np); ;}
    break;

  case 216:
#line 720 "..\bison\tjs.y"
    { cn->Add(yyvsp[0].np); ;}
    break;

  case 217:
#line 725 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP1(T_ARRAYARG, NULL); ;}
    break;

  case 218:
#line 726 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP1(T_ARRAYARG, yyvsp[0].np); ;}
    break;

  case 219:
#line 731 "..\bison\tjs.y"
    { tTJSExprNode *node =
										  cc->MakeNP0(T_INLINEDIC);
										  cc->PushCurrentNode(node); ;}
    break;

  case 220:
#line 736 "..\bison\tjs.y"
    { yyval.np = cn; cc->PopCurrentNode(); ;}
    break;

  case 222:
#line 743 "..\bison\tjs.y"
    { cn->Add(yyvsp[0].np); ;}
    break;

  case 223:
#line 744 "..\bison\tjs.y"
    { cn->Add(yyvsp[0].np); ;}
    break;

  case 224:
#line 749 "..\bison\tjs.y"
    { yyval.np = cc->MakeNP2(T_DICELM, yyvsp[-2].np, yyvsp[0].np); ;}
    break;

  case 225:
#line 750 "..\bison\tjs.y"
    { tTJSVariant val(lx->GetString(yyvsp[-2].num));
										  tTJSExprNode *node0 = cc->MakeNP0(T_CONSTVAL);
										  node0->SetValue(val);
										  yyval.np = cc->MakeNP2(T_DICELM, node0, yyvsp[0].np); ;}
    break;


    }

/* Line 999 of yacc.c.  */
#line 2841 "tjs.tab.c"

  yyvsp -= yylen;
  yyssp -= yylen;


  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  const char* yyprefix;
	  char *yymsg;
	  int yyx;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 0;

	  yyprefix = ", expecting ";
	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		yysize += yystrlen (yyprefix) + yystrlen (yytname [yyx]);
		yycount += 1;
		if (yycount == 5)
		  {
		    yysize = 0;
		    break;
		  }
	      }
	  yysize += (sizeof ("syntax error, unexpected ")
		     + yystrlen (yytname[yytype]));
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yyprefix = ", expecting ";
		  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			yyp = yystpcpy (yyp, yyprefix);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yyprefix = " or ";
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* Return failure if at end of input.  */
      if (yychar == YYEOF)
        {
	  /* Pop the error token.  */
          YYPOPSTACK;
	  /* Pop the rest of the stack.  */
	  while (yyss < yyssp)
	    {
	      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
	      yydestruct (yystos[*yyssp], yyvsp);
	      YYPOPSTACK;
	    }
	  YYABORT;
        }

      YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
      yydestruct (yytoken, &yylval);
      yychar = YYEMPTY;

    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*----------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action.  |
`----------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
      yydestruct (yystos[yystate], yyvsp);
      yyvsp--;
      yystate = *--yyssp;

      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;


  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 763 "..\bison\tjs.y"



}
