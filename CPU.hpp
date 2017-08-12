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
	void move(const std::vector<unsigned int>& params);
	void write(const std::vector<unsigned int>& params);
	void dump(const std::vector<unsigned int>& params);
	void printError(const std::string& txt, int line_number);
protected:
	Memory* memory;
public:
	CPU();
	std::vector<Instruction> possible_instructions;
	void loadProgram(const std::string& filename);
	void runProgram();
};