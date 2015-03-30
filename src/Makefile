BINDIR=bin
OBJDIR=obj

BINNAME=lutin
BIN=$(BINDIR)/$(BINNAME)
CLEAN=clean
TEST=test
PREPARE=prepare

DEBUGDIR=Debug
RELEASEDIR=Release
CPP11DEBUGDIR=cpp11Debug
CPP11RELEASEDIR=cpp11Release

DEBUG=debug
RELEASE=release
CPP11DEBUG=cpp11debug
CPP11RELEASE=cpp11release

GPP=clang++
CFLAGS=-Wall -Wextra -Wmissing-braces #-pedantic
INCLUDE=-I"./"

MAINFILE=main.cpp

CPPFILES=$(MAINFILE) Assignment.cpp Automaton.cpp ConcreteStates.cpp Constant.cpp Element.cpp Expression.cpp Instruction.cpp LexicalAnalyzer.cpp NestedExpression.cpp Operation.cpp Program.cpp Read.cpp Rules.cpp State.cpp Symbol.cpp Value.cpp Variable.cpp Word.cpp Write.cpp

OBJ=$(CPPFILES:.cpp=.o)
OBJABS=$(addprefix $(OBJDIR)/,$(OBJ))

OBJDEBUG=$(addprefix $(DEBUGDIR)/,$(OBJABS))
OBJRELEASE=$(addprefix $(RELEASEDIR)/,$(OBJABS))
OBJCPP11DEBUG=$(addprefix $(CPP11DEBUGDIR)/,$(OBJABS))
OBJCPP11RELEASE=$(addprefix $(CPP11RELEASEDIR)/,$(OBJABS))

BINDEBUG=$(addprefix $(DEBUGDIR)/,$(BIN))
BINRELEASE=$(addprefix $(RELEASEDIR)/,$(BIN))
BINCPP11DEBUG=$(addprefix $(CPP11DEBUGDIR)/,$(BIN))
BINCPP11RELEASE=$(addprefix $(CPP11RELEASEDR)/,$(BIN))

FLAGSDEBUG=-g -pg
FLAGSRELEASE=-O2
FLAGSBOOST=-std=c++11 -DUSE_BOOST
FLAGSCPP11=-std=c++11 -stdlib=libc++

LIBS=
LIBSBOOST=-lboost_regex

$(DEBUG): $(OBJDEBUG)
	$(GPP) $(FLAGSDEBUG) $(LIBS) $(LIBSBOOST) -o $(BINDEBUG) $(OBJDEBUG)

$(CPP11DEBUG): $(OBJCPP11DEBUG)
	$(GPP) $(FLAGSDEBUG) $(CPP11FLAGS) $(LIBS) -o $(CPP11BINDEBUG) $(CPP11OBJDEBUG)

$(RELEASE): $(OBJRELEASE)
	$(GPP) $(FLAGSRELEASE) $(LIBS) $(LIBSBOOST) -o $(BINRELEASE) $(OBJRELEASE)

$(CPP11RELEASE): $(OBJCPP11RELEASE)
	$(GPP) $(FLAGSRELEASE) $(CPP11FLAGS) $(LIBS) -o $(BINCPP11RELEASE) $(OBJCPP11RELEASE)

$(CLEAN):
	rm -f $(BINDEBUG) $(BINRELEASE) $(BINCPP11DEBUG) $(BINCPP11RELEASE) $(OBJDEBUG) $(OBJRELEASE) $(OBJCPP11DEBUG) $(OBJCPP11RELEASE)

$(TEST):
	(cd ../Tests;./mktest.sh)

$(DEBUGDIR)/$(OBJDIR)/%.o: %.cpp
	$(GPP) $(CFLAGS) $(FLAGSDEBUG) $(FLAGSBOOST) $(INCLUDE) -c -o $@ $<

$(RELEASEDIR)/$(OBJDIR)/%.o: %.cpp
	$(GPP) $(CFLAGS) $(FLAGSRELEASE) $(FLAGSBOOST) $(INCLUDE) -c -o $@ $<
	
$(CPP11DEBUGDIR)/$(OBJDIR)/%.o: %.cpp
	$(GPP) $(CFLAGS) $(FLAGSCPP11DEBUG) $(INCLUDE) -c -o $@ $<

$(CPP11RELEASEDIR)/$(OBJDIR)/%.o: %.cpp
	$(GPP) $(CFLAGS) $(FLAGSCPP11RELEASE) $(INCLUDE) -c -o $@ $<

