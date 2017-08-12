#include "CPU.hpp"

CPU::CPU(){
	memory = new Memory();
	program_counter = 0;
	possible_instructions.push_back(Instruction("MOV", &CPU::move, 2)); // MOV SRC DEST
	possible_instructions.push_back(Instruction("SAVE", &CPU::save, 2)); // SAVE SRC RDEST
	possible_instructions.push_back(Instruction("LOAD", &CPU::load, 2)); // LOAD RSRC DEST
	possible_instructions.push_back(Instruction("WRITE", &CPU::write, 2)); // WRITE DEST VAL
	possible_instructions.push_back(Instruction("DUMP", &CPU::dump, 0)); // DUMP
	possible_instructions.push_back(Instruction("JMP", &CPU::jump, 1)); // DUMP
}

void CPU::loadProgram(const std::string& filename){
	std::ifstream infile(filename);
	std::istringstream stream;
	int line_number = 0;
    for (std::string line; std::getline(infile, line); ) {
    	stream.clear();
    	stream.str(line);
    	//generate the tokens ( aka split a line by spaces )
		std::vector<std::string> tokens{std::istream_iterator<std::string>{stream}, std::istream_iterator<std::string>{}};

		//if there's actually something there
        if(tokens.size() > 0){

    		//	special case of labels!
    		// these are preproccessed, so aren't added like instructions
    		if(tokens[0] == "LABEL"){
    			//is there an id given?
    			if(tokens.size() < 2){
    				printError("LABELS REQUIRE AN ID!", line_number);
	    			return;
    			}
    			//create a jump point to the previous instruction
    			memory->labels.push_back(Label(std::stoi(tokens[1]), memory->program_instructions.size()));
    			line_number++;
    			continue;
    		}

	        //find the instruction given
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
	    		//create the instruction
	    		std::vector<unsigned int> params;
	    		Instruction temp_ins(*iter);
	    		for(int i = 0; i < (*iter).num_params; i++){
	    			temp_ins.parameters.push_back(std::stoi(tokens[i+1]));
	    		}
	    		//push it back
		    	memory->program_instructions.push_back(temp_ins);
		    	//incremement the line number, used for errors
		    	line_number++;
	    	}
    	}
    }

}

void CPU::printError(const std::string& txt, int line_number){
	std::cout << "Error on line " << line_number+1 << ": " << txt << std::endl;
}

void CPU::runtimeError(const std::string& txt){
	std::cout << "Runtime: " << txt << std::endl;
}

void CPU::printInstruction(const Instruction& ins){
	std::cout << ins.name << " ";
	for(auto& param : ins.parameters){
		std::cout << param << " ";
	}
	std::cout << std::endl;
}

void CPU::runProgram(bool verbose){
	while(program_counter <  memory->program_instructions.size()){
		if(verbose){
			printInstruction(memory->program_instructions[program_counter]);
		}
		bool result = (this->*memory->program_instructions[program_counter].func)(memory->program_instructions[program_counter].parameters);
		if(!result){
			return;
		}
		program_counter++;
	}
}


/*

CPU INSTRUCTIONS

*/


bool CPU::move(const std::vector<unsigned int>& params){
	// MOV SRC DEST
	memory->main_memory[params[1]] = memory->main_memory[params[0]];
	return true;
}

bool CPU::write(const std::vector<unsigned int>& params){
	// WRITE DEST VAL
	memory->main_memory[params[0]] = params[1];
	return true;
}

bool CPU::save(const std::vector<unsigned int>& params){
	// SAVE SRC RDEST
	if(params[1] >= NUM_REGISTERS){
		runtimeError("Register is out of bounds, there are only 0-4");
		return false;
	}
	memory->registers[params[1]] = memory->main_memory[params[0]];
	return true;
}

bool CPU::load(const std::vector<unsigned int>& params){
	// LOAD RSRC DEST
	if(params[1] >= NUM_REGISTERS){
		runtimeError("Register is out of bounds, there are only 0-4");
		return false;
	}
	memory->main_memory[params[1]] = memory->registers[params[0]];
	return true;
}

bool CPU::jump(const std::vector<unsigned int>& params){
	for(const auto& label : memory->labels){
		if(label.id == params[0]){
			program_counter = label.address-1; // has to be -1 because by default it'll +1 after
			return true;
		}
	}
	std::string error(" Failed to find jump label ");
	error.append(std::to_string(params[0]));
	runtimeError(error);
	return false;
}

bool CPU::dump(const std::vector<unsigned int>& params){
	// DUMP
	// prints the memory
	std::cout << "== MEMORY ==" << std::endl;
	for(auto mem : memory->main_memory){
		std::cout << mem << " ";
	}
	std::cout << std::endl;
	std::cout << "== REGISTERS ==" << std::endl;
	for(auto reg : memory->registers){
		std::cout << reg << " ";
	}
	std::cout << std::endl;
	return true;
}