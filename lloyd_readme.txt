Author: Ameya Nayak and Salil Rajadhyaksha
File: lloyd_readme.txt

Class Lloyd inherits class Solver< string >

int solve function:
returns 0 if the Lloyd problem is solved else returns -1
@param argc: no of arguments passed using the command line
@param argv: array of arguments
this function generates the possible next configurations which is then pushed in the queue until the goal is reached.
From a given configuration four configurations are generated , that is, the '.' moves left, right, up and down(if the moves are possible) and the contents of the blocks are exchanged.

example commandline
- - 
 intitial and final configuration to be taken at command line and solution to be printed at console.

- "test.txt"

intitial and final configuration to be taken at command line and solution to be entered into test.txt.

"test.txt" -

intitial and final configuration to be taken from "test.txt" and solution to be entered into console.

"test.txt" "test1.txt"
intitial and final configuration to be taken from "test.txt" and solution to be entered into "test1.txt".



