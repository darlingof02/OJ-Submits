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
        double sum=0;
        double x=n;
        sum+=x;
        for(int i=2;i<=m;i++)
        {
            x=sqrt(x);
            sum+=x;
        }
        printf("%.2f\n",sum);
    }
    return 0;
}