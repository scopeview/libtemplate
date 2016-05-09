TOP:=$(shell pwd)
LIBNAME=libtemplate

AS		= $(CROSS_COMPILE)as
LD		= $(CROSS_COMPILE)ld
CC		= $(CROSS_COMPILE)gcc
CXX		= $(CROSS_COMPILE)g++
CPP		= $(CC) -E
AR		= $(CROSS_COMPILE)ar
NM		= $(CROSS_COMPILE)nm
STRIP		= $(CROSS_COMPILE)strip
CFLAGS+=$(DEPFLAGS)
CXXFLAGS+=$(DEPFLAGS) -g
CXXFLAGS+=-I$(TOP)/..
CXXFLAGS+=-std=c++0x
# CXXFLAGS+=-D_GLIBCXX_PROFILE
# CXXFLAGS+=$(pkg-config --clfags gtest)
LDFLAGS+=
# LDFLAGS+=$(pkg-config --libs gtest)
LIB_EXPORT_DIR:=.libs

GTEST_DIR=/home/dd/project/gtest-1.7.0
TEST_CFLAGS+=$(DEPFLAGS)
TEST_CFLAGS+=-I$(TOP)/../
TEST_CXXFLAGS+=$(CXXFLAGS)
TEST_CXXFLAGS+=$(DEPFLAGS)
TEST_CXXFLAGS+=-I$(TOP)/../
TEST_CXXFLAGS+=-I$(GTEST_DIR)/include/
TEST_LDFLAGS+=-L$(GTEST_DIR)/lib/.libs/ -lgtest -pthread
# TEST_LDFLAGS+=-L$(TOP)/$(LIB_EXPORT_DIR) -l$(LIBNAME) -lpcrecpp -lpcre


DEMO_CFLAGS+=$(DEPFLAGS)
DEMO_CFLAGS+=-I$(TOP)/../
DEMO_CXXFLAGS+=-std=c++0x
DEMO_CXXFLAGS+=$(DEPFLAGS)
DEMO_CXXFLAGS+=-I$(TOP)/../
# DEMO_LDFLAGS+=-L$(TOP)/$(LIB_EXPORT_DIR) -l$(LIBNAME) -lpcrecpp -lpcre


DEPDIR:=.deps
DEPFLAGS=-MMD -MP
#DEPFLAGS = -MMD -MF ${DEPDIR}/$*.d -MP
MKDEPDIR = ${MKDIR_P} ${DEPDIR}
MKDIR_P = /bin/mkdir -p

# subdirs
subdirs:=$(shell cd $(TOP); find -type d)
subdirs:=$(patsubst ./%,%,$(subdirs))
# subdirs:=$(shell cd $(TOP); ls -d */)
# subdirs:=$(patsubst %/,%,$(subdirs))
libs-subdirs:=$(filter-out unit_test demo,$(subdirs))
tests-subdirs:=$(filter unit_test,$(subdirs))
demo-subdirs:=$(filter demo,$(subdirs))

# srcs
libs-c-srcs:=$(foreach dir,$(libs-subdirs),$(wildcard $(dir)/*.c))
libs-cpp-srcs:=$(foreach dir,$(libs-subdirs),$(wildcard $(dir)/*.cpp))
tests-c-srcs:=$(foreach dir,$(tests-subdirs),$(wildcard $(dir)/*.c))
tests-cpp-srcs:=$(foreach dir,$(tests-subdirs),$(wildcard $(dir)/*.cpp))
demo-c-srcs:=$(foreach dir,$(demo-subdirs),$(wildcard $(dir)/*.c))
demo-cpp-srcs:=$(foreach dir,$(demo-subdirs),$(wildcard $(dir)/*.cpp))

# objects
libs-c-objects:=$(patsubst %.c,%.o,$(libs-c-srcs))
libs-cpp-objects:=$(patsubst %.cpp,%.o,$(libs-cpp-srcs))
tests-c-objects:=$(patsubst %.c,%.o,$(tests-c-srcs))
tests-cpp-objects:=$(patsubst %.cpp,%.o,$(tests-cpp-srcs))
demo-c-objects:=$(patsubst %.c,%.o,$(demo-c-srcs))
demo-cpp-objects:=$(patsubst %.cpp,%.o,$(demo-cpp-srcs))

libs-objects:=$(libs-c-objects) $(libs-cpp-objects)
tests-objects:=$(tests-c-objects) $(tests-cpp-objects)
demo-objects:=$(demo-c-objects) $(demo-cpp-objects)
objects:=$(libs-objects) $(tests-objects) $(demo-objects)

# dependence
libs-c-dependences:=$(patsubst %.c,%.d,$(libs-c-srcs))
libs-cpp-dependences:=$(patsubst %.cpp,%.d,$(libs-cpp-srcs))
tests-c-dependences:=$(patsubst %.c,%.d,$(tests-c-srcs))
tests-cpp-dependences:=$(patsubst %.cpp,%.d,$(tests-cpp-srcs))
demo-c-dependences:=$(patsubst %.c,%.d,$(demo-c-srcs))
demo-cpp-dependences:=$(patsubst %.cpp,%.d,$(demo-cpp-srcs))

libs-dependences:=$(libs-c-dependences) $(libs-cpp-dependences)
tests-dependences:=$(tests-c-dependences) $(tests-cpp-dependences)
demo-dependences:=$(demo-c-dependences) $(demo-cpp-dependences)
dependences:=$(libs-dependences) $(tests-dependences) $(demo-dependences)

all: lib

$(libs-c-objects): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(libs-cpp-objects): %.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

$(tests-c-objects): %.o: %.c
	$(CC) -c $(TEST_CFLAGS) $< -o $@

$(tests-cpp-objects): %.o: %.cpp
	$(CXX) -c $(TEST_CXXFLAGS) $< -o $@

$(demo-c-objects): %.o: %.c
	$(CC) -c $(DEMO_CFLAGS) $< -o $@

$(demo-cpp-objects): %.o: %.cpp
	$(CXX) -c $(DEMO_CXXFLAGS) $< -o $@

lib:$(libs-objects)

unit_test: $(tests-objects)
	@echo $(subdirs-test)
	$(CXX) $(tests-objects) -o unit_test/test $(TEST_LDFLAGS)

run_unit_test:unit_test
	LD_LIBRARY_PATH=$(GTEST_DIR)/lib/.libs/:$(TOP)/$(LIB_EXPORT_DIR) ./unit_test/test

demo:lib $(demo-objects)
	$(CC) $(demo-objects) -o demo/a $(TEST_LDFLAGS)

run_demo:demo
	LD_LIBRARY_PATH=$(GTEST_DIR)/lib/.libs/:$(TOP)/$(LIB_EXPORT_DIR) ./demo/a

clean:
	rm -rf $(objects) $(dependences) $(LIB_EXPORT_DIR)

.PHONEY: all

-include $(dependences)
