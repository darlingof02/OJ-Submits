#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m;
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    while(~scanf("%d %d",&n,&m))
    {
        if(!n&&!m) break;
        bool flag=false;
        for(int i=-sqrt(abs(m))-1;i<=sqrt(abs(m))+1;i++)
        {
            if(i==0) continue;
            if(m%i==0)
            {
                int x=i;
                int y=m/i;
                if(x+y==n) 
                {
                    flag=true;
                    break;
                }
            }
        }
        if(!flag)
        {
            cout<<"No"<<endl;
        }
        else
        {
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}