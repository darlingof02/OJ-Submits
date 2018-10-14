#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
char str[10000];
char newStr[10000];
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    while(~scanf("%s",str))
    {
        memset(newStr,0,sizeof(newStr));
        int len=strlen(str);
        char maxChar=str[0];
        for(int i=1;i<len;i++)
        {
            maxChar=max(maxChar,str[i]);
        }
        int newLen=0;
        for(int i=0;i<len;i++)
        {
            if(str[i]==maxChar)
            {
                newStr[newLen++]=str[i];
                newStr[newLen++]='(';
                newStr[newLen++]='m';
                newStr[newLen++]='a';
                newStr[newLen++]='x';
                newStr[newLen++]=')';
            }
            else
            {
                newStr[newLen++]=str[i];
            }
        }
        cout<<newStr<<endl;
    }
    return 0;
}