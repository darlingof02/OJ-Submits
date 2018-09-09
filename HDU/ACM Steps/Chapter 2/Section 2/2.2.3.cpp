#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
int T;
ll m,n;
ll gcd(ll a,ll b)
{
    return (!b)?a:gcd(b,a%b);
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld %lld",&m,&n);
        if(gcd(m,n)==1)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
        }
    }
    return 0;
}