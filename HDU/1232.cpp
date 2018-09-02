#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
#include<ctime>
#include<algorithm>
#define N 1001
using namespace std;
int n,m,cnt;
int a,b;
int fa[N];

void read(int &x)
{
	int a=0,b=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') b=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){a=a*10+ch-'0';ch=getchar();}
	x=a*b;
}

int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}

void un(int x,int y){fa[find(x)]=find(y);}

int main()
{
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
    while(1)
    {
      read(n);
	  if(!n) break;
	  read(m);
	  cnt=0;
	  for(int i=1;i<=n;i++) fa[i]=i;
	  for(int i=1;i<=m;i++)
	  {
		 read(a),read(b);
		 int px,py;
		 px=find(a),py=find(b);
		 if(px!=py) un(px,py);
	  }
	  for(int i=1;i<=n;i++)
	  {
		 if(fa[i]==i)
		  cnt++;
	  }
	     cout<<cnt-1<<endl;
	}
	return 0;
}
