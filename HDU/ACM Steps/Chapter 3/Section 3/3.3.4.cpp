#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int C;
struct item
{
    int p;  //价格
    int h;  //重量
    int c;  //袋数
};
item rice[101];
int dp[101];
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&C);
    while(C--)
    {
        int n,m;
        scanf("%d %d",&n,&m);  //n：经费金额 m：大米种类
        for(int i=1;i<=m;i++)
        {
            scanf("%d %d %d",&rice[i].p,&rice[i].h,&rice[i].c);
        }
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=m;i++)
            for(int j=n;j>=0;j--)
                for(int k=0;k<=rice[i].c;k++)
                {
                    if(j>=k*rice[i].p)
                    {
                        dp[j]=max(dp[j],dp[j-k*rice[i].p]+k*rice[i].h);
                    }
                }
        cout<<dp[n]<<endl;
    }
    return 0;
}