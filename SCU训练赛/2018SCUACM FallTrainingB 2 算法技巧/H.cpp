#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int cnt;
struct NumberList{
	int A;
	int B;
	int C;
	int D;
};
NumberList list[4001];
int sum[4001*4001];
int find(int x){
	int l=0,r=cnt;
	while(l<=r){
		int mid=(l+r)>>1;
		if(sum[mid]>x){
			r=mid-1;
		}
		else if(sum[mid]<x){
			l=mid+1;
		}
		else{
			int tot=1;
			for(int i=mid-1;i>=1;i--){
				if(sum[i]!=sum[mid]){
					break;
				}
				tot++;
			}
			for(int i=mid+1;i<=cnt;i++){
				if(sum[i]!=sum[mid]){
					break;
				}
				tot++;
			}
			return tot;
		}
	}
	return 0;
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d %d %d",&list[i].A,&list[i].B,&list[i].C,&list[i].D);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			sum[++cnt]=-(list[i].C+list[j].D);
		}
	}
	sort(sum+1,sum+1+cnt);
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans+=find(list[i].A+list[j].B);
		}
	}
	cout<<ans<<endl;
	return 0;
}