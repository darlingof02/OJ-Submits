#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
int n;
int map[100010][20];
int dp[100010][20];
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    while(~scanf("%d",&n))
    {
        if(!n) break;
        int maxT=0;
        memset(map,0,sizeof(map));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            int x,T;
            scanf("%d %d",&x,&T);
            map[T][x]++;
            maxT=max(maxT,T);
        }
        for(int i=maxT;i>=0;i--)
            for(int j=0;j<=10;j++)
            {
                if(j==0) 
                {
                    dp[i][j]=max(dp[i][j]+map[i][j],dp[i+1][j+1]+map[i][j]);
                    dp[i][j]=max(dp[i][j],dp[i+1][j]+map[i][j]);
                }
                else if(j==10) 
                {
                    dp[i][j]=max(dp[i][j]+map[i][j],dp[i+1][j-1]+map[i][j]);
                    dp[i][j]=max(dp[i][j],dp[i+1][j]+map[i][j]);
                }
                else 
                {
                    dp[i][j]=max(dp[i][j],dp[i+1][j-1]+map[i][j]);
                    dp[i][j]=max(dp[i][j],dp[i+1][j+1]+map[i][j]);
                    dp[i][j]=max(dp[i][j],dp[i+1][j]+map[i][j]);
                }
            }
        cout<<dp[0][5]<<endl;
    }
    return 0;
}
