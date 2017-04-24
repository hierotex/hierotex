#!/bin/sh -e
# Automatically added by dh_installdocs
if [ \( "$1" = "upgrade" -o "$1" = "remove" \) -a -L /usr/doc/tipa-type1 ]; then
	rm -f /usr/doc/tipa-type1
fi
# End automatically added section
