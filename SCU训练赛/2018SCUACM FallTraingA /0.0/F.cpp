#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int x,y;
int f(int n){return n*n+n+41;}
bool isPrime(int x)
{
    if(x==1||x==2) return true;
    for(int i=2;i<=sqrt(x)+1;i++)
    {
        if(x%i==0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    while(~scanf("%d %d",&x,&y))
    {
        if(!x&&!y) break;
        bool flag=true;
        for(int i=x;i<=y;i++)
        {
            int num=f(i);
            if(!isPrime(num))
            {
                flag=false;
                break;
            }
        }
        if(!flag)
        {
            cout<<"Sorry"<<endl;
        }
        else
        {
            cout<<"OK"<<endl;
        }
    }
    return 0;
}