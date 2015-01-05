Author: Ameya Nayak and Salil Rajadhyaksha
File: jug_readme.txt

Class Jug inherits class Solver< vector<int> >

int solve function:
returns 0 if the jug problem is solved else returns -1
@param argc: no of arguments passed using the command line
@param argv: array of arguments
this function generates the possible next configurations which is then pushed in the queue until the goal is reached.
From a given configuration 3 base configurations are generated , that is, one by one, empty the jug ,fill the jug , pour the contents from 1 jug to another jug. Each base configuration leads to n configurations where n is the nuber of jugs.
Each base configuratoon is compared with the goal. If it matches then the problem is solved and the output is printed, else new configurations are added to the queue and the configuration in the front of the queue becomes the next base configuration.
If all the configurations are examined and the goal is not reached,the given goal configuration cannot be reached from the given intitial configuration.

example parameters.

6 7 8 9 

amount of water to be filled is 6
capacity of jug1 is 7
capacity of jug2 is 8
capacity of jug3 is 9