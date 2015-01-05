Author: Ameya Nayak and Salil Rajadhyaksha
File: solver_readme.txt

template<class T>
class Solver
Solver is a class template which acts as a common solver for clock, jug and lloyd problem

variables<T>:

queue q: A queue into which all configurations are pushed and then popped if the configuration is not the goal

map config: A map which stores all the configurations along with their base configuration

stack s: A stack which is used to print solution from initial to goal state

It consists of 3 function

1) void pushconfig(T a , T b)
@param a: base config
@param b: derived config
check if config b exists in the map using find function. If not add it to both queue q and map config

2)T retrieveConfig(T s)
@param s: value to be returned by this function, initially equal to a value which is to be returned in case the queue is empty 
if the queue is not empty s stores the value present in the front of the queue. Pop the front element and return s


3)Vector<T> solution(T init, T goal)
@param init:Initial configuration
@param goal: Goal Configuration
In this function we trace the path from goal state to initial state and store it in a stack
The stack pops configuration  in LIFO order which is stored in vector a 
The function returns this vector a. 