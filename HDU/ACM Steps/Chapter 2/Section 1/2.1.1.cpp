#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int a,b;
int gcd(int a,int b)
{
    return (b==0)?a:gcd(b,a%b);
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    while(~scanf("%d %d",&a,&b))
    {
        cout<<a*b/gcd(a,b)<<endl;
    }
    return 0;
}