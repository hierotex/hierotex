/* 
	 Module supérieur de gestion de la mémoire.
*/
#include <stdlib.h>
#include "quadra.h"
#include "mynew.h"

DECLARE_STACK(Quadra)
IMPLEMENTE_STACK(Quadra)
DECLARE_STACK(Horliste)
IMPLEMENTE_STACK(Horliste)

Quadra *new_quadra(val)
		Typegroupe val;
{
	Quadra * q;
	q= NEW(Quadra);
	q->type= val;
	q->last= q;
	q->kerning= 0;
	q->separateur= S_sansseparateur;
	q->shading= NOSHADING;
	q->next= NULL;
	q->previous= NULL;
	return q;
}

Quadra* new_signe(s)
	Typesigne s;
{
	Quadra * q;
	q= new_quadra(S_signe);
	q->contenu.un_signe.type=s;
	q->contenu.un_signe.size=0;	
	q->contenu.un_signe.rotation=0;
	q->contenu.un_signe.reverted=0;
	q->contenu.un_signe.typehachure= S_aucune;
	q->kerning= 0;
	return q;
}

Horliste * new_hor()
{
	Horliste * h;
	h= NEW(Horliste);
	h->kerning=0;
	h->last= h;
	h->next= NULL;
	h->previous= NULL;
	return h;
}

void initialise_quadras()
{
	INIT_STACK(Quadra);
	INIT_STACK(Horliste);
}

void detruit_quadras()
{
	DESTROY(Quadra);
	DESTROY(Horliste);
}

void libere_quadras()
{
	CLEANUP(Quadra);
	CLEANUP(Horliste);
}



