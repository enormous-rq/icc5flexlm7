#ifndef PNOPEN_H
#define PNOPEN_H
/******************************************************************************

	    COPYRIGHT (c) 1991 by Globetrotter Software Inc.
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
 *	Module:	%M% v%R%.%L%
 *
 *	Function:
 *
 *	Description: 
 *
 *	Parameters:
 *
 *	Return:
 *
 * 	Author:  Jim McBeath, Globetrotter Software
 *  	6.Aug.90  jimmc  Initial definition
 *
 *	Last changed:  %G%
 *
 */

#ifndef FILE
#include <stdio.h>
#endif

struct pnopen {
	int pid;
	int numfiles;
	FILE **files;
};

extern struct pnopen *pnopen();
extern int pnclose();

#endif PNOPEN_H
