
/***************************************************************************\
	Serge Rosmorduc, le 10/7/94
	this package is placed under the GNU LICENCE LIBRARY,
	If you want to use it in another way, ask me.

	Efficient memory management for very dynamic programs
	This set of macros is intended for often malloc()-ed 
	and free()-ed structures. It is supposed to be cleaner and more 
	efficient than simple malloc and free.

	Using this package :
	you must define your structures as this :

	typedef struct _TheBloodyNameOfMyStructure
	{
	......
	} TheBloodyNameOfMyStructure;

	Then, in ONE file :
	#include "mynew.h"
	DECLARE_STACK(TheBloodyNameOfMyStructure)
	IMPLEMENTE_STACK(TheBloodyNameOfMyStructure)

	and when you want to use it :
	#include "mynew.h"
	DECLARE_STACK(TheBloodyNameOfMyStructure)
	
	....
	practical use :
	INIT_STACK(TheBloodyNameOfMyStructure); ONCE ONLY !

	TheBloodyNameOfMyStructure * toto= NEW(TheBloodyNameOfMyStructure);

	DELETE(TheBloodyNameOfMyStructure,toto); To free toto

	CLEANUP(TheBloodyNameOfMyStructure); will declare all allocated space
	to be free, so that it can be reused, for the SAME type. Useful when
	you build complex structures, you destroy them, and then you build
	them anew.

	DESTROY(TheBloodyNameOfMyStructure); REAL cleanup of the type.

\***************************************************************************/

/* 
	 CONCAT2 and CONCAT3 are two macros that are supposed to concatenate
	 their arguments.  As there is no general way of doing it,
	 we try both methods : ANSI is using ##, 
	 and K&R usual way is using an empty comment
*/

#if __STDC__
#define CONCAT2(a,b) a##b
#define CONCAT3(a,b,c) a##b##c
#else
#define CONCAT2(a,b) a/**/b
#define CONCAT3(a,b,c) a/**/b/**/c
#endif

#define MININSTACK 100					/* basic number of allocated elements */
#define STACKINSTACK 50					/* basic number of allocated STACKS */

#if __STDC__
#define DECLARE_STACK(_type_) \
  extern _type_ * CONCAT2(new_,_type_) ();\
  extern void CONCAT2(free_,_type_) (_type_ *);\
  extern void CONCAT3(init_,_type_,_stack)();\
  extern void CONCAT2(_type_,_cleanup)();
#else
#define DECLARE_STACK(_type_) \
  extern _type_ * CONCAT2(new_,_type_) ();\
  extern void CONCAT2(free_,_type_) ();\
  extern void CONCAT3(init_,_type_,_stack)();\
  extern void CONCAT2(_type_,_cleanup)();
#endif
					  

#define IMPLEMENTE_STACK(_type_) \
typedef CONCAT2(struct _type_,_aux_pointer_struct) \
{ \
  struct CONCAT2(_,_type_) structure;\
  struct CONCAT2(_type_,_aux_pointer_struct) *next;\
}* CONCAT2(_type_,_aux_pointer); \
\
static struct CONCAT2(_type_,_stack_struct) \
{\
  CONCAT2(_type_,_aux_pointer)  pile, firstfree;\
  CONCAT2(_type_,_aux_pointer)  *piles; \
  unsigned int nombre_de_piles, nombre_de_piles_max;\
  unsigned int total; \
} CONCAT2(_type_,_stack) ;\
static void CONCAT2(_type_,_expand_struct)()\
{\
  int i;\
  CONCAT2(_type_,_stack).piles[CONCAT2(_type_,_stack).nombre_de_piles]=\
    (CONCAT2(_type_,_aux_pointer))malloc\
      ((unsigned)(MININSTACK)*sizeof(struct CONCAT2(_type_,_aux_pointer_struct)));\
  CONCAT2(_type_,_stack).firstfree= (CONCAT2(_type_,_stack).piles[CONCAT2(_type_,_stack).nombre_de_piles]);\
  for (i= 0; i<MININSTACK-1; i++)\
    ((CONCAT2(_type_,_stack).piles[CONCAT2(_type_,_stack).nombre_de_piles])[i]).next=\
      (CONCAT2(_type_,_stack).piles[CONCAT2(_type_,_stack).nombre_de_piles])\
	 +i +1;\
 ((CONCAT2(_type_,_stack).piles[CONCAT2(_type_,_stack).nombre_de_piles])[MININSTACK-1]).next= NULL;\
 CONCAT2(_type_,_stack).nombre_de_piles++;\
 CONCAT2(_type_,_stack).total+= MININSTACK;\
	 if (CONCAT2(_type_,_stack).nombre_de_piles == CONCAT2(_type_,_stack).nombre_de_piles_max)\
 {\
		(CONCAT2(_type_,_stack).nombre_de_piles_max) += STACKINSTACK;\
		CONCAT2(_type_,_stack).piles= (CONCAT2(_type_,_aux_pointer)  *)\
		                                      realloc(CONCAT2(_type_,_stack).piles,\
																					(CONCAT2(_type_,_stack).nombre_de_piles_max) *\
																					sizeof(CONCAT2(_type_,_aux_pointer))\
																					);\
}\
}\
void CONCAT3(init_,_type_,_stack)()\
{\
  int i;\
  CONCAT2(_type_,_stack).firstfree= \
    CONCAT2(_type_,_stack).pile= (CONCAT2(_type_,_aux_pointer))malloc\
      ((unsigned)MININSTACK*sizeof(struct CONCAT2(_type_,_aux_pointer_struct)));\
  CONCAT2(_type_,_stack).nombre_de_piles=1;\
	CONCAT2(_type_,_stack).nombre_de_piles_max=STACKINSTACK;\
	CONCAT2(_type_,_stack).piles=(CONCAT2(_type_,_aux_pointer)  *)malloc((unsigned)STACKINSTACK * \
																																			 sizeof(CONCAT2(_type_,_aux_pointer)));\
 CONCAT2(_type_,_stack).piles[0]= CONCAT2(_type_,_stack).pile;\
  CONCAT2(_type_,_stack).total= MININSTACK;\
  for (i= 0; i<MININSTACK-1; i++)\
    (CONCAT2(_type_,_stack).pile[i]).next=\
      CONCAT2(_type_,_stack).pile + i+ 1;\
  (CONCAT2(_type_,_stack).pile[MININSTACK-1]).next= NULL;\
}\
void CONCAT2(free_,_type_) (f)\
	_type_ * f;\
{\
  if (CONCAT2(_type_,_stack).firstfree)\
    {\
       ((CONCAT2(_type_,_aux_pointer))(f))->next= \
	CONCAT2(_type_,_stack).firstfree;\
    }\
  else\
    ((CONCAT2(_type_,_aux_pointer))(f))->next= NULL;\
  CONCAT2(_type_,_stack).firstfree= (CONCAT2(_type_,_aux_pointer))(f);\
}\
_type_ * CONCAT2(new_,_type_) ()\
{\
  _type_ * t;\
  t= (_type_ *)(CONCAT2(_type_,_stack).firstfree);\
  if (CONCAT2(_type_,_stack).firstfree->next)\
    CONCAT2(_type_,_stack).firstfree= CONCAT2(_type_,_stack).firstfree->next;\
  else\
    CONCAT2(_type_,_expand_struct)();\
      return t; \
}\
void  CONCAT2(_type_,_cleanup)()\
{\
	int i;\
	for (i= 0; i< CONCAT2(_type_,_stack).nombre_de_piles; i++)\
	{\
		int j;\
		for (j= 0; j< MININSTACK-1; j++)\
			(CONCAT2(_type_,_stack).piles[i])[j].next= CONCAT2(_type_,_stack).piles[i] +j +1;\
		if (i != CONCAT2(_type_,_stack).nombre_de_piles -1)\
			(CONCAT2(_type_,_stack).piles[i])[MININSTACK-1].next= (CONCAT2(_type_,_stack).piles[i+1]);\
		else\
			(CONCAT2(_type_,_stack).piles[i])[MININSTACK-1].next= NULL;\
	}\
	CONCAT2(_type_,_stack).firstfree= (CONCAT2(_type_,_stack).piles[0]);\
}\
void  CONCAT2(_type_,_destroy)()\
{\
  int i;\
  for (i= 0; i< CONCAT2(_type_,_stack).nombre_de_piles; i++)\
    {\
			 free((CONCAT2(_type_,_stack).piles[i]));\
    }\
}

#define INIT_STACK(_type_) CONCAT3(init_,_type_,_stack)()
#define NEW(_type_) CONCAT2(new_,_type_) ()
#define DELETE(_type_,xx) CONCAT2(free_,_type_) (xx)
#define CLEANUP(_type_)   CONCAT2(_type_,_cleanup)()
#define DESTROY(_type_)   CONCAT2(_type_,_destroy)()





