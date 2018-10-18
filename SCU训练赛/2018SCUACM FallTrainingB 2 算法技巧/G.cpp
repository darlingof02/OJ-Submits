#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
#include<ctime>
#include<algorithm>
#define N int(1e5+1)
#define ll long long
using namespace std;
int n,len;
ll sum,ans;

struct Sequence
{
	ll s,h;
	string str;
}set[N];

bool cmp(const Sequence &a,const Sequence &b) 
{
	return a.s*b.h>a.h*b.s;
}

int main()
{
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>set[i].str;
		len=set[i].str.length();
		for(int j=0;j<len;j++)
		{
			if(set[i].str[j]=='s') set[i].s++;
			if(set[i].str[j]=='h') set[i].h++;
		}
	}
    sort(set+1,set+1+n,cmp);
    for(int i=2;i<=n;i++)
     set[1].str+=set[i].str;
    len=set[1].str.length();
    for(int i=0;i<len;i++)
    {
    	if(set[1].str[i]=='s') sum++;
    	if(set[1].str[i]=='h') ans+=sum;
	}
	cout<<ans<<endl;
    return 0;
}