#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
char str[10001];
int cnt[27];
int main()
{
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	scanf("%s",str);
	int len=strlen(str);
	for(int i=0;i<len;i++)
	{
		if(str[i]>='a')
		{
			str[i]-=32;
		}
	}
	for(int i=0;i<len;i++)
	{
		cnt[str[i]-'A'+1]++;
	}
	sort(cnt+1,cnt+1+26);
	int ans=0;
	for(int i=26;i>=1;i--)
	{
		ans+=cnt[i]*i;
	}
	cout<<ans<<endl;
	return 0;
}