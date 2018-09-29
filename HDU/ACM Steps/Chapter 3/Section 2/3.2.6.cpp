#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int T,N;
int tower[101][101];
int dp[101][101];
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=i;j++)
            {
                scanf("%d",&tower[i][j]);
            }
        }
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=i;j++)
            {
                dp[i][j]=max(dp[i-1][j-1]+tower[i][j],dp[i-1][j]+tower[i][j]);
            }
        }
        int ans=0;
        for(int i=1;i<=N;i++)
        {
            ans=max(ans,dp[N][i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}