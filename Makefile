# A General makefile

include variable.mk

SRCDOC=texmf/doc/latex/hierotex
SRCFONT=texmf/fonts/source/public/hierotex
SRCSTY=texmf/tex/latex/hierotex

default : 
	@echo " General Sesh installation "
	@echo
	@echo "make tetex-install tries to install everything"
	@echo "you should edit variable.mk first"
	@echo
	@echo "other targets : save publish"
	@echo " 	  clean -> minor cleaning, backup files"
	@echo "		  veryclean -> intermediary files"
	@echo "		  veryveryclean -> everything that can be built with the"
	@echo "			right tools"


TAR=tar -X Exclude -cvf
TARZ=tar -X Exclude -zcvf
save :  ../egyptoS.tar

publish : ../HieroTeX-$(EGYPTO_USER_VERSION).tgz ../HieroType1-$(EGYPTO_USER_VERSION).tgz

../HieroType1-$(EGYPTO_USER_VERSION).tgz : FORCE distclean
	$(TARZ) $@ -h -C .. \
		texmf/fonts/type1 \
		texmf/dvips\
		texmf/pdftex

../HieroTeX-$(EGYPTO_USER_VERSION).tgz : FORCE distclean
	$(TARZ) $@  -C ..  HieroTeX/Seshnesu  HieroTeX/texmf \
		 HieroTeX/LIZEZMOI  HieroTeX/Licence\
		 HieroTeX/README_FIRST\
		 HieroTeX/Makefile\
		 HieroTeX/variable.mk


distclean: FORCE clean
	-(cd Seshnesu; $(MAKE) distclean)	
	-(cd texmf/doc/latex/hierotex; $(MAKE) clean)

clean : FORCE
	-$(RM) -f *~ "#*#"
	-(cd Seshnesu; $(MAKE) clean)	
	-(cd texmf/doc/latex/hierotex; $(MAKE) clean)

veryclean : clean
	-(cd Seshnesu; $(MAKE) veryclean)	
	-(cd texmf/doc/latex/hierotex; $(MAKE) veryclean)

veryveryclean : clean
	-(cd Seshnesu; $(MAKE) veryclean)	
	-(cd texmf/doc/latex/hierotex; $(MAKE) veryveryclean)


## Makefile for a possible tetex installation

tetex-install: FORCE
	(cd Seshnesu; make sesh)
	-$(INSTALL) -d $(BINDIR)
	-$(INSTALL) -d $(TEXSTYLE)
	-$(INSTALL) -d $(TEXDOC)
	-$(INSTALL) -d $(FONTDIR)/auxmf $(FONTDIR)/mf
	-$(INSTALL)  Seshnesu/sesh $(BINDIR)
	-$(INSTALL)  -m 644 $(SRCFONT)/auxmf/* $(FONTDIR)/auxmf
	-$(INSTALL)  -m 644 $(SRCFONT)/mf/* $(FONTDIR)/mf
	-$(INSTALL)  -m 644 $(SRCSTY)/* $(TEXSTYLE)
	-$(INSTALL)  -m 644 $(SRCDOC)/* $(TEXDOC)
	texhash 2>/dev/null

FORCE :


