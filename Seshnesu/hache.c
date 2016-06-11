
/***************************************************************************\
													 table de hachage
\***************************************************************************/
#include "hache.h"
#include <malloc.h>
/* Dans le .h */
typedef struct 
{
  char * clef;
  char * data;
} ENTREE;

struct tablenode
{
  ENTREE monentree;
  struct tablenode * next;
};


#ifndef NULL
#define NULL (void *)0
#endif

tableau *creer_table()
{
  tableau * tmp;
  int i;
  tmp= (tableau*)malloc(sizeof(tableau));
  for (i=0; i<TAILLETAB; i++)
    (*tmp)[i]= NULL;
  return tmp;
}

void detruire_table(table)	/*  insuffisant ! */
     tableau * table;
{
  /* int i;*/
  free(table);
}
  
static unsigned int hache(clef)
     char *clef;
{
  char *p;
  unsigned h=0,g;
  for (p= clef; *p ;p++)
    {
      h= (h<<4)+(*p);
      if ((g = h & 0xF0000000) != 0)
	{
	  h ^= (g>>24);
	  h ^= g;
	}
    }
  return h % TAILLETAB;
}

void insere(clef, donnee, table)
     char * clef, *donnee;
     tableau * table;
{
  /* int ou;*/
  struct tablenode ** T, *O;

  O= *(T= &(*table)[hache(clef)]);
  while (O)
    O=*(T= &(O->next));
  *T= (struct tablenode*)malloc(sizeof(struct tablenode));
  (*T)->monentree.clef= clef;
  (*T)->monentree.data= donnee;  
  (*T)->next=NULL;
}

char * trouve(clef,table)
     char * clef;
     tableau * table;
{
  /* int ou;*/
  /* char * res;*/
  
  struct tablenode * T;
  T= (*table)[hache(clef)];
  while (T && (strcmp(T->monentree.clef, clef)!=0))
    T= T->next;
  if (T)
    return T->monentree.data;
  else
    return NULL;
}


  
