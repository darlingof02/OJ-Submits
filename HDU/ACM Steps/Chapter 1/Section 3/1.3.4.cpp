#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int a[10001];
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a+1,a+1+n);
        int head=1,tail=n;
        while(head<=tail)
        {
            if(head!=tail) 
            {
                if(head+1!=tail)
                {
                    printf("%d %d ",a[tail],a[head]);
                }
                else
                {
                    printf("%d %d",a[tail],a[head]);
                }
            }
            else
            {
                printf("%d",a[head]);
            }
            tail--,head++;
        }
        printf("\n");
    }
    return 0;
}