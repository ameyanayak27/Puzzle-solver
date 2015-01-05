Author: Salil Rajadhyaksha
File: clock_readme.txt

Class Clock inherits class Solver<int>

int solve function:
returns 0 if the clock problem is solved else returns -1
@param argc: no of arguments passed using the command line
@param argv: array of arguments
this function generates the possible next configurations which is then pushed in the queue until the goal is reached.
The intervals by which  the clock can move forward or backward is 1 and -1
from each configuartion, a new configuaration is got by adding the interval value to it.
the new configuration is compared to goal configuration.if it is goal configuration.the solution is printed.Else the new configuration is pushed into the queue of configurations.
if all the configurations are examined and the goal is not reached,the given goal configuration cannot be reached from the given intitial configuration.

example parameters.

100 8 96 

dial is 100
intial postion 8
destination postion 96
