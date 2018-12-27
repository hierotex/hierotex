#!/bin/sh
# doinst of package hierotex
# Author: Serge Rosmorduc <rosmord@iut.univ-paris8.fr>
# adapted from Rafael Laboissière <rafael@icp.inpg.fr>'s tipa-type1 package


set -e

texmf_dvips=/etc/texmf/dvips
updmap=${texmf_dvips}/updmap

case "$1" in
    configure)     
      if [ -x $updmap ] ; then \
        TMP=`tempfile --mode=0755` ; \
        perl -e 'while(<>){if (/^(extra_modules=\")(.*)$/){print "$1\nhierotex.map\n$2"}else {print}}' \
          < $updmap > $TMP ; \
        mv $TMP $updmap ; \
	( cd $texmf_dvips ; ./updmap ); \
      fi
      if [ -x /usr/bin/texhash ] ; then \
         /usr/bin/texhash ; \
      fi
        ;;
    abort-upgrade | abort-deconfigure | abort-remove)
	;;
    *)
	echo "$0: incorrect arguments: $*" >&2
	exit 1
	;;
esac

# Automatically added by dh_installdocs
if [ "$1" = "configure" ]; then
	if [ -d /usr/doc -a ! -e /usr/doc/hierotex -a -d /usr/share/doc/hierotex ]; then
		ln -sf ../share/doc/hierotex /usr/doc/hierotex
	fi
fi
# End automatically added section

