#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int year;
int month;
int day;
int monthDay[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool isLeapYear(int x)
{
    return ((x%4==0&&x%100!=0)||x%400==0);
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    while(~scanf("%d/%d/%d",&year,&month,&day))
    {
        int ans=0;
        for(int i=1;i<month;i++)
        {
            ans+=monthDay[i];
        }
        ans+=day;
        if(isLeapYear(year)&&month>2)
        {
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}