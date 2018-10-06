#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m;
int cnt;
int ans;
struct object
{
    int weight;
    int value;
    int count;
};
object item[101];
int dp[100001];
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    while(~scanf("%d %d",&n,&m))
    {
        if(!n&&!m) break;
        cnt=0,ans=0;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&item[i].value);
            item[i].weight=item[i].value;
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&item[i].count);
        }
        for(int i=1;i<=n;i++)
        {
            if(item[i].count*item[i].weight>m)  //完全背包 
            {
                for(int j=item[i].weight;j<=m;j++)
                {
                    dp[j]=max(dp[j],dp[j-item[i].weight]+item[i].value);
                }
            }
            else
            {
                for(int k=1;k<=item[i].count;k<<=1)
                {
                    for(int j=m;j>=k*item[i].weight;j--)
                    {
                        dp[j]=max(dp[j],dp[j-k*item[i].weight]+k*item[i].value);
                    }
                    item[i].count-=k;
                }
                if(item[i].count>0)
                {
                    for(int j=m;j>=item[i].count*item[i].weight;j--)
                    {
                        dp[j]=max(dp[j],dp[j-item[i].count*item[i].weight]+item[i].count*item[i].value);
                    }
                }
            }
        }
        for(int i=1;i<=m;i++)
        {
            if(dp[i]==i) 
            {
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}