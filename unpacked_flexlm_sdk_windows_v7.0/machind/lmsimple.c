/******************************************************************************

	    COPYRIGHT (c) 1995, 1997 by Globetrotter Software Inc.
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
 *	Module: $Id: lmsimple.c,v 1.7 1999/07/03 00:26:47 daniel Exp $
 *
 *	Description: 	Simple API example
 *
 *	D. Birns
 *	11/30/95
 *
 *	Last changed:  11/6/97
 *
 */
#include "lmpolicy.h"
#include <stdio.h>
#define FEATURE "f1"

#ifdef PC
#define LICPATH "license.dat;."
#else
#define LICPATH "@localhost:license.dat:."
#endif /* PC */

main()
{
  char feature[MAX_FEATURE_LEN+1];
  LP_HANDLE *lp_handle;

#ifdef PC
	printf("Enter \"lcm\" to demo new LCM functionality\n");
	printf("Enter \"flexlock\" to demo FLEXlock functionality\n\n");
	printf("Enter \"f1\" to demo floating functionality\n");
	printf("Enter \"f2\" to node-locked functionality\n");
#endif
	printf("Enter feature to checkout [default: \"%s\"]: ", FEATURE);

	fgets(feature, MAX_FEATURE_LEN, stdin); 
	if (*feature == '\n') 
		strcpy(feature, FEATURE);
	else
		feature[strlen(feature)-1] = '\0'; /* truncate */
#ifdef PC
	if (!strcmp(feature, "lcm")) printf("Use key: OR6802-4864392\n");
#endif
/* 
 *      ISVs with high security requirements should not include LM_FLEXLOCK
 *      in lp_checkout()
 */
	if (lp_checkout(LPCODE, LM_RESTRICTIVE|LM_FLEXLOCK, feature, "1.0", 1, 
					LICPATH, &lp_handle))
	{
		lp_perror(lp_handle, "Checkout failed");
		exit(1);
	}
	printf("%s checked out...press return to exit...", feature); 
	getchar();
	lp_checkin(lp_handle); 
}

