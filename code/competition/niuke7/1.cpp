#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
const int N=1e5+5,mo=998244353,Z=120;
const int maxn=210000;
const int wd=2;
int tail,type;
struct node{
    int dim[wd],val;
    bool operator<(const node &a)const{
        return dim[type]<a.dim[type];
    }
}tree[maxn],tmp[maxn];
int root,dfsid,trid,rub,bin[maxn];
int tp[maxn],ls[maxn],rs[maxn],ma[maxn][wd],mi[maxn][wd],sz[maxn];
ll sum[maxn];
void pushup(int pos){
    for(int i=0;i<wd;i++){
        ma[pos][i]=mi[pos][i]=tree[pos].dim[i];
        if(ls[pos])MAX(ma[pos][i],ma[ls[pos]][i]),MIN(mi[pos][i],mi[ls[pos]][i]);
        if(rs[pos])MAX(ma[pos][i],ma[rs[pos]][i]),MIN(mi[pos][i],mi[rs[pos]][i]);
    }
    sum[pos]=sum[ls[pos]]+sum[rs[pos]]+tree[pos].val;
    sz[pos]=sz[ls[pos]]+sz[rs[pos]]+1;
}
void newnode(int& ans ,int ty,const node &rhs){
    if(rub)ans=bin[rub--];
    else ans=++trid;
    tp[ans]=ty;
    tree[ans]=rhs;
    ls[ans]=rs[ans]=0;
    pushup(ans);
}
void clean_node(int x){
    bin[++rub]=x;
    ls[x]=rs[x]=sz[x]=sum[x]=0;
}
void rebuild(int &x,int l,int r){
    int mid=l+r>>1;
    type=(++tail)&1;
    nth_element(tmp+l,tmp+mid,tmp+r+1);
    newnode(x,type,tmp[mid]);
    if(l<mid)rebuild(ls[x],l,mid-1);
    if(mid<r)rebuild(rs[x],mid+1,r);
    pushup(x);
}
void to_array(int x){
    if(ls[x])to_array(ls[x]);
    if(rs[x])to_array(rs[x]);
    tmp[++dfsid]=tree[x];
    clean_node(x);
}
void insert(int&x,const node&rhs){
    if(x==0){
        newnode(x,(++tail)&1,rhs);
        return;
    }
    if(rhs.dim[tp[x]]<=tree[x].dim[tp[x]])insert(ls[x],rhs);
    else insert(rs[x],rhs);
    pushup(x);
    if(sz[ls[x]]>sz[x]*0.75||sz[rs[x]]>sz[x]*0.75){
        dfsid=0;
        to_array(x);
        rebuild(x,1,dfsid);
    }
}
inline bool inside(int xl,int xr,int yl,int yr,int x1,int x2,int y1,int y2){
    return xl<=x1&&x2<=xr&&yl<=y1&&yr>=y2;
}
inline bool outside(int xl,int xr,int yl,int yr,int x1,int x2,int y1,int y2){
    return xl>x2||xr<x1||yl>y2||yr<y1;
}
ll query(int x,int xl,int xr,int yl,int yr){
    if(x==0)
        return 0;
    if(outside(xl,xr,yl,yr,mi[x][0],ma[x][0],mi[x][1],ma[x][1]))return 0;
    if(inside(xl,xr,yl,yr,mi[x][0],ma[x][0],mi[x][1],ma[x][1]))return sum[x];
    ll ans=query(ls[x],xl,xr,yl,yr)+query(rs[x],xl,xr,yl,yr);
    if(inside(xl,xr,yl,yr,tree[x].dim[0],tree[x].dim[0],tree[x].dim[1],tree[x].dim[1]))
        ans+=tree[x].val;
    return ans;
}
inline void add(int&a,const int&b){a+=b-mo;a+=a>>31&mo;}
ull a1,a2;
ull myRand(ull &k1, ull &k2) {
    ull k3 = k1, k4 = k2;
    k1 = k4;
    k3 ^= (k3 << 23);
    k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
    return k2 + k4;
}
ull rnd(){
	for(;;){
		ull x=myRand(a1,a2);
		if(x)return x;
	}
}
struct vec{
	int a[Z];
	inline void in(){for(int i=0;i<Z;++i)a[i]=rnd()%mo;}
    int operator*(vec aa){
	    int ans=0;
	    for(int i=0;i<Z;++i)ans=(ans+1ll*a[i]*aa.a[i])%mo;
	    return ans;
    }
    vec operator+(vec aa){
        vec tt;
        for(int i=0;i<Z;++i)tt.a[i]=(a[i]+aa.a[i])%mo;
        return tt;
    }
};
struct P{
	int x,y;
	inline void in(){x=rnd()%mo;y=rnd()%mo;}
}a[N];
inline ll sqr(const int&x){return 1ll*x*x;}
inline ll dis(const P&a,const P&b){return sqr(a.x-b.x)+sqr(a.y-b.y);}
int n,i,j,ans;
ll R;
vec val[N];
int main(){
	scanf("%d%lld%lld%lld",&n,&R,&a1,&a2);
	for(i=0;i<n;++i)a[i].in(),val[i].in();
    for(i=0;i<n;i++)
        date[i]=(node){a[i].}
	for(i=0;i<n;++i)for(j=i+1;j<n;++j)if(dis(a[i],a[j])<=R)
		add(ans,val[i]*val[j]);
	printf("%d\n",ans);
}