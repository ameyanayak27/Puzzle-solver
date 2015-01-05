#include <iostream>
#include <stdlib.h>
#include<string>
#include<vector>
#include "solver.h"
using namespace std;
/*
*jug.cpp
*@author:Ameya Nayak
*@author: Salil Rajadhyaksha
*Description in jug_readme.txt
*/
class Jug :public Solver<vector<int> >
{
public:
    Solver so;
    int solve(int argc, char *argv[])
    {
        if(argc<3)
        {
            cout<<"invalid number of inputs";
            return -1;
        }
        vector<int> cap;//vector of capacity of jug
        vector<int> init_copy;//copy of initial config
        vector <int> init;//initial config
        int goal=atoi(argv[1]);
        for(int i=2; i<argc; i++)
        {
            init.push_back(0);
            cap.push_back(atoi(argv[i]));
        }
        init_copy=init;
        so.pushConfig(init,init);
        bool flag=false;
        vector<int> empty;
        empty.push_back(-1);
        do
        {
            vector<int> s=so.retrieveConfig(empty);//base config
            init=s;
            int i;
            for(i=0; i<s.size(); i++)
                if(init[i]==goal||init[i]==-1)
                    flag=true;
            if(flag)
                break;
            //Now onwards init stores the derived configs
            //empty the jugs
            for(i=0; i<s.size(); i++)
            {
                if(init[i]!=0)
                {
                    init[i]=0;
                    so.pushConfig(s,init);
                    init=s;
                }
            }
            //fill the jug
            for(i=0; i<s.size(); i++)
            {
                if(init[i]!=cap[i])
                {
                    init[i]=cap[i];
                    so.pushConfig(s,init);
                    init=s;
                }
            }
            //pour from one to other
            for(i=0; i<s.size(); i++)
                for(int j=0; j<s.size(); j++)
                {
                    if(i!=j)
                    {
                        //if jug j will overflow after content of jug i is added to j
                        if((init[i]+init[j])>cap[j])
                        {
                            int x=init[j];
                            init[j]=cap[j];
                            init[i]=init[i]-(cap[j]-x);
                            so.pushConfig(s,init);
                            init=s;
                        }
                        else
                        {
                            init[j]=init[j]+init[i];
                            init[i]=0;
                            so.pushConfig(s,init);
                            init=s;
                        }
                    }
                }
        }
        while(true);
        //if queue is emoty
        if(init[0]==-1)
        {
            cout<<"not solvable";
            return -1;
        }
        vector<vector<int> > a=so.solution(init_copy,init);
        for(int i=0; i<a.size(); i++)
        {
            for(int j=0; j<a[i].size(); j++)
                cout<<a[i][j]<<" /"<<cap[j]<<"    ";
            cout<<endl;
        }
        return 0;
    }
};
int main(int argc, char *argv[])
{
    Jug so;
    so.solve(argc,argv);
}
