/*
ID: DeCode
PROG: beads
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <vector>
//#define cin fin
//#define cout fout
using namespace std;

int main()
{
	//ifstream fin("beads.in");
	//ofstream fout("beads.out");
	int n,a;
	cin>>n;
	string s;
	char w;
	cin>>s;
	s+=s;
	int val=0,pv=0,pr=n;
	for(int a=0;a<n;a++)
	{
		char z=s[a];
		int flag=0,f2=0;
		int count=0;
		for(int b=a;b<n+a;b++)
		{
			if(f2==0 && z!=s[b])
			{
				pv=count;
				pr=b-1;
				f2=1;
			}
			if(s[b]=='w')
				count++;
			else 
			{
				if(z=='w')
				{
					count++;
					z=s[b];
				}
				else if(s[b]==z)
					count++;
				else
				{
					if(count+pv>val)
						val=count+pv;
					break;
				}
			}
		}
		if(count>n)
			count=n;
		if(count>val)
			val=count;
		if(pr>a)
			a=pr;
	}
	if(val==0 || val>n)
	val=n;
	cout<<val<<endl;
}