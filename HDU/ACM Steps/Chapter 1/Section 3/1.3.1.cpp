#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int M,N;
struct object
{
    int F,J;
    double cost;
}item[1001];
bool cmp(const object &a,const object &b)
{
    return a.cost<b.cost;
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    while(~scanf("%d %d",&M,&N))
    {
        if(N==-1&&M==-1) break;
        double ans=0.000;
        for(int i=1;i<=N;i++)
        {
            scanf("%d %d",&item[i].J,&item[i].F);
            item[i].cost=(item[i].F*1.0)/(item[i].J*1.0);
        }
        sort(item+1,item+1+N,cmp);
        for(int i=1;i<=N;i++)
        {
            if(M-item[i].F>=0)
            {
                M-=item[i].F;
                ans+=(item[i].J*1.0);
            }
            else
            {
                ans+=(item[i].J*1.0)*((M*1.0)/(item[i].F*1.0));
                break;
            }
        }
        printf("%.3f\n",ans);
    }
    return 0;
}