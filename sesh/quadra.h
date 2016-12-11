/***************************************************************************\				   
								 Definition des quadras a` bas niveau
\***************************************************************************/
/* 	$Id: quadra.h,v 2.5 1995/06/07 11:28:05 rosmord Exp $	 */


#ifndef _QUADRA_H
#define _QUADRA_H

#ifndef NULL
#define NULL 0
#endif

/* "New" (well 1994 !) shading system */
#define SHADING1 (1)
#define SHADING2 (1<<1)
#define SHADING3 (1<<2)
#define SHADING4 (1<<3)
#define NOSHADING 0
#define FULLSHADING (SHADING4|SHADING3|SHADING2|SHADING1)

typedef unsigned char Shading;

/* Old fashioned shadings : */
typedef enum _Typehachure {
				S_aucune,
				S_ga,
				S_ha,
				S_va, 
				S_ta
} Typehachure;

typedef enum _Typeseparateur {
	S_espace,
	S_finligne,
	S_finpage,
	S_intersignes,
	S_sansseparateur
} Typeseparateur;


/* Il y a deux sortes de donne'es inse're'es : 
	 Celles qui parenthe`sent d'autres constructions 
	 Les autres
	 */

typedef enum _Typesigne
{
		S_hieroglyphe,
		S_ligature,
		S_romain,
		S_textesuper,
		S_pointrouge,
		S_pointnoir,
		S_haplographie,
		S_gauchedroite, 
		S_droitegauche ,
		S_lacune ,
		S_lignelacune ,
		S_point,
		S_pointpoint,
		S_smallspace,
		S_hachureg,
		S_hachureh,
		S_hachurev,
		S_hachuret
} Typesigne;

typedef enum _Typegroupe
{
	S_signe,											/* feuille */
	S_quadra,											/* quadra  */
	S_hachure,										/* groupe hachure */
	S_carto ,											/* cartouche autour du groupe */
	S_debcarto,										/* diverses boites */
	S_rightleft,
	S_milcarto ,
	S_fincarto ,
	S_serekh ,
	S_enceinte ,
	S_chateau ,
	S_debserekh ,
	S_milserekh ,
	S_finserekh ,
	S_debenceinte ,
	S_milenceinte ,
	S_finenceinte ,
	S_debchateau ,
	S_milchateau ,
	S_finchateau ,
	S_enrouge,										/* mise en rouge */
	S_superfetatoire,							/* Les parentheses */
	S_efface,
	S_disparu,
	S_ajoutscribe,
	S_ajoutauteur,
	S_overwrite
	}  Typegroupe;


typedef struct _Signe {
	Typesigne type;
	Typehachure typehachure;
	int size, rotation, reverted;
	union _Donnees {
		struct {
			char * fontName;
			int caractere;						/* numero dans la fonte */
		} hieroglyphe;
		char * texte;								/* symboles divers directement repre'sente's */
	} donnees;
} Signe;


typedef struct _Horliste {
	struct _Quadra *un_quadra;		/* premie`re ligne */
	int kerning;									/* kerning vertical */	
	struct _Horliste * next, * previous, *last; /* les suivantes */
} Horliste;

typedef struct _Quadra {
  Typegroupe type;
  int kerning;			/* kerning horizontal */
  Typeseparateur separateur;	/* separation d avec le signe suivant */
  Shading shading;
  union {
    Horliste  *horizontal;	/* liste des lignes du quadra s'il y a lieu */
    Signe un_signe;
    struct _Quadra * des_quadras; /* quadra imbrique' ! */
  } contenu;
  struct _Quadra * next, *previous, *last;
} Quadra;


/* 
	 Gestion de la memoire
*/

Quadra *new_quadra();
Quadra *new_signe();
Horliste * new_hor();

void initialise_quadras();
void detruit_quadras();
void libere_quadras();

#endif


