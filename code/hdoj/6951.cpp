#include <bits/stdc++.h>
//#include <bits/extc++.h>
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
using namespace std;
#pragma optimize(2)
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rbset(T) tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>
const int inf = 0x7FFFFFFF;
typedef long long ll;
typedef double db;
typedef long double ld;
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
namespace FastIO
{
char buf[1 << 21], buf2[1 << 21], a[20], *p1 = buf, *p2 = buf, hh = '\n';
int p, p3 = -1;
void read() {}
void print() {}
inline int getc()
{
return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++;
}
inline void flush()
{
fwrite(buf2, 1, p3 + 1, stdout), p3 = -1;
}
template <typename T, typename... T2>
inline void read(T &x, T2 &... oth)
{
int f = 0;x = 0;char ch = getc();
while (!isdigit(ch)){if (ch == '-')f = 1;ch = getc();}
while (isdigit(ch)){x = x * 10 + ch - 48;ch = getc();}
x = f ? -x : x;read(oth...);
}
template <typename T, typename... T2>
inline void print(T x, T2... oth)
{
if (p3 > 1 << 20)flush();
if (x < 0)buf2[++p3] = 45, x = -x;
do{a[++p] = x % 10 + 48;}while (x /= 10);
do{buf2[++p3] = a[p];}while (--p);
buf2[++p3] = hh;
print(oth...);
}
} // namespace FastIO
#define read FastIO::read
#define print FastIO::print
#define flush FastIO::flush
#define mul(a,b,mod) (__int128)(a)*(b)%(mod) 
#define pii(a,b) pair<a,b>
#define pow powmod
#define X first
#define Y second
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
ll pow(ll a,ll b,ll md=mod) {ll res=1;a%=md; assert(b>=0); for(;b;b>>=1){if(b&1)res=mul(res,a,md);a=mul(a,a,md);}return res;}
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 1;
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
        if(ls[pos]){MAX(ma[pos][i],ma[ls[pos]][i]);MIN(mi[pos][i],mi[ls[pos]][i]);}
        if(rs[pos]){MAX(ma[pos][i],ma[rs[pos]][i]);MIN(mi[pos][i],mi[rs[pos]][i]);}
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
signed main(){
   //  freopen("in.txt", "r", stdin);
   ios::sync_with_stdio(false);
   cin.tie(NULL);
    int n;
    int ans=0;
   //  read(n);
   cin>>n;
    while(1){
        int opt;
      //   read(opt);
      cin>>opt;
      //   print(opt);
      //   flush();
        if(opt==1){
            int x,y,v;
            cin>>x>>y>>v;
            // read(x,y,v);
            x^=ans,y^=ans,v^=ans;
            insert(root,(node){x,y,v});
        }else if(opt==2){
            int xl,xr,yl,yr;
            // read(xl,yl,xr,yr);
            cin>>xl>>yl>>xr>>yr;
            xl^=ans,xr^=ans,yl^=ans,yr^=ans;
            ans=query(root,xl,xr,yl,yr);
            // print(ans);
            cout<<ans<<'\n';
        }else if(opt==3)
            break;
    }
   //  print(1221231231123);
   //  flush();
}