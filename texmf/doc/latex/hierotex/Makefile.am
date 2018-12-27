BUILT_SOURCES = EGypto.tex bib.bib
EXTRA_DIST = EGypto.htx signlist.tex bib.src
CLEANFILES = EGypto.pdf EGypto.log EGypto.dic EGypto.aux bib.bib EGypto.tex EGypto.blg EGypto.bbl

# Deploy doc with source files
texmfdir = $(prefix)/share/texmf
texmfdocdir = $(texmfdir)/doc/latex/@PACKAGE@
texmfdoc_DATA = bib.src bib.bib EGypto.pdf EGypto.htx EGypto.tex signlist.tex

.htx.tex:
	../../../../sesh/sesh < $< > $@

.src.bib:
	cp -f $< $@

# Different usage of updmap depending on version, two runs and some copying to
# get bibtex to run correctly in an out-of-tree build.
.tex.pdf: bib.bib
	TEXMFHOME=$(srcdir)/../../../ updmap -user || TEXMFHOME=$(srcdir)/../../../ updmap
	TEXINPUTS="$(srcdir):" TEXMFHOME=$(srcdir)/../../../ lualatex $<
	bibtex *.aux
	TEXINPUTS="$(srcdir):" TEXMFHOME=$(srcdir)/../../../ lualatex $<
