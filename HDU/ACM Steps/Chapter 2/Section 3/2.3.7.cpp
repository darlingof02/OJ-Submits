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
        char str[1001];
        int num[1001];
        int len;
        BigInt()
        {
            clear();
        }
        void clear()
        {
            memset(str,0,sizeof(str));
            memset(num,0,sizeof(num));
            len=1;
        }
        void set()
        {
            clear();
            str[0]='1';
            num[0]=1;
            len=1;
        }
        BigInt operator + (BigInt & b)
        {
            BigInt c;
            BigInt a=(*this);
            c.len=max(a.len,b.len);
            int add=0;
            for(int i=0;i<c.len;i++)
            {
                c.num[i]=a.num[i]+b.num[i]+add;
                add=c.num[i]/10;
                c.num[i]%=10;
            }
            while(add)
            {
                c.num[c.len++]=add%10;
                add/=10;
            }
            return c;
        }
        BigInt operator * (BigInt & b)
        {
            BigInt c;
            BigInt a=(*this);
            c.len=a.len+b.len;
            for(int i=0;i<a.len;i++)
                for(int j=0;j<b.len;j++)
                    c.num[i+j]+=a.num[i]*b.num[j];
            int carry=0;
            for(int i=0;i<c.len;i++)
            {
                carry+=c.num[i];
                c.num[i]=carry%10;
                carry/=10;
            }
            if(carry) c.num[c.len-1]=carry;
            while(c.len>1&&c.num[c.len-1]==0)
            {
                c.len--;
            }
            return c;
        }
        friend istream & operator >> (istream & input,BigInt & o)
        {
            input>>o.str;
            o.len=strlen(o.str);
            for(int i=0;i<o.len;i++)
            {
                o.num[o.len-i-1]=o.str[i]-'0';
            }
            return input;
        }
        friend ostream & operator << (ostream & output,BigInt & o)
        {
            for(int i=o.len-1;i>=0;i--)
            {
                cout<<o.num[i];
            }
            return output;
        }
};
BigInt F[101];
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    F[0].set();
    F[1].set();
    for(int i=2;i<=100;i++)
    {
        for(int j=0;j<i;j++)
        {
            BigInt tmp=F[j]*F[i-j-1];
            F[i]=F[i]+tmp;
        }
    }
    while(~scanf("%d",&n))
    {
        if(n==-1) break;
        cout<<F[n]<<endl;
    }
    return 0;
}