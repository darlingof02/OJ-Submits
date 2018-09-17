#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int a,b,c;
int gcd(int a,int b)
{
    return (!b)?a:gcd(b,a%b);
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&a,&c);
        int base=2;
        while(gcd(a,c*base)!=c)
        {
            base++;
        }
        cout<<c*base<<endl;
    }
    return 0;
}