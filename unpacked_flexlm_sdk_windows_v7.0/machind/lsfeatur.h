/******************************************************************************

	    COPYRIGHT (c) 1988, 1998 by Globetrotter Software Inc.
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
 *	Module: $Id: lsfeatur.h,v 1.4 1999/06/23 00:58:47 daniel Exp $
 *
 *	Description: Definitions of feature in-memory data
 *
 *	M. Christiano
 *	2/22/88
 *
 *	Last changed:  12/9/98
 *
 */

/*
 **************************************************************************
 *	NOTE: If you modify this file, you MUST, MUST, update lm_noserver.c
 **************************************************************************
 */
/*
 *	Per-feature user-specified options
 */
typedef struct options {
			struct options *next; /* Link */
			char type;	/* Type of option */
#define RESERVE 1			/* Reserve a feature */
#define INCLUDE 2			/* Only these users allowed */
#define EXCLUDE 3			/* These users disallowed */
#define OPT_BORROW  4			
#define OPT_TRANSPORT  5		
#define OPT_OVERDRAFT  6		/* Reduce overdraft cnt */
#define OPT_MAX  7			/* MAX count for group/feature */
			char type2;	/* Sub-type - what this applies to */
#define OPT_HOST 1			/* applies to host */
#define OPT_USER 2			/* applies to user */
#define RES_USER_v1_0 2				/* Comm v1.0 value */
#define OPT_DISPLAY 3			/* applies to display */
#define OPT_GROUP 4			/* applies to group */
#define OPT_HOST_GROUP 5			/* applies to group */
#define OPT_INTERNET 6			/* applies to client internet address */
#define OPT_PROJECT 7			/* $LM_PROJECT */
			char *name;	/* Name of user/host/group */
			short inet_addr[4]; /* Internet address */
			char addr_type;	/* Internet address type a/b/c */
			int count;	/* MAX option only */
			char *internal_use1; /* for growth */
			char *internal_use2; /* for vendor user */
			} OPTIONS;



/*
 *	The user database for this server
 */

typedef struct _u {
/*
 *		    Links and structure ID.
 */
		    struct _u *next;
		    struct _u *brother;	/* "Brothers" if this feature supports
						       grouping duplicates */
		    OPTIONS *o;	/* Listhead of reservation structs */
		    int serialno;	/* Serial number of this struct */
		    int seq;		/* Sequence # of this struct */
		    int license_handle;	/* 100xserialno + seq%100 */
/*
 *		    Client-supplied data
 */
		    char name[MAX_USER_NAME + 1];
		    char node[MAX_SERVER_NAME + 1];
		    char display[MAX_DISPLAY_NAME + 1];
		    char project[MAX_PROJECT_LEN + 1];
		    char vendor_def[MAX_VENDOR_CHECKOUT_DATA + 1];
		    char version[MAX_VER_LEN+1];  /* Version number */
		    char code[MAX_CRYPT_LEN+1];	/* Code from license file */
		    int count;		/* How many of these licenses he has */
		    int linger;		/* How long license is to linger */
/*
 *		    Derived license information
 */
		    long time;		/* Time user started using feature */
		    long endtime;	/* Time user stopped using feature */
		    int normal_count;	/* How many "normal" licenses */
		    SERVERNUM snum;	/* Which server he is connected to */
		    HANDLE_T handle;
		    HANDLE_T group_handle; 
		    long flags;		/* 32 flags */
#define LM_ULF_METER_BORROW	0x1
#define LM_ULF_METER_BORROW_DECREMENTED	0x2
		    char *internal_use1; /* for growth */
		    char *internal_use2; /* for vendor user */
		  } USERLIST;
		  
USERLIST *f_list();

/*
 *	linked list of old_codes -- for reread 
 */

typedef struct old_codes_list {
				struct old_codes_list *next;
				char code[MAX_CRYPT_LEN+1];
			      } OLD_CODE_LIST;




/*
 *	The feature database
 */

typedef struct feature_list {
/*
 *			Links
 */
			struct feature_list *next;  /* Forward link */
			struct feature_list *last;  /* Backward link */
			struct feature_list *package;  /* If component 
						or LM_PKG_PARENT if 
						it's the enabling feature 
						or 0 if it's neither */
#define LM_PKG_PARENT (FEATURE_LIST *)1L
			USERLIST *u;	/* Current users */
			USERLIST *queue;/* Users waiting */
			OPTIONS *opt;	/* User-specified options */
			OPTIONS *include; /* User-specified INCLUDE list */
			OPTIONS *exclude; /* User-specified EXCLUDE list */
			OPTIONS *b_include;  /* User's BORROW include list */
			OPTIONS *b_exclude;  /* User's BORROW exclude list */
			OPTIONS *res_list;  
			OPTIONS *reread_reserves; /* for reread */

/*
 *			Static data from license
 */
			char *feature;	/* Name of the feature (NULL at end) */
			char version[MAX_VER_LEN+1];	/* Version of feature */
			char expdate[DATE_LEN+1]; /* Expiration date */
			char *vendor_def; /* Vendor-defined string */
			char code[MAX_CRYPT_LEN+1]; /* Encryption code */
			OLD_CODE_LIST *old_codes; /* old codes -- for reread */
			int nlic;	/* Number of licenses available --
					   includes overdraft --  # of "legal" 
					   licenses is nlic - overdraft */
			int overdraft;	/* # of overdraft licenses */
			char *id;	/* Node-lock hostid (pre-conversion) */
			HOSTID *hostid;	/* Node-lock hostid (convert if need) */
/*
 *			Dynamic license data
 */
			short sticky_dup; /* dup_select specified in license */
			short dup_select; /* How does feature count dups */
			int sticky_linger;/* LINGER in license file */
			int linger;	  /* User or license file LINGER
					     specification */
			LS_POOLED *pooled; /* expire once a day */
/*
 *			End-user specified options
 *				(Note that linger is also end-user specified
 *				or from license file)
 */
			int lowwater;	/* Minimum to allow for borrow */
			int timeout;	/* User inactivity timeout */
			int res;	/* # reserved licenses */
			int maxborrow;	/* Maximum BORROW interval (days) */
			int type_mask;	/* from CONFIG lc_type_mask;*/
			int user_based;
			int host_based;
			int minimum;
			int flags;
#define LM_FL_FLAG_USER_BASED_ERR 	 0x1
#define LM_FL_FLAG_UNCOUNTED 		 0x2
#define LM_FL_FLAG_LS_HOST_REMOVED 	 0x4
#define LM_FL_FLAG_REREAD_REMOVED 	 0x8
#define LM_FL_FLAG_ALL_RESERVED        	0x10
#define LM_FL_FLAG_METER_BORROW        	0x20
#define LM_FL_FLAG_SUITE_PARENT        	0x40
#define LM_FL_FLAG_NONSUITE_PARENT      0x80
#define LM_FL_FLAG_PKG_PARENT      	(LM_FL_FLAG_SUITE_PARENT | \
					LM_FL_FLAG_NONSUITE_PARENT)
#define LM_FL_FLAG_SUITE_COMPONENT     0x100
#define LM_FL_FLAG_NONSUITE_COMPONENT  0x200
#define LM_FL_FLAG_COMPONENT  	       (LM_FL_FLAG_SUITE_COMPONENT| \
						LM_FL_FLAG_NONSUITE_COMPONENT)
#if 0
			int policy;	/* from CONFIG lc_policy */
#endif
			char **platforms; /* from CONFIG lc_platforms */
			CONFIG *conf; 	/* first feat that created this fl */
			int conf_dup_group;
		    	char *internal_use1; /* for growth */
		    	char *internal_use2; /* for vendor user */
			} FEATURE_LIST;

#define LM_HOSTID_REQUESTED -9999


extern long ls_currtime;


