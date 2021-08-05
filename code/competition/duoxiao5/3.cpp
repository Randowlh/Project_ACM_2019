#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=3005;
int _,n,m;
char str[N];
ll ans,d[N];
int main(){
	int i,l,r,x;
//	freopen("out.txt","w",stdout);
	for (scanf("%d",&_);_;_--){
		scanf("%d%d%s",&n,&m,str+1);
		if (m>n) m=n;
		memset(d,0,sizeof(d));
		for (i=1;i<n;i++){
			l=1;
			x=0;
			for (r=l+i;r<=n;r++){
				if (str[r-i]^str[r]) x++;
				while (r-i>l+i||l+i<=r&&x>m){
					if (str[l]!=str[l+i]) x--;
					l++;
				}
//				if (!l+i>r) continue;
				d[r-i]+=r-i-l+1;
				d[r-i+1]-=r-i-l+1;
				d[l+i]--;
				d[r+1]++;
			}
		}
		ans=0;
//		for (i=1;i<=n;i++) printf("%lld ",d[i]);printf("\n");
		for (i=1;i<n;i++){
			d[i]+=d[i-1];
			ans+=d[i];
			printf("%lld\n",ans);
		}
	}
	return 0;
}