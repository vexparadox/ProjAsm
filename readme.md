# Schematic

* Main Memory 256 bytes directly addressed (0-255)
* 5 byte registers (0-4) , 0 is the accumulator
* All memory is 0 at the start of a program

# Instructions
| Opcode      |  Parameter 1  | Parameter 2  | Notes  	  |
|:-------------:|:-------------:|:------------:|:------------:|
|    MOV        | Address source| Address destination | Copies a value from the src to the dest in main memory|
| SAVE      | Address source    |   Register destination    | Copies the value from the src to the destination register|
| LOAD | Register source      |  Address destination | Copies a value from the register src to the dest address in main memory.|
| WRITE | Value      |  Address destination | Writes the raw value to the dest in main memory.|
| ADD 	| Address source      |  NULL | Adds the value at the address source in main memory to the first register.|
| SUB 	| Address source      |  NULL | Subtracts the value at the address source in main memory to the first register.|
| LABEL | Label ID      |  NULL | Creates a jumpable part of the program with an ID.|
| JMP 	| Label ID      |  NULL | Jumps to the corresponding label.|
| DUMP 	| NULL      |  NULL | Writes the memory and registers to STD::OUT.|