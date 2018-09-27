#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
class BigInt
{
    public:
        int num[1001];
        char str[1001];
        int len;
        BigInt()
        {
            clear();
        }
        void clear()
        {
            memset(num,0,sizeof(num));
            memset(str,0,sizeof(str));
            len=0;
        }
        void set()
        {
            clear();
            num[0]=1;
            len=1;
        }
        void set(int x)
        {
            clear();
            if(x==0)
            {
                num[0]=0;
                len=1;
                return;
            }
            while(x)
            {
                num[len++]=x%10;
                x/=10;
            }
        }
        BigInt operator +(BigInt &x)
        {
            BigInt sum;
            sum.len=max(x.len,len);
            int carry=0;
            for(int i=0;i<sum.len;i++)
            {
                carry=num[i]+x.num[i]+carry;
                sum.num[i]=carry%10;
                carry/=10;
            }
            if(carry) 
            {
                sum.num[sum.len++]=carry;
            }
            while(sum.len>1&&sum.num[sum.len-1]==0)
            {
                sum.len--;
            }
            return sum;
        }
        friend istream & operator >>(istream &input,BigInt &x)
        {
            input>>x.str;
            x.len=strlen(x.str);
            for(int i=0;i<x.len;i++)
            {
                x.num[i]=x.str[x.len-i-1]-'0';
            }
            return input;
        }
        friend ostream & operator <<(ostream &output,BigInt &x)
        {
            for(int i=x.len-1;i>=0;i--)
            {
                output<<x.num[i];
            }
            return output;
        }
};
BigInt F[1001];
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout); 
    F[0].set(1);
    F[1].set(1);
    F[2].set(2);
    F[3].set(4);
    for(int i=4;i<=1000;i++)
    {
        F[i]=F[i-1]+F[i-2]+F[i-4];
    }
    while(~scanf("%d",&n))
    {
        cout<<F[n]<<endl;
    }
    return 0;
}