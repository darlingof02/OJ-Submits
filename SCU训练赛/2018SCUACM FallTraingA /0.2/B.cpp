#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
char str[10000];
bool isLetter(char x)
{
    return (('a'<=x&&x<='z')||('A'<=x&&x<='Z'));
}
bool isNumber(char x)
{
    return ('0'<=x&&x<='9');
}
bool check(char *str)
{
    int len=strlen(str);
    if(!isLetter(str[0])&&str[0]!='_')
    {
        return false;
    }
    for(int i=1;i<len;i++)
    {
        if(!isLetter(str[i])&&!isNumber(str[i])&&str[i]!='_')
        {
            return false;
        }
    }
    return true;
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d\n",&n);
    for(int i=1;i<=n;i++)
    {
        gets(str);
        if(check(str))
        {
            cout<<"yes"<<endl;
        }
        else
        {
            cout<<"no"<<endl;
        }
    }
    return 0;
}