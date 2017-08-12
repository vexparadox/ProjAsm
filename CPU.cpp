#include "CPU.hpp"

CPU::CPU(){
	memory = new Memory();
	possible_instructions.push_back(Instruction("MOV", &CPU::move, 2));
}

void CPU::loadProgram(const std::string& filename){
	std::ifstream infile(filename);
	std::istringstream stream;
    for (std::string line; std::getline(infile, line); ) {
    	stream.clear();
    	stream.str(line);
    	//generate the tokens
		std::vector<std::string> tokens{std::istream_iterator<std::string>{stream}, std::istream_iterator<std::string>{}};

		//if there's actually something there
        if(tokens.size() > 0){
	        //find the instructions
	    	auto iter = std::find_if(possible_instructions.begin(), possible_instructions.end(), [&](const Instruction& ins){ return tokens[0] == ins.name; });
	    	//the instruction doesn't exist
	    	if(iter == possible_instructions.end()){
	    		std::cout << "ERROR: " << tokens[0] << " IS NOT A VALID INSTRUCTION!" << std::endl;
	    		return;
	    	}else{
	    		//if there's enough instructions
	    		if(tokens.size()-1 < (*iter).num_params){
					std::cout << "ERROR: " << tokens[0] << " REQUIRES " << (*iter).num_params << " PARAMS!" << std::endl;
	    			return;
	    		}
	    		std::vector<int> params;
	    		Instruction temp_ins(*iter);
	    		for(int i = 0; i < (*iter).num_params; i++){
	    			temp_ins.parameters.push_back(std::stoi(tokens[i+1]));
	    		}
		    	memory->program_instructions.push_back(temp_ins);
	    	}
    	}
    }

}

void CPU::runProgram(){
	
}

void CPU::move(std::initializer_list<int> params){

}