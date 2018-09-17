#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int T;
char A[10001],B[10001],C[10001];
int numA[10001],numB[10001],numC[10001];
int lenA,lenB,len;
void add(char *A,char *B)
{
    memset(numA,0,sizeof(numA));
    memset(numB,0,sizeof(numB));
    memset(numC,0,sizeof(numC));
    lenA=strlen(A);
    lenB=strlen(B);
    len=max(lenA,lenB);
    for(int i=0;i<lenA;i++)
    {
        numA[lenA-i-1]=A[i]-'0';
    }
    for(int i=0;i<lenB;i++)
    {
        numB[lenB-i-1]=B[i]-'0';
    }
    for(int i=0;i<len;i++)
    {
        numC[i]+=(numA[i]+numB[i]);
        numC[i+1]+=(numC[i]/10);
        numC[i]%=10;
    }
    while(numC[len-1]==0)
    {
        len--;
    }
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        scanf("%s %s",A,B);
        add(A,B);
        cout<<"Case "<<i<<":"<<endl;
        cout<<A<<" + "<<B<<" = ";
        for(int i=len-1;i>=0;i--)
        {
            cout<<numC[i];
        }
        cout<<endl;
        if(i<T) cout<<endl;
    }
    return 0;
}