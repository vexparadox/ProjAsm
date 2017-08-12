#pragma once
#include <vector>
#include <string>
#include <initializer_list>
class CPU;
typedef void (CPU::*InstructionFunction)(const std::vector<unsigned int>& params);

struct Instruction{
	std::string name;
	int num_params;
	std::vector<unsigned int> parameters;
	InstructionFunction func;
	Instruction(const std::string& name, InstructionFunction func, int num_params) : name(name), func(func), num_params(num_params){};
};