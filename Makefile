#!/usr/bin/make -f
#
# Filename:		Makefile
# Date:			04/30/2020
# Author:		Jason Lim
# Email:		jhl180002@utdallas.edu
# Version:		1.0
# Copyright:		2020, All Rights Reserved
#
# Description: This is a Makefile that will link the Curse library with the .cc files all to create the executable.
 

CXX = g++
CXXFLAGS = -Wall -Wno-write-strings -I /scratch/perkins/include
LDFLAGS = -L /scratch/perkins/lib
LDLIBS = -l cdk -lcurses

EXECFILE = hw6

SRCS = driver6.cc

OBJS = $(SRCS:cc=o)

.PHONY: all clean

all: $(EXECFILE)

$(EXECFILE): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS) $(LDLIBS)


clean:
	rm -f $(OBJS) $(EXECFILE) *.P *~  \

backup:
	@make clean
	@mkdir -p ~/backups; chmod 700 ~/backups
	@$(eval CURDIRNAME := $(shell basename "`pwd`"))
	@$(eval MKBKUPNAME := ~/backups/$(PROJECTNAME)-$(shell date +'%Y.%m.%d-%H:%M:%S').tar.gz)
	@echo
	@echo Writing Backup file to: $(MKBKUPNAME)
	@echo
	@-tar zcfv $(MKBKUPNAME) ../$(CURDIRNAME) 2> /dev/null
	@chmod 600 $(MKBKUPNAME)
	@echo
	@echo Done!

