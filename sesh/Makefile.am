BUILT_SOURCES = sesh.h seshl.c seshSource.h
AM_YFLAGS = --yacc -d -Wall
AM_LFLAGS = -8

bin_PROGRAMS = sesh
sesh_SOURCES = fonctions.c sesh.y seshl.l hache.c quadra.c flexaux.c seshSource.txt
sesh_CFLAGS = -Wall

.txt.h:
	awk -f mklex.awk < $< > $@
