#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m;
int num[10001];
int main()
{
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
	}
	sort(num+1,num+1+n);
	int head=1,tail=n;
	int couple=0;
	int dog=0;
	while(head<tail)
	{
		if(num[tail]+num[head]<=m)
		{
			couple++;
			tail--;
			head++;
		}
		else 
		{
			tail--;
			dog++;
		}
	}
	if(head==tail) cout<<couple+dog+1<<endl;
	else cout<<couple+dog<<endl;
	return 0;
}