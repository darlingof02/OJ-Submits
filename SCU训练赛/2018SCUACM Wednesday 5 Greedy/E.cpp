#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<set>
#include<algorithm>
#define ll long long
using namespace std;
const int inf=0x7fffffff;
const int MOD=1e9+7;
int n;
ll ans;
int bestBuy;
int bestSell;
int extraNum;
set<int>orderBook;
int main()
{
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&n);
	ans=1;
	int x;
	char str[10];
	bestBuy=-inf;
	bestSell=inf;
	orderBook.insert(bestBuy);
	orderBook.insert(bestSell);
	for(int i=1;i<=n;i++)
	{
		scanf("%s %d",str,&x);
		if(!strcmp(str,"ADD"))
		{
			orderBook.insert(x);
			if(bestBuy<x&&x<bestSell)
			{
				extraNum++;
			}
		}
		else
		{
			extraNum=0;
			orderBook.erase(x);
			if(x<bestBuy||x>bestSell)
			{
				cout<<0<<endl;
				return 0;
			}
			else if(x!=bestBuy&&x!=bestSell)
			{
				ans<<=1;
				ans%=MOD;
			}
			set<int>::iterator it;
			it=orderBook.lower_bound(x);
			bestSell=*(it);
			it--;
			bestBuy=*(it);
		}
	}
	ans*=(extraNum+1);
	ans%=MOD;
	cout<<ans<<endl;
	return 0;
}