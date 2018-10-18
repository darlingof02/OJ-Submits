#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int score[101];
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&score[i]);
        }
        sort(score+1,score+1+n);
        double ans=0;
        for(int i=2;i<=n-1;i++)
        {
            ans+=score[i];
        }
        ans=(ans*1.0)/((n-2)*1.0);
        printf("%.2f\n",ans);
    }
    return 0;
}