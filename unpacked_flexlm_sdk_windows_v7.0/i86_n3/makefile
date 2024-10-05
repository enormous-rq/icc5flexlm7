SRCDIR = ../machind

LD = LINK /nologo /NODEFAULTLIB

INCFLAGS = /I$(SRCDIR)



!ifdef DEBUG
XTRACFLAG=/Zi /D LM_INTERNAL
LDFLAGS=/DEBUG
CNAME=d
!else
XTRACFLAG = 
LDFLAGS =
CNAME=
!endif


XTRALIB =  oldnames.lib wsock32.lib \
        libcmt$(CNAME).lib kernel32.lib user32.lib netapi32.lib advapi32.lib \
        gdi32.lib comdlg32.lib \
        comctl32.lib

#
#	Use XTRAOBJS to define your object files for vendor daemon
#	initialization routines, checkout filter, checkin callback, etc.
#
XTRAOBJS = 


CFLAGS = /nologo /c /O1 $(INCFLAGS) /MT $(XTRACFLAG)

SRCS	= $(SRCDIR)/lsvendor.c

DAEMON = demo.exe

EXECS = lmwin.exe makekey.exe makepkg.exe lmclient.exe lmcrypt.exe lmfeats.exe lmstrip.exe installs.exe

CLIENTLIB	= lmgr.lib 
LIBS		= lmgras.lib lmgrs.lib $(CLIENTLIB)



all: $(EXECS) $(DAEMON) utils


daemon:	$(DAEMON)

$(DAEMON):	$(XTRAOBJS) $(LIBS) lsvendor.obj $(SRCDIR)/lsserver.h \
        		lm_new.obj
        $(LD) $(LDFLAGS) /subsystem:console /out:$(DAEMON) lsvendor.obj lm_new.obj $(XTRAOBJS) \
        			$(LIBS) $(XTRALIB) 

flxtest.obj:  $(SRCDIR)/flxtest.c


lsvendor.obj: lm_new.obj
        $(CC) $(CFLAGS) -I../h lsrvend.c 
    del lsvendor.obj
        ren lsrvend.obj lsvendor.obj
 
lm_new.obj: $(SRCDIR)/lsvendor.c $(SRCDIR)\lm_code.h
        lmrand1 -i $(SRCDIR)/lsvendor.c
        $(CC) /c $(CFLAGS) -I../h lmcode.c
        $(LD) lmrand2.obj lmcode.obj $(CLIENTLIB) $(XTRALIB) /out:lmrand2.exe
        del lm_new.c
        lmrand2.exe $(DAEMON)  -o lm_new.c
        $(CC) $(CFLAGS) -I../h lm_new.c

makekey.exe:	$(SRCDIR)/makekey.c $(SRCDIR)\lm_code.h \
        			$(SRCDIR)/lmclient.h $(CLIENTLIB)
        $(CC) $(CFLAGS) $(SRCDIR)/makekey.c
        $(LD) $(LDFLAGS) /out:makekey.exe makekey.obj $(CLIENTLIB) $(XTRALIB)
        del makekey.obj

makepkg.exe:	$(SRCDIR)/makepkg.c lm_new.obj \
        			$(SRCDIR)/lmclient.h $(CLIENTLIB)
        $(CC) $(LDFLAGS) $(CFLAGS) $(SRCDIR)/makepkg.c
        $(LD) /out:makepkg.exe makepkg.obj $(CLIENTLIB) $(XTRALIB)
        del makepkg.obj

lmcrypt.exe: $(SRCDIR)/lmcrypt.c \
        	$(SRCDIR)/lmclient.h $(SRCDIR)\lm_code.h $(CLIENTLIB)
        $(CC) $(LDFLAGS) $(CFLAGS) $(SRCDIR)/lmcrypt.c
        $(LD) /out:lmcrypt.exe lmcrypt.obj $(CLIENTLIB) $(XTRALIB)

validdat.exe:	$(SRCDIR)/validdat.c  $(CLIENTLIB)
        $(CC) $(CFLAGS) $(SRCDIR)/validdat.c
        $(LD) $(LDFLAGS) /out:validdat.exe validdat.obj $(CLIENTLIB) $(XTRALIB)
        del validdat.obj

lmclient.exe:	$(SRCDIR)/lmclient.c  lm_new.obj \
        			$(CLIENTLIB) lmstrip.exe
        $(CC) $(CFLAGS) $(SRCDIR)/lmclient.c
        $(LD) $(LDFLAGS) /out:lmclient.exe lmclient.obj lm_new.obj $(CLIENTLIB) $(XTRALIB)
        del lmclient.obj

lmsimple.exe:	$(SRCDIR)/lmsimple.c  lm_new.obj \
        			$(CLIENTLIB) lmstrip.exe
        $(CC) $(CFLAGS) $(SRCDIR)/lmsimple.c
        $(LD) $(LDFLAGS) /out:lmsimple.exe lmsimple.obj lm_new.obj $(CLIENTLIB) $(XTRALIB)
        del lmsimple.obj

lmwin.exe:	$(SRCDIR)/lmwin.c  lm_new.obj lmwin.res
        $(CC) $(CFLAGS) /Zi $(SRCDIR)/lmwin.c
        $(LD) $(LDFLAGS) /debug /out:lmwin.exe lmwin.obj lm_new.obj lmwin.res lmgr.lib $(XTRALIB)
        del lmwin.obj

lmflex.exe:	$(SRCDIR)/lmflex.c  lm_new.obj \
        			$(CLIENTLIB) lmstrip.exe
        $(CC) $(CFLAGS) $(SRCDIR)/lmflex.c
        $(LD) $(LDFLAGS) /out:lmflex.exe lmflex.obj lm_new.obj $(CLIENTLIB) $(XTRALIB)
        del lmflex.obj

lmfeats.exe: $(SRCDIR)/lmfeats.c $(CLIENTLIB) 
        $(CC) $(CFLAGS) $(SRCDIR)/lmfeats.c
        $(LD) /out:lmfeats.exe lmfeats.obj $(CLIENTLIB) $(XTRALIB)
        del lmfeats.obj

lmstrip.exe: $(SRCDIR)/lmstrip.c
        $(CC) $(CFLAGS) $(SRCDIR)/lmstrip.c
        $(LD) $(LDFLAGS) /out:lmstrip.exe lmstrip.obj $(XTRALIB)
        del lmstrip.obj

installs.exe: $(SRCDIR)/installs.c
        $(CC) $(CFLAGS) $(SRCDIR)/installs.c
        $(LD) $(LDFLAGS) /out:installs.exe installs.obj $(XTRALIB)
        del installs.obj

lmwin.res: $(SRCDIR)/lmwin.rc
        rc /l 0x409 /r /folmwin.res $(SRCDIR)/lmwin.rc

clean:;	
        ren lmrand2.obj lmrand2.sav
        if exist *.obj del *.obj
        ren lmrand2.sav lmrand2.obj
        if exist makekey.exe del makekey.exe 
        if exist lmrand2.exe del lmrand2.exe
        if exist makepkg.exe del makepkg.exe 
        if exist lmclient.exe del lmclient.exe 
        if exist lmcrypt.exe del lmcrypt.exe 
        if exist lmfeats.exe del lmfeats.exe 
        if exist lmstrip.exe del lmstrip.exe
        if exist $(DAEMON) del $(DAEMON)
        if exist lmcode.c del lmcode.c 
        if exist lmcode.obj del lmcode.obj 
        if exist lmrand2.exe del lmrand2.exe 
        if exist lm_new.c del lm_new.c 
        if exist lm_new.obj del lm_new.obj 
        if exist lsrvend.c del lsrvend.c 
        if exist lmflex.exe del lmflex.exe

veryclean:
        del lmhostid.exe
        del lmver.exe
        del lmcksum.exe
        del lmdown.exe
        del lmremove.exe
        del lmreread.exe
        del lmswitchr.exe
        del lmstat.exe
        del lmdiag.exe
        del lminstall.exe
        del *.p*
        $(MAKE) clean

kitclean:
        del lmcode.c
        del lmcode.obj
        del lmcrypt.obj
        del lmrand2.exe
        del lm_new.c
        del lm_new.obj
        del lsvendor.obj
        del lmhostid.exe
 	del lmver.exe
        del lmcksum.exe
        del lmdown.exe
        del lmhostid.exe
        del lminstall.exe
        del lmremove.exe
        del lmreread.exe
        del  lmswitchr.exe
        del lmstat.exe
        del lmdiag.exe
        del lmver.exe 
        



lmcrypt.obj:	$(SRCDIR)/lmcrypt.c $(SRCDIR)\lm_code.h $(SRCDIR)/lmclient.h
        $(CC) $(CFLAGS) $(SRCDIR)/lmcrypt.c
        del lmcrypt.exe

utils:	lmhostid.exe lmver.exe lmcksum.exe lmdown.exe lmremove.exe lmreread.exe lmswitchr.exe lmstat.exe lmdiag.exe lminstall.exe

lmhostid.exe:   lmutil.exe
    copy lmutil.exe lmhostid.exe

lmver.exe:   lmutil.exe
    copy lmutil.exe lmver.exe

lmcksum.exe:   lmutil.exe
    copy lmutil.exe lmcksum.exe

lmdown.exe:   lmutil.exe
    copy lmutil.exe lmdown.exe

lmremove.exe:   lmutil.exe
    copy lmutil.exe lmremove.exe

lmswitchr.exe:   lmutil.exe
    copy lmutil.exe lmswitchr.exe

lmreread.exe:   lmutil.exe
    copy lmutil.exe lmreread.exe

lmstat.exe:   lmutil.exe
    copy lmutil.exe lmstat.exe

lmdiag.exe:   lmutil.exe
    copy lmutil.exe lmdiag.exe

lminstall.exe:   lmutil.exe
    copy lmutil.exe lminstall.exe

        copy lmutil.exe lmhostid.exe
        copy lmutil.exe lmver.exe
        copy lmutil.exe lmcksum.exe
        copy lmutil.exe lmdown.exe
        copy lmutil.exe lmremove.exe
        copy lmutil.exe lmreread.exe
        copy lmutil.exe lmswitchr.exe
        copy lmutil.exe lmstat.exe
        copy lmutil.exe lmdiag.exe
        copy lmutil.exe lminstall.exe

