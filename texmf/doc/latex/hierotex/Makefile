RM=/bin/rm 

include ../../../../variable.mk

SESHDIR=../../../../Seshnesu

EGypto.pdf : $(SESHDIR)/sesh signlist.tex EGypto.htx
	@echo "well, I try to build EGypto.dvi"
	@echo "make offerings to Toth and D. Knuth"
	@echo "and perhaps it will work"
	$(SESHDIR)/sesh <EGypto.htx >toto.tex
	$(LATEX) toto.tex
	-bibtex toto
	$(LATEX) toto.tex
	$(LATEX) toto.tex
	-$(RM) toto.tex
	-mv toto.pdf EGypto.pdf
	-$(RM) toto.dic toto.aux toto.log toto.blg toto.bbl

$(SESHDIR)/sesh : 
	(cd $(SESHDIR) ; $(MAKE) sesh)

signlist.tex : $(SESHDIR)/seshSource.txt $(SESHDIR)/mkliste.awk
	$(SESHDIR)/mkliste.awk < $(SESHDIR)/seshSource.txt | sed 's/Aa/ZZZ/' |\
		sort -t= +0 -1 +1n -2 +2n -3 | sed 's/ZZZ/Aa/' |\
		nawk -F = '{print "\\showHvalue{\\hieroglyph " $$4 "\\endhieroglyph}{" $$5 "}" }'\
		| $(SESHDIR)/sesh > $@

configure:

clean : FORCE
	-$(RM) -f *~ \#*\# *.log *.aux *.dic *.blg *.bbl

veryclean : clean

veryveryclean : clean
	$(RM) -f *.dvi

FORCE :



