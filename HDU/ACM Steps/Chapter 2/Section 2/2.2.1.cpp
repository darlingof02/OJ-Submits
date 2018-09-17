#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int T;
int n;
int F[21];
void pre_calc()
{
    F[0]=0,F[1]=1,F[2]=1;
    for(int i=3;i<=20;i++)
    {
        F[i]=F[i-1]+F[i-2];
    }
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    double base1=sqrt(5.0)/5.0;
    double base2=(1.0+sqrt(5.0))/2.0;
    pre_calc();
    while(~scanf("%d",&n))
    {
        if(n<=20)
        {
            cout<<F[n]<<endl;
            continue;
        }
        double m=log10(base1)+n*log10(base2);
        long long y=m;
        double x=pow(10.0,m-y);
        while(x<1000)
        {
            x*=10.0;
        }
        cout<<int(x)<<endl;
    }
    return 0;
}