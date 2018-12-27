
/*  A Bison parser, made from sesh.y
    by GNU Bison version 1.28  */

#define YYBISON 1  /* Identify Bison output.  */

#define	SIGNDECL	257
#define	STRING	258
#define	INTEGER	259
#define	ENDDECL	260
#define	TEXTE	261
#define	DEBUTHIEROGS	262
#define	FINHIEROGS	263
#define	HIEROGLYPHE	264
#define	LIGATURE	265
#define	POINT	266
#define	POINTPOINT	267
#define	SMALLSPACE	268
#define	KERNING	269
#define	DEBUTCONSTRUCTION	270
#define	CARTF	271
#define	DIEZE0	272
#define	DIEZE1	273
#define	ROMAIN	274
#define	GAUCHEDROITE	275
#define	DROITEGAUCHE	276
#define	LEFTRIGHT	277
#define	RIGHTLEFT	278
#define	INTERNALSPACE	279
#define	HACHUREGA	280
#define	HACHUREVA	281
#define	HACHUREHA	282
#define	HACHURETA	283
#define	HACHUREG	284
#define	HACHUREV	285
#define	HACHUREH	286
#define	HACHURET	287
#define	SHADING	288
#define	OVERWRITE	289
#define	SIZE	290
#define	ROTATION	291
#define	REVERT	292
#define	TEXTESUPER	293
#define	POINTROUGE	294
#define	POINTNOIR	295
#define	COULEUR0	296
#define	COULEUR1	297
#define	HAPLOGRAPHIE	298
#define	LACUNE	299
#define	LIGNELACUNE	300
#define	DSTSUPERFETATOIRE	301
#define	FSTSUPERFETATOIRE	302
#define	DSTEFFACE	303
#define	FSTEFFACE	304
#define	DSTDISPARU	305
#define	FSTDISPARU	306
#define	DSTRAJOUTSCRIBE	307
#define	FSTRAJOUTSCRIBE	308
#define	DSTRAJOUTAUTEUR	309
#define	FSTRAJOUTAUTEUR	310
#define	SEPARATEUR	311

#line 8 "sesh.y"

#include <stdlib.h>
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
} YYSTYPE;
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		100
#define	YYFLAG		-32768
#define	YYNTBASE	62

#define YYTRANSLATE(x) ((unsigned)(x) <= 311 ? yytranslate[x] : 80)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    60,
    61,    59,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    58,     2,     2,
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
     2,     2,     2,     2,     2,     1,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
    47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
    57
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     3,     6,     9,    10,    16,    22,    26,    29,    34,
    35,    37,    40,    42,    44,    46,    48,    50,    52,    54,
    56,    61,    63,    64,    69,    71,    73,    75,    77,    79,
    81,    83,    87,    91,    93,    97,   101,   103,   105,   109,
   110,   113,   115,   119,   121,   123,   125,   127,   131,   132,
   135,   137,   139,   141,   142,   144,   146,   148,   150,   154,
   158,   162,   166
};

static const short yyrhs[] = {    62,
     7,     0,    62,    64,     0,    62,    63,     0,     0,     3,
     4,     4,     5,     6,     0,     8,    66,    65,    66,     9,
     0,     8,    66,     9,     0,    72,    67,     0,    65,    66,
    72,    67,     0,     0,    57,     0,    68,    69,     0,    20,
     0,    44,     0,    21,     0,    22,     0,    45,     0,    46,
     0,    39,     0,    70,     0,    68,    58,    72,    70,     0,
    34,     0,     0,    70,    59,    72,    71,     0,    71,     0,
    73,     0,    12,     0,    30,     0,    32,     0,    31,     0,
    33,     0,    16,    65,    17,     0,    24,    65,    23,     0,
    79,     0,    18,    65,    19,     0,    42,    65,    43,     0,
    13,     0,    14,     0,    60,    65,    61,     0,     0,    72,
    15,     0,    75,     0,    75,    35,    75,     0,    10,     0,
    11,     0,    40,     0,    41,     0,    74,    76,    78,     0,
     0,    77,    76,     0,    36,     0,    37,     0,    38,     0,
     0,    26,     0,    28,     0,    27,     0,    29,     0,    47,
    65,    48,     0,    49,    65,    50,     0,    51,    65,    52,
     0,    53,    65,    54,     0,    55,    65,    56,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    89,    90,    91,    92,    95,   111,   114,   117,   122,   133,
   135,   138,   145,   151,   156,   161,   166,   171,   176,   184,
   189,   200,   202,   205,   214,   220,   221,   227,   233,   239,
   245,   251,   257,   263,   264,   270,   276,   282,   288,   295,
   299,   305,   306,   315,   320,   325,   330,   337,   344,   345,
   348,   350,   351,   354,   358,   362,   366,   370,   376,   383,
   389,   395,   401
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","SIGNDECL",
"STRING","INTEGER","ENDDECL","TEXTE","DEBUTHIEROGS","FINHIEROGS","HIEROGLYPHE",
"LIGATURE","POINT","POINTPOINT","SMALLSPACE","KERNING","DEBUTCONSTRUCTION","CARTF",
"DIEZE0","DIEZE1","ROMAIN","GAUCHEDROITE","DROITEGAUCHE","LEFTRIGHT","RIGHTLEFT",
"INTERNALSPACE","HACHUREGA","HACHUREVA","HACHUREHA","HACHURETA","HACHUREG","HACHUREV",
"HACHUREH","HACHURET","SHADING","OVERWRITE","SIZE","ROTATION","REVERT","TEXTESUPER",
"POINTROUGE","POINTNOIR","COULEUR0","COULEUR1","HAPLOGRAPHIE","LACUNE","LIGNELACUNE",
"DSTSUPERFETATOIRE","FSTSUPERFETATOIRE","DSTEFFACE","FSTEFFACE","DSTDISPARU",
"FSTDISPARU","DSTRAJOUTSCRIBE","FSTRAJOUTSCRIBE","DSTRAJOUTAUTEUR","FSTRAJOUTAUTEUR",
"SEPARATEUR","':'","'*'","'('","')'","tout","signDecl","hierogs","quadras","separateur",
"quadra","sousquadras","optShading","sousquadra","inhierliste","kerning","hieroglyphes",
"signe","hieroglyphe","modificateurs","modificateur","hachure","construction_parenthesee", NULL
};
#endif

static const short yyr1[] = {     0,
    62,    62,    62,    62,    63,    64,    64,    65,    65,    66,
    66,    67,    67,    67,    67,    67,    67,    67,    67,    68,
    68,    69,    69,    70,    70,    71,    71,    71,    71,    71,
    71,    71,    71,    71,    71,    71,    71,    71,    71,    72,
    72,    73,    73,    74,    74,    74,    74,    75,    76,    76,
    77,    77,    77,    78,    78,    78,    78,    78,    79,    79,
    79,    79,    79
};

static const short yyr2[] = {     0,
     2,     2,     2,     0,     5,     5,     3,     2,     4,     0,
     1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
     4,     1,     0,     4,     1,     1,     1,     1,     1,     1,
     1,     3,     3,     1,     3,     3,     1,     1,     3,     0,
     2,     1,     3,     1,     1,     1,     1,     3,     0,     2,
     1,     1,     1,     0,     1,     1,     1,     1,     3,     3,
     3,     3,     3
};

static const short yydefact[] = {     4,
     0,     0,     1,    10,     3,     2,     0,    11,    40,     0,
     7,    10,     0,     0,    40,    44,    45,    27,    37,    38,
    41,    40,    40,    13,    15,    16,    40,    28,    30,    29,
    31,    19,    46,    47,    40,    14,    17,    18,    40,    40,
    40,    40,    40,    40,     8,    23,    20,    25,    26,    49,
    42,    34,     5,     6,     0,    10,    10,    10,    10,    10,
    10,    10,    10,    10,    10,    22,    40,    12,    40,    51,
    52,    53,    54,    49,     0,     9,    32,    40,    35,    33,
    36,    59,    60,    61,    62,    63,    39,     0,     0,    55,
    57,    56,    58,    48,    50,    43,    21,    24,     0,     0
};

static const short yydefgoto[] = {     1,
     5,     6,    12,    78,    45,    46,    68,    47,    48,    13,
    49,    50,    51,    73,    74,    94,    52
};

static const short yypact[] = {-32768,
    82,     4,-32768,   -12,-32768,-32768,    71,-32768,    74,    79,
-32768,   -12,    -9,    88,    89,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,     7,    41,-32768,-32768,    11,
    70,-32768,-32768,-32768,    -9,    -7,    -2,    -4,   -29,   -32,
   -30,   -23,    17,    24,   -18,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,    40,    11,    62,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,    46,    46,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,    41,-32768,   107,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,    69,    14,    59,-32768,-32768,    27,    28,   -15,
-32768,-32768,    43,    42,-32768,-32768,-32768
};


#define	YYLAST		118


static const short yytable[] = {    55,
    16,    17,    18,    19,    20,    21,    22,     7,    23,    77,
    24,    25,    26,    81,    27,    82,    79,     9,    80,    83,
    28,    29,    30,    31,     8,    15,     8,     8,    84,    32,
    33,    34,    35,     8,    36,    37,    38,    39,     8,    40,
    66,    41,    87,    42,     8,    43,    70,    71,    72,     8,
    44,    88,     8,    89,     8,    16,    17,    18,    19,    20,
    21,    22,    55,    23,    67,    90,    91,    92,    93,    27,
    85,    16,    17,     8,    10,    28,    29,    30,    31,    86,
     8,    99,    11,    14,     2,    33,    34,    35,     3,     4,
    56,    57,    39,    53,    40,    58,    41,    54,    42,    69,
    43,    33,    34,    59,    75,    44,   100,    60,    61,    62,
    63,    64,    65,    76,    97,    95,    98,    96
};

static const short yycheck[] = {    15,
    10,    11,    12,    13,    14,    15,    16,     4,    18,    17,
    20,    21,    22,    43,    24,    48,    19,     4,    23,    50,
    30,    31,    32,    33,    57,    12,    57,    57,    52,    39,
    40,    41,    42,    57,    44,    45,    46,    47,    57,    49,
    34,    51,    61,    53,    57,    55,    36,    37,    38,    57,
    60,    67,    57,    69,    57,    10,    11,    12,    13,    14,
    15,    16,    78,    18,    58,    26,    27,    28,    29,    24,
    54,    10,    11,    57,     4,    30,    31,    32,    33,    56,
    57,     0,     9,     5,     3,    40,    41,    42,     7,     8,
    22,    23,    47,     6,    49,    27,    51,     9,    53,    59,
    55,    40,    41,    35,    35,    60,     0,    39,    40,    41,
    42,    43,    44,    55,    88,    74,    89,    75
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/share/bison.simple"
/* This file comes from bison-1.28.  */

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

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

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

#ifndef YYSTACK_USE_ALLOCA
#ifdef alloca
#define YYSTACK_USE_ALLOCA
#else /* alloca not defined */
#ifdef __GNUC__
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi) || (defined (__sun) && defined (__i386))
#define YYSTACK_USE_ALLOCA
#include <alloca.h>
#else /* not sparc */
/* We think this test detects Watcom and Microsoft C.  */
/* This used to test MSDOS, but that is a bad idea
   since that symbol is in the user namespace.  */
#if (defined (_MSDOS) || defined (_MSDOS_)) && !defined (__TURBOC__)
#if 0 /* No need for malloc.h, which pollutes the namespace;
	 instead, just don't use alloca.  */
#include <malloc.h>
#endif
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
/* I don't know what this was needed for, but it pollutes the namespace.
   So I turned it off.   rms, 2 May 1997.  */
/* #include <malloc.h>  */
 #pragma alloca
#define YYSTACK_USE_ALLOCA
#else /* not MSDOS, or __TURBOC__, or _AIX */
#if 0
#ifdef __hpux /* haible@ilog.fr says this works for HPUX 9.05 and up,
		 and on HPUX 10.  Eventually we can turn this on.  */
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#endif /* __hpux */
#endif
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc */
#endif /* not GNU C */
#endif /* alloca not defined */
#endif /* YYSTACK_USE_ALLOCA not defined */

#ifdef YYSTACK_USE_ALLOCA
#define YYSTACK_ALLOC alloca
#else
#define YYSTACK_ALLOC malloc
#endif

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Define __yy_memcpy.  Note that the size argument
   should be passed with type unsigned int, because that is what the non-GCC
   definitions require.  With GCC, __builtin_memcpy takes an arg
   of type size_t, but it can handle unsigned int.  */

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     unsigned int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, unsigned int count)
{
  register char *t = to;
  register char *f = from;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 217 "/usr/share/bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
#ifdef YYPARSE_PARAM
int yyparse (void *);
#else
int yyparse (void);
#endif
#endif

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;
  int yyfree_stacks = 0;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  if (yyfree_stacks)
	    {
	      free (yyss);
	      free (yyvs);
#ifdef YYLSP_NEEDED
	      free (yyls);
#endif
	    }
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
#ifndef YYSTACK_USE_ALLOCA
      yyfree_stacks = 1;
#endif
      yyss = (short *) YYSTACK_ALLOC (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1,
		   size * (unsigned int) sizeof (*yyssp));
      yyvs = (YYSTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1,
		   size * (unsigned int) sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1,
		   size * (unsigned int) sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
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
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
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

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
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
;
    break;}
case 6:
#line 111 "sesh.y"
{
  affiche_quadras(yyvsp[-2].un_quadra);
;
    break;}
case 8:
#line 118 "sesh.y"
{
	yyval.un_quadra= yyvsp[0].un_quadra;
	yyval.un_quadra->kerning= yyvsp[-1].un_entier;								/* nombre de signes de kerning */
;
    break;}
case 9:
#line 123 "sesh.y"
{
	yyval.un_quadra=yyvsp[-3].un_quadra;
	yyval.un_quadra->last->next= yyvsp[0].un_quadra;
	yyvsp[0].un_quadra->previous= yyval.un_quadra->last;
	yyval.un_quadra->last->separateur= yyvsp[-2].un_separateur;
	yyval.un_quadra->last=yyvsp[0].un_quadra;
	yyvsp[0].un_quadra->kerning= yyvsp[-1].un_entier;
;
    break;}
case 10:
#line 134 "sesh.y"
{ yyval.un_separateur= S_intersignes; ;
    break;}
case 12:
#line 139 "sesh.y"
{
	yyval.un_quadra= new_quadra(S_quadra);
	yyval.un_quadra->kerning= 0;
	yyval.un_quadra->contenu.horizontal= yyvsp[-1].une_horliste;
	yyval.un_quadra->shading= yyvsp[0].shading;
;
    break;}
case 13:
#line 146 "sesh.y"
{
	yyval.un_quadra= new_signe(S_romain);
	yyval.un_quadra->kerning= 0;
	yyval.un_quadra->contenu.un_signe.donnees= yyvsp[0].une_donnee;
;
    break;}
case 14:
#line 152 "sesh.y"
{
	yyval.un_quadra= new_signe(S_haplographie);
	yyval.un_quadra->kerning= 0;
;
    break;}
case 15:
#line 157 "sesh.y"
{
	yyval.un_quadra= new_signe(S_gauchedroite);
	yyval.un_quadra->kerning= 0;
;
    break;}
case 16:
#line 162 "sesh.y"
{
	yyval.un_quadra= new_signe(S_droitegauche);
	yyval.un_quadra->kerning= 0;
;
    break;}
case 17:
#line 167 "sesh.y"
{
	yyval.un_quadra= new_signe(S_lacune);
	yyval.un_quadra->kerning= 0;
;
    break;}
case 18:
#line 172 "sesh.y"
{
	 yyval.un_quadra= new_signe(S_lignelacune);
	 yyval.un_quadra->kerning= 0;
 ;
    break;}
case 19:
#line 177 "sesh.y"
{
	 yyval.un_quadra= new_signe(S_textesuper);
	 yyval.un_quadra->contenu.un_signe.donnees= yyvsp[0].une_donnee;
	 yyval.un_quadra->kerning= 0;
 ;
    break;}
case 20:
#line 185 "sesh.y"
{
	 yyval.une_horliste= new_hor();
	 yyval.une_horliste->un_quadra= yyvsp[0].un_quadra;
 ;
    break;}
case 21:
#line 190 "sesh.y"
{
	 yyval.une_horliste=yyvsp[-3].une_horliste;
	 yyval.une_horliste->last->next= new_hor();
	 yyval.une_horliste->last->next->previous= yyval.une_horliste->last;
	 yyval.une_horliste->last= yyval.une_horliste->last->next;
	 yyval.une_horliste->last->un_quadra= yyvsp[0].un_quadra;
	 yyval.une_horliste->last->kerning= yyvsp[-1].un_entier;
 ;
    break;}
case 22:
#line 201 "sesh.y"
{yyval.shading= yyvsp[0].shading;;
    break;}
case 23:
#line 202 "sesh.y"
{yyval.shading= NOSHADING;;
    break;}
case 24:
#line 206 "sesh.y"
{
	 yyval.un_quadra= yyvsp[-3].un_quadra;
	 yyval.un_quadra->last->next= yyvsp[0].un_quadra;
	 yyval.un_quadra->last->separateur= S_intersignes;
	 yyval.un_quadra->last->next->previous= yyval.un_quadra->last;
	 yyval.un_quadra->last= yyvsp[0].un_quadra;
	 yyval.un_quadra->last->kerning= yyvsp[-1].un_entier;
 ;
    break;}
case 25:
#line 215 "sesh.y"
{
	 yyval.un_quadra= yyvsp[0].un_quadra;
 ;
    break;}
case 27:
#line 222 "sesh.y"
{
	 yyval.un_quadra= new_signe(S_signe);
	 yyval.un_quadra->contenu.un_signe.type= S_point;
	 yyval.un_quadra->kerning= 0;
 ;
    break;}
case 28:
#line 228 "sesh.y"
{
	 yyval.un_quadra= new_signe(S_signe);
	 yyval.un_quadra->contenu.un_signe.type= S_hachureg;
	 yyval.un_quadra->kerning= 0;
 ;
    break;}
case 29:
#line 234 "sesh.y"
{
	 yyval.un_quadra= new_signe(S_signe);
	 yyval.un_quadra->contenu.un_signe.type= S_hachureh;
	 yyval.un_quadra->kerning= 0;
;
    break;}
case 30:
#line 240 "sesh.y"
{
	yyval.un_quadra= new_signe(S_signe);
	yyval.un_quadra->contenu.un_signe.type= S_hachurev;
	yyval.un_quadra->kerning= 0;
;
    break;}
case 31:
#line 246 "sesh.y"
{
	yyval.un_quadra= new_signe(S_signe);
	yyval.un_quadra->contenu.un_signe.type= S_hachuret;
	yyval.un_quadra->kerning= 0;
;
    break;}
case 32:
#line 252 "sesh.y"
{	
	yyval.un_quadra= new_quadra(yyvsp[-2].un_typegroupe);
	yyval.un_quadra->contenu.des_quadras= yyvsp[-1].un_quadra;
	yyval.un_quadra->kerning= 0;	
;
    break;}
case 33:
#line 258 "sesh.y"
{	
	yyval.un_quadra= new_quadra(S_rightleft);
	yyval.un_quadra->contenu.des_quadras= yyvsp[-1].un_quadra;
	yyval.un_quadra->kerning= 0;	
;
    break;}
case 35:
#line 265 "sesh.y"
{
	yyval.un_quadra= new_quadra(S_hachure);
	yyval.un_quadra->contenu.des_quadras= yyvsp[-1].un_quadra;
	yyval.un_quadra->kerning= 0;
;
    break;}
case 36:
#line 271 "sesh.y"
{
	yyval.un_quadra= new_quadra(S_enrouge);
	yyval.un_quadra->contenu.des_quadras= yyvsp[-1].un_quadra;
	yyval.un_quadra->kerning= 0;
;
    break;}
case 37:
#line 277 "sesh.y"
{
	yyval.un_quadra= new_signe(S_signe);
	yyval.un_quadra->contenu.un_signe.type= S_pointpoint;
	yyval.un_quadra->kerning= 0;
;
    break;}
case 38:
#line 283 "sesh.y"
{
	yyval.un_quadra= new_signe(S_signe);
	yyval.un_quadra->contenu.un_signe.type= S_smallspace;
	yyval.un_quadra->kerning= 0;
;
    break;}
case 39:
#line 289 "sesh.y"
{
	yyval.un_quadra= yyvsp[-1].un_quadra;
;
    break;}
case 40:
#line 296 "sesh.y"
{
	yyval.un_entier =0;
;
    break;}
case 41:
#line 300 "sesh.y"
{
	yyval.un_entier= yyvsp[-1].un_entier + 1;
;
    break;}
case 43:
#line 307 "sesh.y"
{
	yyval.un_quadra= new_quadra(S_overwrite);
	yyval.un_quadra->contenu.des_quadras= yyvsp[-2].un_quadra;
	yyval.un_quadra->contenu.des_quadras->next= yyvsp[0].un_quadra;
	yyval.un_quadra->kerning= 0;	
;
    break;}
case 44:
#line 316 "sesh.y"
{
	yyval.un_quadra= new_signe(S_hieroglyphe);
	yyval.un_quadra->contenu.un_signe.donnees= yyvsp[0].une_donnee;
;
    break;}
case 45:
#line 321 "sesh.y"
{
	yyval.un_quadra= new_signe(S_ligature);
	yyval.un_quadra->contenu.un_signe.donnees= yyvsp[0].une_donnee;
;
    break;}
case 46:
#line 326 "sesh.y"
{
	 yyval.un_quadra= new_signe(S_pointrouge);
	 yyval.un_quadra->kerning= 0;
 ;
    break;}
case 47:
#line 331 "sesh.y"
{
	 yyval.un_quadra= new_signe(S_pointnoir);
	 yyval.un_quadra->kerning= 0;
 ;
    break;}
case 48:
#line 338 "sesh.y"
{
	yyval.un_quadra= yyvsp[-2].un_quadra;
	yyval.un_quadra->contenu.un_signe.typehachure= yyvsp[0].une_hachure;
;
    break;}
case 49:
#line 344 "sesh.y"
{yyval.un_quadra = yyvsp[0].un_quadra;;
    break;}
case 50:
#line 345 "sesh.y"
{yyval.un_quadra = yyvsp[-2].un_quadra;;
    break;}
case 51:
#line 349 "sesh.y"
{yyval.un_quadra = yyvsp[-1].un_quadra; 	yyval.un_quadra->contenu.un_signe.size= yyvsp[0].un_entier;;
    break;}
case 52:
#line 350 "sesh.y"
{yyval.un_quadra = yyvsp[-1].un_quadra; yyval.un_quadra->contenu.un_signe.rotation= yyvsp[0].un_entier;;
    break;}
case 53:
#line 351 "sesh.y"
{yyval.un_quadra = yyvsp[-1].un_quadra; yyval.un_quadra->contenu.un_signe.reverted= TRUE;;
    break;}
case 54:
#line 355 "sesh.y"
{
  yyval.une_hachure= S_aucune;
;
    break;}
case 55:
#line 359 "sesh.y"
{
	yyval.une_hachure= S_ga;
;
    break;}
case 56:
#line 363 "sesh.y"
{
	yyval.une_hachure= S_ha;
;
    break;}
case 57:
#line 367 "sesh.y"
{
	yyval.une_hachure= S_va;
;
    break;}
case 58:
#line 371 "sesh.y"
{
	yyval.une_hachure= S_ta;
;
    break;}
case 59:
#line 378 "sesh.y"
{
	yyval.un_quadra= new_quadra(S_superfetatoire);						
	yyval.un_quadra->contenu.des_quadras= yyvsp[-1].un_quadra;
	yyval.un_quadra->kerning= 0;	
;
    break;}
case 60:
#line 384 "sesh.y"
{
	yyval.un_quadra= new_quadra(S_efface);						
	yyval.un_quadra->contenu.des_quadras= yyvsp[-1].un_quadra;
	yyval.un_quadra->kerning= 0;
;
    break;}
case 61:
#line 390 "sesh.y"
{
	yyval.un_quadra= new_quadra(S_disparu);						
	yyval.un_quadra->contenu.des_quadras= yyvsp[-1].un_quadra;
	yyval.un_quadra->kerning= 0;
;
    break;}
case 62:
#line 396 "sesh.y"
{
	yyval.un_quadra= new_quadra(S_ajoutscribe);
	yyval.un_quadra->contenu.des_quadras= yyvsp[-1].un_quadra;
	yyval.un_quadra->kerning= 0;
;
    break;}
case 63:
#line 402 "sesh.y"
{
	yyval.un_quadra= new_quadra(S_ajoutauteur);						
	yyval.un_quadra->contenu.des_quadras= yyvsp[-1].un_quadra;
	yyval.un_quadra->kerning= 0;
;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 543 "/usr/share/bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

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

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;

 yyacceptlab:
  /* YYACCEPT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 0;

 yyabortlab:
  /* YYABORT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 1;
}
#line 409 "sesh.y"

