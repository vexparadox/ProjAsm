# What is this?
This is a virtual machine that's controlled using a custom set on instructions. It's main purpose is for emulating an assembly-like language and to aid in learning low level programming. 

## What's a virtual machine? 
A virtual machine is an emulation of a computer system. Virtual machines are based on computer architectures and provide functionality of a physical computer. They create computers inside of your computer.

## Is this an operating system?
No, although an operating system could be built using this program, this is not an operating system. An operating system is a program that runs on your computer that performs basic tasks, such as recognizing input from the keyboard, sending output to the display screen, keeping track of files and directories on the storage drives, and controlling peripheral devices, such as printers.

# Usage
 
 * Build with makefile
 * Launch with program file as first parameter
 * Program files are text based, not binary
 * Program files can have any/no file extension
 * Opcodes must be completed with a return line

# Schematic

* Main Memory 256 bytes directly addressed (0-255)
* 5 byte registers (0-4) , 0 is the accumulator
* All memory is 0 at the start of a program

# Instructions
| Opcode      |  Parameter 1  | Parameter 2  | Notes  	  |
|:-------------:|:-------------:|:------------:|:------------:|
| MOV | Address source| Address destination | Copies a value from the src to the dest in main memory|
| SAVE | Address source | Register destination | Copies the value from the src in main memory to the destination register|
| LOAD | Register source | Address destination | Copies a value from the register src to the dest address in main memory.|
| WRITE | Value | Address destination | Writes the raw value to the dest in main memory.|
| ADD | Address source |  NULL | Adds the value at the address source in main memory to the first register.|
| SUB | Address source |  NULL | Subtracts the value at the address source in main memory from the first register.|
| LABEL | Label ID  |  NULL | Creates a jumpable part of the program with an ID.|
| JMP 	| Label ID  |  NULL | Jumps to the corresponding label.|
| DUMP 	| NULL      |  NULL | Writes the memory and registers to STD::OUT.|


# Example programs

## Doubler
This program doubles a number
```
WRITE 20 0
SAVE  0 0
ADD   0
LOAD  0 0
SAVE  1 0
DUMP
```
Output:
```
== MEMORY ==
40 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
== REGISTERS ==
0 0 0 0 0 
```