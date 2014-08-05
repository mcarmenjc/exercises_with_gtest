
# A sample Makefile for building Google Test and using it in user
# tests.  Please tweak it to suit your environment and project.  You
# may want to move it to your project's root directory.
#
# SYNOPSIS:
#
#   make [all]  - makes everything.
#   make TARGET - makes the given target.
#   make clean  - removes all files generated by make.

# Please tweak the following variable definitions as needed by your
# project, except GTEST_HEADERS, which you can use in your own targets
# but shouldn't modify.

# Points to the root of Google Test, relative to where this file is.
# Remember to tweak this if you move this file.
GTEST_DIR = ./gtest

# Where to find user code.
SRC = ./src
INC = ./include
OBJ = ./obj
LIB = ./lib

# Flags passed to the preprocessor.
# Set Google Test's header directory as a system directory, such that
# the compiler doesn't generate warnings in Google Test headers.
CPPFLAGS += -isystem $(GTEST_DIR)/include

# Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra -pthread

# All tests produced by this Makefile.  Remember to add new tests you
# created to the list.
TESTS = main_tests

# All Google Test headers.  Usually you shouldn't change this
# definition.
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

# House-keeping build targets.

all : $(TESTS)

clean :
	rm -f $(TESTS) $(LIB)/gtest.a $(LIB)/gtest_main.a $(OBJ)/*.o

# Builds gtest.a and gtest_main.a.

# Usually you shouldn't tweak such internal variables, indicated by a
# trailing _.
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

# For simplicity and to avoid depending on Google Test's
# implementation details, the dependencies specified below are
# conservative and not optimized.  This is fine as Google Test
# compiles fast and for ordinary users its source rarely changes.
$(OBJ)/gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c $(GTEST_DIR)/src/gtest-all.cc -o $(OBJ)/gtest-all.o

$(OBJ)/gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c $(GTEST_DIR)/src/gtest_main.cc -o $(OBJ)/gtest_main.o

$(LIB)/gtest.a : $(OBJ)/gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

$(LIB)/gtest_main.a : $(OBJ)/gtest-all.o $(OBJ)/gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

# Builds a sample test.  A test should link with either gtest.a or
# gtest_main.a, depending on whether it defines its own main()
# function.

$(OBJ)/number.o : $(SRC)/number.cpp $(INC)/number.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(SRC)/number.cpp -o $(OBJ)/number.o

$(OBJ)/array_problems.o : $(SRC)/array_problems.cpp $(INC)/array_problems.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(SRC)/array_problems.cpp -o $(OBJ)/array_problems.o

$(OBJ)/number_test.o : $(SRC)/number_test.cpp $(INC)/number.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(SRC)/number_test.cpp -o $(OBJ)/number_test.o

$(OBJ)/array_problems_test.o : $(SRC)/array_problems_test.cpp $(INC)/array_problems.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(SRC)/array_problems_test.cpp -o $(OBJ)/array_problems_test.o

$(OBJ)/main_tests.o : $(SRC)/main_tests.cpp $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(SRC)/main_tests.cpp -o $(OBJ)/main_tests.o

main_tests : $(OBJ)/number.o $(OBJ)/number_test.o $(OBJ)/array_problems.o $(OBJ)/array_problems_test.o $(OBJ)/main_tests.o $(LIB)/gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@
