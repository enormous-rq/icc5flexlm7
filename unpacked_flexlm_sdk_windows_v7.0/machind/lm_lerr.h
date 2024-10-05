/******************************************************************************

	    COPYRIGHT (c) 1990, 1998 by Globetrotter Software Inc.
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
 *	Module: $Id: lm_lerr.h,v 1.5 1999/04/02 17:53:14 daniel Exp $
 *
 *	Description: FLEXlm long error strings
 *
 *	D. Birns
 *	4/22/97
 *
 *	Last changed:  12/23/98
 *
 */

/* 0:NOERROR */
" Usually this error message should be ignored.\n\
 It occurs when the FLEXlm error message function was called\n\
 though no error was detected",

/* 1: NOCONFFILE */	

" The license files (or server network addresses) attempted are \n\
 listed below.  Use LM_LICENSE_FILE to use a different license file,\n\
 or contact your software provider for a license file.",

/* BADFILE */		0,
/* NOSERVER */		0,
/* MAXUSERS */		0,
/* NOFEATURE */		0,
/* NOSERVICE */		0,
/* NOSOCKET */		0,
/* BADCODE */		
" The license-key and data for the feature do no match.\n\
 This usually happens when a license file has been altered",
/* NOTTHISHOST */	
" The hostid of this system does not match the hostid\n\
 specified in the license file",
/* LONGGONE */		0,
/* BADDATE */		0,
/* BADCOMM */		0,
/* NO_SERVER_IN_FILE */	0,
/* BADHOST */		
" The lookup for the hostname on the SERVER line in the\n\
 license file failed.  This often happens when NIS or DNS\n\
 or the hosts file is incorrect.  Workaround: Use IP-Address\n\
 (e.g., 123.456.789.123) instead of hostname",
/* CANTCONNECT */	
" The server (lmgrd) has not been started yet, or\n\
 the wrong port@host or license file is being used, or the\n\
 port or hostname in the license file has been changed.",
/* CANTREAD */		
" The license server process appears to be running, but is not\n\
responding.  If this persists, notify the System Administrator.\n\
(The lmgrd and vendor daemon processes should be terminated and restarted.)",
/* CANTWRITE */		0,
/* NOSERVSUPP */	0,
/* SELECTERR */		0,
/* SERVBUSY */		0,
/* OLDVER */		0,
/* CHECKINBAD */	0,
/* BUSYNEWSERV */	0,
/* USERSQUEUED */	0,
/* SERVLONGGONE */	0,
/* TOOMANY */		0,
/* CANTREADKMEM */	0,
/* CANTREADVMUNIX */	0,
/* CANTFINDETHER */	0,
/* NOREADLIC */		0,
/* TOOEARLY */		0,
/* NOSUCHATTR */	0,
/* BADHANDSHAKE */	0,
/* CLOCKBAD */		0,
/* FEATQUEUE */		0,
/* FEATCORRUPT */	0,
/* BADFEATPARAM */	0,
/* FEATEXCLUDE */	0,
/* FEATNOTINCLUDE */	0,
/* CANTMALLOC */	0,
/* NEVERCHECKOUT */	0,
/* BADPARAM */		0,
/* NOKEYDATA */		0,
/* BADKEYDATA */	0,
/* FUNCNOTAVAIL */	0,
/* DEMOKIT */		0,
/* NOCLOCKCHECK */	0,
/* BADPLATFORM */	0,
/* DATE_TOOBIG */	0,
/* EXPIREDKEYS */	0,
/* NOFLEXLMINIT */	0,
/* NOSERVRESP */	0,
/* CHECKOUTFILTERED */	0,
/* NOFEATSET */		0,
/* BADFEATSET */	0,
/* CANTCOMPUTEFEATSET */ 0,
/* SOCKETFAIL */ 	0,
/* SETSOCKFAIL */	0,
/* BADCHECKSUM */	0,
/* SERVBADCHECKSUM */	0,
/* SERVNOREADLIC */	0,
/* NONETWORK */		0,
/* NOTLICADMIN */	0,
/* REMOVETOOSOON */	0,
/* BADVENDORDATA */	0,
/* LIBRARYMISMATCH */	0,
/* NONETOBORROW */	0,
/* NOBORROWSUPP */	0,
/* BORROWCORRUPT */	0,
/* LM_BORROWLOCKED */
" lmutil lmborrow -startupdate was issued but not updated yet.\n\
To override this, stop and restart the license server.\n\
WARNING: overriding may cause loss of licenses.",
/* BAD_TZ */		0,
/* OLDVENDORDATA */	0,
/* LOCALFILTER */	0,
/* LM_ENDPATH */	0,
/* LM_VMS_SETIMR_FAILED */ 0,
/* LM_INTERNAL_ERROR */	0,
/* LM_BAD_VERSION */	0,
/* LM_NOADMINAPI */	0,
/* LM_NOFILEOPS */	0,
/* LM_NODATAFILE */	0,
/* LM_NOFILEVSEND */	0,
/* LM_BADPKG */	 	0,
/* LM_SERVOLDVER */	0,
/* LM_USERBASED	*/ 	0,
/* LM_NOSERVCAP	*/ 	0,
/* LM_OBJECTUSED */	0,
/* LM_MAXLIMIT */	0,
/* LM_BADSYSDATE */	0,
/* LM_PLATNOTLIC */	0,
/* LM_FUTURE_FILE */	
" The file was issued for a later version of FLEXlm than this\n\
 program understands.",
/* LM_DEFAULT_SEEDS */ 	0,
/* LM_SERVER_REMOVED */ 	0, 
/* LM_POOL */
" This is a warning condition.  The server has pooled one or more\n\
 INCREMENT lines into a single pool, and the request was made on\n\
 an INCREMENT line that has been pooled.  If this is reported as an\n\
 error, it's an internal error in FLEXlm",
 /* LM_LGEN_VER */	0,
/* LM_NEED_SERVER_HOSTNAME */	
" The license file indicates THIS_HOST, and the server is not\n\
 running on this host.  If it's running on a different host, \n\
 THIS_HOST should be changed to the correct host.",
/* LM_HOSTDOWN */
" See the system adminstrator about starting the server, or\n\
 make sure the you're referring to the right host (see LM_LICENSE_FILE)",
/* LM_VENDOR_DOWN */ 	
" 1) Check the lmgrd log file, or 2) Try lmreread",
/* LM_CANT_DECIMAL */ 	0,
/* LM_BADDECFILE */ 	0,
/* LM_REMOVE_LINGER */ 	0,
/* LM_RESVFOROTHERS */ 	
" The system administrator has reserved all the licenses for others.\n\
 Reservations are made in the options file. The server must be restarted\n\
 for options file changes to take effect.",
/* LM_BORROW_ERROR */ 	0,
/* LM_BORROW_NOCOUNTER */ 
" The FLEXid borrow counters are all in use. You will need another \n\
 FLEXid which can be obtained from Globetrotter Software \n\
 www.globetrotter.com",
/* LM_BORROWED_ALREADY */ 0,
/* LM_UNBORROWED_ALREADY */ 0,
/* LM_SERVER_MAXED_OUT */
" The vendor daemon can't handle any more users.\n\
See the lmgrd debug log for further information.",
/* LM_NOBORROWCOMP */ 	
0,
/* LM_BORROW_METEREMPTY */ 	
" Either all licenses have been borrowed or the server's borrow \n\
 meter was never initialized with license tokens.",
/* LM_NOBORROWMETER */ 	
" No borrow meters found.  Make sure lmhostid -flexid works.\n\
 If not make sure the dongle is attached, and necessary device\n \
drivers installed.",
/* LM_NODONGLE*/ 	
" Either the hardware dongle is unattached, or the necessary\n\
 software drivers for this dongle type is not installed.",
/* LM_NORESLINK */ 
" When linking Windows binaries, you must link with lmgr.lib as\n\
 well as lmgr.res.",
/* LM_NODONGLEDRIVER */
" In order to read the dongle hostid, the correct driver must be\n\
 installed.  These drivers are available at www.globetrotter.com\n\
 or from your software vendor.",
/* LM_FLEXLOCK2CKOUT */
" Only 1 checkout is allowed with FLEXlock enabled apps.\n\
 Subsequent checkout attempts will fail.  They should be disabled\n\
 if first checkout succeeded in FLEXlock mode."
