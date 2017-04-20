/*
ID: DeCode
PROG: friday
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#define cin fin
#define cout fout
using namespace std;
bool isleap(int n)
{
    if(n%100==0)
    {
        if(n%400==0)
            return true;
        else
            return false;
    }
    else if(n%4==0)
        return true;
    return false;
}
int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int n;
    cin>>n;
    int be=0;
    int m[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int d[]={0,0,0,0,0,0,0};
    for(int a=0;a<n;a++)
    {
        if(isleap(1900+a))
            m[1]=29;
        else
            m[1]=28;
        for(int b=0;b<12;b++)
        {
            be%=7;
            d[be]++;
            be+=m[b];
        }
    }
    for(int a=0;a<6;a++)
        cout<<d[a]<<" ";
        cout<<d[6]<<"\n";
    return 0;
}