#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int maxFre[100010][21];
struct Interval
{
	int value;
	int frequency;
	int L;
	int R;
};
Interval num[100010];
int n,q;
int RMQ(int x,int y)
{
	int len=y-x+1;
	int t=log2(len);
	return max(maxFre[x][t],maxFre[y-(1<<t)+1][t]);
}
int main()
{
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	while(~scanf("%d",&n))
	{
		if(!n) break;
		scanf("%d",&q);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&num[i].value);
			if(num[i].value==num[i-1].value)
			{
				num[i].frequency=num[i-1].frequency+1;
			}
			else
			{
				num[i].frequency=1;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(num[i].value==num[i-1].value)
			{
				num[i].L=num[i-1].L;
			}
			else
			{
				num[i].L=i;
			}
		}
		for(int i=n;i>=1;i--)
		{
			if(num[i].value==num[i+1].value)
			{
				num[i].R=num[i+1].R;
			}
			else
			{
				num[i].R=i;
			}
		}
		for(int i=1;i<=n;i++)
		{
			maxFre[i][0]=num[i].frequency;
		}
		for(int j=1;(1<<j)<=n;j++)
		{
			for(int i=1;i+(1<<j)-1<=n;i++)
			{
				maxFre[i][j]=max(maxFre[i][j-1],maxFre[i+(1<<(j-1))][j-1]);
			}
		}
		while(q--)
		{
			int a,b,ans=-1;
			scanf("%d %d",&a,&b);
			if(a>b)
			{
				cout<<0<<endl;
				continue;
			}
			int start=num[a].R+1;
			int end=num[b].L-1;
			if(start>end)  //不存在中间区间
			{
				if(num[a].value!=num[b].value)
				{
					int maxL=num[num[a].R].frequency-num[a].frequency+1;
					int maxR=num[b].frequency-num[num[b].L].frequency+1;
					ans=max(maxL,maxR);
				}
				else
				{
					ans=num[b].frequency-num[a].frequency+1;
				}
			}
			else
			{
				int maxL=num[num[a].R].frequency-num[a].frequency+1;
				int maxR=num[b].frequency-num[num[b].L].frequency+1;
				int maxM=RMQ(start,end);
				ans=max(maxM,max(maxL,maxR));
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}