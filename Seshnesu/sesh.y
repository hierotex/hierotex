/****************************************************************************
			     Sesh Nesout
	   Un programme d'aide a` la frappe hieroglyphique
	     utilisant le format du ``MANUEL DE CODAGE''
			   Serge Rosmorduc
	 $Id: sesh.y,v 2.5 1995/06/07 11:28:00 rosmord Exp $
****************************************************************************/
%{
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

%}

%union {
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
}

%token SIGNDECL STRING INTEGER ENDDECL
%token TEXTE DEBUTHIEROGS FINHIEROGS
%token HIEROGLYPHE LIGATURE
%token POINT
%token POINTPOINT  
%token SMALLSPACE
%token KERNING  
%token DEBUTCONSTRUCTION CARTF 
%token DIEZE0 DIEZE1
%token ROMAIN 
%token GAUCHEDROITE DROITEGAUCHE
%token LEFTRIGHT RIGHTLEFT
%token INTERNALSPACE
%token HACHUREGA HACHUREVA HACHUREHA HACHURETA
%token HACHUREG HACHUREV HACHUREH HACHURET
%token SHADING
%token OVERWRITE
%token SIZE ROTATION REVERT
%token TEXTESUPER POINTROUGE POINTNOIR
%token COULEUR0 COULEUR1
%token HAPLOGRAPHIE LACUNE LIGNELACUNE
%token DSTSUPERFETATOIRE FSTSUPERFETATOIRE
%token DSTEFFACE FSTEFFACE
%token DSTDISPARU FSTDISPARU
%token DSTRAJOUTSCRIBE FSTRAJOUTSCRIBE
%token DSTRAJOUTAUTEUR FSTRAJOUTAUTEUR
%token SEPARATEUR


%type <un_quadra> quadras quadra sousquadra inhierliste
%type <un_quadra> hieroglyphe hieroglyphes signe
%type <un_quadra> modificateurs modificateur
%type <un_quadra> construction_parenthesee
%type <une_horliste> sousquadras 
%type <un_entier> kerning SIZE ROTATION REVERT
%type <une_hachure> hachure
%type <un_typegroupe> DEBUTCONSTRUCTION
%type <une_donnee> HIEROGLYPHE LIGATURE
%type <une_donnee> TEXTESUPER ROMAIN
%type <un_separateur> SEPARATEUR separateur
%type <shading>	optShading SHADING
%type <chaine> STRING
%type <un_entier> INTEGER
%left ':'
%left '*'

%%

tout						: tout TEXTE
								| tout hierogs
								| tout signDecl
								| /* empty */
;

signDecl				: SIGNDECL STRING STRING INTEGER ENDDECL {
	struct caractere * chardef ;
	if ($4 > 255 || $4 < 0)
		{
			yyerror("bad number for char in font in signdecl.\nNumbers should be between 0 and 255.");
			YYERROR;
		}

	chardef= (struct caractere*)malloc(sizeof(struct caractere));
	chardef->fontName= $3;
	chardef->numero= $4;
	fprintf(stderr, "on définit %s", $3);
	defineNewChar($2, chardef);
}
;
			
hierogs					: DEBUTHIEROGS  separateur quadras separateur FINHIEROGS {
  affiche_quadras($3);
}
                | DEBUTHIEROGS  separateur FINHIEROGS
;

quadras					: kerning quadra
{
	$$= $2;
	$$->kerning= $1;								/* nombre de signes de kerning */
}
								| quadras separateur kerning quadra
{
	$$=$1;
	$$->last->next= $4;
	$4->previous= $$->last;
	$$->last->separateur= $2;
	$$->last=$4;
	$4->kerning= $3;
}
;

separateur: 
/* empty */ { $$= S_intersignes; }
|SEPARATEUR
;

quadra					: sousquadras optShading
{
	$$= new_quadra(S_quadra);
	$$->kerning= 0;
	$$->contenu.horizontal= $1;
	$$->shading= $2;
}
								 | ROMAIN
{
	$$= new_signe(S_romain);
	$$->kerning= 0;
	$$->contenu.un_signe.donnees= $1;
}
								 | HAPLOGRAPHIE
{
	$$= new_signe(S_haplographie);
	$$->kerning= 0;
}
								 | GAUCHEDROITE
{
	$$= new_signe(S_gauchedroite);
	$$->kerning= 0;
}
								 | DROITEGAUCHE
{
	$$= new_signe(S_droitegauche);
	$$->kerning= 0;
}
								 | LACUNE
{
	$$= new_signe(S_lacune);
	$$->kerning= 0;
}
								 | LIGNELACUNE
 {
	 $$= new_signe(S_lignelacune);
	 $$->kerning= 0;
 }
								 | TEXTESUPER
 {
	 $$= new_signe(S_textesuper);
	 $$->contenu.un_signe.donnees= $1;
	 $$->kerning= 0;
 }
 ;

sousquadras			: sousquadra
 {
	 $$= new_hor();
	 $$->un_quadra= $1;
 }
								 | sousquadras ':' kerning sousquadra
 {
	 $$=$1;
	 $$->last->next= new_hor();
	 $$->last->next->previous= $$->last;
	 $$->last= $$->last->next;
	 $$->last->un_quadra= $4;
	 $$->last->kerning= $3;
 }
 ;

optShading :
SHADING {$$= $1;}
| /*empty*/ {$$= NOSHADING;}
;

sousquadra			: sousquadra '*' kerning inhierliste
 {
	 $$= $1;
	 $$->last->next= $4;
	 $$->last->separateur= S_intersignes;
	 $$->last->next->previous= $$->last;
	 $$->last= $4;
	 $$->last->kerning= $3;
 }
								 | inhierliste
 {
	 $$= $1;
 }
 ;

inhierliste			: hieroglyphes
								 | POINT
 {
	 $$= new_signe(S_signe);
	 $$->contenu.un_signe.type= S_point;
	 $$->kerning= 0;
 }
								 | HACHUREG
 {
	 $$= new_signe(S_signe);
	 $$->contenu.un_signe.type= S_hachureg;
	 $$->kerning= 0;
 }
								 | HACHUREH
 {
	 $$= new_signe(S_signe);
	 $$->contenu.un_signe.type= S_hachureh;
	 $$->kerning= 0;
}
								| HACHUREV
{
	$$= new_signe(S_signe);
	$$->contenu.un_signe.type= S_hachurev;
	$$->kerning= 0;
}
								| HACHURET
{
	$$= new_signe(S_signe);
	$$->contenu.un_signe.type= S_hachuret;
	$$->kerning= 0;
}
								| DEBUTCONSTRUCTION quadras CARTF
{	
	$$= new_quadra($1);
	$$->contenu.des_quadras= $2;
	$$->kerning= 0;	
}
								| RIGHTLEFT quadras LEFTRIGHT
{	
	$$= new_quadra(S_rightleft);
	$$->contenu.des_quadras= $2;
	$$->kerning= 0;	
}
								| construction_parenthesee
								| DIEZE0 quadras DIEZE1
{
	$$= new_quadra(S_hachure);
	$$->contenu.des_quadras= $2;
	$$->kerning= 0;
}
								| COULEUR0 quadras COULEUR1
{
	$$= new_quadra(S_enrouge);
	$$->contenu.des_quadras= $2;
	$$->kerning= 0;
}
								| POINTPOINT
{
	$$= new_signe(S_signe);
	$$->contenu.un_signe.type= S_pointpoint;
	$$->kerning= 0;
}
								| SMALLSPACE
{
	$$= new_signe(S_signe);
	$$->contenu.un_signe.type= S_smallspace;
	$$->kerning= 0;
}
								| '(' quadras ')'
{
	$$= $2;
}
;


kerning: /* empty */
{
	$$ =0;
}
                | kerning KERNING
{
	$$= $1 + 1;
}
;

hieroglyphes    : hieroglyphe
| hieroglyphe OVERWRITE hieroglyphe
{
	$$= new_quadra(S_overwrite);
	$$->contenu.des_quadras= $1;
	$$->contenu.des_quadras->next= $3;
	$$->kerning= 0;	
}
;

signe  			: HIEROGLYPHE
{
	$$= new_signe(S_hieroglyphe);
	$$->contenu.un_signe.donnees= $1;
}
| LIGATURE
{
	$$= new_signe(S_ligature);
	$$->contenu.un_signe.donnees= $1;
}
								 | POINTROUGE
 {
	 $$= new_signe(S_pointrouge);
	 $$->kerning= 0;
 }
								 | POINTNOIR
 {
	 $$= new_signe(S_pointnoir);
	 $$->kerning= 0;
 }
;

hieroglyphe     : signe modificateurs hachure
{
	$$= $1;
	$$->contenu.un_signe.typehachure= $3;
}
;

modificateurs   : /* empty */ {$$ = $<un_quadra>0;} /* le signe doit etre repete */
                | modificateur modificateurs {$$ = $<un_quadra>0;} /* le signe doit etre repete */
;

modificateur    :
SIZE {$$ = $<un_quadra>0; 	$$->contenu.un_signe.size= $1;} /* le signe */
| ROTATION {$$ = $<un_quadra>0; $$->contenu.un_signe.rotation= $1;}
| REVERT   {$$ = $<un_quadra>0; $$->contenu.un_signe.reverted= TRUE;}
;

hachure         : /* empty */
{
  $$= S_aucune;
}
								| HACHUREGA
{
	$$= S_ga;
}
								| HACHUREHA
{
	$$= S_ha;
}
								| HACHUREVA
{
	$$= S_va;
}
								| HACHURETA
{
	$$= S_ta;
}
;

construction_parenthesee :
DSTSUPERFETATOIRE quadras FSTSUPERFETATOIRE
{
	$$= new_quadra(S_superfetatoire);						
	$$->contenu.des_quadras= $2;
	$$->kerning= 0;	
}
| DSTEFFACE quadras FSTEFFACE
{
	$$= new_quadra(S_efface);						
	$$->contenu.des_quadras= $2;
	$$->kerning= 0;
}
| DSTDISPARU quadras FSTDISPARU
{
	$$= new_quadra(S_disparu);						
	$$->contenu.des_quadras= $2;
	$$->kerning= 0;
}
| DSTRAJOUTSCRIBE quadras FSTRAJOUTSCRIBE
{
	$$= new_quadra(S_ajoutscribe);
	$$->contenu.des_quadras= $2;
	$$->kerning= 0;
}
| DSTRAJOUTAUTEUR quadras FSTRAJOUTAUTEUR
{
	$$= new_quadra(S_ajoutauteur);						
	$$->contenu.des_quadras= $2;
	$$->kerning= 0;
}
;

%%
