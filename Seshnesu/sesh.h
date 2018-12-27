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


extern YYSTYPE yylval;
