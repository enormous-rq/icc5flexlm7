/******************************************************************************

	    COPYRIGHT (c) 1988, 1998 by Globetrotter Software Inc.
	This software has been provided pursuant to a License Agreement
	containing restrictions on its use.  This software contains
	valuable trade secrets and proprietary information of 
	Globetrotter Software Inc and is protected, by law.  It may 
	not be copied or distributed in any form or medium, disclosed 
	to third parties, reverse engineered or used in any manner not 
	provided for in said License Agreement except with the prior 
	written authorization from Globetrotter Software Inc.

 *****************************************************************************/
/*
 *	Module:	lsserver.h v1.35.0.0
 *
 *	Description: Local definitions for license manager servers
 *
 *	M. Christiano
 *	2/22/88
 *
 *	Last changed:  11/13/98
 *
 */

#ifndef _LS_SERVER_H_
#define _LS_SERVER_H_

#ifdef getenv
#undef getenv
#define getenv(x) l_getenv(lm_job, x)
#endif /* getenv */
#include "lm_comm.h"
#include <stdio.h>
#include <sys/types.h>
#ifdef USE_WINSOCK
#include <pcsock.h>
#else
#include <netinet/in.h>
#endif
/*
 *	P3090:  BASE_EXIT was based on NSIG which is a number that 
 *		varies across platforms and across OS releases.  
 *		This has caused serious problems when the vendor daemon 
 *		is built with one BASE_EXIT, but lmgrd another.
 *		In particular, redundant servers fail.
 *		Therefore, we're now identifying existing platforms
 *		and hardcoding BASE_EXIT, and all new platforms should
 *		hard-code BASE_EXIT.
 */

/*
 *	BASE_EXIT must be a number higher than the signals available
 *	on the o/s, and low enough that BASE_SIG + <num> is < 255
 *	which is the highest possible exit value on unix.
 */
#ifdef SUNOS4
#define BASE_EXIT 32
#endif /* SUNOS4 */
#ifdef SUNOS5
#ifdef i386
#define BASE_EXIT 44
#else
#define BASE_EXIT 34 /* sparc */
#endif /* i386 */
#endif /* SUNOS5 */
#ifdef UNIXWARE
#define BASE_EXIT 35
#endif /* UNIXWARE */
#ifdef DEC_UNIX_3
#define BASE_EXIT 32
#endif /* ALPHA_OSF */
#ifdef DGX86
#define BASE_EXIT 65
#endif /* DGX86 */
#ifdef SGI
#define BASE_EXIT 65
#endif /* SGI */
#ifdef HP700
#ifdef HP64
#define BASE_EXIT 45
#else
#define BASE_EXIT 31
#endif /* HP64 */
#endif /* HP700 */
#ifdef PMAX
#define BASE_EXIT 32
#endif /* PMAX -- ultrix mips */
#ifdef HP300
#define BASE_EXIT 33
#endif /* HP300 */
#ifdef LINUX
#define BASE_EXIT 32
#endif /* LINUX */
#ifdef NEC
#define BASE_EXIT 32
#endif /* NEC */
#ifdef RS6000 /* ppc also */
#define BASE_EXIT 64
#endif /* RS6000 */
#ifdef SINIX 
#define BASE_EXIT 32
#endif /* SINIX */
#ifdef SCO 
#define BASE_EXIT 32
#endif /* SCO */
#ifdef FREEBSD
#define BASE_EXIT 32
#endif /* FREEBSD */
#ifdef BSDI
#define BASE_EXIT 32
#endif /* BSDI */
#ifdef sony_news
#define BASE_EXIT 32
#endif /* sony_news */
#ifdef TANDEM
#define BASE_EXIT 35
#endif /* sony_news */

#ifdef PC
#define BASE_EXIT 23
#endif /* PC */

#ifdef LYNX 
#define BASE_EXIT 22
#endif /* LYNX */

#ifdef LYNXPPC 
#define BASE_EXIT 24
#endif /* LYNXPPC */

#ifndef BASE_EXIT
	ERROR -- Must define BASE_EXIT
#endif /* BASE_EXIT */


/*
 *	Error exit codes - These are used by the master to tell
 *		what went wrong with the vendor daemon
 */

#define EXIT_BADCONFIG	    BASE_EXIT + 1	/* Bad configuration data */
#define EXIT_WRONGHOST	    BASE_EXIT + 2	/* Invalid host */
#define EXIT_PORT_IN_USE    BASE_EXIT + 3	/* Internet "ADDRESS ALREADY IN USE" */
#define EXIT_NOFEATURES	    BASE_EXIT + 4	/* No features to serve */
#define EXIT_COMM	    BASE_EXIT + 5	/* Communications error */
#define EXIT_DESC	    BASE_EXIT + 6	/* Not enough descriptors to */
							/* re-create pipes */
#define EXIT_NOMASTER	    BASE_EXIT + 7	/* Couldn't find a master */
#define EXIT_SIGNAL	    BASE_EXIT + 8	/* Exited due to some signal */
#define EXIT_SERVERRUNNING  BASE_EXIT + 9	/* Exited because another server */
							    /* was running */
#define EXIT_MALLOC	    BASE_EXIT + 10	/* malloc() failure */
#define EXIT_BICKER	    BASE_EXIT + 11	/* Servers can't agree on who is */
							     /* the master */
#define EXIT_BADDAEMON	    BASE_EXIT + 12	/* DAEMON name doesn't agree between */
						/* daemon and license file */
#define EXIT_CANTEXEC	    BASE_EXIT + 13	/* Child cannot exec requested server */
#define EXIT_REQUESTED	    BASE_EXIT + 14	/* lmgrd requested vendor daemon down */
#define EXIT_EXPIRED	    BASE_EXIT + 15	/* demo version has expired */
#define EXIT_BADCALL	    BASE_EXIT + 16	/* vendor daemon started incorrectly */
#define EXIT_INCONSISTENT   BASE_EXIT + 17	/* vendor daemon consistency error */
#define EXIT_FEATSET_ERROR  BASE_EXIT + 18	/* Feature-set inconsistent */
#define EXIT_BORROW_ERROR   BASE_EXIT + 19	/* Borrow database corrupted */
#define EXIT_NO_LICENSE_FILE BASE_EXIT + 20	/* No license file */
#define EXIT_NO_SERVERS     BASE_EXIT + 20	/* Vendor keys don't support */


typedef unsigned char SERVERNUM;
#define MAX_SERVER_NUM 256		/* Maximum # of servers in a "chain" */

#ifdef MULTIPLE_VD_SPAWN
extern SERVERNUM snum;	/* Our server number */
#endif

#define TRUE 1
#define FALSE 0
#define INCLUDE_DUMP_CMD	    /* Define to include (debugging) dump command */
#define MASTER_TIMEOUT 10	    /* # of seconds to wait for master to respond */
#define TIMERSECS 60                /* Timer to go off to send data to another lmgrd */
#define MASTER_ALIVE (2*TIMERSECS)  /* # seconds to wait for any data from */
				    /* another lmgrd - if we don't get it, 
				      declare the other lmgrd down */

#define CLIENT_FD   0
#define CLIENT_SOCK 1
typedef int HANDLE_T;

#ifdef SUPPORT_FIFO
typedef struct _ls_local_addr {
	int server_write; /* write fd */
	char *name;	/* there are actually two files: with
				 * "cr" or "cw" appended for client read
				 * or client write -- destroyer of
				 * CLIENT_ADDR is responsible for freeing
				 * malloc's memory.  This is the name
				 * that's sent in the original message from
				 * client.
				 */
} LS_LOCAL_DATA;
#endif

typedef union _addr_id  {
			LM_SOCKET	fd;		/* if is_fd */
			struct sockaddr_in sin; 	/* if LM_UDP */
		} ADDR_ID;
	
typedef struct _client_addr {
		ADDR_ID addr; 		/* enough to uniquely identify */
		int is_fd; 		/*boolean -- TRUE if fd address*/
		int transport;          /*LM_TCP, LM_UDP, LM_LOCAL*/
#ifdef SUPPORT_FIFO
		LS_LOCAL_DATA local;
#endif
	} CLIENT_ADDR;

#define MAX_CLIENT_HANDLE sizeof(HANDLE_T) /*(32 bit int)*/

typedef struct group {
			struct group *next;	/* Forward link */
			char *name;	/* Group name */
			char *list;	/* List for INCLUDE, EXCLUDE */
		     } GROUP;

typedef struct client_data {
		CLIENT_ADDR addr;		/* fd / sockaddr*/
		HANDLE_T handle;
		char name[MAX_USER_NAME +1];		/* Username */
		char node[MAX_SERVER_NAME + 1];		/* Node */
		char display[MAX_DISPLAY_NAME + 1];	/* Display */
		char vendor_def[MAX_VENDOR_CHECKOUT_DATA + 1]; /* Changes with
								each checkout */
		short use_vendor_def;		/* Use vendor_def data */
		short inet_addr[4];		/* Internet addr */
		long time;	/* Time started */
		char platform[MAX_PLATFORM_NAME + 1];	/* e.g., sun4_u4 */
		unsigned int lastcomm;	/* Last communications 
					 * received (or heartbeat sent) 
					 * if -1, marked for later deletion
					 */
#define	LS_DELETE_THIS_CLIENT 0xffffffff
		long encryption; /* Comm encryption code */
		int comm_version; /* Client's communication version */
		int comm_revision; /* Client's communication revision */
		int udp_sernum;	 /*For lost or duplicate UDP messages*/
		int udp_timeout;
		char *udp_last_resp; 	/* For lost/duplicate *UDP messages*/
					/* Must be malloc'd -- only for
					 * UDP clients*/
		int tcp_timeout;	
		long pid;		/* client's pid */
		HOSTID *hostids;       /* null-terminated array of
					 * client's hostids */
		char *project;		/* $LM_PROJECT for reportlog */
		short capacity;		/* Multiplier for checkout cnt */
		unsigned char flexlm_ver; /* FLEXlm ver (>= v5) */
		unsigned char flexlm_rev; /* FLEXlm revision (>= v5) */
#ifdef LM_GENERIC_VD
		char *flist;		/* Gets cast to a FEATURE_LIST * by
					   vendor daemon */
		char *gen_sav_msg;	/* used by generic server */
#endif /* GENERIC */
		int curr_cpu_usage[4];	/* Usage numbers */
		int last_logged_cpu_usage[4]; /* Last logged Usage numbers */
#define CPU_USAGE_DEFAULT_DELTA 3 		/* 10ths/sec -- .3 sec */
#define CPU_USAGE_CHECKIN_ONLY	0xffffff	/* no usage with heartbeats */
#define CPU_USAGE_DEFAULT_INTERVAL CPU_USAGE_CHECKIN_ONLY
		GROUP *groups;			/* groups this user */
		GROUP *hostgroups ;		/*   belongs to */
		long flags;
#define CLIENT_FLAG_BADDATE_DETECTED 	0x1
#define CLIENT_FLAG_BORROWER 		0x2
#define CLIENT_FLAG_NOMORE 		0x4
		unsigned short ckout_sernum;
		unsigned long group_id;	
#define NO_GROUP_ID 0xffffffff
		char *sn;

	} CLIENT_DATA;


typedef struct lm_quorum {
				int count;      /* How many active */
				int quorum;     /* How many required */
				int master;	/* Index into list of master */
				int n_order;	/* How many order messages we
						   need before we start */
				int alpha_order; /* Use alphabetical master
						   selection algorithm */
				LM_SERVER *list; /* Who they are */
				int debug;	/* Debug flag */
			  } LM_QUORUM;


typedef struct ls_pooled {
			struct ls_pooled *next;
			char date[DATE_LEN+1]; 
			char code[MAX_CRYPT_LEN+1];
			char *lc_vendor_def;
			LM_CHAR_PTR lc_dist_info;
			LM_CHAR_PTR lc_user_info;
			LM_CHAR_PTR lc_asset_info;      
			LM_CHAR_PTR lc_issuer;
			LM_CHAR_PTR lc_notice;  
			LM_CHAR_PTR parent_featname;
			LM_CHAR_PTR parent_featkey;
			int users; 	/* How many expire at that date */
} LS_POOLED;
			
/*
 *	States involved in connecting to other servers (bitmap)
 */
#define C_NONE 0	/* Not started */
#define C_SOCK 1	/* Socket to other server connected */
#define C_SENT 2	/* (fd1) Socket connected, Msg sent to other master */
#define C_CONNECT1 4	/* (fd1) Connection to other server complete */
#define C_CONNECT2 8	/* (fd2) Other server has established connection */
#define C_CONNECTED 16	/* Completely connected */
#define C_MASTER_READY 32 /* Connection complete, master elected and ready */
#define C_TIMEDOUT 64	/* Connection timed out - don't retry */
#define C_NOHOST 128	/* This host doesn't exist */

/*
 *	Output to error log file
 *
 *	The LOG_INFO macros are used to generate the documentation
 *	on all the LOG calls.  They are always ignored, as far as
 *	the code is concerned.
 */

#define LOGERR(x) \
	{\
		ls_log_prefix(LL_LOGTO_BOTH, LL_ERROR); \
		ls_log_error x;\
	}
#define _LOGERR(x) ls_log_error x ;
#define LOG(x) {ls_log_prefix(LL_LOGTO_ASCII, 0); (void) ls_log_asc_printf x;}
#define LOG_INFO(x)

/*
 *	If LOG_TIME_AT_START is defined, all daemon logging is
 *	done with timestamps at the beginning of the lines, rather
 *	than just certain (important) lines being timestamped at the
 *	end.  LOG_TIME_AT_START became the default in v1.3.
 */
#define LOG_TIME_AT_START	/* Log time @ start of log lines */

/* 
 *	Default directory for lock file and lmgrd info file
 */

#ifdef WINNT 
#define LS_LOCKDIR "C:\\flexlm"
#else
#ifdef BSDI
#define LS_LOCKDIR "/tmp/.flexlm"
#else
#define LS_LOCKDIR "/usr/tmp/.flexlm"
#endif /* BSDI */
#endif /* WINNT */

/*
 *	Output to log without header (for building strings)
 */
#define _LOG(x) { (void) ls_log_asc_printf x; }


extern int dlog_on;
extern LM_SOCKET ls_udp_s;		/* Global UDP socket for reading */
extern int _ls_fifo_fd;		/* Global fifo fd for reading */
extern LM_HANDLE *lm_job;	/* Server's one (and only) job */

#define DLOG(x) { if (dlog_on) \
	  { ls_log_prefix(LL_LOGTO_ASCII, -1); (void) ls_log_asc_printf x; } }
/*
 *	Output to log without header (for building strings)
 */
#define _DLOG(x) { if (dlog_on) { (void) ls_log_asc_printf x; } }

/*
 *	Exchange descriptors so that parent-child communication is happy
 */

#define XCHANGE(_p) { int _t = _p[3]; _p[3] = _p[1]; _p[1] = _t; }

/*
 *	Server's malloc - simply logs an error if malloc fails, and exits
 */

extern char *ls_malloc();
#define LS_MALLOC(x)	ls_malloc((x), __LINE__, __FILE__)

/*
 *	listen() backlog - number of pending connections
 */
#ifdef WINNT
#define LISTEN_BACKLOG 5
#else
#define LISTEN_BACKLOG 50
#endif
/*
 *	Get the time 
 */
/* 
 *	Sun/Vax uses _TIME_ to detect <sys/time.h>, Apollo uses the 
 *	same include file for both <time.h> and <sys/time.h>
 */

#ifndef ITIMER_REAL	
#include <time.h>
#endif
struct tm *ls_gettime();

#include "ls_sprot.h"

#define LS_READ_TIMEOUT 60000 /* 60 seconds */
#endif 	/* _LS_SERVER_H_ */
