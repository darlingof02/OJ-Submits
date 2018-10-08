#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int N;
double Q;
double dp[31];
double value[31];
int main()
{
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	while(~scanf("%lf %d",&Q,&N))
	{
		if(!N) break;
		memset(value,0,sizeof(value));
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=N;i++)
		{
			int x;
			double money;
			double A=0,B=0,C=0;
			bool flag=false;
			scanf("%d",&x);
			for(int j=1;j<=x;j++)
			{
				char billType;
				scanf(" %c:%lf",&billType,&money);
				if(billType!='A'&&billType!='B'&&billType!='C')
				{
					flag=true;
					break;
				}
				if(billType=='A')
				{
					A+=money;
				}
				if(billType=='B')
				{
					B+=money;
				}
				if(billType=='C')
				{
					C+=money;
				}	
			}
			if(A+B+C<=1000&&A<=600&&B<=600&&C<=600&&!flag)
			{
				value[i]=A+B+C;
			}
		}
		for(int i=1;i<=N;i++)
		{
			for(int j=i-1;j>=0;j--)
			{
				if(dp[j]+value[i]<=Q)
				{
					dp[i]=max(dp[i],dp[j]+value[i]);
				}
			}
		}
		double ans=0;
		for(int i=1;i<=N;i++)
		{
			ans=max(ans,dp[i]);
		}
		printf("%.2f\n",ans);
	}
	return 0;
}