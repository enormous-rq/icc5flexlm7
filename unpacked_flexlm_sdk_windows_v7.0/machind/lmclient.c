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
 *	Module: $Id: lmclient.c,v 1.10 1999/07/29 04:29:01 daniel Exp $
 *
 *	Description: 	 Trivial API example: CHECKOUT, CHECKIN and ERRSTRING
 *
 *	D. Birns
 *	Jan 17, 1995
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


#ifdef PC
	printf("Enter \"lcm\" to demo new LCM functionality \n");
	printf("Enter \"flexlock\" to demo FLEXlock functionality\n");
	printf("Enter \"f1\" to demo floating functionality\n");
	printf("Enter \"f2\" to node-locked functionality\n");

#endif
	printf("Enter feature to checkout [default: \"%s\"]: ", FEATURE);

	fgets(feature, MAX_FEATURE_LEN, stdin); 
	if (*feature == '\n') strcpy(feature, FEATURE);
	else feature[strlen(feature)-1] = '\0'; /* truncate */

#ifdef PC
	if (!strcmp(feature, "lcm")) printf("Use key: OR6802-4864392\n");
#endif
/* 
 *      ISVs with high security requirements should not include LM_FLEXLOCK
 *      in CHECKOUT
 */
	if (CHECKOUT(LM_RESTRICTIVE|LM_FLEXLOCK, feature, "1.0", LICPATH))
	{
		PERROR("Checkout failed");
	}
	else
	{
		printf("%s checked out...press return to exit...", feature); 
		getchar();
                CHECKIN(); 
	}
	exit(0);
}
