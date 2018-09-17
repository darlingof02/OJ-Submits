#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int T;
int n;
int dp[41];
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    dp[1]=1;dp[2]=1;
    for(int i=3;i<=40;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        cout<<dp[n]<<endl;
    }
    return 0;
}