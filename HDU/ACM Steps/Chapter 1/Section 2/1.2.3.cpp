#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
char str[256];
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    while(gets(str))
    {
        int len=strlen(str);
        int sum=0;
        if(len==1&&str[0]=='#') break;
        for(int i=0;i<len;i++)
        {
            if(str[i]>='A'&&str[i]<='Z')
            {
                sum+=(str[i]-'A'+1)*(i+1);
            }
            else
            {
                continue;
            }
        }
        cout<<sum<<endl;
    }
}