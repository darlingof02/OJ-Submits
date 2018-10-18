#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
bool isFlowerNumber[1000];
int ans[1000];
int m;
int n;
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    for(int i=1;i<=9;i++)
        for(int j=0;j<=9;j++)
            for(int k=0;k<=9;k++)
            {
                if(i*i*i+j*j*j+k*k*k==100*i+10*j+k)
                {
                    isFlowerNumber[100*i+10*j+k]=true;
                }
                else
                {
                    isFlowerNumber[100*i+10*j+k]=false;
                }
            }
    while(~scanf("%d %d",&m,&n))
    {
        int cnt=0;
        for(int i=m;i<=n;i++)
        {
            if(isFlowerNumber[i])
            {
                ans[++cnt]=i;
            }
        }
        if(cnt==0)
        {
            cout<<"no"<<endl;
        }
        else
        {
            for(int i=1;i<cnt;i++)
            {
                cout<<ans[i]<<" ";
            }
            cout<<ans[cnt]<<endl;
        }
    }
    return 0;
}