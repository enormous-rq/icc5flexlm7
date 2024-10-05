/******************************************************************************

	    COPYRIGHT (c) 1992 by Globetrotter Software Inc.
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
 *	Module: $Id: ls_attr.h,v 1.1 1999/02/03 20:20:10 daniel Exp $
 *
 *	Description: 	Vendor daemon attribute tags.
 *
 *	M. Christiano
 *	3/6/92
 *
 *	Last changed:  4/3/92
 *
 */

#define LS_ATTR_FEATURE		1	/* (char *) */
#define LS_ATTR_NLIC		2	/* (int) */
#define LS_ATTR_FLAG		3	/* (int) */
#define LS_ATTR_VERSION		4	/* (char *) */
#define LS_ATTR_CLIENT		5	/* (CLIENT_DATA *) */
#define LS_ATTR_DUP_SEL		6	/* (int) */
#define LS_ATTR_LINGER		7	/* (int) */
#define LS_ATTR_CODE		8	/* (char *) */
#define LS_ATTR_SERVER		9	/* (int) */
