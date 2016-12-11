%{
/* 	$Id: seshl.l,v 2.5 1995/06/07 11:27:47 rosmord Exp $	 */

#include "quadra.h"
#include "sesh.h"
#include "hache.h"
#include "fonctions.h"

#undef YYLMAX
#define YYLMAX 10240
#include <string.h>
#include <strings.h>
#include <stdio.h>

#define G(x) {yylval=find_sign(x); return HIEROGLYPHE;}
#define Commence(x) BEGIN(x); etat=x;
#define INITIAL0 0

PRIVATE void computeShading(Shading *h);

extern union _Donnees find_sign(char *x, int sens); /* OK, c'est mal */
extern int signe_trouve;

extern TABLE definitions;

void traite();

char * nomdefine;

int dieze=0;
int couleur=0;
int signe_lu= FALSE;
int signe_deja_lu= FALSE;
int etat= INITIAL0;
extern int numligne;
void TLIGNE();

/* Les ligatures */

char * les_ligatures[]= {
  "\\ligAROBDd ",
  "\\ligAROBD",
  "\\ligAROBDt",
  "\\ligAROBDra",
  "\\hierCC",
  "\\hierXX"
};

%}

entier	([0-9]+)
INTEGER	(-?{entier})
gardiner	(([A-Z]|Aa){entier}a*)
ident	([a-zA-Z0-9.'`]+)
ligident	([a-zA-Z0-9.'`&]+)
ESPS	([ _\t\n\015=]+)
ESPSO	([ _\t\n\015=]*)
ESP	([ _\t\n\015=])
ESPSOH	([ _\t\n\015=-]*)
ESPSH	([ _\t\n\015=-]+)

%s DEFINE0 DEFINE1 HieroText TEXTEIMBR COMMENTAIRE InSignDecl
%e 2000

%%
 	switch(etat)
	{ case INITIAL0: BEGIN(INITIAL0);break;
	  case HieroText: BEGIN(HieroText);break;
	  case InSignDecl: fprintf(stderr, "aaa\n"); BEGIN(InSignDecl); ; break;
	}
                                        /* infamous trick. # should have ONE meaning */
                                        if ( signe_lu )
                                        { 
                                           if (signe_deja_lu) 
                                              { signe_deja_lu = FALSE; signe_lu= FALSE; }
                                           else
                                              { signe_deja_lu= TRUE;}
                                        }

<INITIAL>(.)	{ECHO; return TEXTE;}
<INITIAL>(\n)	{ECHO; numligne++; return TEXTE;}
<INITIAL>"\\hieroglyph"[ \n\t]*         |
<INITIAL>"\\begin{hieroglyph}"[ \n\t]*	{ TLIGNE();
	  Commence(HieroText); 
                                          signe_lu= FALSE;
                                          return DEBUTHIEROGS;}

<DEFINE0>{ESPS}	BEGIN(DEFINE1);
<DEFINE1>[^#]*"#"{ESP}*	{ char *pt;
	char *s= strdup(yytext);
	TLIGNE();
	pt= s + yyleng;
	while (*(--pt) != '#');
	*pt= 0;
	stocke(nomdefine, s);
	Commence(HieroText);}

<HieroText>{ESP}*"\\endhieroglyph"      |
<HieroText>{ESP}*"\\end{hieroglyph}"	{ TLIGNE(); Commence(INITIAL); return FINHIEROGS;}

<HieroText>"D&d"	|
<HieroText>D:d	{yylval.une_donnee.texte= les_ligatures[0];
 /*  mieux vaudrait des noms symboliques */
	  signe_lu= TRUE;
	  return LIGATURE;
	}

<HieroText>"o"	return POINTROUGE;
<HieroText>"O"	return POINTNOIR;

<HieroText>D	{yylval.une_donnee.texte= les_ligatures[1];
	 signe_lu= TRUE;
	 return LIGATURE;}

<HieroText>D:t	{yylval.une_donnee.texte= les_ligatures[2];
                                          signe_lu= TRUE;
	 return LIGATURE;}
<HieroText>D:ra	{yylval.une_donnee.texte= les_ligatures[3];
                                          signe_lu= TRUE;
	 return LIGATURE;}
<HieroText>200	{yylval.une_donnee.texte= les_ligatures[4];
                                         signe_lu= TRUE;
	 return LIGATURE;} 
<HieroText>20	{yylval.une_donnee.texte= les_ligatures[5];
              	 signe_lu= TRUE;
	 return LIGATURE;}

<HieroText>"aA\\r1"	{ yylval.une_donnee =find_sign("aAv",0); 
	  if (!signe_trouve) {REJECT } 
	  else { signe_lu= TRUE; return HIEROGLYPHE;}
	}

<HieroText>"Y1\\r3"	{ yylval.une_donnee =find_sign("Y1v",0); 
	  if (!signe_trouve) {REJECT } 
	  else { signe_lu= TRUE; return HIEROGLYPHE;}
	}

<HieroText>{ident}	|
<HieroText>([A-Z]|Aa){entier}A*	{ yylval.une_donnee =find_sign(yytext,0); 
	  if (!signe_trouve) {REJECT } 
	  else { signe_lu= TRUE; return HIEROGLYPHE;}
	}

<HieroText>","{ident}	{traite(yytext+1);}
<INITIAL>"#signdecl" 	{Commence(InSignDecl); return SIGNDECL;}
<InSignDecl>{entier}	{yylval.un_entier= atoi(yytext); fprintf(stderr, "\nHERE\n");return INTEGER;}
<InSignDecl>[a-zA-Z0-9.'`_@]+	{yylval.chaine = strdup(yytext); fprintf(stderr, "\nHERE1\n");return STRING;}
<InSignDecl>"#enddecl"	{Commence(INITIAL); return ENDDECL;}
<InSignDecl>" "|\t|\n|\r	{fprintf(stderr, "espace\n");} 
<InSignDecl>.	{fprintf(stderr, "char\n");}
<HieroText>"#def"{ESPS}{ligident}	{ int i;
	  for (i=4; yytext[i] && (yytext[i] == ' ' || yytext[i]== '\t');
	       i++);
	  if  (yytext[i])
	  {
	    nomdefine=strdup(yytext+i);
	    BEGIN (DEFINE0);
	  }
	  else
	    yyerror("Mauvaise definition");
	}
<HieroText>"="{ESPSO}	|
<HieroText>"-"{ESPSO}	{ 
                                          yylval.un_separateur= S_intersignes; 
                                          return SEPARATEUR;
                                        }
<HieroText>{ESPSH}	|
<HieroText>{ESPSH}"-"	{
                                          TLIGNE(); 
                                          yylval.un_separateur= S_espace; 
                                          return SEPARATEUR;
                                        }
<HieroText>\n	{
                                         numligne++;
                                         yylval.un_separateur= S_espace; 
                                         return SEPARATEUR;
                                        }

<HieroText>{ESPSOH}"!="{INTEGER}"%"{ESPSOH}            |
<HieroText>{ESPSOH}"!"{ESPSOH}	{
                                          TLIGNE(); 
                                          yylval.un_separateur= S_finligne;
                                          return SEPARATEUR;
                                        }

<HieroText>{ESPSOH}"!!="{INTEGER}"%"{ESPSOH}            |
<HieroText>{ESPSOH}"!!"{ESPSOH}	{ 
                                          TLIGNE();
                                          yylval.un_separateur= S_finpage;
                                          return SEPARATEUR;
                                        }
<HieroText>{ESPSO}"*"{ESPSO}	{TLIGNE(); return '*';}
<HieroText>{ESPSO}":"{ESPSO}	{TLIGNE(); {return ':'; }}
<HieroText>"+l"	BEGIN(TEXTEIMBR);
<HieroText>"+dg"	return DROITEGAUCHE;
<HieroText>"+gd"	return GAUCHEDROITE;
<HieroText>{ESPSOH}"+lr"	return LEFTRIGHT;
<HieroText>"+rl"{ESPSOH}	{TLIGNE(); return RIGHTLEFT;}

<HieroText>"|"[^-]+	{ yylval.une_donnee.texte= strdup(yytext+1);
	  return TEXTESUPER;
	}
<HieroText>\\!	return KERNING;
<HieroText>"."	return POINT;
<HieroText>".."	return POINTPOINT;
<HieroText>"01"	return SMALLSPACE;
<HieroText>{ligident}	{traite(yytext); /* les macros-definitions !!! */}
<HieroText>"//"	return HACHUREG;
<HieroText>"h/"	return HACHUREH;
<HieroText>"v/"	return HACHUREV;
<HieroText>"/"	return HACHURET;
<HieroText>"#"{entier} 	{
  	  computeShading(&(yylval.shading));
	  return SHADING;
	}
<HieroText>"#//"	return HACHUREGA;
<HieroText>"#h/"	return HACHUREHA ;
<HieroText>"#v/"	return HACHUREVA;
<HieroText>"#/"	return HACHURETA;
<HieroText>"^"	return HAPLOGRAPHIE;
<HieroText>"?"	return LACUNE;
<HieroText>"??"	return  LIGNELACUNE;
<HieroText>"[{"{ESPSOH}	{TLIGNE(); return DSTSUPERFETATOIRE;}
<HieroText>{ESPSOH}"}]"	{TLIGNE(); return FSTSUPERFETATOIRE;}
<HieroText>"[["{ESPSOH}	{TLIGNE(); return DSTEFFACE;}
<HieroText>{ESPSOH}"]]"	{TLIGNE(); return FSTEFFACE;}
<HieroText>"[\""{ESPSOH}	{TLIGNE(); return  DSTDISPARU ;}
<HieroText>{ESPSOH}"\"]"	{TLIGNE(); return  FSTDISPARU ;}
<HieroText>"['"{ESPSOH}	{TLIGNE(); return  DSTRAJOUTSCRIBE;}
<HieroText>{ESPSOH}"']"	{TLIGNE(); return  FSTRAJOUTSCRIBE;}
<HieroText>"[&"{ESPSOH}	{TLIGNE(); return  DSTRAJOUTAUTEUR;}
<HieroText>{ESPSOH}"&]"	{TLIGNE(); return  FSTRAJOUTAUTEUR;}
<HieroText>"<"{ESPSOH}	{TLIGNE(); yylval.un_typegroupe= S_carto; return DEBUTCONSTRUCTION;}
<HieroText>"<b"{ESPSOH}	{TLIGNE(); yylval.un_typegroupe= S_debcarto; return DEBUTCONSTRUCTION;}
<HieroText>"<m"{ESPSOH}	{TLIGNE(); yylval.un_typegroupe= S_milcarto; return DEBUTCONSTRUCTION;}
<HieroText>"<e"{ESPSOH}	{TLIGNE(); yylval.un_typegroupe= S_fincarto; return DEBUTCONSTRUCTION;}
<HieroText>{ESPSOH}">"	{TLIGNE(); return CARTF;}
<HieroText>"<S"{ESPSOH}	{TLIGNE(); yylval.un_typegroupe= S_serekh; return DEBUTCONSTRUCTION;}
<HieroText>"<F"{ESPSOH}	{TLIGNE(); yylval.un_typegroupe= S_enceinte; return DEBUTCONSTRUCTION;}
<HieroText>"<H"{ESPSOH}	{TLIGNE(); yylval.un_typegroupe= S_chateau; return DEBUTCONSTRUCTION;}
<HieroText>"<Sb"{ESPSOH}	{TLIGNE(); yylval.un_typegroupe= S_debserekh; return DEBUTCONSTRUCTION;}
<HieroText>"<Sm"{ESPSOH}	{TLIGNE(); yylval.un_typegroupe= S_milserekh; return DEBUTCONSTRUCTION;}
<HieroText>"<Se"{ESPSOH}	{TLIGNE(); yylval.un_typegroupe= S_finserekh; return DEBUTCONSTRUCTION;}
<HieroText>"<Fb"{ESPSOH}	{TLIGNE(); yylval.un_typegroupe= S_debenceinte; return DEBUTCONSTRUCTION;}
<HieroText>"<Fm"{ESPSOH}	{TLIGNE(); yylval.un_typegroupe= S_milenceinte; return DEBUTCONSTRUCTION;}
<HieroText>"<Fe"{ESPSOH}	{TLIGNE(); yylval.un_typegroupe= S_finenceinte; return DEBUTCONSTRUCTION;}
<HieroText>"<Hb"{ESPSOH}	{TLIGNE(); yylval.un_typegroupe= S_debchateau; return DEBUTCONSTRUCTION;}
<HieroText>"<Hm"{ESPSOH}	{TLIGNE(); yylval.un_typegroupe= S_milchateau; return DEBUTCONSTRUCTION;}
<HieroText>"<He"{ESPSOH}	{TLIGNE(); yylval.un_typegroupe= S_finchateau; return DEBUTCONSTRUCTION;}
<HieroText>{ESPSOH}"#-"{ESPSOH}	|
<HieroText>{ESPSOH}"-#"{ESPSOH}	|
<HieroText>{ESPSOH}"-#-"{ESPSOH}	{TLIGNE(); dieze=1-dieze; /* ne compliquons pas la grammaire */
	  if (dieze==1) return DIEZE0;
	  else return DIEZE1;}
<HieroText>"#b"{ESPSOH}                  {TLIGNE(); if (signe_lu) REJECT; dieze=1-dieze; return DIEZE0;}
<HieroText>{ESPSOH}"#b"{ESPSOH}	{TLIGNE(); dieze=1-dieze; return DIEZE0;}
<HieroText>{ESPSOH}"#e"{ESPSOH}         {TLIGNE(); dieze=1-dieze; return DIEZE1;}
<HieroText>"#"	{if (signe_lu) return OVERWRITE; else REJECT;}
<HieroText>"##"	{if (signe_lu) return OVERWRITE; else REJECT;}

<HieroText>{ESPSOH}"$"{ESPSOH}	{TLIGNE(); couleur=1-couleur; /* ne compliquons pas la grammaire */
	  if (couleur==1) return COULEUR0;
	  else return COULEUR1;}
<HieroText>{ESPSOH}"$b"{ESPSOH} 	{TLIGNE(); couleur=1; return COULEUR1;}
<HieroText>{ESPSOH}"$r"{ESPSOH}	{TLIGNE(); couleur=0; return COULEUR0;}

<HieroText>\\	{return REVERT;}
<HieroText>\\s[0-9]	{
                                          yylval.un_entier= atoi(yytext+2); 
                                          return SIZE;  
                                        }
<HieroText>\\{INTEGER}
<HieroText>\\R{INTEGER}	{
                                          yylval.un_entier= atoi(yytext+2); 
                                          return ROTATION;  
                                        }
<HieroText>\\t{INTEGER}
<HieroText>\\r{INTEGER}	{
	  yylval.un_entier= 360-atoi(yytext+2)* 90; 
                                          return ROTATION;  
	}
<HieroText>"("{ESPSO}	{TLIGNE(); return '(';}
<HieroText>{ESPSOH}")"{ESPSO}	{TLIGNE(); return ')';}

<HieroText>"+s-"
<HieroText>"+b-"
<HieroText>"+r-"
<HieroText>{ESPSO}"++"	{TLIGNE(); BEGIN(COMMENTAIRE);}
<HieroText>\015                                    ;
<HieroText>(.)	return yytext[0];

<TEXTEIMBR>"+s"	{ yylval.une_donnee.texte= strdup(yytext);
	  yylval.une_donnee.texte[strlen(yylval.une_donnee.texte)-2]=0;
	  return ROMAIN;
	}
<TEXTEIMBR>(.|\n)	{TLIGNE(); yymore(); }

<COMMENTAIRE>(.|\n)	{TLIGNE();}
<COMMENTAIRE>"+s"{ESPSOH}	{TLIGNE(); BEGIN(HieroText);}

%%

void traite(texte)
     char * texte;
{
  int i;
  char *result;
  if ((result= trouve(texte, definitions)))
    {
      for (i=strlen(result) -1; i> -1; i--)
        unput(result[i]);		
    }
  else
  {
    char toto[300];
    sprintf(toto, "texte non reconnu: %s", texte);
    yyerror(toto);
  }
}

void TLIGNE()
{
  char *s;
  s= yytext;
  while ((s= strchr(s, '\n')))
  {
    numligne++;
    s++;
  }
}

PRIVATE void
computeShading(Shading *h)
{
  int i;
  *h= NOSHADING;
  for (i=1; i< yyleng; i++)
    switch(yytext[i])
      {
      case '1':
        *h |= SHADING1;
        break;
      case '2':
        *h |= SHADING2;
        break;
      case '3':
        *h |= SHADING3;
        break;
      case '4':
        *h |= SHADING4;
        break;
      }
}

/* 
 * Local Variables:
 * mode: c
 * tab-width: 40
 * End:
 */
