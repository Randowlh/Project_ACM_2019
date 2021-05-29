#include <bits/stdc++.h>
// #include <bits/extc++.h>
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;
using namespace std;
#pragma optimize(2)
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #define rbset(T) tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>
const int inf = 0x7FFFFFFF;
typedef long long ll;
typedef double db;
typedef long double ld;
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
template<class T>inline void rd(T &x){
   x=0;char o,f=1;
   while(o=getchar(),o<48)if(o==45)f=-f;
   do x=(x<<3)+(x<<1)+(o^48);
   while(o=getchar(),o>47);
   x*=f;
}
template<class T>
void wt(T x){
   if(x < 0) putchar('-'), x = -x;
   if(x >= 10) wt(x / 10);
   putchar('0' + x % 10);
}
#define lowbit(x) (x&-x)
#define MP make_pair
#define pb push_back
#define pt putchar
#define yx_queue priority_queue
#define lson(pos) (pos<<1)
#define rson(pos) (pos<<1|1)
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
// #define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll llinf = 4223372036854775807;
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 1;
const int maxn = 510000;
const int SIZE=2e5+5;

int TYPE,jiedai;
struct kd_node{
	int dim[2],val;
	bool operator <(const kd_node &A)const{
		return dim[TYPE]<A.dim[TYPE];
	}
}tree[SIZE],tmp[SIZE];
int root,trid,dfsid,rub,bin[SIZE];
int type[SIZE],ls[SIZE],rs[SIZE],mx[SIZE][2],mi[SIZE][2],sz[SIZE];
ll sum[SIZE];
void up(int x){
	for(int i=0;i<2;i++){
		mx[x][i]=mi[x][i]=tree[x].dim[i];
		if(ls[x])MAX(mx[x][i],mx[ls[x]][i]),MIN(mi[x][i],mi[ls[x]][i]);
		if(rs[x])MAX(mx[x][i],mx[rs[x]][i]),MIN(mi[x][i],mi[rs[x]][i]);
	}
	sum[x]=sum[ls[x]]+sum[rs[x]]+tree[x].val;
	sz[x]=sz[ls[x]]+sz[rs[x]]+1;
}
void new_node(int &x,int ty,const kd_node &rhs){
	if(rub)x=bin[rub--];
	else x=++trid;
	type[x]=ty;
	tree[x]=rhs;
	ls[x]=rs[x]=0;
	up(x);
}
void clean_node(int x){
	bin[++rub]=x;
	ls[x]=rs[x]=sz[x]=sum[x]=0;
}
void rebuild(int &x,int l,int r){
	int mid=l+r>>1;
	TYPE=(++jiedai)&1;
	nth_element(tmp+l,tmp+mid,tmp+r+1);
	new_node(x,TYPE,tmp[mid]);
	if(l<mid)rebuild(ls[x],l,mid-1);
	if(mid<r)rebuild(rs[x],mid+1,r);
	up(x);
}
void to_array(int x){
	if(ls[x])to_array(ls[x]);
	if(rs[x])to_array(rs[x]);
	tmp[++dfsid]=tree[x];
	clean_node(x);
}
void insert(int &x,const kd_node &rhs){
	if(x==0){
		new_node(x,(++jiedai)&1,rhs);
		return;
	}
	if(rhs.dim[type[x]]<=tree[x].dim[type[x]])insert(ls[x],rhs);
	else insert(rs[x],rhs);
	up(x);
	if(sz[ls[x]]>sz[x]*0.75||sz[rs[x]]>sz[x]*0.75){
		dfsid=0;
		to_array(x);
		rebuild(x,1,dfsid);
	}
}
inline bool outside(int a1,int a2,int b1,int b2,int x1,int x2,int y1,int y2){
	return x1>a2||x2<a1||y1>b2||y2<b1;
}
inline bool inside(int a1,int a2,int b1,int b2,int x1,int x2,int y1,int y2){
	return x1>=a1&&x2<=a2&&y1>=b1&&y2<=b2;
}
ll query(int x,int a1,int a2,int b1,int b2){//a1<=x<=a2 b1<=y<=b2
	if(x==0)return 0;
	if(outside(a1,a2,b1,b2,mi[x][0],mx[x][0],mi[x][1],mx[x][1]))return 0;
	if(inside(a1,a2,b1,b2,mi[x][0],mx[x][0],mi[x][1],mx[x][1]))return sum[x];
	if(inside(a1,a2,b1,b2,tree[x].dim[0],tree[x].dim[0],tree[x].dim[1],tree[x].dim[1]))
		return query(ls[x],a1,a2,b1,b2)+query(rs[x],a1,a2,b1,b2)+tree[x].val;
	return query(ls[x],a1,a2,b1,b2)+query(rs[x],a1,a2,b1,b2);
}
signed main(){
#ifndef ONLINE_JUDGE
	freopen("jiedai.in","r",stdin);
#endif
	int n,op,x,y,v,x1,x2,y1,y2,lstans=0;
	rd(n);
	while(1){
		rd(op);
		if(op==1){
			rd(x),rd(y),rd(v);
			x^=lstans,y^=lstans,v^=lstans;
			insert(root,(kd_node){x,y,v});
		}
		else if(op==2){
			rd(x1),rd(y1),rd(x2),rd(y2);
			x1^=lstans,y1^=lstans,x2^=lstans,y2^=lstans;
			printf("%lld\n",lstans=query(root,x1,x2,y1,y2));
		}
		else if(op==3)break;
	}
	return (0-0);
}
