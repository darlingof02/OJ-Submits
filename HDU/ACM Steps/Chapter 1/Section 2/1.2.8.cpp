#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int getsum(int x,int base)
{
    int sum=0;
    while(x)
    {
        sum+=(x%base);
        x/=base;
    }
    return sum;
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    for(int i=1000;i<=9999;i++)
    {
        int check_dec=0;
        int check_duo=0;
        int check_hex=0;
        check_dec=getsum(i,10);
        check_duo=getsum(i,12);
        check_hex=getsum(i,16);
        if(check_dec==check_duo&&check_duo==check_hex)
        {
            cout<<i<<endl;
        }
    }
    return 0;
}