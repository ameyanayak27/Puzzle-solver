#include <iostream>
#include <stdlib.h>
#include "solver.h"
using namespace std;
/*
*clock2.cpp
*@author:Ameya Nayak
*Description in clock2_readme.txt
*@param argc:number of arguments passed at commandline.
*@param argv[]:array that stores the commandline arguments.
*/
class Clock2: public Solver<int>
{
public:
    Solver so;
    int solve(int argc, char *argv[])
    {
     if(argc<5)//checks if the required number of arguments have been passed at runtime.
    {
        cout<<"invalid number of inputs";
        return -1;
    }
    int dial=atoi(argv[1]);//number of dials
    int curr_time=atoi(argv[2]);//current time
    int true_time=atoi(argv[3]);//true time
    vector <int> interval;// Create a vector of intervals
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
//Form new configurations by adding values of vector intervals to current configuratio.
//check if new config.is the goal configuratio.If not push into configuration queue.
 for(int i=4; i<argc; i++)
        interval.push_back(atoi(argv[i]));
    do
    {
        time=so.retrieveConfig(-1);
        if(time==true_time)
            break;
            for(int i=0;i<interval.size();i++)
        {
            //update the time using all the intervals one by one
            a=time+interval[i];
        if(a>dial)
            a=a-dial;
        if(a<1)
            a=dial+a;
        so.pushConfig(time,a);
        //so.pushConfig(time,b);
        }
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
   Clock2 c;
   c.solve(argc,argv);
}
