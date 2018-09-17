#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int T;

double paraA,paraB,paraC;
struct point
{
    double x;
    double y;
};
point p1,p2,p3;
point z1,z2;

double sqr(double x)
{
    return x*x;
}

double F(double x)
{
    return paraA*x*x*x/3.0+paraB*x*x/2.0+paraC*x;
}

int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf %lf",&p1.x,&p1.y);
        scanf("%lf %lf",&p2.x,&p2.y);
        scanf("%lf %lf",&p3.x,&p3.y);
        if(p2.x>p3.x) swap(p2,p3);

        paraA=(p3.y-p1.y)/(p3.x*p3.x-2.0*p1.x*p3.x-p1.x*p1.x+2.0*p1.x*p1.x);
        paraB=(-2.0)*paraA*p1.x;
        paraC=p1.y+paraA*sqr(p1.x);

        double delta=paraB*paraB-4.0*paraA*paraC;
        z1.x=(-paraB-sqrt(delta))/(2*paraA);
        z1.y=0;
        z2.x=(-paraB+sqrt(delta))/(2*paraB);
        z2.y=0;
        
        if(z1.x>z2.x) swap(z1,z2);

        double paraS1=F(p2.x)-F(z1.x);
        double paraS2=F(p3.x)-F(z1.x);
        double lineS=(p3.y+p2.y)*(p3.x-p2.x)/2.0;
        double ans=paraS2-paraS1-lineS;

        printf("%.2f\n",ans);
    }
    return 0;
}