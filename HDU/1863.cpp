#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
#include<ctime>
#include<algorithm>
#define N 10001
using namespace std;
int n,m,ans,cnt;
int a,b,v;
int fa[N];

struct edge
{
	int from,to,len;
}e[N];

void read(int &x)
{
	int a=0,b=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') b=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){a=a*10+ch-'0';ch=getchar();}
	x=a*b;
} 

bool cmp(const edge &a,const edge &b){return a.len<b.len;}

int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}

void un(int x,int y){fa[find(x)]=find(y);}

int main()
{
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	while(1)
	{
		read(n),ans=0,cnt=0;
		if(!n) break;
        read(m);
		for(int i=1;i<=m;i++) fa[i]=i;
		for(int i=1;i<=n;i++)
		{
			read(a),read(b),read(v);
			e[i].from=a;
			e[i].to=b;
			e[i].len=v;
		}
		sort(e+1,e+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			int px,py;
			px=find(e[i].from);
			py=find(e[i].to);
			if(px!=py)
			{
				ans+=e[i].len;
				un(px,py);
				if(++cnt==m-1) break;
			}
		}		
		if(cnt<m-1) cout<<"?"<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}
