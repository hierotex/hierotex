### THIS FILES CONTAINS VARIABLES FOR BUILDING EVERYTHING IN
### sesh nesu, from the TeX files and the fonts to the 
### font editor. 
### 
### So you probably need to modify only part of it.

##############################################################################
# Where should I install the software :

# Place where the binary goes
BINDIR=/usr/local/bin
# Root of the tex tree the files should be installed into.
TEXROOT=/usr/share/texmf
# Tex Style file directory
TEXSTYLE=$(TEXROOT)/tex/latex/HieroTeX
# Font directory
FONTDIR=$(TEXROOT)/fonts/source/public/HieroTeX
# Docs directory
TEXDOC=$(TEXROOT)/doc/latex/hierotex

# If you want a user installation of hierotex, without root access,
# the following values may help you. Uncomment them if needed.
#BINDIR=$(HOME)/hierotex/bin
#TEXROOT=`/usr/bin/kpsewhich -var-value=TEXMFHOME`
#TEXSTYLE=$(TEXROOT)/tex/latex/hierotex
#FONTDIR=$(TEXROOT)/fonts/source/public/hierotex
#TEXDOC=$(TEXROOT)/doc/latex/hierotex

# Programs used in the installation process
INSTALL=/usr/bin/install
DELFILE=/bin/rm 2>/dev/null
RM=-/bin/rm

# The make program. It should be GNU make, if you want to build
# the fonts. 
# (however, Sbzr and sesh can be built with simpler versions of make)
MAKE=make

# The C compiler
CC = gcc

# small hack for cross compiling on linux for windows :
# path to the MINGW c compiler.
# You probably don't need to touch this line,
# unless you are cross-compiling
MINGW=/usr/bin/i686-w64-mingw32-gcc

# Commands used for building Seshnesu
LEX=flex
LFLAGS= -8
YACC=bison
YFLAGS=-y -d -v 

# The command for latex. for building the docs
LATEX=pdflatex

# VERSIONS NUMBERS : You don't want to modify them (except in case of patches)
EGYPTO_USER_VERSION=3.5.1
HIEROTYPE_VERSION=3.1.4
SESH_VERSION=2.9.6

