#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int F[10000];
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    F[1]=1;
    int x1,x2,x3,x4;
    x1=x2=x3=x4=1;
    int cnt=1;
    while(cnt<=5842)
    {
        cnt++;
        F[cnt]=F[x1]*2;
        F[cnt]=min(F[cnt],F[x2]*3);
        F[cnt]=min(F[cnt],F[x3]*5);
        F[cnt]=min(F[cnt],F[x4]*7);
        if(F[cnt]==F[x1]*2) x1++;
        if(F[cnt]==F[x2]*3) x2++;
        if(F[cnt]==F[x3]*5) x3++;
        if(F[cnt]==F[x4]*7) x4++;
    }
    while(~scanf("%d",&n))
    {
        if(!n) break;
        int x=n%10;
        int y=n%100;
        if(x==1)
        {
            if(y!=11) printf("The %dst humble number is %d.\n",n,F[n]);
            else printf("The %dth humble number is %d.\n",n,F[n]);
            continue;
        }
        if(x==2)
        {
            if(y!=12) printf("The %dnd humble number is %d.\n",n,F[n]);
            else printf("The %dth humble number is %d.\n",n,F[n]);
            continue;
        }
        if(x==3)
        {
            if(y!=13) printf("The %drd humble number is %d.\n",n,F[n]);
            else printf("The %dth humble number is %d.\n",n,F[n]);
            continue;
        }
        else
        {
            printf("The %dth humble number is %d.\n",n,F[n]);
            continue;
        }
    }
    return 0;
}