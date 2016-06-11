/* Interface to PUBLIC fonctions in fonctions */

#ifndef _FONCTIONS_H
#define _FONCTIONS_H

#include "quadra.h"
#include "general.h"

struct caractere {char * fontName; unsigned  char numero;};

#if __STDC__
PUBLIC void yyerror(char *s);
PUBLIC void affiche_quadras(Quadra *q);
PUBLIC void stocke(char *nom, char *valeur);
PUBLIC union _Donnees find_sign(char *x, int sens);
PUBLIC void defineNewChar(char * charname, struct caractere * chardef);
#else
PUBLIC void yyerror();
PUBLIC void affiche_quadras();
PUBLIC void stocke();
PUBLIC union _Donnees find_sign();
PUBLIC void defineNewChar();
#endif

#endif /* ifndef FONCTIONS_H */
