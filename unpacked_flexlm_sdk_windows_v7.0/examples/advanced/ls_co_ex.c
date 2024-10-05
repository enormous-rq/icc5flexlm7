/******************************************************************************

	    COPYRIGHT (c) 1994 by Globetrotter Software Inc.
	This software has been provided pursuant to a License Agreement
	containing restrictions on its use.  This software contains
	valuable trade secrets and proprietary information of 
	Globetrotter Software Inc and is protected by law.  It may 
	not be copied or distributed in any form or medium, disclosed 
	to third parties, reverse engineered or used in any manner not 
	provided for in said License Agreement except with the prior 
	written authorization from Globetrotter Software Inc.

 *****************************************************************************/
/*	
 *	Module:	ls_co_ex.c v1.2.0.0
 *
 *	Function: 	ls_co_filter_example
 *
 *	Description: 	example of how to use ls_checkout() and
 *			ls_get_attr().
 *			The tricky part of this is that ls_get_attr()
 *			often returns a type unacceptable to
 *			ls_checkout, and the value
 *			has to be converted, as shown in the example.
 *
 *	Parameters:	none  
 *
 *	Return:		1 -- indication to the vendor daemon that
 *			     this routine has done the ls_checkout call.
 *
 *	D. Birns
 *	9/39/94
 *
 *	Last changed:  2/13/96
 *
 */
#include "lmclient.h"
#include <stdio.h>
#include "ls_attr.h"
#include "lsserver.h"
#include "lm_code.h"

ls_co_filter_example()
{
  char *f;
  char nlic[MAX_LONG_LEN+1], flag[MAX_LONG_LEN+1];
  char *version, dup_sel[MAX_LONG_LEN+1];
  char linger[MAX_LONG_LEN+1];
  char *code;


	CLIENT_DATA *cd;
	int nlicd, flagd, dup_seld, lingerd, serverd;
	ls_get_attr(LS_ATTR_FEATURE, &f);
	ls_get_attr(LS_ATTR_NLIC, &nlicd);
/*
 *	convert to string
 */
	sprintf(nlic, "%d", nlicd);
	ls_get_attr(LS_ATTR_FLAG, &flagd);
/*
 *	convert to string
 */
	sprintf(flag, "%d", flagd);
	ls_get_attr(LS_ATTR_VERSION, &version);
	ls_get_attr(LS_ATTR_CLIENT, &cd);
	ls_get_attr(LS_ATTR_DUP_SEL, &dup_seld);
/*
 *	convert to string
 */
	sprintf(dup_sel, "%d", dup_seld);
	ls_get_attr(LS_ATTR_LINGER, &lingerd);
/*
 *	convert to string
 */
	sprintf(linger, "%d", lingerd);
	ls_get_attr(LS_ATTR_CODE, &code);
	ls_get_attr(LS_ATTR_SERVER, &serverd);
	ls_checkout(f, nlic, flag, cd, version, serverd, dup_sel,
		linger, code);

	return 0; /* this means we've done the ls_checkout call */
}
