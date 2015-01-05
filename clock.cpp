#include <iostream>
#include <stdlib.h>
#include "solver.h"
using namespace std;
/*
*clock.cpp
*@author:Ameya Nayak
*@author: Salil Rajadhyaksha
*Description in clock_readme.txt
*@param argc:number of arguments passed at commandline.
*@param argv[]:array that stores the commandline arguments.
*/
class Clock: public Solver<int>
{
public:
    Solver so;
    int solve(int argc, char *argv[])
    {
     if(argc!=4)//checks if the required number of arguments have been passed at runtime.
    {
        cout<<"invalid number of inputs";
        return -1;
    }
    int dial=atoi(argv[1]);//number of dials
    int curr_time=atoi(argv[2]);//current time
    int true_time=atoi(argv[3]);//true time
    if(curr_time>dial||true_time>dial)//checks if the arguments passed are valid.
    {
        cout<<"Invalid arguments";
        return -1;
    }
    if(curr_time==atoi(argv[3]))
    {
        cout<<"current time=Actual time";
        return 0;
    }
    int time=0;
    so.pushConfig(curr_time,curr_time);//push the current time as intitial config.
    int a,b,c;
//Form new configurations by adding 1 hr and subtracting 1 hr to current configuratio.
//check if new config.is the goal configuratio.If not push into configuration queue.
    do
    {
        time=so.retrieveConfig(-1);
        if(time==true_time)
            break;
        a=time+1;//move time forward
        b=time-1;//move time backward
        if(a>dial)
            a=1;
        if(b<1)
            b=dial;
        so.pushConfig(time,a);
        so.pushConfig(time,b);
    }
    while(time!=-1);
    if(time==-1&&time!=true_time)
    {
        cout<<"not solvable";//if all the configurations checked but goal not reached.
        return 0;
    }
    vector<int> s=so.solution(curr_time,true_time);
    for(int i=0;i<s.size();i++)
        cout<<s[i]<<endl;
    return 0;
    }
};
int main(int argc, char *argv[])
{
   Clock c;
   c.solve(argc,argv);
}
