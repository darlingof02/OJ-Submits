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
	int P;
	int Q;
	int V;
};
object item[501];
int N,M;
int dp[5001];
bool cmp(object a,object b)
{
	return (a.P-a.Q)>(b.P-b.Q);
}
int main()
{
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	while(~scanf("%d %d",&N,&M))
	{
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=N;i++)
		{
			scanf("%d %d %d",&item[i].P,&item[i].Q,&item[i].V);
		}
		sort(item+1,item+1+N,cmp);
		for(int i=1;i<=N;i++)
		{
			for(int j=M;j>=item[i].Q;j--)
			{
				dp[j]=max(dp[j],dp[j-item[i].P]+item[i].V);
			}
		}
		cout<<dp[M]<<endl;
	}
	return 0;
}