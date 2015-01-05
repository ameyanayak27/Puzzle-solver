#include <iostream>
#include<string>
#include<fstream>
#include "solver.h"
using namespace std;
/*
*lloyd.cpp
*@author:Ameya Nayak
*@author: Salil Rajadhyaksha
*Description in lloyd_readme.txt
*@parameter :argCount :the number of parameters passed at commandline.
*@parameter:argv[]:array that stored all the command line arguments.
*/
class Lloyd : public Solver<string>
{
public:
    Solver so;
    int nextconfig(int argCount, char *argv[])
    {
        int row;//number of rows
        int col;//number of columns
        int k=0;
        string s;//input Configuration
        string goal;//Goal
        if(argCount<3||argCount>3)
        {
            cerr<<"Enter Two argument only."<<endl;
            return -1;
        }
        else
        {
            ostream *osp;
            istream *isp;
            ifstream ifs;
            ofstream ofs;
            //sets os to either cout or file name based on command line argument.

            //sets is to either cin of file name based on command line argument.
            if(argv[1][0] == '-' && argv[1][1] == '\0')
            {
                isp = &cin;
            }
            else
            {
                ifs.open(argv[1]);
                isp = &ifs;
            }
            istream &is = *isp;

            if(argv[2][0] == '-' && argv[2][1] == '\0')
            {
                osp = &cout;
            }
            else
            {
                ofs.open(argv[2]);
                osp = &ofs;
            }
            ostream &os = *osp;

            if(argv[1][0] == '-')
            {
                cout << "Enter row  " << endl;
            }
            is >> row;
            if(argv[1][0] == '-')
            {
                cout << "Enter Column  " << endl;
            }
            is >> col;
            if(argv[1][0] == '-')
            {
                cout<<"enter initial config"<<endl;
            }
            string temp;

		
            for(int x=0; x<row; x++)
            {
                if(argv[1][0] == '-')
                {
                    cout<<"row"<<x+1<<":";
                }
                is>>temp;
                s=s+temp;
            }
            int expectedLength=row*col;
	//checks if the initial configuration is valid.
            if(s.length()!=expectedLength)
            {
                cout<<"Invalid Input Initial Configuration!"<<endl;
                return -1;
            }
            if(argv[1][0] == '-')
            {
                cout<<"Enter goal:"<<endl;
            }
            temp="";
            for(int x=0; x<row; x++)
            {
                if(argv[1][0] == '-')
                {
                    cout<<"Row"<<x+1<<":";
                }
                is>>temp;
                goal=goal+temp;
            }
            char currentConfig[row][col];//2D array for string current configuration.
            char clone[row][col];//stores the clone of current configuration.
            so.pushConfig(s,s);
            string a;
            string b;
            a=so.retrieveConfig("empty");
            //while there are no more configurations in the queue.
            while(a!="empty")
            {
                for(int i=0; i<row; i++)
                {
                    string temp="";
                    for(int j=0; j<col; j++)
                    {
                        temp =temp+a[k];
                        currentConfig[i][j]=a[k];
                        clone[i][j]=a[k];
                        k++;
                    }
                }
                //checking for all possiblle config
                for(int i=0; i<row; i++)
                    for(int j=0; j<col; j++)
                    {
                        if(currentConfig[i][j]=='.')
                        {
                            if(j-1>=0)//check left
                            {
                                clone[i][j]=clone[i][j-1];
                                clone[i][j-1]='.';
                                b="";
                                for(int x=0; x<row; x++)
                                    for(int y=0; y<col; y++)
                                        b=b+clone[x][y];
                                so.pushConfig(a,b);
                                if(b==goal)
                                {
                                    cout<<"goal Reached."<<endl;
                                    break;
                                }
                                for(int x=0; x<row; x++)
                                    for(int y=0; y<col; y++)
                                        clone[x][y]=currentConfig[x][y];
                            }
                            if(j+1<col)//check Right
                            {
                                clone[i][j]=clone[i][j+1];
                                clone[i][j+1]='.';
                                b="";
                                for(int x=0; x<row; x++)
                                    for(int y=0; y<col; y++)
                                        b=b+clone[x][y];
                                so.pushConfig(a,b);
                                if(b==goal)
                                {
                                    cout<<"goal Reached."<<endl;
                                    break;
                                }
                                for(int x=0; x<row; x++)
                                    for(int y=0; y<col; y++)
                                        clone[x][y]=currentConfig[x][y];
                            }
                            if(i+1<row)//check below
                            {
                                clone[i][j]=clone[i+1][j];
                                clone[i+1][j]='.';
                                b="";
                                for(int x=0; x<row; x++)
                                    for(int y=0; y<col; y++)
                                        b=b+clone[x][y];
                                so.pushConfig(a,b);
                                if(b==goal)
                                {
                                    cout<<"goal Reached."<<endl;

                                    break;
                                }
                                for(int x=0; x<row; x++)
                                    for(int y=0; y<col; y++)
                                        clone[x][y]=currentConfig[x][y];
                            }
                            if(i-1>=0)//check above
                            {
                                clone[i][j]=clone[i-1][j];
                                clone[i-1][j]='.';
                                b="";
                                for(int x=0; x<row; x++)
                                    for(int y=0; y<col; y++)
                                        b=b+clone[x][y];
                                so.pushConfig(a,b);
                                if(b==goal)
                                {
                                    cout<<"goal Reached."<<endl;
                                    break;
                                }
                                for(int x=0; x<row; x++)
                                    for(int y=0; y<col; y++)
                                        clone[x][y]=currentConfig[x][y];
                            }
                        }
                        if(b==goal)
                            break;
                    }
                a=so.retrieveConfig("empty");
                k=0;
                if(b==goal)
                    break;
            }
//if all the configurations in the queue are checked and goal not reached.Solution not possible.
            if(a.compare("empty")==0&&b!=goal)
            {
                cout<<"not solvable"<<endl;
                return -1;
            }
	//retreive the solution vector and print.
            vector<string> sol;
            sol=so.solution(s,goal);
            //print solution
            for(int i=0; i<sol.size(); i++)
                os<<sol[i]<<endl;
        }
        return 0;
    }
};
int main(int argCount, char *argv[])
{
    Lloyd a;
    a.nextconfig(argCount,argv);
}
