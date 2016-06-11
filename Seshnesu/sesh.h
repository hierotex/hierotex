/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SIGNDECL = 258,
    STRING = 259,
    INTEGER = 260,
    ENDDECL = 261,
    TEXTE = 262,
    DEBUTHIEROGS = 263,
    FINHIEROGS = 264,
    HIEROGLYPHE = 265,
    LIGATURE = 266,
    POINT = 267,
    POINTPOINT = 268,
    SMALLSPACE = 269,
    KERNING = 270,
    DEBUTCONSTRUCTION = 271,
    CARTF = 272,
    DIEZE0 = 273,
    DIEZE1 = 274,
    ROMAIN = 275,
    GAUCHEDROITE = 276,
    DROITEGAUCHE = 277,
    LEFTRIGHT = 278,
    RIGHTLEFT = 279,
    INTERNALSPACE = 280,
    HACHUREGA = 281,
    HACHUREVA = 282,
    HACHUREHA = 283,
    HACHURETA = 284,
    HACHUREG = 285,
    HACHUREV = 286,
    HACHUREH = 287,
    HACHURET = 288,
    SHADING = 289,
    OVERWRITE = 290,
    SIZE = 291,
    ROTATION = 292,
    REVERT = 293,
    TEXTESUPER = 294,
    POINTROUGE = 295,
    POINTNOIR = 296,
    COULEUR0 = 297,
    COULEUR1 = 298,
    HAPLOGRAPHIE = 299,
    LACUNE = 300,
    LIGNELACUNE = 301,
    DSTSUPERFETATOIRE = 302,
    FSTSUPERFETATOIRE = 303,
    DSTEFFACE = 304,
    FSTEFFACE = 305,
    DSTDISPARU = 306,
    FSTDISPARU = 307,
    DSTRAJOUTSCRIBE = 308,
    FSTRAJOUTSCRIBE = 309,
    DSTRAJOUTAUTEUR = 310,
    FSTRAJOUTAUTEUR = 311,
    SEPARATEUR = 312
  };
#endif
/* Tokens.  */
#define SIGNDECL 258
#define STRING 259
#define INTEGER 260
#define ENDDECL 261
#define TEXTE 262
#define DEBUTHIEROGS 263
#define FINHIEROGS 264
#define HIEROGLYPHE 265
#define LIGATURE 266
#define POINT 267
#define POINTPOINT 268
#define SMALLSPACE 269
#define KERNING 270
#define DEBUTCONSTRUCTION 271
#define CARTF 272
#define DIEZE0 273
#define DIEZE1 274
#define ROMAIN 275
#define GAUCHEDROITE 276
#define DROITEGAUCHE 277
#define LEFTRIGHT 278
#define RIGHTLEFT 279
#define INTERNALSPACE 280
#define HACHUREGA 281
#define HACHUREVA 282
#define HACHUREHA 283
#define HACHURETA 284
#define HACHUREG 285
#define HACHUREV 286
#define HACHUREH 287
#define HACHURET 288
#define SHADING 289
#define OVERWRITE 290
#define SIZE 291
#define ROTATION 292
#define REVERT 293
#define TEXTESUPER 294
#define POINTROUGE 295
#define POINTNOIR 296
#define COULEUR0 297
#define COULEUR1 298
#define HAPLOGRAPHIE 299
#define LACUNE 300
#define LIGNELACUNE 301
#define DSTSUPERFETATOIRE 302
#define FSTSUPERFETATOIRE 303
#define DSTEFFACE 304
#define FSTEFFACE 305
#define DSTDISPARU 306
#define FSTDISPARU 307
#define DSTRAJOUTSCRIBE 308
#define FSTRAJOUTSCRIBE 309
#define DSTRAJOUTAUTEUR 310
#define FSTRAJOUTAUTEUR 311
#define SEPARATEUR 312

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 28 "sesh.y" /* yacc.c:1909  */

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

#line 181 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
