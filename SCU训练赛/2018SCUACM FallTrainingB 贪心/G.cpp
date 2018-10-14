#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<algorithm>
#define N int(1e3+1)
using namespace std;
int n,ans;
int T[N],K[N];
int main()
{
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	while(~scanf("%d",&n))
	{
		if(!n) break;
		for(int i=1;i<=n;i++) scanf("%d",&T[i]);
		for(int i=1;i<=n;i++) scanf("%d",&K[i]);
		sort(T+1,T+1+n),sort(K+1,K+1+n);
		ans=0;
		int slow_T=1,fast_T=n,slow_K=1,fast_K=n;
		while(slow_T<=fast_T&&slow_K<=fast_K)
		{
			if(T[slow_T]>K[slow_K])
			{
				slow_T++,slow_K++;
				ans++;
				continue;
			}
			if(T[slow_T]==K[slow_K])
			{
				if(T[fast_T]>K[fast_K])
				{
					fast_T--,fast_K--;
					ans++;
				}
				else
				{
					if(T[slow_T]<K[fast_K]) ans--;
					slow_T++,fast_K--;
				}
				continue;
			}
			if(T[slow_T]<K[slow_K])
			{
				slow_T++,fast_K--;
				ans--;
				continue;
			}
		}
		cout<<ans*200<<endl;
	}
	return 0;
}
