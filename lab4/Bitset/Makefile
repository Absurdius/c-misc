# Define the compiler and the linker. The linker must be defined since
# the implicit rule for linking uses CC as the linker. g++ can be
# changed to clang++.
CXX = g++
CC  = $(CXX)

DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

# Define preprocessor, compiler, and linker flags. Uncomment the # lines
# if you use clang++ and wish to use libc++ instead of GNU's libstdc++.
# -g is for debugging.
CPPFLAGS =  -std=c++11
CXXFLAGS =  -O0 -Wall -Wextra -pedantic-errors -Wold-style-cast
CXXFLAGS += -std=c++11
CXXFLAGS += -g
CXXFLAGS += $(DEPFLAGS)
LDFLAGS =   -g
#CPPFLAGS += -stdlib=libc++
#CXXFLAGS += -stdlib=libc++
#LDFLAGS +=  -stdlib=libc++

# Targets
PROGS = simplebitsettest bitsettest1 bitsettest2

all: $(PROGS)


# Targets rely on implicit rules for compiling and linking
simplebitset: simplebitset.o
simplebitsettest: simplebitsettest.o simplebitset.o
bitsettest1: bitsettest1.o bitset.o bitreference.o
bitsettest2: bitsettest2.o bitset.o bitreference.o bitsetiterator.h

bitset: bitset.o bitsetiterator.h
bitreference: bitreference.o bitset.o bitsetiterator.h
bitsetiterator: bitsetiterator.h bitreference.o




# Phony targets
.PHONY: all clean

# Standard clean
clean:
	rm -f *.o $(PROGS)

# Include the *.d files
SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)
