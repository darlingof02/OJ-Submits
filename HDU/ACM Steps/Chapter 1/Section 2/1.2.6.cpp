#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
char str[100];
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    while(gets(str))
    {
        int len=strlen(str);
        int count=0;
        double sum=0.0;
        bool flag=false;
        for(int i=0;i<len;i++)
        {
            if(str[i]==' '||str[i]=='\n') continue;
            if(str[i]=='A')
            {
                count++;
                sum+=4.0;
                continue;
            }
            if(str[i]=='B')
            {
                count++;
                sum+=3.0;
                continue;
            }
            if(str[i]=='C')
            {
                count++;
                sum+=2.0;
                continue;
            }
            if(str[i]=='D')
            {
                count++;
                sum+=1.0;
                continue;
            }
            if(str[i]=='F')
            {
                count++;
                continue;
            }
            else
            {
                flag=true;
                break;
            }
        }
        if(flag)
        {
            cout<<"Unknown letter grade in input"<<endl;
        }
        else
        {
            printf("%.2f\n",(sum*1.0)/(count*1.0));
        }
    }
    return 0;
}