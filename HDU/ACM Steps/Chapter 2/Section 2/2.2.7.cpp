#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
char str[10000];
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    while(~scanf("%s",str))
    {
        if(str[0]=='0') break;
        int len=strlen(str);
        int sum=0;
        for(int i=0;i<len;i++)
        {
            sum+=str[i]-'0';
            if(sum>=10)
            {
                int A=sum%10;
                int B=sum/10;
                sum=A+B;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}