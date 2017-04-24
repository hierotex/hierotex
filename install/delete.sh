#!/bin/sh
# postrm of package hierotex
# Author: Serge Rosmorduc <rosmord@iut.univ-paris8.fr>
# adapted from Rafael Laboissière <rafael@icp.inpg.fr>'s tipa-type1 package

set -e

texmf_dvips=/etc/texmf/dvips
updmap=${texmf_dvips}/updmap

case "$1" in
    purge | remove)     
      if [ -x /usr/bin/texhash ] ; then \
         /usr/bin/texhash ; \
      fi
      if [ -x $updmap ] ; then \
        TMP=`tempfile --mode=0755` ; \
        perl -e 'while(<>){if (not (/^hierotex.map$/)) { print; }}' \
          < $updmap > $TMP ; \
        mv $TMP $updmap ; \
	( cd $texmf_dvips ; ./updmap ); \
      fi
        ;;
    upgrade | failed-upgrade | abort-upgrade | abort-install)
	;;
    *)
	echo "$0: incorrect arguments: $*" >&2
	exit 1
	;;
esac

exit 0

