#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        if(a*a+b*b==c*c||a*a+c*c==b*b||b*b+c*c==a*a)
        {
            printf("Scenario #%d:\nyes\n\n",i);
        }
        else
        {
            printf("Scenario #%d:\nno\n\n",i);
        }
    }
    return 0;
}