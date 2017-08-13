#pragma once
#include <vector>
#include <string>
#include <initializer_list>

#define NUM_REGISTERS 5

class CPU;
typedef bool (CPU::*InstructionFunction)(const std::vector<unsigned int>& params);
typedef unsigned char Byte;

struct Label{
	unsigned int address;
	unsigned int id;
	Label(unsigned int id, unsigned int address) : id(id), address(address){};
};

struct Instruction{
	std::string name;
	int num_params;
	std::vector<unsigned int> parameters;
	InstructionFunction func;
	Instruction(const std::string& name, InstructionFunction func, int num_params) : name(name), func(func), num_params(num_params){};
};