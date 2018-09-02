#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
char str[100];
int pow(int a,int b)
{
    int res=1;
    for(int i=1;i<=b;i++)
    {
        res*=a;
    }
    return res;
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    while(~scanf("%d",&n))
    {
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            int sys=0;
            int mark;
            scanf("%s",str);
            int len=strlen(str);
            for(int j=0;j<len;j++)
            {
                if(str[j]=='(')
                {
                    mark=j;
                    break;
                }
            }
            for(int j=len-2,k=0;j>mark;j--,k++)
            {
                sys+=(str[j]-'0')*pow(10,k);
            }
            for(int j=mark-1,k=0;j>=0;j--,k++)
            {
                sum+=(str[j]-'0')*pow(sys,k);
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}