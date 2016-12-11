#!/bin/sh
# Create a sorted list of signs
# USE + as a separator in array coded

awk '
BEGIN {
}

{ 
  if (coded[$3 $4]=="")
    coded[$3 $4]=$1 ;
  else
    coded[$3 $4]=coded[$3 $4] ", " $1 ;
  if (match($1,/[A-Z].*[0-9]+A?/)) 
    {
      main[$3 $4]=$1;
      match($1,/^[A-Z]a?/);
      codeA[$3 $4]=substr($1,RSTART,RLENGTH);
      match($1,/[0-9]+/)
      codeB[$3 $4]=substr($1,RSTART,RLENGTH);
      if (match($1,/A$/))
	  codeC[$3 $4]=1;
      else
	  codeC[$3 $4]=0;
    }
}

END {for (i in coded) 
     { print codeA[i] "=" codeB[i] "=" codeC[i] "=" main[i] "=" coded[i] }}


'
