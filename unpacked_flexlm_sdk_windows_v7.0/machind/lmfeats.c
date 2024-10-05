/******************************************************************************

	    COPYRIGHT (c) 1989-1994 by Globetrotter Software Inc.
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
 *	Module: $Id: lmfeats.c,v 1.1 1999/02/03 20:20:09 daniel Exp $
 *
 *	Function: lmfeats
 *
 *	Description: Creates a FEATSET line for a license file
 *
 *	Parameters:	lmfeats daemon [-c license_file]
 *
 *	M. Christiano
 *	10/30/89
 *
 *	Last changed:  2/2/96
 *
 */

#include "lmclient.h"
#include "lm_code.h"
#include "lm_attr.h"
#include <stdio.h>

#ifdef WINNT
#include <process.h>
#endif

#ifdef VMS
extern exit();
#endif

LM_DATA;

LM_CODE(code, ENCRYPTION_SEED1, ENCRYPTION_SEED2, VENDOR_KEY1,
			VENDOR_KEY2, VENDOR_KEY3, VENDOR_KEY4, VENDOR_KEY5);
char *daemon = "";
int quiet = 0;
static void process_args(), usage();

#ifndef VMS             /* None of the VMS compilers likes void mains */
void
#endif /* !VMS */
main(argc, argv)
int argc;
char *argv[];
{
  char *p;

	(void) lm_init(VENDOR_NAME, &code, &lm_job);
	process_args(argc, argv);
	if (!quiet)
		(void) printf("lmfeats - Copyright (C) 1989-1994 Globetrotter Software, Inc.\n");
	p = lc_feat_set(lm_job, daemon, &code, 0);
	if (p)
	  (void) printf("%s %s %s\n", LM_RESERVED_FEATURESET, daemon, 
					lc_feat_set(lm_job, daemon, &code, 0));
	else
	  lm_perror("lm_feat_set");

	exit(_lm_errno);
}

static void
process_args(argc, argv)
int argc;
char *argv[];
{
	while (argc > 1)
	{
	  char *p = argv[1]+1;

                if (*argv[1] == '-') switch (*p)
		{
			case 'c':
				if (argc > 2 && *argv[2] != '-')
				{

					argv++; argc--;
					(void) lm_set_attr(LM_A_DISABLE_ENV, 1);
					(void) lm_set_attr(LM_A_LICENSE_FILE, 
						(LM_A_VAL_TYPE) argv[1]);
				}
				break;

			case 'n':
				quiet++;
				break;

			default:
				break;
		}
		else
		{
			daemon = argv[1];
		}

		argc--; argv++;
	}
	if (*daemon == '\0')
	{
		usage();
		exit(0);
	}
}

static
void
usage()
{
	(void) printf("usage: lmfeats daemon [-c license_file] [-n]\n");
}
