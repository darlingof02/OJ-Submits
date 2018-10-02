#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int T;
int N,V;
struct Item
{
    int value;
    int volume;
};
Item bone[1001];
int dp[1001];
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&N,&V);
        for(int i=1;i<=N;i++)
        {
            scanf("%d",&bone[i].value);
        }
        for(int i=1;i<=N;i++)
        {
            scanf("%d",&bone[i].volume);
        }
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=N;i++)
            for(int j=V;j>=0;j--)
            {
                if(j>=bone[i].volume)
                {
                    dp[j]=max(dp[j],dp[j-bone[i].volume]+bone[i].value);
                }
            }
        cout<<dp[V]<<endl;
    }
    return 0;
}