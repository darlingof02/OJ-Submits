#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int p,q;
int gcd(int a,int b)
{
    return (!b)?a:gcd(b,a%b);
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    while(~scanf("%d %d",&p,&q))
    {
        cout<<p+q-gcd(p,q)<<endl;
    }
    return 0;
}