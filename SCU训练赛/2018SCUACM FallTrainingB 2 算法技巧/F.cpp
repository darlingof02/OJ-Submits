#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxH=2*1e5+1;
int n,k;
int ans;
int h[maxH];
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d %d",&n,&k);
	int x,maxHeight=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		h[x]++;
		maxHeight=max(maxHeight,x);
	}
	int removeNum=0;
	for(int i=maxHeight;i>=0;i--){
		if(h[i]==n){
			if(removeNum){
				ans++;
			}
			break;
		}
		else{
			if(removeNum+h[i]<=k){
				removeNum+=h[i];
			}
			else{
				removeNum=h[i];
				ans++;
			}
			h[i-1]+=h[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}