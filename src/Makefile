BINDIR=bin
OBJDIR=obj

BINNAME=lutin
BIN=$(BINDIR)/$(BINNAME)
CLEAN=clean

DEBUGDIR=Debug2
RELEASEDIR=Release
BOOSTDIR=Debug

DEBUG=debug
RELEASE=release

GPP=clang++
ADDFLAGS=-std=c++11 -stdlib=libc++
CFLAGS=-Wall -Wextra -Wmissing-braces -pedantic
INCLUDE=-I"./"

MAINFILE=main.cpp

CPPFILES=$(MAINFILE) Assignment.cpp Automaton.cpp ConcreteStates.cpp Constant.cpp Element.cpp Expression.cpp Instruction.cpp LexicalAnalyzer.cpp Logger.cpp NestedExpression.cpp Operation.cpp Program.cpp Read.cpp Rules.cpp State.cpp Symbol.cpp Value.cpp Variable.cpp Word.cpp Write.cpp

OBJ=$(CPPFILES:.cpp=.o)
OBJABS=$(addprefix $(OBJDIR)/,$(OBJ))

OBJDEBUG=$(addprefix $(DEBUGDIR)/,$(OBJABS))
OBJRELEASE=$(addprefix $(RELEASEDIR)/,$(OBJABS))
OBJBOOST=$(addprefix $(BOOSTDIR)/,$(OBJABS))

BINDEBUG=$(addprefix $(DEBUGDIR)/,$(BIN))
BINRELEASE=$(addprefix $(RELEASEDIR)/,$(BIN))
BINBOOST=$(addprefix $(BOOSTDIR)/,$(BIN))

FLAGSDEBUG=-g -pg
FLAGSRELEASE=-O2
FLAGSBOOST=-std=c++11 -DUSE_BOOST

LIBS=
LIBSBOOST=-lboost_regex

boost: $(OBJBOOST)
	$(GPP) $(FLAGSBOOST) $(LIBSBOOST) -o $(BINBOOST) $(OBJBOOST)
	
$(DEBUG): $(OBJDEBUG)
	$(GPP) $(ADDFLAGS) $(LIBS) -o $(BINDEBUG) $(OBJDEBUG)

$(RELEASE): $(OBJRELEASE)
	$(GPP) $(ADDFLAGS) $(LIBS) -o $(BINRELEASE) $(OBJRELEASE)

$(CLEAN):
	rm -f $(BINDEBUG) $(BINRELEASE) $(BINBOOST) $(OBJDEBUG) $(OBJRELEASE) $(OBJBOOST)

$(DEBUGDIR)/$(OBJDIR)/%.o: %.cpp
	$(GPP) $(ADDFLAGS) $(CFLAGS) $(FLAGSDEBUG) $(INCLUDE) -c -o $@ $<

$(RELEASEDIR)/$(OBJDIR)/%.o: %.cpp
	$(GPP) $(ADDFLAGS) $(CFLAGS) $(FLAGSRELEASE) $(INCLUDE) -c -o $@ $<
	
$(BOOSTDIR)/$(OBJDIR)/%.o: %.cpp
	$(GPP) $(CFLAGS) $(FLAGSBOOST) $(INCLUDE) -c -o $@ $<
