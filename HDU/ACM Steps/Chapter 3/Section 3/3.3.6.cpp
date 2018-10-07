#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int N,M;
struct object
{
	int weight;
	int value;
	int belong;
};
object item[100001];
int dp[101][101];
int main()
{
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	while(~scanf("%d %d",&N,&M))
	{
		if(!N&&!M) break;
		int cnt=0;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=M;j++)
			{
				cnt++;
				item[cnt].weight=j;
				item[cnt].belong=i;
				scanf("%d",&item[cnt].value);
			}
		}
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=cnt;j++)
			{
				if(item[j].belong==i)
				{
					for(int k=M;k>=item[j].weight;k--)
					{
						dp[i][k]=max(dp[i][k],max(dp[i-1][k],dp[i-1][k-item[j].weight]+item[j].value));
					}
				}
			}
		}
		cout<<dp[N][M]<<endl;
	}
	return 0;
}