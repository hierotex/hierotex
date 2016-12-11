
#define TAILLETAB 997

typedef struct tablenode * (tableau[TAILLETAB]) ;
typedef tableau *TABLE ;

extern TABLE creer_table();
extern void detruire_table( /* table */ );

extern void insere(/* clef, donnee, table */);

extern char * trouve(/* clef,tableau */);











