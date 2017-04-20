#include <bits/stdc++.h>
using namespace std;

void kmp(string &t, string &p)
{
    int num[p.length()];
    num[0]=0;
    for(int i=1,j=0;i<p.length();i++)
    {
        if(p[i]==p[j])
        {
            j++;
            num[i]=j;
        }
        else
        {
            while(j>0)
            {
               j=num[j-1];
               if(p[i]==p[j])
               {
                   j++;
                   num[i]=j;
                   break;
               }
            }
            if(j==0)
                num[i]=0;
        }
    }
    for(int a=0;a<p.length();a++)
    cout<<num[a]<<" ";
    cout<<endl;
    for(int a=0,b=0;a<t.length();a++)
    {
        if(t[a]==p[b])
        {
            a++;b++;
            int flag=1;
            for(;a<t.length() && b<p.length();a++,b++)
            {
                if(t[a]!=p[b])
                {
                    flag=0;
                    b=num[b];
                    a--;
                    break;
                }
            }
            if(flag)
            {
                cout<<"match found at "<<a-b<<endl;
                b=num[p.length()-1];
                a--;
            }
        }

    }
    return;
}

int main()
{
    string text,pattern;
    cin>>text>>pattern;
    kmp(text,pattern);
    cin>>text;
}
