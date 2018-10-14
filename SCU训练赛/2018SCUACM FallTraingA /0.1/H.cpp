#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int num[100];
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    while(~scanf("%d",&n))
    {
        if(!n) break;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&num[i]);
        }
        int minNum=num[1];
        int target=1;
        for(int i=2;i<=n;i++)
        {
            if(num[i]<minNum)
            {
                minNum=num[i];
                target=i;
            }
        }
        swap(num[1],num[target]);
        for(int i=1;i<n;i++)
        {
            cout<<num[i]<<" ";
        }
        cout<<num[n]<<endl;
    }
    return 0;
}