#include "main.hpp"

int main(int argc, char const *argv[]){
	cpu = new CPU();
	cpu->loadProgram("test.txt");
	cpu->runProgram();
	return 0;
}