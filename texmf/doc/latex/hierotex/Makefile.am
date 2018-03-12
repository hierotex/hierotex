BUILT_SOURCES = EGypto.tex signlist.tex
EXTRA_DIST = EGypto.htx EGypto.tex signlist.tex
CLEANFILES = EGypto.pdf EGypto.log EGypto.dic EGypto.aux EGypto.tex
doc_DATA = EGypto.pdf

.htx.tex:
	$(srcdir)/../../../../sesh/sesh < $< > $@

.tex.pdf:
	TEXMFHOME=$(srcdir)/../../../ updmap -user
	TEXINPUTS="$(srcdir):" TEXMFHOME=$(srcdir)/../../../ lualatex $<

