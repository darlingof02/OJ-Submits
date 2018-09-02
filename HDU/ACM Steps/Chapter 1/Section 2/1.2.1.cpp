#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int sum;
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    while(~scanf("%d",&n))
    {
        if(!n) break;
        int x,last;
        sum=last=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            if(x>=last)
            {
                sum+=(x-last)*6;
                sum+=5;
            }
            else
            {
                sum+=(last-x)*4;
                sum+=5;
            }
            last=x;
        }
        cout<<sum<<endl;
    }
    return 0;
}