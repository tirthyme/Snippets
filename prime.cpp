#include<iostream>
#include<vector>
#include<fstream>
#define N 1000001
using namespace std;
int main()
{
    ofstream f("F:\\prime.txt");
    vector<bool>prime(N,true);
    for(long long int a=2;a<=N;a++)
    {
        if(prime[a])
        {
            f<<1<<",";
            for(long long int b=a+a;b<=N;b+=a)
            prime[b]=false;
        }
        else
            f<<0<<",";
    }
    f.close();
}
