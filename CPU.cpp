#include "CPU.hpp"

CPU::CPU(){
	memory = new Memory();
	possible_instructions.push_back(Instruction("MOV", &CPU::move, 2)); // MOV SRC DEST
	possible_instructions.push_back(Instruction("WRITE", &CPU::write, 2)); // WRITE DEST VAL
	possible_instructions.push_back(Instruction("DUMP", &CPU::dump, 0)); // DUMP
}

void CPU::loadProgram(const std::string& filename){
	std::ifstream infile(filename);
	std::istringstream stream;
	int line_number = 0;
    for (std::string line; std::getline(infile, line); ) {
    	stream.clear();
    	stream.str(line);
    	//generate the tokens
		std::vector<std::string> tokens{std::istream_iterator<std::string>{stream}, std::istream_iterator<std::string>{}};

		//if there's actually something there
        if(tokens.size() > 0){


    		//special case of labels!
    		if(tokens[0] == "LABEL"){
    			if(tokens.size() < 2){
    				printError("LABELS REQUIRE A NAME!", line_number);
	    			return;
    			}
    			line_number++;
    			continue;
    		}

	        //find the instructions
	    	auto iter = std::find_if(possible_instructions.begin(), possible_instructions.end(), [&](const Instruction& ins){ return tokens[0] == ins.name; });
	    	//the instruction doesn't exist
	    	if(iter == possible_instructions.end()){
	    		std::string error(tokens[0]);
	    		error.append(" IS NOT A VALID INSTRUCTION!");
	    		printError(error, line_number);
	    		return;
	    	}else{
	    		//if there's enough parameters
	    		if(tokens.size()-1 < (*iter).num_params || tokens.size()-1 > (*iter).num_params){
	    			std::string error = tokens[0];
	    			error.append(" REQUIRES ");
	    			error.append(std::to_string((*iter).num_params));
	    			error.append(" PARAMS!");
					printError(error, line_number);
	    			return;
	    		}
	    		std::vector<unsigned int> params;
	    		Instruction temp_ins(*iter);
	    		for(int i = 0; i < (*iter).num_params; i++){
	    			temp_ins.parameters.push_back(std::stoi(tokens[i+1]));
	    		}
		    	memory->program_instructions.push_back(temp_ins);
		    	line_number++;
	    	}
    	}
    }

}

void CPU::printError(const std::string& txt, int line_number){
	std::cout << "Error on line " << line_number+1 << ": " << txt << std::endl;
}

void CPU::runProgram(){
	for(auto& ins : memory->program_instructions){
		(this->*ins.func)(ins.parameters);
	}
}

void CPU::move(const std::vector<unsigned int>& params){
	// MOV SRC DEST
	memory->main_memory[params[1]] = memory->main_memory[params[0]];
}

void CPU::write(const std::vector<unsigned int>& params){
	// WRITE DEST VAL
	memory->main_memory[params[0]] = params[1];
}

void CPU::dump(const std::vector<unsigned int>& params){
	// DUMP
	// prints the memory
	for(auto mem : memory->main_memory){
		std::cout << mem;
	}
	std::cout << std::endl;
}