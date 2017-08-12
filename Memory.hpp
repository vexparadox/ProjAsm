#pragma once
#include "General.hpp"
#include <array>
class Memory{
public:
	Memory();
	//the program data
	std::vector<Instruction> program_instructions;
	//themain memory
	std::array<unsigned int, 20> main_memory = {};
	//the labels given, this maps to program_instructions
	std::vector<Label> labels;
};