INCFLAGS = -I../../machind

KITDIR = ../../sun3/sunOS3

CFLAGS = $(INCFLAGS) -g

LDFLAGS = -g

OBJS =  child.o \
	crypt.o \
	startchild.o \
	parent.o \
	pnopen.o

SRCS =  child.c \
	crypt.c \
	startchild.c \
	parent.c \
	pnopen.c

EXECS = child parent

LIBRARY	= $(KITDIR)/lmgr.a
LIBS = $(LIBRARY)
LINTLIB = $(KITDIR)/llib-llmgr.a.ln

all:	$(EXECS)

child:	child.o crypt.o $(LIBRARY)
	cc $(LDFLAGS) -o child child.o crypt.o $(LIBS)

parent:	parent.o startchild.o pnopen.o crypt.o $(LIBRARY)
	cc $(LDFLAGS) -o parent parent.o startchild.o pnopen.o crypt.o $(LIBS)

lint:;	lint $(INCFLAGS) child.c $(LINTLIB)

clean:;	rm -f $(OBJS) $(EXECS)

$(OBJS):	../../machind/lm_client.h parent.h
