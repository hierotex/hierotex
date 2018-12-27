#ifndef _GENERAL_H
#define _GENERAL_H

#ifndef PUBLIC
#define PUBLIC
#define PRIVATE static
#endif

#if __STDC__
#define ANSI(x) x
#define TRAD(x)
#else
#define ANSI(x)
#define TRAD(x) x
#endif

#ifndef TRUE 
#define TRUE 1
#define FALSE 0
#endif


#endif
