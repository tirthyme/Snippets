/*
ID: DeCode
PROG: gift1
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#define cin fin
#define cout fout
using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int n;
    cin>>n;
    vector<string>name(n);
    for(int a=0;a<n;a++)
        cin>>name[a];
    map<string , int>data;

    for(int a=0;a<n;a++)
        data[name[a]]=0;

    for(int a=0;a<n;a++)
    {
        string giver;
        int money,nop;
        cin>>giver>>money>>nop;
        if(nop>0)
        {
            data[giver]=data[giver]-money+(money%nop);
            for(int b=0;b<nop;b++)
            {
                cin>>giver;
                data[giver]+=money/nop;
            }
        }
    }

    for(int a=0;a<n;a++)
    {
        cout<<name[a]<<" "<<data[name[a]]<<"\n";
    }
    return 0;
}