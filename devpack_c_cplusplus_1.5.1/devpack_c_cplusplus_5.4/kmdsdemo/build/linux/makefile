#****************************************************************************
# Makefile for kmdsdemo
#****************************************************************************

# DEBUG can be set to YES to include debugging info, or NO otherwise

# PROFILE can be set to YES to include profiling info, or NO otherwise
PROFILE        := NO

#****************************************************************************

ifeq (YES, ${LDEBUG})
   EXETAIL      := _debug
else
   EXETAIL      :=
endif

#****************************************************************************
# change here
# Targets of the build
#****************************************************************************
OUTPUT := kmdsdemo${EXETAIL}

# setting
# sourcecode path
BASESRCDIR  := ../../
# working path
BASEWRKDIR  := ../../../
#output path
OUTPUTDIR   := ../../bin_linux64/



CC     := gcc
CXX    := g++
LD     := g++
AR     := ar cr
RANLIB := ranlib

DEBUG_CFLAGS     := -Wall -Wno-format -g -DDEBUG -D_DEBUG -D_TEST_
RELEASE_CFLAGS   := -Wall -Wno-unknown-pragmas -Wno-format -O3

DEBUG_CXXFLAGS   := ${DEBUG_CFLAGS}
RELEASE_CXXFLAGS := ${RELEASE_CFLAGS}

LIBPATH = -L${BASEWRKDIR}lib_linux64

ifeq (YES, ${LDEBUG})
BASE_LIBS := -lpthread -ldl ${LIBPATH} \
             -lkmdsapi_debug -ltibrvft64 -ltibrvcm64 -ltibrv64 -lkcbpcli -lkcbpcrypt -lkcxpmq \
             -llcomm_debug
else
BASE_LIBS := -lpthread -ldl ${LIBPATH} \
             -lkmdsapi -ltibrvft64 -ltibrvcm64 -ltibrv64 -lkcbpcli -lkcbpcrypt -lkcxpmq \
             -llcomm
endif

MELDFLAGS := -s

DEBUG_LDFLAGS    := -g
RELEASE_LDFLAGS  := ${MELDFLAGS}

ifeq (YES, ${LDEBUG})
   CFLAGS       := ${DEBUG_CFLAGS}
   CXXFLAGS     := ${DEBUG_CXXFLAGS}
   LDFLAGS      := ${DEBUG_LDFLAGS}
else
   CFLAGS       := ${RELEASE_CFLAGS}
   CXXFLAGS     := ${RELEASE_CXXFLAGS}
   LDFLAGS      := ${RELEASE_LDFLAGS}
endif

ifeq (YES, ${PROFILE})
   CFLAGS   := ${CFLAGS} -pg -O3
   CXXFLAGS := ${CXXFLAGS} -pg -O3
   LDFLAGS  := ${LDFLAGS} -pg
endif



#****************************************************************************
# Preprocessor directives
#****************************************************************************
DEFS := -D_LINUX_ -D_KMDS_LBM_TEST_

#****************************************************************************
# Include paths
#****************************************************************************
INCS := -I${BASEWRKDIR}include

#****************************************************************************
# Makefile code common to all platforms
#****************************************************************************
CFLAGS   := ${CFLAGS}   ${DEFS}
CXXFLAGS := ${CXXFLAGS} ${DEFS}


all: ${OUTPUT}

#****************************************************************************
# Source files
#****************************************************************************
SRCS =  ${BASESRCDIR}src/demo_c.cpp
SRCS += ${BASESRCDIR}src/demo_cplusplus.cpp



##SRCS += $(wildcard ./src/*.cpp)

# Add on the sources for libraries
SRCS := ${SRCS}

OBJS := $(addsuffix .o,$(basename ${SRCS}))

# ${BASEWRKDIR}lib/kdlib/liblcomm${LIBENDNAME}.a

#****************************************************************************
# Output
#****************************************************************************

${OUTPUT}: ${OBJS}
	${LD} -o $@ ${LDFLAGS} ${OBJS}  ${LIBS} ${BASE_LIBS} ${EXTRA_LIBS}
	cp -f ${OUTPUT} ${OUTPUTDIR}${OUTPUT}
	rm -f $@

#****************************************************************************
# common rules
#****************************************************************************

# Rules for compiling source files to object files
%.o : %.cpp
	${CXX} -c ${CXXFLAGS} ${INCS} $< -o $@

%.o : %.c
	${CC} -c ${CFLAGS} ${INCS} $< -o $@

dist:
	bash makedistlinux

clean:
	-rm -f core ${OBJS} ${OUTPUT} ${OUTPUTDIR}${OUTPUT}

cleanobjs:
	-rm -f core ${OBJS}

auto:
	make clean
	make all
	make cleanobjs
