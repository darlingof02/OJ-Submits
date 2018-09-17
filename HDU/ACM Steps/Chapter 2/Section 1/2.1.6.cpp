#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int T;
int n;

int k[35000];
int prime[35000];
bool flag[35000];
int cnt;

void make_prime()
{
    for(int i=2;i<35000;i++)
    {
        if(!flag[i])
        {
            prime[++cnt]=i;
        }
        for(int j=1;j<=cnt&&i*prime[j]<35000;j++)
        {
            flag[i*prime[j]]=true;
            if(i%prime[j]==0) break;
        }
    }
}

int ksm(int a,int b)
{
    int ans=1;
    while(b)
    {
        if(b%2) ans*=a;
        b>>=1;
        a*=a;
    }
    return ans;
}

int phi(int x)
{
    if(x==1) return 1;
    memset(k,0,sizeof(k));
    int pos=1;
    while(x>=prime[pos])
    {
        if(x%prime[pos]==0)
        {
            k[pos]++;
            x/=prime[pos];
        }
        else
        {
            pos++;
        }
    }

    int ans=1;
    for(int i=1;i<=pos;i++)
    {
        if(k[i]>=1)
        {
            ans*=ksm(prime[i],k[i]-1)*(prime[i]-1);
        }
    }
    return ans;
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&T);
    make_prime();
    while(T--)
    {
        scanf("%d",&n);
        cout<<phi(n)<<endl;
    }
    return 0;
}