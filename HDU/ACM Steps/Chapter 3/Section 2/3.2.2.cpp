#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
char A[1005];
char B[1005];
int dp[1005][1005];
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    while(~scanf("%s %s",A+1,B+1))
    {
        int lenA=strlen(A+1);
        int lenB=strlen(B+1);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=lenA;i++)
            for(int j=1;j<=lenB;j++)
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                if(A[i]==B[j])
                {
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
                }
            }
        cout<<dp[lenA][lenB]<<endl;
    }
    return 0;
}