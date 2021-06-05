#
# 'make depend' uses makedepend to automatically generate dependencies 
#               (dependencies are added to end of Makefile)
# 'make'        build executable file 'mycc'
# 'make clean'  removes all .o and executable files
#

# define the C compiler to use
CXX = g++

# Needed for coverage: -fprofile-arcs -ftest-coverage
CXXFLAGS = -Wall -g -O2 -DBOOST_TEST_DYN_LINK -fprofile-arcs -ftest-coverage

# define any directories containing header files other than /usr/include
#
INCLUDES = -I. -I/usr/include/boost169

# define any libraries to link into executable:
#   if I want to link in libraries (libx.so or libx.a) I use the -llibname 
#   option, something like (this will link in libmylib.so and libm.so:
LIBS = -lboost_unit_test_framework

LIBPATH = -L/usr/lib64/boost169/

# define the C++ source files
SRCS = fizzbuzz.cpp

# define the C++ object files 
#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#         For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .c of all words in the macro SRCS
# with the .o suffix
#
OBJS = $(SRCS:.cpp=.o)

# define the executable file 
MAIN = fizzbuzzMain
TEST = fizzbuzzTest

#
# The following part of the makefile is generic; it can be used to 
# build any executable just by changing the definitions above and by
# deleting dependencies appended to the file from 'make depend'
#

.PHONY: depend clean

all: $(MAIN) $(TEST)
	@echo $(MAIN) and $(TEST) have been built

$(MAIN): $(OBJS) $(MAIN).cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(MAIN) $(MAIN).cpp $(OBJS) $(LIBS) $(LIBPATH)

$(TEST): $(OBJS) $(TEST).cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(TEST) $(TEST).cpp $(OBJS) $(LIBS) $(LIBPATH)

# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file) 
# (see the gnu make manual section about automatic variables)
.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $<  -o $@

fizzbuzz.o: fizzbuzz.h

clean:
	$(RM) *.o *~ $(MAIN) $(TEST) *.gcda *.gcno *.gcov
