/******************************************************************************

	    COPYRIGHT (c) 1988, 1994 by Globetrotter Software Inc.
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
 *	Module: $Id: validdat.c,v 1.2 1999/06/26 00:37:49 daniel Exp $
 *
 *	Function: validdat date
 *
 *	Description: Verifies that the date specified is valid.
 *
 *	Parameters:	(char *) date - a trial date
 *
 *	Return:		(int) - 0 - OK, date if valid
 *				BADDATE - date format invalid
 *				DATE_TOOBIG - Year too large for binary format
 *				LONGGONE - Date has expired
 *				-1 - no date specified
 *
 *	M. Christiano
 *	2/18/88
 *
 *	Last changed:  2/10/96
 *
 */

#include "stdio.h"
#include "lmclient.h"

int l_validdate();
void exit();

main(argc, argv)
int argc;
char *argv[];
{
  LM_HANDLE job;

	if (argc < 2)
	{
		(void) printf("Usage: %s trial-date\n", argv[0]);
		exit(-1);
	}
	return(l_validdate(&job, argv[1]));
}
