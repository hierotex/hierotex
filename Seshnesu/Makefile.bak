
## ALL THAT CAN CHANGE IS HERE, in variable.mk (ONLY TOUCH THE UPPER FILE !!)

include ../variable.mk

SRCS=Version.c fonctions.c fonctions.h general.h hache.h mynew.h quadra.c quadra.h sesh.y seshSource.h seshl.l flexaux.c


# End of things you can change.
CFLAGS=-g

WINCPPFLAGS=-DSESH_VERSION=\"$(SESH_VERSION)\"

CPPFLAGS=-DSESH_VERSION=\"$(SESH_VERSION)\" -DSESHDIR=\"$(SESHDIR)\"

OBJETS= fonctions.o sesh.o seshl.o hache.o quadra.o Version.o flexaux.o

default:
	@echo "	To make the sesh program : "
	@echo "  first edit the variables.mk file in the parent directory"
	@echo "  and  type make sesh"
	@echo
	@echo " If 1) you haven't got lex+yacc or bison+flex"
	@echo " and 2) sesh doesn't compile, don't despair. "
	@echo " you can a) try to patch the sesh.c and seshl.c files"
	@echo " or b) (cleaner way) get a working version of these for your machine"
	@echo " or ultimately, migrate to Linux :-)"

# For mingw cross compiler :
SOURCES=fonctions.c sesh.c seshl.c hache.c quadra.c Version.c flexaux.c

sesh.exe : $(SOURCES)
	$(MINGW) -o $@ -I./windows $(WINCPPFLAGS) $(SOURCES)

sesh: $(OBJETS)
	$(LINK.c) -o $@ $(OBJETS) $(LIBR)

quadra.o: quadra.c quadra.h mynew.h

sesh.o : fonctions.h sesh.c
sesh.c sesh.h: sesh.y
	$(YACC.y) -d sesh.y
	mv y.tab.c sesh.c
	mv y.tab.h sesh.h;

seshl.o: sesh.h fonctions.h

fonctions.o : seshSource.h fonctions.h

seshSource.h: seshSource.txt
	awk -f mklex.awk < seshSource.txt > $@

Version.o: ../variable.mk
## CONFIGURE TRIES TO FIND $(LEX) AND $(YACC) and then 
## remove

configure:
	@-PATHS=`echo $$PATH | tr ':' ' '`;\
	for i in $$PATHS; do if [ -f $$i/$(LEX) ]; then oulex=trouve ; fi; done;\
	if [ $${oulex:-rien} != rien  ] ; then $(DELFILE) seshl.c ; fi;\
	for i in $$PATHS; do if [ -f $$i/$(YACC) ]; then ouyacc=trouve ; fi;done;\
	if [ $${ouyacc:-rien} != rien  ] ; then $(DELFILE) sesh.c sesh.h; fi



clean: FORCE
	-/bin/rm -f *~ "#*#"

veryclean : clean
	-/bin/rm -f *.o

# only veryveryclean supresses what can't be built on 
# systems without bison and flex

distclean : seshl.c sesh.c sesh.h seshSource.h clean 
	-/bin/rm -f sesh
	-makedepend --  # suppress the informations added by makedepend.

veryveryclean : veryclean
	-/bin/rm -f sesh
	-/bin/rm -f  seshl.c
	-/bin/rm -f sesh.c
	-/bin/rm -f sesh.h
	-/bin/rm -f seshSource.h


cleanyacclex : cleanyacc cleanlex

cleanyacc :
	-/bin/rm sesh.c
	-/bin/rm sesh.h

cleanlex :
	-/bin/rm seshl.c

depend: 
	makedepend -- $(CFLAGS) -- $(SRCS)

FORCE :
# DO NOT DELETE
