BUILT_SOURCES = sesh.h seshl.c seshSource.h
AM_YFLAGS = --yacc --debug -d -Wall
AM_LFLAGS = -8

bin_PROGRAMS = sesh
sesh_SOURCES = fonctions.c sesh.y seshl.l hache.c quadra.c flexaux.c seshSource.txt
sesh_CFLAGS = -Wall -Wextra

.txt.h:
	awk -f mklex.awk < $< > $@
