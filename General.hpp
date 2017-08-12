#pragma once
#include <vector>
#include <string>
#include <initializer_list>
class CPU;
typedef void (CPU::*InstructionFunction)(std::initializer_list<int> params);

struct Instruction{
	std::string name;
	int num_params;
	std::vector<int> parameters;
	InstructionFunction func;
	Instruction(const std::string& name, InstructionFunction func, int num_params) : name(name), func(func), num_params(num_params){};
};