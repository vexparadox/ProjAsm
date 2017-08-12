#pragma once
#include "General.hpp"
#include <array>
class Memory{
public:
	Memory();
	//the program data
	std::vector<Instruction> program_instructions;
	//the main memory
	std::array<unsigned int, 20> main_memory = {};
	//the registers
	std::array<unsigned int, NUM_REGISTERS> registers = {};
	//the labels given, this maps to program_instructions
	std::vector<Label> labels;
};