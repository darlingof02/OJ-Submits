#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,k;
int bestPoint[1001];
int main()
{
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d %d",&n,&k);
	int currentPoint=1,cnt=1;
	bestPoint[1]=1;
	while(1)
	{
		if(currentPoint+k<=n)
		{
			currentPoint+=(2*k+1);
			if(currentPoint<=n)
			{
				bestPoint[++cnt]=currentPoint;
			}
		}
		else
		{
			break;
		}
	}
	if(bestPoint[cnt]+k>=n)
	{
		cout<<cnt<<endl;
		for(int i=1;i<=cnt;i++)
		{
			cout<<bestPoint[i]<<" ";
		}
		return 0;
	}
	else
	{
		int delta=n-(bestPoint[cnt]+k);
		cout<<cnt<<endl;
		for(int i=1;i<=cnt;i++)
		{
			bestPoint[i]+=delta;
			cout<<bestPoint[i]<<" ";
		}
		return 0;
	}
}
