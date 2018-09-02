#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
string A,B;
int pow(int a,int b)
{
    int res=1;
    for(int i=1;i<=b;i++)
    {
        res*=a;
    }
    return res;
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    while(cin>>A>>B)
    {
        int lenA=A.length();
        int lenB=B.length();
        int decimal_A=0;
        int decimal_B=0;

        for(int i=lenA-1,j=0;i>=0;i--,j++)
        {
            if(A[i]>='0'&&A[i]<='9')
            {
                decimal_A+=(A[i]-'0')*pow(16,j);
            }
            if(A[i]>='A'&&A[i]<='Z')
            {
                decimal_A+=(A[i]-'A'+10)*pow(16,j);
            }
            if(A[i]>='a'&&A[i]<='z')
            {
                decimal_A+=(A[i]-'a'+10)*pow(16,j);
            }
        }

        for(int i=lenB-1,j=0;i>=0;i--,j++)
        {
            if(B[i]>='0'&&B[i]<='9')
            {
                decimal_B+=(B[i]-'0')*pow(16,j);
            }
            if(B[i]>='A'&&B[i]<='Z')
            {
                decimal_B+=(B[i]-'A'+10)*pow(16,j);
            }
            if(B[i]>='a'&&B[i]<='z')
            {
                decimal_B+=(B[i]-'a'+10)*pow(16,j);
            }
        }
        cout<<decimal_A+decimal_B<<endl;
    }
    return 0;
}