/* A Bison parser, made from sesh.y
   by GNU bison 1.35.  */

#define YYBISON 1  /* Identify Bison output.  */

# define	SIGNDECL	257
# define	STRING	258
# define	INTEGER	259
# define	ENDDECL	260
# define	TEXTE	261
# define	DEBUTHIEROGS	262
# define	FINHIEROGS	263
# define	HIEROGLYPHE	264
# define	LIGATURE	265
# define	POINT	266
# define	POINTPOINT	267
# define	SMALLSPACE	268
# define	KERNING	269
# define	DEBUTCONSTRUCTION	270
# define	CARTF	271
# define	DIEZE0	272
# define	DIEZE1	273
# define	ROMAIN	274
# define	GAUCHEDROITE	275
# define	DROITEGAUCHE	276
# define	LEFTRIGHT	277
# define	RIGHTLEFT	278
# define	INTERNALSPACE	279
# define	HACHUREGA	280
# define	HACHUREVA	281
# define	HACHUREHA	282
# define	HACHURETA	283
# define	HACHUREG	284
# define	HACHUREV	285
# define	HACHUREH	286
# define	HACHURET	287
# define	SHADING	288
# define	OVERWRITE	289
# define	SIZE	290
# define	ROTATION	291
# define	REVERT	292
# define	TEXTESUPER	293
# define	POINTROUGE	294
# define	POINTNOIR	295
# define	COULEUR0	296
# define	COULEUR1	297
# define	HAPLOGRAPHIE	298
# define	LACUNE	299
# define	LIGNELACUNE	300
# define	DSTSUPERFETATOIRE	301
# define	FSTSUPERFETATOIRE	302
# define	DSTEFFACE	303
# define	FSTEFFACE	304
# define	DSTDISPARU	305
# define	FSTDISPARU	306
# define	DSTRAJOUTSCRIBE	307
# define	FSTRAJOUTSCRIBE	308
# define	DSTRAJOUTAUTEUR	309
# define	FSTRAJOUTAUTEUR	310
# define	SEPARATEUR	311

#line 8 "sesh.y"

#include <malloc.h>
#include "quadra.h"
#include "fonctions.h"

extern void affiche_hiero();
extern void initialise_lex();

#include <stdio.h>
#ifndef NULL
#define NULL 0
#endif

#ifndef TRUE
#define TRUE 1
#define FALSE 0
#endif


#line 28 "sesh.y"
#ifndef YYSTYPE
typedef union {
	Quadra * un_quadra;
	Horliste* une_horliste;
	union _Donnees une_donnee;
	Signe un_signe;
	int un_entier;
	Typehachure une_hachure;
	Shading shading;
	Typegroupe un_typegroupe;
	Typeseparateur un_separateur;
	char * chaine;
} yystype;
# define YYSTYPE yystype
# define YYSTYPE_IS_TRIVIAL 1
#endif
#ifndef YYDEBUG
# define YYDEBUG 0
#endif



#define	YYFINAL		100
#define	YYFLAG		-32768
#define	YYNTBASE	62

/* YYTRANSLATE(YYLEX) -- Bison token number corresponding to YYLEX. */
#define YYTRANSLATE(x) ((unsigned)(x) <= 311 ? yytranslate[x] : 80)

/* YYTRANSLATE[YYLEX] -- Bison token number corresponding to YYLEX. */
static const char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      60,    61,    59,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    58,     2,
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
       2,     2,     2,     2,     2,     2,     1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57
};

#if YYDEBUG
static const short yyprhs[] =
{
       0,     0,     3,     6,     9,    10,    16,    22,    26,    29,
      34,    35,    37,    40,    42,    44,    46,    48,    50,    52,
      54,    56,    61,    63,    64,    69,    71,    73,    75,    77,
      79,    81,    83,    87,    91,    93,    97,   101,   103,   105,
     109,   110,   113,   115,   119,   121,   123,   125,   127,   131,
     132,   135,   137,   139,   141,   142,   144,   146,   148,   150,
     154,   158,   162,   166
};
static const short yyrhs[] =
{
      62,     7,     0,    62,    64,     0,    62,    63,     0,     0,
       3,     4,     4,     5,     6,     0,     8,    66,    65,    66,
       9,     0,     8,    66,     9,     0,    72,    67,     0,    65,
      66,    72,    67,     0,     0,    57,     0,    68,    69,     0,
      20,     0,    44,     0,    21,     0,    22,     0,    45,     0,
      46,     0,    39,     0,    70,     0,    68,    58,    72,    70,
       0,    34,     0,     0,    70,    59,    72,    71,     0,    71,
       0,    73,     0,    12,     0,    30,     0,    32,     0,    31,
       0,    33,     0,    16,    65,    17,     0,    24,    65,    23,
       0,    79,     0,    18,    65,    19,     0,    42,    65,    43,
       0,    13,     0,    14,     0,    60,    65,    61,     0,     0,
      72,    15,     0,    75,     0,    75,    35,    75,     0,    10,
       0,    11,     0,    40,     0,    41,     0,    74,    76,    78,
       0,     0,    77,    76,     0,    36,     0,    37,     0,    38,
       0,     0,    26,     0,    28,     0,    27,     0,    29,     0,
      47,    65,    48,     0,    49,    65,    50,     0,    51,    65,
      52,     0,    53,    65,    54,     0,    55,    65,    56,     0
};

#endif

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined. */
static const short yyrline[] =
{
       0,    89,    90,    91,    92,    95,   111,   114,   117,   122,
     133,   135,   138,   145,   151,   156,   161,   166,   171,   176,
     184,   189,   200,   202,   205,   214,   220,   221,   227,   233,
     239,   245,   251,   257,   263,   264,   270,   276,   282,   288,
     295,   299,   305,   306,   315,   320,   325,   330,   337,   344,
     345,   348,   350,   351,   354,   358,   362,   366,   370,   376,
     383,   389,   395,   401
};
#endif


#if (YYDEBUG) || defined YYERROR_VERBOSE

/* YYTNAME[TOKEN_NUM] -- String name of the token TOKEN_NUM. */
static const char *const yytname[] =
{
  "$", "error", "$undefined.", "SIGNDECL", "STRING", "INTEGER", "ENDDECL", 
  "TEXTE", "DEBUTHIEROGS", "FINHIEROGS", "HIEROGLYPHE", "LIGATURE", 
  "POINT", "POINTPOINT", "SMALLSPACE", "KERNING", "DEBUTCONSTRUCTION", 
  "CARTF", "DIEZE0", "DIEZE1", "ROMAIN", "GAUCHEDROITE", "DROITEGAUCHE", 
  "LEFTRIGHT", "RIGHTLEFT", "INTERNALSPACE", "HACHUREGA", "HACHUREVA", 
  "HACHUREHA", "HACHURETA", "HACHUREG", "HACHUREV", "HACHUREH", 
  "HACHURET", "SHADING", "OVERWRITE", "SIZE", "ROTATION", "REVERT", 
  "TEXTESUPER", "POINTROUGE", "POINTNOIR", "COULEUR0", "COULEUR1", 
  "HAPLOGRAPHIE", "LACUNE", "LIGNELACUNE", "DSTSUPERFETATOIRE", 
  "FSTSUPERFETATOIRE", "DSTEFFACE", "FSTEFFACE", "DSTDISPARU", 
  "FSTDISPARU", "DSTRAJOUTSCRIBE", "FSTRAJOUTSCRIBE", "DSTRAJOUTAUTEUR", 
  "FSTRAJOUTAUTEUR", "SEPARATEUR", "':'", "'*'", "'('", "')'", "tout", 
  "signDecl", "hierogs", "quadras", "separateur", "quadra", "sousquadras", 
  "optShading", "sousquadra", "inhierliste", "kerning", "hieroglyphes", 
  "signe", "hieroglyphe", "modificateurs", "modificateur", "hachure", 
  "construction_parenthesee", 0
};
#endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives. */
static const short yyr1[] =
{
       0,    62,    62,    62,    62,    63,    64,    64,    65,    65,
      66,    66,    67,    67,    67,    67,    67,    67,    67,    67,
      68,    68,    69,    69,    70,    70,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      72,    72,    73,    73,    74,    74,    74,    74,    75,    76,
      76,    77,    77,    77,    78,    78,    78,    78,    78,    79,
      79,    79,    79,    79
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN. */
static const short yyr2[] =
{
       0,     2,     2,     2,     0,     5,     5,     3,     2,     4,
       0,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     0,     4,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     3,     3,     1,     1,     3,
       0,     2,     1,     3,     1,     1,     1,     1,     3,     0,
       2,     1,     1,     1,     0,     1,     1,     1,     1,     3,
       3,     3,     3,     3
};

/* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
   doesn't specify something else to do.  Zero means the default is an
   error. */
static const short yydefact[] =
{
       4,     0,     0,     1,    10,     3,     2,     0,    11,    40,
       0,     7,    10,     0,     0,    40,    44,    45,    27,    37,
      38,    41,    40,    40,    13,    15,    16,    40,    28,    30,
      29,    31,    19,    46,    47,    40,    14,    17,    18,    40,
      40,    40,    40,    40,    40,     8,    23,    20,    25,    26,
      49,    42,    34,     5,     6,     0,    10,    10,    10,    10,
      10,    10,    10,    10,    10,    10,    22,    40,    12,    40,
      51,    52,    53,    54,    49,     0,     9,    32,    40,    35,
      33,    36,    59,    60,    61,    62,    63,    39,     0,     0,
      55,    57,    56,    58,    48,    50,    43,    21,    24,     0,
       0
};

static const short yydefgoto[] =
{
       1,     5,     6,    12,    78,    45,    46,    68,    47,    48,
      13,    49,    50,    51,    73,    74,    94,    52
};

static const short yypact[] =
{
  -32768,    82,     4,-32768,   -12,-32768,-32768,    71,-32768,    74,
      79,-32768,   -12,    -9,    88,    89,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,     7,    41,-32768,-32768,
      11,    70,-32768,-32768,-32768,    -9,    -7,    -2,    -4,   -29,
     -32,   -30,   -23,    17,    24,   -18,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,    40,    11,    62,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,    46,    46,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,    41,-32768,   107,
  -32768
};

static const short yypgoto[] =
{
  -32768,-32768,-32768,    69,    14,    59,-32768,-32768,    27,    28,
     -15,-32768,-32768,    43,    42,-32768,-32768,-32768
};


#define	YYLAST		118


static const short yytable[] =
{
      55,    16,    17,    18,    19,    20,    21,    22,     7,    23,
      77,    24,    25,    26,    81,    27,    82,    79,     9,    80,
      83,    28,    29,    30,    31,     8,    15,     8,     8,    84,
      32,    33,    34,    35,     8,    36,    37,    38,    39,     8,
      40,    66,    41,    87,    42,     8,    43,    70,    71,    72,
       8,    44,    88,     8,    89,     8,    16,    17,    18,    19,
      20,    21,    22,    55,    23,    67,    90,    91,    92,    93,
      27,    85,    16,    17,     8,    10,    28,    29,    30,    31,
      86,     8,    99,    11,    14,     2,    33,    34,    35,     3,
       4,    56,    57,    39,    53,    40,    58,    41,    54,    42,
      69,    43,    33,    34,    59,    75,    44,   100,    60,    61,
      62,    63,    64,    65,    76,    97,    95,    98,    96
};

static const short yycheck[] =
{
      15,    10,    11,    12,    13,    14,    15,    16,     4,    18,
      17,    20,    21,    22,    43,    24,    48,    19,     4,    23,
      50,    30,    31,    32,    33,    57,    12,    57,    57,    52,
      39,    40,    41,    42,    57,    44,    45,    46,    47,    57,
      49,    34,    51,    61,    53,    57,    55,    36,    37,    38,
      57,    60,    67,    57,    69,    57,    10,    11,    12,    13,
      14,    15,    16,    78,    18,    58,    26,    27,    28,    29,
      24,    54,    10,    11,    57,     4,    30,    31,    32,    33,
      56,    57,     0,     9,     5,     3,    40,    41,    42,     7,
       8,    22,    23,    47,     6,    49,    27,    51,     9,    53,
      59,    55,    40,    41,    35,    35,    60,     0,    39,    40,
      41,    42,    43,    44,    55,    88,    74,    89,    75
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/share/bison/bison.simple"

/* Skeleton output parser for bison,

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software
   Foundation, Inc.

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

/* This is the parser code that is written into each bison parser when
   the %semantic_parser declaration is not specified in the grammar.
   It was written by Richard Stallman by simplifying the hairy parser
   used when %semantic_parser is specified.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

#if ! defined (yyoverflow) || defined (YYERROR_VERBOSE)

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
#endif /* ! defined (yyoverflow) || defined (YYERROR_VERBOSE) */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYLTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
# if YYLSP_NEEDED
  YYLTYPE yyls;
# endif
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAX (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# if YYLSP_NEEDED
#  define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE) + sizeof (YYLTYPE))	\
      + 2 * YYSTACK_GAP_MAX)
# else
#  define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAX)
# endif

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
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAX;	\
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif


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
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
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
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");			\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).

   When YYLLOC_DEFAULT is run, CURRENT is set the location of the
   first token.  By default, to implement support for ranges, extend
   its range to the last symbol.  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)       	\
   Current.last_line   = Rhs[N].last_line;	\
   Current.last_column = Rhs[N].last_column;
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#if YYPURE
# if YYLSP_NEEDED
#  ifdef YYLEX_PARAM
#   define YYLEX		yylex (&yylval, &yylloc, YYLEX_PARAM)
#  else
#   define YYLEX		yylex (&yylval, &yylloc)
#  endif
# else /* !YYLSP_NEEDED */
#  ifdef YYLEX_PARAM
#   define YYLEX		yylex (&yylval, YYLEX_PARAM)
#  else
#   define YYLEX		yylex (&yylval)
#  endif
# endif /* !YYLSP_NEEDED */
#else /* !YYPURE */
# define YYLEX			yylex ()
#endif /* !YYPURE */


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
/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
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

#ifdef YYERROR_VERBOSE

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
#endif

#line 315 "/usr/share/bison/bison.simple"


/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
#  define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL
# else
#  define YYPARSE_PARAM_ARG YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
# endif
#else /* !YYPARSE_PARAM */
# define YYPARSE_PARAM_ARG
# define YYPARSE_PARAM_DECL
#endif /* !YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
# ifdef YYPARSE_PARAM
int yyparse (void *);
# else
int yyparse (void);
# endif
#endif

/* YY_DECL_VARIABLES -- depending whether we use a pure parser,
   variables are global, or local to YYPARSE.  */

#define YY_DECL_NON_LSP_VARIABLES			\
/* The lookahead symbol.  */				\
int yychar;						\
							\
/* The semantic value of the lookahead symbol. */	\
YYSTYPE yylval;						\
							\
/* Number of parse errors so far.  */			\
int yynerrs;

#if YYLSP_NEEDED
# define YY_DECL_VARIABLES			\
YY_DECL_NON_LSP_VARIABLES			\
						\
/* Location data for the lookahead symbol.  */	\
YYLTYPE yylloc;
#else
# define YY_DECL_VARIABLES			\
YY_DECL_NON_LSP_VARIABLES
#endif


/* If nonreentrant, generate the variables here. */

#if !YYPURE
YY_DECL_VARIABLES
#endif  /* !YYPURE */

int
yyparse (YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  /* If reentrant, generate the variables here. */
#if YYPURE
  YY_DECL_VARIABLES
#endif  /* !YYPURE */

  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yychar1 = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack. */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;

#if YYLSP_NEEDED
  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
#endif

#if YYLSP_NEEDED
# define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
# define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  YYSIZE_T yystacksize = YYINITDEPTH;


  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
#if YYLSP_NEEDED
  YYLTYPE yyloc;
#endif

  /* When reducing, the number of symbols on the RHS of the reduced
     rule. */
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
#if YYLSP_NEEDED
  yylsp = yyls;
#endif
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

  if (yyssp >= yyss + yystacksize - 1)
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
	   data in use in that stack, in bytes.  */
# if YYLSP_NEEDED
	YYLTYPE *yyls1 = yyls;
	/* This used to be a conditional around just the two extra args,
	   but that might be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
# else
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);
# endif
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
# if YYLSP_NEEDED
	YYSTACK_RELOCATE (yyls);
# endif
# undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
#if YYLSP_NEEDED
      yylsp = yyls + yysize - 1;
#endif

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyssp >= yyss + yystacksize - 1)
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
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yychar1 = YYTRANSLATE (yychar);

#if YYDEBUG
     /* We have to keep this `#if YYDEBUG', since we use variables
	which are defined only if `YYDEBUG' is set.  */
      if (yydebug)
	{
	  YYFPRINTF (stderr, "Next token is %d (%s",
		     yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise
	     meaning of a token, for further debugging info.  */
# ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
# endif
	  YYFPRINTF (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %d (%s), ",
	      yychar, yytname[yychar1]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#if YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

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

     Otherwise, the following line sets YYVAL to the semantic value of
     the lookahead token.  This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

#if YYLSP_NEEDED
  /* Similarly for the default location.  Let the user run additional
     commands if for instance locations are ranges.  */
  yyloc = yylsp[1-yylen];
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
#endif

#if YYDEBUG
  /* We have to keep this `#if YYDEBUG', since we use variables which
     are defined only if `YYDEBUG' is set.  */
  if (yydebug)
    {
      int yyi;

      YYFPRINTF (stderr, "Reducing via rule %d (line %d), ",
		 yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (yyi = yyprhs[yyn]; yyrhs[yyi] > 0; yyi++)
	YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
      YYFPRINTF (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif

  switch (yyn) {

case 5:
#line 95 "sesh.y"
{
	struct caractere * chardef ;
	if (yyvsp[-1].un_entier > 255 || yyvsp[-1].un_entier < 0)
		{
			yyerror("bad number for char in font in signdecl.\nNumbers should be between 0 and 255.");
			YYERROR;
		}

	chardef= (struct caractere*)malloc(sizeof(struct caractere));
	chardef->fontName= yyvsp[-2].chaine;
	chardef->numero= yyvsp[-1].un_entier;
	fprintf(stderr, "on définit %s", yyvsp[-2].chaine);
	defineNewChar(yyvsp[-3].chaine, chardef);
}
    break;
case 6:
#line 111 "sesh.y"
{
  affiche_quadras(yyvsp[-2].un_quadra);
}
    break;
case 8:
#line 118 "sesh.y"
{
	yyval.un_quadra= yyvsp[0].un_quadra;
	yyval.un_quadra->kerning= yyvsp[-1].un_entier;								/* nombre de signes de kerning */
}
    break;
case 9:
#line 123 "sesh.y"
{
	yyval.un_quadra=yyvsp[-3].un_quadra;
	yyval.un_quadra->last->next= yyvsp[0].un_quadra;
	yyvsp[0].un_quadra->previous= yyval.un_quadra->last;
	yyval.un_quadra->last->separateur= yyvsp[-2].un_separateur;
	yyval.un_quadra->last=yyvsp[0].un_quadra;
	yyvsp[0].un_quadra->kerning= yyvsp[-1].un_entier;
}
    break;
case 10:
#line 134 "sesh.y"
{ yyval.un_separateur= S_intersignes; }
    break;
case 12:
#line 139 "sesh.y"
{
	yyval.un_quadra= new_quadra(S_quadra);
	yyval.un_quadra->kerning= 0;
	yyval.un_quadra->contenu.horizontal= yyvsp[-1].une_horliste;
	yyval.un_quadra->shading= yyvsp[0].shading;
}
    break;
case 13:
#line 146 "sesh.y"
{
	yyval.un_quadra= new_signe(S_romain);
	yyval.un_quadra->kerning= 0;
	yyval.un_quadra->contenu.un_signe.donnees= yyvsp[0].une_donnee;
}
    break;
case 14:
#line 152 "sesh.y"
{
	yyval.un_quadra= new_signe(S_haplographie);
	yyval.un_quadra->kerning= 0;
}
    break;
case 15:
#line 157 "sesh.y"
{
	yyval.un_quadra= new_signe(S_gauchedroite);
	yyval.un_quadra->kerning= 0;
}
    break;
case 16:
#line 162 "sesh.y"
{
	yyval.un_quadra= new_signe(S_droitegauche);
	yyval.un_quadra->kerning= 0;
}
    break;
case 17:
#line 167 "sesh.y"
{
	yyval.un_quadra= new_signe(S_lacune);
	yyval.un_quadra->kerning= 0;
}
    break;
case 18:
#line 172 "sesh.y"
{
	 yyval.un_quadra= new_signe(S_lignelacune);
	 yyval.un_quadra->kerning= 0;
 }
    break;
case 19:
#line 177 "sesh.y"
{
	 yyval.un_quadra= new_signe(S_textesuper);
	 yyval.un_quadra->contenu.un_signe.donnees= yyvsp[0].une_donnee;
	 yyval.un_quadra->kerning= 0;
 }
    break;
case 20:
#line 185 "sesh.y"
{
	 yyval.une_horliste= new_hor();
	 yyval.une_horliste->un_quadra= yyvsp[0].un_quadra;
 }
    break;
case 21:
#line 190 "sesh.y"
{
	 yyval.une_horliste=yyvsp[-3].une_horliste;
	 yyval.une_horliste->last->next= new_hor();
	 yyval.une_horliste->last->next->previous= yyval.une_horliste->last;
	 yyval.une_horliste->last= yyval.une_horliste->last->next;
	 yyval.une_horliste->last->un_quadra= yyvsp[0].un_quadra;
	 yyval.une_horliste->last->kerning= yyvsp[-1].un_entier;
 }
    break;
case 22:
#line 201 "sesh.y"
{yyval.shading= yyvsp[0].shading;}
    break;
case 23:
#line 202 "sesh.y"
{yyval.shading= NOSHADING;}
    break;
case 24:
#line 206 "sesh.y"
{
	 yyval.un_quadra= yyvsp[-3].un_quadra;
	 yyval.un_quadra->last->next= yyvsp[0].un_quadra;
	 yyval.un_quadra->last->separateur= S_intersignes;
	 yyval.un_quadra->last->next->previous= yyval.un_quadra->last;
	 yyval.un_quadra->last= yyvsp[0].un_quadra;
	 yyval.un_quadra->last->kerning= yyvsp[-1].un_entier;
 }
    break;
case 25:
#line 215 "sesh.y"
{
	 yyval.un_quadra= yyvsp[0].un_quadra;
 }
    break;
case 27:
#line 222 "sesh.y"
{
	 yyval.un_quadra= new_signe(S_signe);
	 yyval.un_quadra->contenu.un_signe.type= S_point;
	 yyval.un_quadra->kerning= 0;
 }
    break;
case 28:
#line 228 "sesh.y"
{
	 yyval.un_quadra= new_signe(S_signe);
	 yyval.un_quadra->contenu.un_signe.type= S_hachureg;
	 yyval.un_quadra->kerning= 0;
 }
    break;
case 29:
#line 234 "sesh.y"
{
	 yyval.un_quadra= new_signe(S_signe);
	 yyval.un_quadra->contenu.un_signe.type= S_hachureh;
	 yyval.un_quadra->kerning= 0;
}
    break;
case 30:
#line 240 "sesh.y"
{
	yyval.un_quadra= new_signe(S_signe);
	yyval.un_quadra->contenu.un_signe.type= S_hachurev;
	yyval.un_quadra->kerning= 0;
}
    break;
case 31:
#line 246 "sesh.y"
{
	yyval.un_quadra= new_signe(S_signe);
	yyval.un_quadra->contenu.un_signe.type= S_hachuret;
	yyval.un_quadra->kerning= 0;
}
    break;
case 32:
#line 252 "sesh.y"
{	
	yyval.un_quadra= new_quadra(yyvsp[-2].un_typegroupe);
	yyval.un_quadra->contenu.des_quadras= yyvsp[-1].un_quadra;
	yyval.un_quadra->kerning= 0;	
}
    break;
case 33:
#line 258 "sesh.y"
{	
	yyval.un_quadra= new_quadra(S_rightleft);
	yyval.un_quadra->contenu.des_quadras= yyvsp[-1].un_quadra;
	yyval.un_quadra->kerning= 0;	
}
    break;
case 35:
#line 265 "sesh.y"
{
	yyval.un_quadra= new_quadra(S_hachure);
	yyval.un_quadra->contenu.des_quadras= yyvsp[-1].un_quadra;
	yyval.un_quadra->kerning= 0;
}
    break;
case 36:
#line 271 "sesh.y"
{
	yyval.un_quadra= new_quadra(S_enrouge);
	yyval.un_quadra->contenu.des_quadras= yyvsp[-1].un_quadra;
	yyval.un_quadra->kerning= 0;
}
    break;
case 37:
#line 277 "sesh.y"
{
	yyval.un_quadra= new_signe(S_signe);
	yyval.un_quadra->contenu.un_signe.type= S_pointpoint;
	yyval.un_quadra->kerning= 0;
}
    break;
case 38:
#line 283 "sesh.y"
{
	yyval.un_quadra= new_signe(S_signe);
	yyval.un_quadra->contenu.un_signe.type= S_smallspace;
	yyval.un_quadra->kerning= 0;
}
    break;
case 39:
#line 289 "sesh.y"
{
	yyval.un_quadra= yyvsp[-1].un_quadra;
}
    break;
case 40:
#line 296 "sesh.y"
{
	yyval.un_entier =0;
}
    break;
case 41:
#line 300 "sesh.y"
{
	yyval.un_entier= yyvsp[-1].un_entier + 1;
}
    break;
case 43:
#line 307 "sesh.y"
{
	yyval.un_quadra= new_quadra(S_overwrite);
	yyval.un_quadra->contenu.des_quadras= yyvsp[-2].un_quadra;
	yyval.un_quadra->contenu.des_quadras->next= yyvsp[0].un_quadra;
	yyval.un_quadra->kerning= 0;	
}
    break;
case 44:
#line 316 "sesh.y"
{
	yyval.un_quadra= new_signe(S_hieroglyphe);
	yyval.un_quadra->contenu.un_signe.donnees= yyvsp[0].une_donnee;
}
    break;
case 45:
#line 321 "sesh.y"
{
	yyval.un_quadra= new_signe(S_ligature);
	yyval.un_quadra->contenu.un_signe.donnees= yyvsp[0].une_donnee;
}
    break;
case 46:
#line 326 "sesh.y"
{
	 yyval.un_quadra= new_signe(S_pointrouge);
	 yyval.un_quadra->kerning= 0;
 }
    break;
case 47:
#line 331 "sesh.y"
{
	 yyval.un_quadra= new_signe(S_pointnoir);
	 yyval.un_quadra->kerning= 0;
 }
    break;
case 48:
#line 338 "sesh.y"
{
	yyval.un_quadra= yyvsp[-2].un_quadra;
	yyval.un_quadra->contenu.un_signe.typehachure= yyvsp[0].une_hachure;
}
    break;
case 49:
#line 344 "sesh.y"
{yyval.un_quadra = yyvsp[0].un_quadra;}
    break;
case 50:
#line 345 "sesh.y"
{yyval.un_quadra = yyvsp[-2].un_quadra;}
    break;
case 51:
#line 349 "sesh.y"
{yyval.un_quadra = yyvsp[-1].un_quadra; 	yyval.un_quadra->contenu.un_signe.size= yyvsp[0].un_entier;}
    break;
case 52:
#line 350 "sesh.y"
{yyval.un_quadra = yyvsp[-1].un_quadra; yyval.un_quadra->contenu.un_signe.rotation= yyvsp[0].un_entier;}
    break;
case 53:
#line 351 "sesh.y"
{yyval.un_quadra = yyvsp[-1].un_quadra; yyval.un_quadra->contenu.un_signe.reverted= TRUE;}
    break;
case 54:
#line 355 "sesh.y"
{
  yyval.une_hachure= S_aucune;
}
    break;
case 55:
#line 359 "sesh.y"
{
	yyval.une_hachure= S_ga;
}
    break;
case 56:
#line 363 "sesh.y"
{
	yyval.une_hachure= S_ha;
}
    break;
case 57:
#line 367 "sesh.y"
{
	yyval.une_hachure= S_va;
}
    break;
case 58:
#line 371 "sesh.y"
{
	yyval.une_hachure= S_ta;
}
    break;
case 59:
#line 378 "sesh.y"
{
	yyval.un_quadra= new_quadra(S_superfetatoire);						
	yyval.un_quadra->contenu.des_quadras= yyvsp[-1].un_quadra;
	yyval.un_quadra->kerning= 0;	
}
    break;
case 60:
#line 384 "sesh.y"
{
	yyval.un_quadra= new_quadra(S_efface);						
	yyval.un_quadra->contenu.des_quadras= yyvsp[-1].un_quadra;
	yyval.un_quadra->kerning= 0;
}
    break;
case 61:
#line 390 "sesh.y"
{
	yyval.un_quadra= new_quadra(S_disparu);						
	yyval.un_quadra->contenu.des_quadras= yyvsp[-1].un_quadra;
	yyval.un_quadra->kerning= 0;
}
    break;
case 62:
#line 396 "sesh.y"
{
	yyval.un_quadra= new_quadra(S_ajoutscribe);
	yyval.un_quadra->contenu.des_quadras= yyvsp[-1].un_quadra;
	yyval.un_quadra->kerning= 0;
}
    break;
case 63:
#line 402 "sesh.y"
{
	yyval.un_quadra= new_quadra(S_ajoutauteur);						
	yyval.un_quadra->contenu.des_quadras= yyvsp[-1].un_quadra;
	yyval.un_quadra->kerning= 0;
}
    break;
}

#line 705 "/usr/share/bison/bison.simple"


  yyvsp -= yylen;
  yyssp -= yylen;
#if YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG
  if (yydebug)
    {
      short *yyssp1 = yyss - 1;
      YYFPRINTF (stderr, "state stack now");
      while (yyssp1 != yyssp)
	YYFPRINTF (stderr, " %d", *++yyssp1);
      YYFPRINTF (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;
#if YYLSP_NEEDED
  *++yylsp = yyloc;
#endif

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  char *yymsg;
	  int yyx, yycount;

	  yycount = 0;
	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  for (yyx = yyn < 0 ? -yyn : 0;
	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
	    if (yycheck[yyx + yyn] == yyx)
	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
	  yysize += yystrlen ("parse error, unexpected ") + 1;
	  yysize += yystrlen (yytname[YYTRANSLATE (yychar)]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "parse error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[YYTRANSLATE (yychar)]);

	      if (yycount < 5)
		{
		  yycount = 0;
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx)
		      {
			const char *yyq = ! yycount ? ", expecting " : " or ";
			yyp = yystpcpy (yyp, yyq);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yycount++;
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exhausted");
	}
      else
#endif /* defined (YYERROR_VERBOSE) */
	yyerror ("parse error");
    }
  goto yyerrlab1;


/*--------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action |
`--------------------------------------------------*/
yyerrlab1:
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;
      YYDPRINTF ((stderr, "Discarding token %d (%s).\n",
		  yychar, yytname[yychar1]));
      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;


/*-------------------------------------------------------------------.
| yyerrdefault -- current state does not do anything special for the |
| error token.                                                       |
`-------------------------------------------------------------------*/
yyerrdefault:
#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */

  /* If its default is to accept any token, ok.  Otherwise pop it.  */
  yyn = yydefact[yystate];
  if (yyn)
    goto yydefault;
#endif


/*---------------------------------------------------------------.
| yyerrpop -- pop the current state because it cannot handle the |
| error token                                                    |
`---------------------------------------------------------------*/
yyerrpop:
  if (yyssp == yyss)
    YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#if YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG
  if (yydebug)
    {
      short *yyssp1 = yyss - 1;
      YYFPRINTF (stderr, "Error: state stack now");
      while (yyssp1 != yyssp)
	YYFPRINTF (stderr, " %d", *++yyssp1);
      YYFPRINTF (stderr, "\n");
    }
#endif

/*--------------.
| yyerrhandle.  |
`--------------*/
yyerrhandle:
  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;
#if YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

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

/*---------------------------------------------.
| yyoverflowab -- parser overflow comes here.  |
`---------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}
#line 409 "sesh.y"

