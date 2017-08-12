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
	//instructions
	bool move(const std::vector<unsigned int>& params);
	bool write(const std::vector<unsigned int>& params);
	bool jump(const std::vector<unsigned int>& params);
	bool dump(const std::vector<unsigned int>& params);
	bool save(const std::vector<unsigned int>& params);
	bool load(const std::vector<unsigned int>& params);

	//prints
	void printError(const std::string& txt, int line_number);
	void runtimeError(const std::string& txt);
	void printInstruction(const Instruction& ins);
	unsigned int program_counter;
protected:
	Memory* memory;
public:
	CPU();
	std::vector<Instruction> possible_instructions;
	void loadProgram(const std::string& filename);
	void runProgram();
};