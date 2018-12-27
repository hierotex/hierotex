#!/bin/nawk -f
BEGIN {
}
{printf("{\"%s\", \"%s\",{ \"G%s\", %s }},\n", $1, $2, $3, $4 + 31); }


