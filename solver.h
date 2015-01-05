#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <vector>
using namespace std;
/*
*solver.h
*@author: Ameya Nayak
*@author: Salil Rajadhyaksha
*Description in solver_readme.txt
*/
template<class T>
class Solver
{
public:
    // A queue into which all configurations are pushed and then popped if the configuration is not the goal
    queue<T> q;
    //A map which stores all the configurations along with their base configuration
    map<T,T>config;
    // A stack which is used to print solution from initial to goal state
    stack<T>s;
    typename map<T,T>::iterator  it ;
    void pushConfig(T a,T b)
    {
        //check if the config exists in the map
        if(config.find(b)==config.end())
            q.push(b);
        config.insert(std::pair<T,T>(b,a));
    }
    T retrieveConfig(T s)
    {

        if(q.empty())
            return s;
        s=q.front();
        q.pop();
        //return the next configuration
        return s;
    }

    vector<T> solution(T init,T goal )
    {
        typename  map<T,T>::iterator  it = config.find(goal);
        vector<T> a;
        while(true)
        {
            //Trace steps from goal to initial
            s.push(it->first);
            if(init==it->first)
                break;
            it=config.find(it->second);
        }
        cout<<"solution"<<endl;
        while(!s.empty())
        {
            a.push_back(s.top());
            s.pop();
        }
        return a;
    }
};
