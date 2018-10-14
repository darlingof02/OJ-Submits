#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
char str[10000];
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    while(gets(str+1))
    {
        int len=strlen(str+1);
        str[0]=' ';
        for(int i=1;i<=len;i++)
        {
            if(str[i]!=' '&&str[i-1]==' ')
            {
                if(str[i]>='a'&&str[i]<='z')
                {
                    str[i]-=32;
                }
            }
        }
        for(int i=1;i<=len;i++)
        {
            cout<<str[i];
        }
        cout<<endl;
    }
    return 0;
}
