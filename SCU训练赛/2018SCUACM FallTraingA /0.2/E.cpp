#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
struct item
{
    char name[100];
    int tryTime;
    int acCount;
};
item people[10000];
int n,m;
char str[100];
bool cmp(item a,item b)
{
    if(a.acCount!=b.acCount)
    {
        return a.acCount>b.acCount;
    }
    else if(a.tryTime!=b.tryTime)
    {
        return a.tryTime<b.tryTime;
    }
    else if(strcmp(a.name,b.name)<0)
    {
        return true;
    }
    else 
    {
        return false;
    }
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d %d",&n,&m);
    int cnt=0;
    while(~scanf("%s",people[++cnt].name))
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%s",str);
            if(str[0]=='-') continue;
            if(str[0]=='0') continue;
            people[cnt].acCount++;
            int len=strlen(str);
            int x=0;
            for(int j=0;j<len;j++)
            {
                if(str[j]=='(')
                {
                    people[cnt].tryTime+=x;
                    x=0;
                    continue;
                }
                else if(str[j]==')')
                {
                    people[cnt].tryTime+=m*x;
                    x=0;
                    continue;
                }
                x=x*10+str[j]-'0';
            }
            people[cnt].tryTime+=x;
        }
    }
    cnt--;
    sort(people+1,people+1+cnt,cmp);
    for(int i=1;i<=cnt;i++)
    {
        cout<<people[i].name;
        int len=strlen(people[i].name);
        for(int j=1;j<=10-len;j++)
        {
            cout<<" ";
        }
        cout<<" ";
        if(people[i].acCount<10)
        {
            cout<<" "<<people[i].acCount;
        }
        else
        {
            cout<<people[i].acCount;
        }
        cout<<" ";
        if(people[i].tryTime<10)
        {
            cout<<"   "<<people[i].tryTime;
        }
        else if(people[i].tryTime<100)
        {
            cout<<"  "<<people[i].tryTime;
        }
        else if(people[i].tryTime<1000)
        {
            cout<<" "<<people[i].tryTime;
        }
        else 
        {
            cout<<people[i].tryTime;
        }
        cout<<endl;
    }
    return 0;
}