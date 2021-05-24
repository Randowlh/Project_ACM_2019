#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll rd(){
	ll x=0;char o,f=1;
	while(o=getchar(),o<48)if(o==45)f=-f;
	do x=(x<<3)+(x<<1)+(o^48);
	while(o=getchar(),o>47);
	return x*f;
}
const int maxn=40005;
int n,k,a[maxn],now[maxn],pre[maxn];
int mn[101][maxn<<2],lazy[101][maxn<<2];
void build(int c,int l=0,int r=n,int p=1){
	if (l==r){
		mn[c][p]=1e9;
		return;
	}
	int mid=(l+r)>>1;
	build(c,l,mid,p<<1);build(c,mid+1,r,p<<1|1);
	mn[c][p]=1e9;
}
void pushup(int c,int p){
	mn[c][p]=min(mn[c][p<<1],mn[c][p<<1|1]);
}
void pushdown(int c,int p){
	if (!lazy[c][p])return;
	mn[c][p<<1]+=lazy[c][p];
	mn[c][p<<1|1]+=lazy[c][p];
	lazy[c][p<<1]+=lazy[c][p];
	lazy[c][p<<1|1]+=lazy[c][p];
	lazy[c][p]=0;
}
void update(int c,int a,int b,int v,int l=0,int r=n,int p=1){
	if (a>r||b<l)return;
	if (a<=l&&b>=r){
		mn[c][p]+=v;
		lazy[c][p]+=v;
		return;
	}
	int mid=(l+r)>>1;
	pushdown(c,p);
	update(c,a,b,v,l,mid,p<<1);update(c,a,b,v,mid+1,r,p<<1|1);
	pushup(c,p);
}
int query(int c,int a,int b,int l=0,int r=n,int p=1){
	if (a>r||b<l)return 1e9;
	if (a<=l&&b>=r)return mn[c][p];
	int mid=(l+r)>>1;
	pushdown(c,p);
	return min(query(c,a,b,l,mid,p<<1),query(c,a,b,mid+1,r,p<<1|1));
}
int main() {
  	n=rd();k=rd();
  	for (int i=1;i<=n;i++)a[i]=rd();
  	for (int i=1;i<=n;i++){
  		if (now[a[i]]==0)pre[i]=i;
  		else pre[i]=now[a[i]];
  		now[a[i]]=i;
  	}
  	for (int i=0;i<=n;i++)build(i);
  	update(0,0,0,-1e9);
  	for (int i=1;i<=n;i++){
  		for (int j=1;j<=min(i,k);j++){
  			if (i!=pre[i]){
  				update(j-1,0,pre[i]-1,i-pre[i]);
  			}
  			update(j,i,i,query(j-1,0,i-1)-1e9);
  		}
  	}
  	printf("%d\n",query(k,n,n));
    return 0;
}