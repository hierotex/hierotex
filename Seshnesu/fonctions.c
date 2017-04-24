#include "hache.h"
#include "quadra.h"
#include "general.h"
#include <stdio.h>
/* #include <varargs.h>  */
/*#include <malloc.h>*/
#include <stdlib.h>
#include <string.h>

#include "fonctions.h"

extern char * Version;



PRIVATE TABLE signes;
PUBLIC TABLE definitions;
/* PUBLIC TABLE phonetiques; not used now */

PUBLIC int numligne= 1;
PUBLIC int signe_trouve;

enum direction { gauche_a_droite, droite_a_gauche};

struct donne {
	char * entree;
	char * phon;
	struct caractere symbole;
};

PRIVATE void quadra_parenthese();

PUBLIC union _Donnees find_sign(x, sens)				/* OK, c'est mal */
	char *x; int sens;
{
	union _Donnees D;
	struct caractere* txt;

	if ((txt=(struct caractere*)trouve(x,signes)))
	{
		signe_trouve= TRUE;
		D.hieroglyphe.fontName= txt->fontName;
		D.hieroglyphe.caractere= txt->numero + sens * 128;
	}
	else
		signe_trouve= FALSE;
	return D;
}


PUBLIC void stocke(nom, valeur)
		char *nom, *valeur;
{
		insere(nom,valeur,definitions);
}

PRIVATE struct donne les_donnees[]=
{
#include "seshSource.h"
    {0,0,{0,0}}
}
;

PRIVATE void initialise_lex()
{
		struct donne *i;
		signes= creer_table();
		definitions= creer_table();
		/* phonetiques= creer_table(); */
		/* indexmots= fopen("index.mot", "w");*/
		/* fflush(indexmots); */
  
		for (i= les_donnees; i->entree; i++)
				{
						insere(i->entree,&(i->symbole), signes);
						/* insere(i->entree,i->phon, phonetiques);*/
				}
}

PUBLIC void defineNewChar(charname, chardef)
		 char * charname;
		 struct caractere * chardef;
{
	insere(charname, chardef, signes);
}

PRIVATE void read_sign_file(fname)
		 char * fname;
{
	struct donne *i;
	FILE *f;
	int numLine= 0;
	if ((f= fopen(fname, "r")) != NULL) {
		int fileIsWellFormed= TRUE;
		while (fileIsWellFormed && !feof(f)) {
			char signCode[21];
			char fontName[21];
			int charNum;
			int itemRead;
			
			itemRead= fscanf(f, "%20s\t%20s\t%d\n", signCode, fontName, &charNum);
			if (itemRead == 3) {
				struct caractere * chardef ;
				chardef= (struct caractere*)malloc(sizeof(struct caractere));
				chardef->fontName= strdup(fontName);
				chardef->numero= charNum;
				insere(strdup(signCode), chardef, signes);
			} else
				fileIsWellFormed= FALSE;
			numLine++;
		}
		if (! fileIsWellFormed)
			{
				fprintf(stderr, "File %s has an error line %d\n", fname, numLine);
			}
	} else {
		/* fprintf(stderr, "File %s doesn't exist. Skipping.\n", fname);*/
	}
}

PUBLIC void yyerror(s)
		char *s;
{
		extern char *yytext;
		fprintf(stderr, "\n\n%s, pres de %s ligne %d\n",s, yytext, numligne);
		exit(-1);
}

PRIVATE void affiche_hiero();

PRIVATE void affiche_un_hieroglyphe(s, externe, hachure, size, rotation, reverted)
	char * s;
	int externe;
	Typehachure hachure;
	int size, rotation, reverted;
{
	switch(hachure)
	{
	case S_aucune:
		break;
	case S_ga:
		printf("\\hachurega{");
		break;
	case S_ha:
		printf("\\hachureha{");
		break;
	case S_va: 
		printf("\\hachureva{");
		break;
	case S_ta:
		printf("\\hachureta{");
		break;
	}
	if (externe)
		printf("\\loneSign{");
	if (size > 0)
	{
		int masize= size;
		printf("{");
		while ((masize--) > 0)
			printf("\\Hsmaller");
	}
	if (reverted)
	{
		printf("\\Hrevert{");
	}		
	if (rotation != 0)
	{
		printf("\\Hrotate{%d}{", -rotation);
	}
	printf(s);
	if (rotation != 0)
	{
		printf("}");
	}
	if (reverted)
	{
		printf("}");
	}
	if (size > 0)
		printf("}");
	if (externe)
		printf("}");
	if (hachure != S_aucune)
		printf("}");
}

PRIVATE void affiche_signe(q, external, sens)
	Quadra *q;
	int external;
	enum direction sens;
{
	switch(q->contenu.un_signe.type)
	{
		static char tempo[30];
	case S_hieroglyphe:
		sprintf(tempo, "\\Aca %s/%u/", 
						q->contenu.un_signe.
												 donnees.hieroglyphe.fontName,
						q->contenu.un_signe.
						donnees.hieroglyphe.caractere
						);										 /* ouf! */ 
		affiche_un_hieroglyphe(tempo, external,
													 q->contenu.un_signe.typehachure, 
													 q->contenu.un_signe.size,
													 q->contenu.un_signe.rotation,
													 q->contenu.un_signe.reverted
													 );
		break;
	case S_ligature:
		affiche_un_hieroglyphe(q->contenu.un_signe.donnees.texte,
													 external, 
 													 q->contenu.un_signe.typehachure, 
													 q->contenu.un_signe.size,
													 q->contenu.un_signe.rotation,
													 q->contenu.un_signe.reverted
													 ); 
		break;
	case S_romain:								/* passage en fonte romaine */
		if (external)
			printf("{\\rm %s}", 
						 q->contenu.un_signe.donnees.texte);
		else
			printf("{\\footnotesize \\rm %s}", 
						 q->contenu.un_signe.donnees.texte);
		break;
	case S_textesuper:						/* texte au dessus d'un trait */
		printf("\\traittexte{%s}",
					 q->contenu.un_signe.donnees.texte);
		break;
	case S_pointrouge:
		printf("\\pointrouge");
		break;
	case S_pointnoir:
		printf("\\pointnoir");
	 break;
	case S_haplographie:
		break;
	case S_gauchedroite:
		printf("\\leftright");
		break;
	case S_droitegauche :
		printf("\\rightleft");
		break;
	case S_lacune :
		break;
	case S_lignelacune :
		break;
	case S_point:
		printf("\\HquarterSpace ");
		break;
	case S_pointpoint:
		printf("\\HfullSpace ");
		break;
	case S_smallspace:
		printf("\\HsmallSpace ");
		break;
	case S_hachureg:
		printf("\\hachureg ");
		break;
	case S_hachureh:
		printf("\\hachureh ");
		break;
	case S_hachurev:
		printf("\\hachurev ");
		break;
	case S_hachuret:
		printf("\\hachuret ");
		break;
	}
}

PRIVATE void affiche_horliste(h, external, sens)
	Horliste *h;
	int external;
	enum direction sens;
{
	if ((h->next == NULL) 
			)	/* un seul signe */
	{
		if (!h->un_quadra || !h->un_quadra->next)
			affiche_hiero(h->un_quadra, external, sens);
		else												/* A*B*C.... */
		{
			printf("\\LoneHorizontalLine{");
			affiche_hiero(h->un_quadra, external, sens);
			printf("}");
		}
	}
	else													/* empilement */
		{
			Horliste *t= h;
			int depart= TRUE;
			
			if (external)
				printf("\\Cadrat{");
			else
				printf("\\InternalCadrat{");
			while (t)
				{
					int i;
					for (i=0; i<t->kerning; i++)
						printf("\\negAROBvspace");
					if (depart)
						{
							printf("\\CadratLineI{");
							depart= FALSE;
						}
					else
						printf("\\CadratLine{");
					affiche_hiero(t->un_quadra,FALSE, sens);
					printf("}");
					t= t->next;								/* this next is vertical */
				}
			printf("}");
		}
}

PRIVATE void quadra_parenthese(debut, q, external, sens)
	char *debut;
	Quadra *q;
	int external;
	enum direction sens;
{
	printf("%s", debut);
	affiche_hiero(q->contenu.des_quadras, external, sens);
	printf("}%\n");
}

/*
 * prints the list of cadrat q.
 * argument q is a pointer to a cadrat list
 */
PRIVATE void affiche_hiero(q, external, sens) 
	Quadra *q;
	int external;
	enum direction sens;
{
	if (sens == droite_a_gauche)
		q= q-> last;
	while (q)
	{
		int i;
		int separator;

		if (q->shading != NOSHADING)
		  {
		    unsigned int i;
		    int j;

		    printf("\\newShading{");
		    for(i= 1, j= 0; j< 4; j++, i= i << 1)
		      if (q->shading & i)
		      printf("X");
		    else
		      printf("O");
		    printf("}{");
		  }
		
		for (i=0; i<q->kerning; i++)
			printf("\\negAROBspace");
		switch(q->type)
		{
		case S_quadra:
			affiche_horliste(q->contenu.horizontal, external, sens);
			break;
		case S_hachure:
			quadra_parenthese("\\hachure{", q, external, sens);
			break;
			/* les constructions de type cartouche */
		case S_carto :
			quadra_parenthese("\\cartouche{", q, external, sens);
			break;
		case S_debcarto:
			quadra_parenthese("\\debcartouche{", q, external, sens);
			break;
		case S_milcarto :
			quadra_parenthese("\\milcartouche{", q, external, sens);
			break;
		case S_fincarto :
			quadra_parenthese("\\endOfcartouche{", q, external, sens);
			break;
		case S_serekh :
			quadra_parenthese("\\serekh{", q, external, sens);
			break;
		case S_enceinte :
			quadra_parenthese("\\enceinte{", q, external, sens);
			break;
		case S_chateau :
			quadra_parenthese("\\chateau{", q, external, sens);
			break;
		case S_debserekh :
			quadra_parenthese("\\debserekh{", q, external, sens);
			break;
		case S_milserekh :
			quadra_parenthese("\\milserekh{", q, external, sens);
			break;
		case S_finserekh :
			quadra_parenthese("\\endOfserekh{", q, external, sens);
			break;
		case S_debenceinte :
			quadra_parenthese("\\debenceinte{", q, external, sens);
			break;
		case S_milenceinte :
			quadra_parenthese("\\milenceinte{", q, external, sens);
			break;
		case S_finenceinte :
			quadra_parenthese("\\endOfenceinte{", q, external, sens);
			break;
		case S_debchateau :
			quadra_parenthese("\\debchateau{", q, external, sens);
			break;
		case S_milchateau :
			quadra_parenthese("\\milchateau{", q, external, sens);
			break;
		case S_finchateau :
			quadra_parenthese("\\endOfchateau{", q, external, sens);
			break;
		case S_enrouge:
			quadra_parenthese("\\enrouge{", q, external, sens);
			break;
		case S_rightleft:
			quadra_parenthese("\\boxrightleft{",
												q, external, 
												droite_a_gauche);
			break;
		case S_overwrite : 
			printf("\\hsuperpose{");
			affiche_signe(q->contenu.des_quadras,
										external, sens);
			printf("}{");
			affiche_signe(q->contenu.des_quadras->next,
										external, sens);
			printf("}");
			break;
		case S_superfetatoire:
			quadra_parenthese("\\edisuperfet{", q, external, sens);
			break;
		case S_efface:
			quadra_parenthese("\\ediefface{", q, external, sens);
			break;
		case S_disparu:
			quadra_parenthese("\\edidisparu{", q, external, sens);			
			break;
		case S_ajoutscribe:
			quadra_parenthese("\\ediajoutscribe{", q, external, sens);
			break;
		case S_ajoutauteur:
			quadra_parenthese("\\ediajoutauteur{", q, external, sens);
			break;
		case S_signe:
			affiche_signe(q, external, sens);
			/* close the accolade opened for \Cadrat */			
		}
		if (q->shading != NOSHADING)
		  printf("}");
		
		/*
			BEWARE ! if orientation is right-to-left,
			we should not consider q->separateur but q->previous->separateur
		*/
		
		if (sens == gauche_a_droite)
		  separator= q->separateur;
		else {
		  if (q->previous)
		    separator= q->previous->separateur;
		  else
		    separator= S_sansseparateur;
		}
		if (external)
			switch (separator)
			{
			case S_espace:
				printf("\\HwordSpace\n"); 
				break;
			case S_finligne:
				printf("}\\end{hieroglyph}\\HendOfLine\n\\begin{hieroglyph}{\\leavevmode\n");
				/* printf("\\Htoline\n");*/
				break;
			case S_finpage:
				printf("}\\end{hieroglyph}\\HendOfPage\n\\begin{hieroglyph}{\\leavevmode\n");
				break;
			case S_intersignes:
				printf("\\HinterSignsSpace\n");
				break;
			case S_sansseparateur:
				break;
			}
		else
			switch (separator)
			{
			case S_espace:
			case S_finligne:
			case S_finpage:
			case S_intersignes:
				printf("\\hfill");
			case S_sansseparateur:
				break;
			}
		if (sens == gauche_a_droite)
			q= q-> next;
		else
			q= q-> previous;
	}
}

PUBLIC void affiche_quadras(q)		/*  affichage de quadras */
	Quadra *q;
{
	printf("\\begin{hieroglyph}{\\leavevmode ");
	affiche_hiero(q, TRUE, gauche_a_droite);
	printf("}\\end{hieroglyph}");
	libere_quadras();
}

extern void yyparse(); 

PRIVATE void readStaticDefinitionFiles()
{
	char * signDefinitionFilePath;
	char * homeDir;

	char signDefinitionFileName[]= "fontDef.txt";
	#ifdef SESHDIR
	signDefinitionFilePath= (char*) malloc(strlen(SESHDIR) + strlen(signDefinitionFileName) + 2);
	strcpy(signDefinitionFilePath, SESHDIR);
	strcat(signDefinitionFilePath, "/");
	strcat(signDefinitionFilePath, signDefinitionFileName);
	read_sign_file(signDefinitionFilePath);
	free(signDefinitionFilePath);
#endif

	if (homeDir= getenv("HOME"))
		{
			signDefinitionFilePath= (char*) malloc(strlen(homeDir) + strlen(signDefinitionFileName) + 2);
			strcpy(signDefinitionFilePath, homeDir);
			strcat(signDefinitionFilePath, "/");
			strcat(signDefinitionFilePath, signDefinitionFileName);
			read_sign_file(signDefinitionFilePath);
			free(signDefinitionFilePath);
		}

		if (signDefinitionFilePath= getenv("SESHDIR"))
		{
			signDefinitionFilePath= (char*) malloc(strlen(homeDir) + strlen(signDefinitionFileName) + 2);
			strcpy(signDefinitionFilePath, homeDir);
			strcat(signDefinitionFilePath, "/");
			strcat(signDefinitionFilePath, signDefinitionFileName);
			read_sign_file(signDefinitionFilePath);
			free(signDefinitionFilePath);
		}
		
}

PUBLIC int main(argc, argv)
	int argc;
	char ** argv;
{
	/*extern */int yydebug;
	int lastArg= 1;
	int argsOk= TRUE;

	while (argsOk && lastArg < argc) {
		if (strcmp(argv[lastArg], "-def") == 0)
			{
				lastArg++;
				if (lastArg < argc)
					{
						read_sign_file(argv[lastArg]);
					}
				else
					argsOk= FALSE;
			}
		else
			argsOk= FALSE;
		lastArg++;
	}
	
	if (!argsOk)
		{
			fprintf(stderr, "sesh nesou, version (%s)\n", Version);
			fprintf(stderr, "usage %s [-def SIGNDEFINITIONFILE]\n", argv[0]);
			exit(0);
		}

	initialise_lex();

	readStaticDefinitionFiles();

	yydebug= 1;
	initialise_quadras();
	(void)yyparse();
	libere_quadras();
	exit(0);
}
/*
 * Local Variables:
 * tab-width: 2
 * End:
 */
