#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Memory.hpp"


struct Instruction{
	std::string name;
	int parameters;
	Instruction(const std::string& name, int parameters) : name(name), parameters(parameters){};
};

struct MemoryInstruction{
	std::vector<int> parameters;
};

class CPU{
protected:
	Memory* memory;
public:
	CPU();
	std::vector<Instruction> possible_instructions;
	void loadProgram(const std::string& filename);
};