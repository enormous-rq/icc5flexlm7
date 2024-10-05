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
 *	Module: $Id: lmerrors.h,v 1.7 1999/04/08 18:15:47 daniel Exp $
 *
 *	Description: FLEXlm error strings
 *
 *	M. Christiano
 *	12/13/90
 *
 *	Last changed:  12/23/98
 *
 */

			"",				/* No error 0 */
/* NOCONFFILE */	"Cannot find license file",
/* BADFILE */		"Invalid license file syntax",
/* NOSERVER */		"No server for this feature",
/* MAXUSERS */		"Licensed number of users already reached",
/* NOFEATURE */		"No such feature exists",
/* NOSERVICE */		"No port number in license file and \"FLEXlm\" service does not exist",
/* NOSOCKET */		"No socket connection to license manager server",
/* BADCODE */		"Invalid (inconsistent) license key",
/* NOTTHISHOST */	"Invalid host",
/* LONGGONE */		"Feature has expired",
/* BADDATE */		"Invalid date format in license file",
/* BADCOMM */		"Invalid returned data from license server",
/* NO_SERVER_IN_FILE */	"No SERVER lines in license file",
/* BADHOST */		"Cannot find SERVER hostname in network database",
/* CANTCONNECT */	"Cannot connect to license server",
/* CANTREAD */		"Cannot read data from license server",
/* CANTWRITE */		"Cannot write data to license server",
/* NOSERVSUPP */	"License server does not support this feature",
/* SELECTERR */		"Error in select system call",
/* SERVBUSY */		"License server busy (no majority)",
/* OLDVER */		"License file does not support this version",
/* CHECKINBAD */	"Feature checkin failure detected at license server",
/* BUSYNEWSERV */	"License server temporarily busy (new server connecting)",
/* USERSQUEUED */	"Users are queued for this feature",
/* SERVLONGGONE */	"License server does not support this version of this feature",
/* TOOMANY */		"Request for more licenses than this feature supports",
/* CANTREADKMEM */	"Cannot read /dev/kmem",
/* CANTREADVMUNIX */	"Cannot read /vmunix",
/* CANTFINDETHER */	"Cannot find ethernet device",
/* NOREADLIC */		"Cannot read license file",
/* TOOEARLY */		"Feature start date is in the future",
/* NOSUCHATTR */	"No such attribute",
/* BADHANDSHAKE */	"Bad encryption handshake with daemon",
/* CLOCKBAD */		"Clock difference too large between client and server",
/* FEATQUEUE */		"In the queue for this feature",
/* FEATCORRUPT */	"Feature database corrupted in daemon",
/* BADFEATPARAM */	"Duplicate selection mismatch for this feature",
/* FEATEXCLUDE */	"User/host on EXCLUDE list for feature",
/* FEATNOTINCLUDE */	"User/host not on INCLUDE list for feature",
/* CANTMALLOC */	"Cannot allocate dynamic memory",
/* NEVERCHECKOUT */	"Feature was never checked out",
/* BADPARAM */		"Invalid parameter",
/* NOKEYDATA */		"No FLEXlm key data supplied in lm_init() call",
/* BADKEYDATA */	"Invalid FLEXlm key data supplied",
/* FUNCNOTAVAIL */	"FLEXlm function not available in this version",
/* DEMOKIT */		"FLEXlm software is demonstration version",
/* NOCLOCKCHECK */	"Clock setting check not available in daemon",
/* BADPLATFORM */	"FLEXlm platform not enabled",
/* DATE_TOOBIG */	"Date invalid for binary format",
/* EXPIREDKEYS */	"FLEXlm key data has expired",
/* NOFLEXLMINIT */	"FLEXlm not initialized",
/* NOSERVRESP */	"FLEXlm vendor daemon did not respond within timeout interval",
/* CHECKOUTFILTERED */	"Checkout request rejected by vendor-defined checkout filter",
/* NOFEATSET */		"No FEATURESET line in license file",
/* BADFEATSET */	"Incorrect FEATURESET line in license file",
/* CANTCOMPUTEFEATSET */ "Cannot compute FEATURESET data from license file",
/* SOCKETFAIL */ 	"socket() call failed",
/* SETSOCKFAIL */	"setsockopt() call failed",
/* BADCHECKSUM */	"Message checksum failure",
/* SERVBADCHECKSUM */	"Server message checksum failure",
/* SERVNOREADLIC */	"Cannot read license file data from server",
/* NONETWORK */		"Network software (tcp/ip) not available",
/* NOTLICADMIN */	"You are not a license administrator",
/* REMOVETOOSOON */	"lmremove request before the minimum lmremove interval",
/* BADVENDORDATA */	"Unknown VENDORCODE struct type passed to lm_init()",
/* LIBRARYMISMATCH */	"FLEXlm include file/library version mismatch",
/* NONETOBORROW */	"No licenses available to borrow",
/* NOBORROWSUPP */	"",
/* BORROWCORRUPT */	"",
/* LM_BORROWLOCKED */	"Meter already being updated, locked",
/* BAD_TZ */		"Invalid TZ environment variable",
/* OLDVENDORDATA */	"Old VENDORCODE (3-word) struct type passed to lm_init()",
/* LOCALFILTER */	"Local checkout filter rejected request",
/* LM_ENDPATH */	"Attempt to read beyond end of license file path",
/* LM_VMS_SETIMR_FAILED */ "SYS$SETIMR call failed",
/* LM_INTERNAL_ERROR */	"Internal FLEXlm Error - Please report to Globetrotter Software",
/* LM_BAD_VERSION */	"Bad version number - must be floating point number, with no letters",
/* LM_NOADMINAPI */	"FLEXadmin API functions not available",
/* LM_NOFILEOPS */	 "FLEXlm internal error -79",
/* LM_NODATAFILE */	 "FLEXlm internal error -80",
/* LM_NOFILEVSEND */	 "FLEXlm internal error -81",
/* LM_BADPKG */	 	"Invalid PACKAGE line in license file",
/* LM_SERVOLDVER */	"FLEXlm version of client newer than server",
/* LM_USERBASED	*/ 	"USER_BASED license has no specified users -- see server log",
/* LM_NOSERVCAP	*/ 	"License server doesn't support this request",
/* LM_OBJECTUSED */	"License object already in use",
/* LM_MAXLIMIT */	"Checkout exceeds MAX specified in options file",
/* LM_BADSYSDATE */	"System clock has been set back",
/* LM_PLATNOTLIC */	"This platform not authorized by license",
/* LM_FUTURE_FILE */ "Future license file format or misspelling in license file",
/* LM_DEFAULT_SEEDS */ 	"ENCRYPTION_SEEDs are non-unique",
/* LM_SERVER_REMOVED */ "feature removed during lmreread, or wrong SERVER line hostid",
/* LM_POOL */ 		"This feature is available in a different license pool",
/* LM_LGEN_VER */     "Attempt to generate license with incompatible attributes",
/* LM_NOT_THIS_HOST */  "Network connect to THIS_HOST failed",
/* LM_HOSTDOWN */ 	"Server node is down or not responding",
/* LM_VENDOR_DOWN */ 	"The desired vendor daemon is down",
/* LM_CANT_DECIMAL */ 	"This FEATURE line can't be converted to decimal format",
/* LM_BADDECFILE */ 	"The decimal format license is typed incorrectly",
/* LM_REMOVE_LINGER */ 	"Cannot remove a linger license",
/* LM_RESVFOROTHERS */ 	"All licenses are reserved for others",
/* LM_BORROW_ERROR */ 	"A FLEXid borrow error occurred",
/* LM_BORROW_NOCOUNTER*/ "No counters available in borrow meter",
/* LM_BORROWED_ALREADY*/ "Feature already borrowed to local meter",
/* LM_UNBORROWED_ALREADY*/ "Feature already returned to server",
/* LM_SERVER_MAXED_OUT*/ "License server out of network connections",
/* LM_NOBORROWCOMP */ 	"Can't borrow a PACKAGE component",
/* LM_BORROW_METEREMPTY */ "Licenses all borrowed or meter empty",
/* LM_NOBORROWMETER */ 	"No borrow meters found",
/* LM_NODONGLE */ "Can't read dongle: check dongle or driver",
/* LM_NORESLINK */      "lmgr.res, Windows Resource file, not linked" ,
/* LM_NODONGLEDRIVER */ "Missing Dongle Driver" ,
/* LM_FLEXLOCK2CKOUT */ "2 FLEXlock checkouts attempted"
