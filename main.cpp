#include "main.hpp"

int main(int argc, char const *argv[]){
	cpu = new CPU();
	if(argc > 1){
		cpu->loadProgram(argv[1]);
	}else{
		cpu->loadProgram("test.txt");
	}
	cpu->runProgram(false);
	return 0;
}