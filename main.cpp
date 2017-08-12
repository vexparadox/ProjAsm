#include "main.hpp"

int main(int argc, char const *argv[]){
	cpu = new CPU();
	cpu->loadProgram("test.txt");
	return 0;
}