#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
int T;
struct object
{
    ll circle;
    ll time;
};
ll gcd(ll a,ll b)
{
    return (b==0)?a:gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
    return a*b/gcd(a,b);
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        object A,B;
        scanf("%lld/%lld %lld/%lld",&A.time,&A.circle,&B.time,&B.circle);
        ll gcdA=gcd(A.time,A.circle);
        ll gcdB=gcd(B.time,B.circle);
        A.time/=gcdA,A.circle/=gcdA;
        B.time/=gcdB,B.circle/=gcdB;
        if(gcd(A.circle,B.circle)!=1)
        {
            cout<<lcm(A.time,B.time)<<"/"<<gcd(A.circle,B.circle)<<endl;
        }
        else
        {
            cout<<lcm(A.time,B.time)<<endl;
        }
    }
    return 0;
}