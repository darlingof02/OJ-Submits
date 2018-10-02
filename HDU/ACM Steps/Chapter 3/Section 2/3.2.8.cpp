#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int inf=0x7ffffff;
int T;
int n,m;
int map[21][1001];
int dp[21][1001];
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&map[i][j]);
                dp[i][j]=-inf;
            }
        dp[1][1]=map[1][1];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                dp[i+1][j]=max(dp[i+1][j],dp[i][j]+map[i+1][j]); //向下走
                dp[i][j+1]=max(dp[i][j+1],dp[i][j]+map[i][j+1]); //向右走一格
                for(int k=2;k;k++)
                {
                    if(j*k>m) break;
                    dp[i][j*k]=max(dp[i][j*k],dp[i][j]+map[i][j*k]);
                }
            }
        cout<<dp[n][m]<<endl;
    }
    return 0;
}