#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
int n;
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    while(~scanf("%d",&n))
    {
        if(n>=90&&n<=100)
        {
            cout<<"A"<<endl;
        }
        else if(n>=80&&n<=89)
        {
            cout<<"B"<<endl;
        }
        else if(n>=70&&n<=79)
        {
            cout<<"C"<<endl;
        }
        else if(n>=60&&n<=69)
        {
            cout<<"D"<<endl;
        }
        else if(n>=0&&n<=59)
        {
            cout<<"E"<<endl;
        }
        else 
        {
            cout<<"Score is error!"<<endl;
        }
    }
}