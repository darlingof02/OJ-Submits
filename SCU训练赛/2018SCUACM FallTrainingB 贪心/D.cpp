#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<algorithm>
#define N_MAX 1001
using namespace std;
int T,N,ans;
int v[N_MAX];
void read(int &x)
{
	int a=0,b=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') b=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){a=a*10+ch-'0';ch=getchar();}
	x=a*b;
}

int main()
{
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	read(T);
	while(T--)
	{
		read(N),ans=0;
		for(int i=1;i<=N;i++) read(v[i]);
		sort(v+1,v+1+N);
		int pos=N;
		while(pos>=4)
		{
			ans+=min(v[2]+v[2]+v[pos]+v[1],v[pos]+v[1]+v[pos-1]+v[1]);  
			pos-=2;
		}
		if(pos==3) cout<<ans+v[1]+v[2]+v[3]<<endl;
		if(pos==2) cout<<ans+v[2]<<endl;
		if(pos==1) cout<<ans+v[1]<<endl;
    }
	return 0;
}