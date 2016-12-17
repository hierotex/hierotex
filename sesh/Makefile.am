BUILT_SOURCES = sesh.h seshl.c seshSource.h
EXTRA_DIST = seshSource.h
AM_YFLAGS = --yacc --debug -d -Wall
AM_LFLAGS = -8

bin_PROGRAMS = sesh
sesh_SOURCES = fonctions.c fonctions.h sesh.y seshl.l hache.c hache.h quadra.c quadra.h flexaux.c general.h mynew.h seshSource.txt mklex.awk mkliste.awk
sesh_CFLAGS = -Wall -Wextra

.txt.h:
	awk -f $(srcdir)/mklex.awk < $< > $@
