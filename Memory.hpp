#pragma once
#include "General.hpp"
#include <array>
class Memory{
public:
	Memory();
	// the program data
	std::vector<Instruction> program_instructions;
	// the main memory
	std::array<Byte, 255> main_memory = {};
	// the registers
	std::array<Byte, NUM_REGISTERS> registers = {};
	// the accumulator
	Byte accumulator = 0;
	// the labels given, this maps to program_instructions
	std::vector<Label> labels;
};