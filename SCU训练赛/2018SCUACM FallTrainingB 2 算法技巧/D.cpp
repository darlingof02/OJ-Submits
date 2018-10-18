#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<algorithm>
#define N int(1e5+1)
using namespace std;
int flag;
char s[N];
int main()
{
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%s",s+1);
	int len=strlen(s+1),cnt=0,t=97;
	for(int i=1;i<=len;i++) if(s[i]=='a'){flag=i;break;}
	if(!flag){cout<<-1<<endl;return 0;}
	for(int i=flag;i<=len;i++)
	{  
	  if(s[i]<=t-1) 
	  {
	   s[i]=t++;
	   if(++cnt==26) break;
	  }
	  if(s[i]==t) 
	  {t++;
	   if(++cnt==26) break;
	  }
	}
	if(cnt==26)
	{
		for(int i=1;i<=len;i++)
		 cout<<s[i];
		cout<<endl;
	 }
	 else 
	    cout<<-1<<endl;
	return 0;
}