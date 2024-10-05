/******************************************************************************

	    COPYRIGHT (c) 1995 by Globetrotter Software Inc.
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
 *	Description: 	Example Vendor-defined hostid implementation for FLEXlm
 *
 *	Parameters:	(misc)
 *
 *	Return:		(misc)
 *
 *	M. Christiano
 *	2/19/96
/*
 *	x_flexlm_newid -- call this function just after lc_init()
 *			  from your application, and also in your
 *		 	  license generator (e.g., lmcrypt.c), and
 *			  your vendor daemon.  To do this in the vendor
 *			  daemon, add the following to lsvendor.c:
 *	
 *			  void x_flexlm_newid();
 *			  void (*ls_user_init1)() = x_flexlm_newid;
 *
 *			  On Windows, the first line looks like:
 *			      void _stdcall x_flexlm_newid();
 *	
 *
 *			  All programs that call this function MUST
 *			  have  a variable (LM_HANDLE *) lm_job that points
 *			  to the current job.  If your job handle is not
 *			  called lm_job, make one that points to it.
 */


#include "lmclient.h"
#include "lm_attr.h"
#include "string.h"

extern LM_HANDLE *lm_job; 	/* This must be the current job! */

#define OURTYPE HOSTID_VENDOR+1
#define OURSTRING "EXAMPLE_HOSTID"
#define OUR_FIXED_ID "1234"		/* This example returns only 1 hostid */


/*
 *      x_flexlm_gethostid() - Callback to get the vendor-defined hostid.
 *		(Sorry about all the windows types for this function...)
 */
 
HOSTID *
#ifdef PC
LM_CALLBACK_TYPE
#endif /* PC */
/*
 *	IMPORTANT NOTE:  This function MUST call l_new_hostid() for
 *			a hostid struct on each call.
 *			If more than one hostid of a type is
 *			found, then call l_new_hostid for each 
 *			and make into a list using the `next' field.
 */
x_flexlm_gethostid(idtype)
short idtype;
{
	HOSTID *h = l_new_hostid();
 
	memset(h, 0, sizeof(HOSTID));
        if (idtype == OURTYPE)
        {
                h->type = OURTYPE;
 
                strncpy(h->id.vendor, OUR_FIXED_ID, MAX_HOSTID_LEN);
		h->id.vendor[MAX_HOSTID_LEN] = 0;
                return(h);
        }
        return((HOSTID *) NULL);
}

 

void
x_flexlm_newid(id)
HOSTID *id;
{
  LM_VENDOR_HOSTID h;
  int rc;

	 memset(&h, 0, sizeof (h));
	 h.label = OURSTRING;
	 h.hostid_num = OURTYPE;
	 h.case_sensitive = 0;
	 h.get_vendor_id = x_flexlm_gethostid;
	 if (lc_set_attr(lm_job, LM_A_VENDOR_ID_DECLARE, (LM_A_VAL_TYPE) &h))
		 lc_perror( lm_job, "LM_A_VENDOR_ID_DECLARE FAILED");
}
