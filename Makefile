PYCFG_FROM_PY := false

MAKE_LOCAL_CFG := make.tmp.mak

PLATFORM := local
COMPILEMODE := debug
LINKMODE := static

CC := gcc

LINK :=

ifneq (,$(wildcard $(MAKE_LOCAL_CFG)))
include $(MAKE_LOCAL_CFG)
else
endif

ifneq (true,$(PYCFG_FROM_PY))
$(error Not from configured source!!)
endif

CINCDIR := inc
CFLAGS := -I$(CINCDIR)
OUTNAME :=

ifeq (debug,$(COMPILEMODE))
CFLAGS += -g
else ifeq (rel,$(COMPILEMODE))
CFLAGS += -O3
endif


LIBDIR := libs/$(PLATFORM)/$(COMPILEMODE)

ifeq (static,$(LINKMODE))
OUTNAME = libihashi.a
LIBOUT := $(LIBDIR)/$(OUTNAME)

LINK = ar rvs $(LIBOUT)

else ifeq (dynamic,$(LINKMODE))
OUTNAME = libihashi.so
LIBOUT := $(LIBDIR)/$(OUTNAME)

CFLAGS += -fPIC

LINK := $(CC) -shared -o $(LIBOUT)

endif


SRCDIR := src
SRCS := $(wildcard $(SRCDIR)/*.c)

OBJDIR := objs/$(PLATFORM)/$(COMPILEMODE)/$(LINKMODE)
OBJS := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

all: $(OBJS) ilink

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

ilink: $(LIBOUT)

$(LIBOUT):
	$(LINK) $(OBJS)