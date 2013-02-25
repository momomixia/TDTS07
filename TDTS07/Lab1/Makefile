## Variable that points to SystemC installation path
## version 2.1
SYSTEMC = /home/TDTS07/sw/systemc-2.1.v1


# The PROGRAM variable should be the name of the final executable
PROGRAM = trafficlight.x
# List your .cc-files here
SRCS = sensor.cc input_gen.cc monitor.cc traffilight_testbench.cc controller.cc




TARGET_ARCH = gccsparcOS5

LIBDIR = -L. -L.. -L$(SYSTEMC)/lib-$(TARGET_ARCH)
LIBS = -lsystemc -lm
LDFLAGS = -g

CC      = g++
OPT     = -O3
DEBUGFLAG = #-g
#OTHER   = -Wall
#OTHER   = -Wno-deprecated -fexceptions -frtti #-lstdc++#-Wall
OTHER = -Wno-deprecated

CFLAGS = $(DEBUGFLAG) $(OTHER)
EXE = $(PROGRAM)

# List all directories from where you include .h-files
INCDIR= -I. -I.. -I$(SYSTEMC)/include

OBJS = $(SRCS:.cc=.o)


.SUFFIXES: .cc .o .x

# This will link all the object files (divider_testbench.o, divider.o,
# monitor.o, input_gen.o) into an executable called divider.x
$(EXE): $(OBJS)
	$(CC) $(LDFLAGS) $(INCDIR) $(LIBDIR) -o $(EXE) $(OBJS) $(LIBS)


## To build the whole project we must compile each .cc file into a .o
## file, and then link all .o-files into an executable. The rule above
## tells the make tool how to link the object files into an
## executable. To create the object files we need additional rules
## (one for each .cc-file). For each .cc-file we add two lines in the
## make file. The first line consists of a list of one .cc file
## (corresponding to the .o-file beeing created) and possibly a list
## of .h-files. Whenever any of the files in the list has changed, the
## make tool will recompile the object file. The list should be the
## .cc-file beeing compiled, and all the .h-files that are included
## in that .cc-file.

traffilight_testbench.o: traffilight_testbench.cc sensor.h input_gen.h monitor.h controller.h
	$(CC) -c $(CFLAGS) $(INCDIR) traffilight_testbench.cc -o traffilight_testbench.o

sensor.o: sensor.cc sensor.h 
	$(CC) -c $(CFLAGS) $(INCDIR) sensor.cc -o sensor.o

input_gen.o: input_gen.cc input_gen.h 
	$(CC) -c $(CFLAGS) $(INCDIR) input_gen.cc -o input_gen.o

monitor.o: monitor.cc monitor.h 
	$(CC) -c $(CFLAGS) $(INCDIR) monitor.cc -o monitor.o

controller.o: controller.cc controller.h 
	$(CC) -c $(CFLAGS) $(INCDIR) controller.cc -o controller.o


clean: 
	rm -f $(OBJS) $(EXE) *~

#Makefile.deps:
#	$(CC) $(CFLAGS) $(INCDIR) -M $(SRCS) >> Makefile.deps

#include Makefile.deps
