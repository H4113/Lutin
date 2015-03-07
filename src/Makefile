BINDIR=bin
OBJDIR=obj

BINNAME=lutin
BIN=$(BINDIR)/$(BINNAME)
CLEAN=clean

DEBUGDIR=Debug
RELEASEDIR=Release

DEBUG=debug
RELEASE=release

GPP=clang++
ADDFLAGS=-std=c++11 -stdlib=libc++
CFLAGS=-Wall -Wextra -Wmissing-braces -pedantic
INCLUDE=-I"./"

MAINFILE=main.cpp

CPPFILES=$(MAINFILE) Assignment.cpp Automaton.cpp ConcreteStates.cpp Constant.cpp Element.cpp Expression.cpp Instruction.cpp LexicalAnalyzer.cpp Operation.cpp Program.cpp Read.cpp Rules.cpp State.cpp Value.cpp Variable.cpp Word.cpp Write.cpp

OBJ=$(CPPFILES:.cpp=.o)
OBJABS=$(addprefix $(OBJDIR)/,$(OBJ))

OBJDEBUG=$(addprefix $(DEBUGDIR)/,$(OBJABS))
OBJRELEASE=$(addprefix $(RELEASEDIR)/,$(OBJABS))

BINDEBUG=$(addprefix $(DEBUGDIR)/,$(BIN))
BINRELEASE=$(addprefix $(RELEASEDIR)/,$(BIN))

FLAGSDEBUG=-g -pg
FLAGSRELEASE=-O2

LIBS=

$(DEBUG): $(OBJDEBUG)
	$(GPP) $(ADDFLAGS) $(LIBS) -o $(BINDEBUG) $(OBJDEBUG)

$(RELEASE): $(OBJRELEASE)
	$(GPP) $(ADDFLAGS) $(LIBS) -o $(BINRELEASE) $(OBJRELEASE)

$(CLEAN):
	rm -f $(BINDEBUG) $(BINRELEASE) $(OBJDEBUG) $(OBJRELEASE)

$(DEBUGDIR)/$(OBJDIR)/%.o: %.cpp
	$(GPP) $(ADDFLAGS) $(CFLAGS) $(FLAGSDEBUG) $(INCLUDE) -c -o $@ $<

$(RELEASEDIR)/$(OBJDIR)/%.o: %.cpp
	$(GPP) $(ADDFLAGS) $(CFLAGS) $(FLAGSRELEASE) $(INCLUDE) -c -o $@ $<
