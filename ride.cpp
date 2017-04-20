/*
ID: DeCode
PROG: ride
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string c,p;
    fin>>c>>p;
    long long int v1=1,v2=1;
    for(int i=0;i<c.length();i++)
    {
    	v1*=(c[i]-64);
    }
    for(int i=0;i<p.length();i++)
    {
    	v2*=(p[i]-64);
    }
    v1%=47;
    v2%=47;
    if(v1==v2)
    	fout<<"GO\n";
    else
    	fout<<"STAY\n";
    return 0;
}