DIR = "../src/"
FILENAME = "ConcreteStates"
STATES_NUM = 40
PREFIX = "/**\n * Project Lutin\n */\n\n\n"

with open("%s%s.h"%(DIR,FILENAME), "w") as headerfile:
	headerfile.write(PREFIX)
	headerfile.write("#ifndef _CONCRETE_STATES_H\n")
	headerfile.write("#define _CONCRETE_STATES_H\n")
	headerfile.write("\n#include \"State.h\"\n\n")

	for x in range(STATES_NUM):
		classname = "State%02d"%x
		headerfile.write("class %s : public State \n{\n"%classname)
		headerfile.write("\tpublic:\n")
		headerfile.write("\t\t%s();\n"%classname)
		headerfile.write("\t\tvirtual ~%s();\n\n"%classname)
		headerfile.write("\t\tvirtual StateResult Transition(Automaton* automaton, Word *word);\n")
		headerfile.write("};\n\n")
	headerfile.write("\n#endif //_CONCRETE_STATES_H\n\n")

with open("%s%s.cpp"%(DIR,FILENAME), "w") as cppfile:
	cppfile.write(PREFIX)
	cppfile.write("#include \"%s.h\"\n"%FILENAME)
		cppfile.write("#include \"Automaton.h\"\n\n")
	
	for x in range(STATES_NUM):
		classname = "State%02d"%x
		cppfile.write("%s::%s() :\n\tState()\n{\n}\n\n"%(classname, classname))
		cppfile.write("%s::~%s() \n{\n}\n\n"%((classname, classname)))
		cppfile.write("StateResult %s::Transition(Automaton* automaton, Word *word) \n{\n"%classname)
		cppfile.write("\treturn SR_ERROR;\n")
		cppfile.write("}\n\n")
		if x != STATES_NUM-1:
			cppfile.write("// %s\n\n"%("-"*64))
