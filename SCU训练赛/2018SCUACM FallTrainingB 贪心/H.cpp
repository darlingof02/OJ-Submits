#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,k,p,x,y;
int num[1001];
int main()
{
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	scanf("%d %d %d %d %d",&n,&k,&p,&x,&y);
	int sum=0;
	int base=0;
	int element;
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&element);
		if(element>=y)
		{
			base++;
		}
		sum+=element;
	}
	int leftSpace=x-sum;
	int leftNum=n-k;
	if(leftSpace<leftNum)
	{
		cout<<-1<<endl;
		return 0;
	}
	for(int i=1;i<=leftNum;i++)
	{
		num[i]=1;
	}
	if(base>=(n+1)/2)
	{
		for(int i=1;i<=leftNum;i++)
		{
			cout<<num[i]<<" ";
		}
		return 0;
	}
	else
	{
		leftSpace-=leftNum;
		for(int i=1;i<=leftNum;i++)
		{
			if(leftSpace-(y-1)>=0)
			{
				num[i]=y;
				base++;
				leftSpace-=(y-1);
			}
			else
			{
				break;
			}
		}
		if(base<(n+1)/2)
		{
			cout<<"-1"<<endl;
		}
		else
		{
			for(int i=1;i<=leftNum;i++)
			{
				cout<<num[i]<<" ";
			}
			return 0;
		}
	}
	return 0;
}
