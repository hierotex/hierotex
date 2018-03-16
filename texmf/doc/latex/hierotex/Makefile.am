BUILT_SOURCES = EGypto.tex signlist.tex
EXTRA_DIST = EGypto.htx EGypto.tex signlist.tex
CLEANFILES = EGypto.pdf EGypto.log EGypto.dic EGypto.aux EGypto.tex

# Deploy doc with source files
texmfdir = $(prefix)/share/texmf
texmfdocdir = $(texmfdir)/doc/latex/@PACKAGE@
texmfdoc_DATA = EGypto.pdf EGypto.htx EGypto.tex signlist.tex

.htx.tex:
	$(srcdir)/../../../../sesh/sesh < $< > $@

# Different usage of updmap depending on version
.tex.pdf:
	TEXMFHOME=$(srcdir)/../../../ updmap -user || TEXMFHOME=$(srcdir)/../../../ updmap
	TEXINPUTS="$(srcdir):" TEXMFHOME=$(srcdir)/../../../ lualatex $<

