#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
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
template<class T>inline void rd(T &x){
   x=0;char o,f=1;
   while(o=getchar(),o<48)if(o==45)f=-f;
   do x=(x<<3)+(x<<1)+(o^48);
   while(o=getchar(),o>47);
   x*=f;
}
template<class T>inline void wt(T x){
    static int top,stk[105];
    if(x<0)x=-x,putchar('-');
    if(x==0)putchar('0');
    while(x)stk[++top]=x%10,x/=10;
    while(top)putchar(stk[top--]+'0');
}
#define X first
#define Y second
#define pii(a,b) pair<a,b>
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
#define int long long
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
const int maxn = 210000;
int seg[maxn<<2],lazy[maxn<<2],date[maxn];
void up(int x){
    seg[x]=min(seg[lson(x)],seg[rson(x)]);
}
bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.X==b.X)
        return a.Y>b.Y;
    return a.X>b.X;
}
void down(int x){
    if(lazy[x]){
        int t=lazy[x];
        lazy[x]=0;
        seg[lson(x)]+=t;
        lazy[lson(x)]+=t;
        seg[rson(x)]+=t;
        lazy[rson(x)]+=t;
    }
}
void update(int x,int l,int r,int ql,int qr,int v){
    if(l>=ql&&r<=qr){
        seg[x]+=v;
        lazy[x]+=v;
        return;
    }
    down(x);
    int mid=l+r>>1;
    if(ql<=mid)
        update(lson(x),l,mid,ql,qr,v);
    if(qr>mid)
        update(rson(x),mid+1,r,ql,qr,v);
    up(x);
}
vector<pii(int,int)> v;
void work()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>date[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        if(date[i]>=0){
            update(1,1,n,i,n,date[i]);
            ans++;
        }else{
            v.push_back(MP(date[i],i));
        }
    }
    // cout<<ans<<endl;
    sort(v.begin(), v.end(),cmp);
    for(int i=0;i<v.size();i++){
        // cout<<v[i].X<<' '<<v[i].Y<<endl;
        update(1,1,n,v[i].second,n,v[i].first);
        if(seg[1]>=0)
            ans++;
        else update(1,1,n,v[i].second,n,-v[i].X);
    }
    cout<<ans<<endl;
}
signed main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
std::ios::sync_with_stdio(false);
cin.tie(NULL);
int t = 1;
// cin>>t;
while (t--)
{
work();
}
return 0;
}