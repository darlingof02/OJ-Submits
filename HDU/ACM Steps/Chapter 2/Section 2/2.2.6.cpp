#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int A;
int B;
int n;
int F[1000];
void Calc_F()
{
    memset(F,-1,sizeof(F));
    F[1]=F[2]=1;
    for(int i=3;i<=49;i++)
    {
        F[i]=(A*F[i-1]+B*F[i-2])%7;
    }
    return;
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    while(~scanf("%d %d %d",&A,&B,&n))
    {
        if(!A&&!B&&!n) break;
        Calc_F();
        n=(n%49==0)?49:n%49;
        cout<<F[n]<<endl;
    }
    return 0;
}