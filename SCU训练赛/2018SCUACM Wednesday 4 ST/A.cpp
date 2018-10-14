#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int maxFre[100010][21];
int fre[1000010];
struct Interval
{
	int value;
	int frequency;
	int L;
	int R;
};
Interval num[100010];
int n,q;
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
		for(int j=1;j<=20;j++)
		{
			for(int i=1;i<=n;i++)
			{
				maxFre[i][0]=num[i].frequency;
				if(i+(1<<j)-1<=n)
				{
					maxFre[i][j]=max(maxFre[i][j-1],maxFre[i+(1<<(j-1))][j-1]);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			cout<<i<<" "<<num[i].value<<" "<<maxFre[i][1]<<endl;
		}
		return 0;
	}
	return 0;
}