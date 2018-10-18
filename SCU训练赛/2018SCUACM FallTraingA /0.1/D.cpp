#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
struct Number
{
    int origin;
    int absValue;
};
Number num[10000];
bool cmp(Number a,Number b)
{
    return a.absValue>b.absValue;
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    while(~scanf("%d",&n))
    {
        if(!n) break;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&num[i].origin);
            num[i].absValue=abs(num[i].origin);
        }
        sort(num+1,num+1+n,cmp);
        for(int i=1;i<n;i++)
        {
            cout<<num[i].origin<<" ";
        }
        cout<<num[n].origin<<endl;
    }
    return 0;
}