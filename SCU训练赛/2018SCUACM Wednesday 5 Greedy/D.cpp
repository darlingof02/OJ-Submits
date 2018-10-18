#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int maxNum=1e9+1;
int n;
struct Number
{
	int ID;
	int value;
};
Number num[200001];
Number zeroList[200001];
int zeroNum;
queue<Number>que;
int main()
{
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&n);
	int minusNum=0;
	int maxMinus=-maxNum;
	int maxMinusID=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i].value);
		num[i].ID=i;
		if(num[i].value==0)
		{
			zeroNum++;
			zeroList[zeroNum]=num[i];
		}
		if(num[i].value<0)
		{
			minusNum++;
			if(num[i].value>maxMinus)
			{
				maxMinus=num[i].value;
				maxMinusID=i;
			}
		}
	}
	if(zeroNum==n)
	{
		for(int i=1;i<n;i++)
		{
			cout<<1<<" "<<i<<" "<<i+1<<endl;
		}
		return 0;
	}
	if(zeroNum==n-1&&minusNum==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(i!=maxMinusID)
			{
				cout<<1<<" "<<maxMinusID<<" "<<i<<endl;
				break;
			}
		}
		for(int i=1;i<zeroNum;i++)
		{
			cout<<1<<" "<<zeroList[i].ID<<" "<<zeroList[i+1].ID<<endl;
		}
		return 0;
	}
	if(minusNum%2==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(num[i].value<0)
			{
				num[i].value=-num[i].value;
			}
		}
	} 
	if(minusNum%2!=0)
	{
		for(int i=1;i<=n;i++)
		{
			if(num[i].value<0&&num[i].ID!=maxMinusID)
			{
				num[i].value=-num[i].value;
			}
		} 
		if(zeroNum==0)  //directly delete max minus number
		{
			cout<<2<<" "<<maxMinusID<<endl;
		}
		else  //use 0 to delete max minus number
		{
			cout<<1<<" "<<maxMinusID<<" "<<zeroList[1].ID<<endl;
		}
	}
	if(zeroNum>0)  //delete 0
	{
		for(int i=1;i<zeroNum;i++)
		{
			cout<<1<<" "<<zeroList[i].ID<<" "<<zeroList[i+1].ID<<endl;
		}
		cout<<2<<" "<<zeroList[zeroNum].ID<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		if(num[i].value>0)
		{
			que.push(num[i]);
		}
	}
	while(!que.empty())
	{
		Number x=que.front();
		que.pop();
		if(que.empty())
		{
			break;
		}
		Number y=que.front();
		que.pop();
		cout<<1<<" "<<x.ID<<" "<<y.ID<<endl;
		que.push(y);
	}
	return 0;
}