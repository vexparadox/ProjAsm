#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "General.hpp"
#include "Memory.hpp"

class CPU{
private:
	void move(std::initializer_list<int> params);
protected:
	Memory* memory;
public:
	CPU();
	std::vector<Instruction> possible_instructions;
	void loadProgram(const std::string& filename);
	void runProgram();
};