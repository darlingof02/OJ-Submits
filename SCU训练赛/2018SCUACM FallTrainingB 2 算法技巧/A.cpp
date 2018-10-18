#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<algorithm>
#define N int(1e3+1)
using namespace std;
int n,m;
double now,ans;

struct Store
{
	int F,J; //F钱数 J串数
	double C; //单价 
}shop[N];

void read(int &x)
{
	int a=0,b=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') b=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){a=a*10+ch-'0';ch=getchar();}
	x=a*b;
}

bool cmp(const Store &a,const Store &b) {return a.C<b.C;}

int main()
{
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	while(1)
	{
		read(m),read(n),ans=0,now=m;
		if(m==-1&&n==-1) break; 
		for(int i=1;i<=n;i++)
		{
			read(shop[i].J);
			read(shop[i].F);
			shop[i].C=shop[i].F*1.0/shop[i].J;
		}
	    sort(shop+1,shop+1+n,cmp);
	    for(int i=1;i<=n;i++)
	    {
	    	if(now-shop[i].F>=0) 
			{
			  	ans+=shop[i].J;
			  	now-=shop[i].F;
			}
	    	else
	    	{
	    		ans+=now*1.0/shop[i].C;
	    		break;
			}
		}
		printf("%.3lf\n",ans);
	}
	return 0;
}