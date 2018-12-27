### THIS FILES CONTAINS VARIABLES FOR BUILDING EVERYTHING IN
### sesh nesu, from the TeX files and the fonts to the 
### font editor. 
### 
### So you probably need to modify only part of it.

##############################################################################
# Where should I install the software :

# Destination directory. Usually /usr, /usr/local or $(HOME)
DESTDIR=/usr
# Place where the binary goes
#BINDIR=$(DESTDIR)/bin
BINDIR=/usr/local/bin
# Root of the tex tree the files should be installed into.
TEXROOT=$(DESTDIR)/share/texmf
# Tex Style file directory
TEXSTYLE=$(TEXROOT)/tex/latex/HieroTeX
# Font directory
FONTDIR=$(TEXROOT)/fonts/source/public/HieroTeX
# define the directory which will include site-wide signs definitions
SESHDIR=/usr/local/lib/sesh

# If you want a user installation of hierotex, without root access,
# the following values may help you. Uncomment them if needed.
DESTDIR=$(HOME)
BINDIR=$(DESTDIR)/bin
TEXROOT=$(DESTDIR)/texmf
TEXSTYLE=$(TEXROOT)/tex/latex/hierotex
FONTDIR=$(TEXROOT)/fonts/source/public/hierotex
TEXDOC=$(TEXROOT)/doc/latex/hierotex
SESHDIR=$(DESTDIR)/lib/sesh

##############################################################################
# Programs used in the installation process
INSTALL=/usr/bin/install
DELFILE=/bin/rm 2>/dev/null
RM=-/bin/rm

# The make program. It should be GNU make, if you want to build
# the fonts. 
# (however, Sbzr and sesh can be built with simpler versions of make)

MAKE=gnumake
MAKE=make # gnumake can be called "make" on some machines

# The C compiler

#CC	=	dos-gcc
CC = gcc
#CC = cc

# small hack for cross compiling on linux for windows :
# path to the MINGW c compiler.
# You probably don't need to touch this line,
# unless you are cross-compiling

MINGW=/usr/local/mingw/bin/mingw32-gcc

##############################################################################

# THINGS FOR SESHNESU :

# sesh can work if you build it with lex, but it won't work with 8bits files
# if you do so, because lex is brain dead in this case. So you should try 
# to get a copy of flex, which is much better and is GNU.


LEX=flex
LFLAGS= -8

#if you have linking problems because of flex,
#uncomment the line below.
#(NOTA : there should be no problems :->)
#LIBR=-lfl

# IF YOU DON'T HAVE FLEX, uncomment the lines below
#LEX=/bin/lex
#LIBR=-ll

#in case you have yacc and not bison, comment the lines below

YACC=bison
YFLAGS=-y -d -v 

# TO use YACC, uncomment these lines
#YACC=/bin/yacc
#YFLAGS=-d -v

##############################################################################

# The command for latex. for building the docs

LATEX=pdflatex
LATEX=pdfelatex
#LATEX=virtex '&lplain'

##############################################################################

# VERSIONS NUMBERS : You don't want to modify them (except in case of patches)

EGYPTO_USER_VERSION=3.6
SESH_VERSION=2.9.5



