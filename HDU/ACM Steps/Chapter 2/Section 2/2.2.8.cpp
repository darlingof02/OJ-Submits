#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int modBase=2009;
int N;
int F[41];
void calcF()
{
    F[0]=1;
    for(int i=1;i<=40;i++)
    {
        F[i]=(i%modBase)*(F[i-1]%modBase)%modBase;
    }
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    calcF();
    while(~scanf("%d",&N))
    {
        if(N<=40)
        {
            cout<<F[N]<<endl;
        }
        else
        {
            cout<<0<<endl;
        }
    }
    return 0;
}