#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
struct object
{
	int belong;
	int weight;
	int value;
};
object item[101];
int dp[11][10001];
int n,m,s;
int main()
{
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	while(~scanf("%d %d %d",&n,&m,&s))
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d %d",&item[i].belong,&item[i].weight,&item[i].value);
		}
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<=m;i++)
		{
			dp[0][i]=0;
		}
		for(int i=1;i<=s;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(item[j].belong==i)
				{
					for(int k=m;k>=item[j].weight;k--) 
					{
						dp[i][k]=max(dp[i][k],max(dp[i][k-item[j].weight]+item[j].value,dp[i-1][k-item[j].weight]+item[j].value));
					}
				}
			}
		}
		if(dp[s][m]<0)
		{
			cout<<"Impossible"<<endl;
		}
		else 
		{
			cout<<dp[s][m]<<endl;
		}
	}
	return 0;
}