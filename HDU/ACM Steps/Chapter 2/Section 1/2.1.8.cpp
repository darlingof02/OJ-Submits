#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int T;
double n;
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf",&n);
        double m=n*log10(n);
        long long t=m;
        double y=t;
        double x=pow(10.0,m-y);
        cout<<int(x)<<endl;
    }
    return 0;
}