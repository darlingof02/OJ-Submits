#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
struct object
{
	int weight;
	int value;
};
object item[100001];
int N,C;
char str[11];
int cnt[11][11];
int dp[100001];
int main()
{
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	while(~scanf("%d %d",&N,&C))
	{
		int value,weight;
		int totalItem=0;
		memset(cnt,0,sizeof(cnt));
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=N;i++)
		{
			scanf("%s",str);
			scanf("%d %d",&value,&weight);
			cnt[value][weight]++;
		}
		for(int i=0;i<=10;i++)  //价值
		{
			for(int j=0;j<=10;j++)  //重量
			{
				for(int k=1;k<=cnt[i][j];k<<=1)
				{
					totalItem++;
					item[totalItem].value=k*i;
					item[totalItem].weight=k*j;
					cnt[i][j]-=k;
				}
				totalItem++;
				item[totalItem].value=cnt[i][j]*i;
				item[totalItem].weight=cnt[i][j]*j;
			}
		}
		for(int i=1;i<=totalItem;i++)
		{
			for(int j=C;j>=item[i].weight;j--)
			{
				dp[j]=max(dp[j],dp[j-item[i].weight]+item[i].value);
			}
		}
		cout<<dp[C]<<endl;
	}
	return 0;
}