BUILT_SOURCES = EGypto.tex signlist.tex
EXTRA_DIST = EGypto.tex signlist.tex
CLEANFILES = EGypto.pdf EGypto.log EGypto.dic EGypto.aux
doc_DATA = EGypto.pdf
EGYPTO_sources = EGypto.htx

.htx.tex:
	$(srcdir)/../../../../sesh/sesh < $< > $@

.tex.pdf:
	TEXMFHOME=$(srcdir)/../../../ updmap
	TEXINPUTS="$(srcdir):" TEXMFHOME=$(srcdir)/../../../ lualatex $<

