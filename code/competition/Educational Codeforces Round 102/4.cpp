#include <bits/stdc++.h>
using namespace std;
#pragma optimize(2)
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
const int maxn = 510000;
int pru[210000],prd[210000];
struct node{
    int mi,ma;
}T[210000<<2];
int date[210000];
inline void  pushup(int pos){
    T[pos].mi=llinf;
    T[pos].ma=-llinf;
    MIN(T[pos].mi,min(T[lson(pos)].mi,T[rson(pos)].mi));
    MAX(T[pos].ma,max(T[lson(pos)].ma,T[rson(pos)].ma));
}
void build(int pos,int l,int r){
    if(l==r){
        T[pos].mi=T[pos].ma=date[l];
        return;
    }
    int mid=(l+r)>>1;
    build(lson(pos),l,mid);
    build(rson(pos),mid+1,r);
    pushup(pos);
}
int queryi(int pos,int l,int r,int ql,int qr){
    if(ql<=l&&qr>=r){
        return T[pos].mi;
    }
    int ans=llinf;
    int mid=(l+r)>>1;
    if(ql<=mid)
        MIN(ans,queryi(lson(pos),l,mid,ql,qr));
    if(qr>=mid+1)
        MIN(ans,queryi(rson(pos),mid+1,r,ql,qr));
    return ans;
}
int querym(int pos,int l,int r,int ql,int qr){
    if(ql<=l&&qr>=r){
        return T[pos].ma;
    }
    int ans=-llinf;
    int mid=(l+r)>>1;
    if(ql<=mid)
        MAX(ans,querym(lson(pos),l,mid,ql,qr));
    if(qr>=mid+1)
        MAX(ans,querym(rson(pos),mid+1,r,ql,qr));
    return ans;
}
void work()
{
    int n,m;
    cin>>n>>m;
    string tmp;
    cin>>tmp;
    for(int i=1;i<=n;i++){
        int ff=(tmp[i-1]=='+');
        pru[i]=pru[i-1]+ff;
        prd[i]=prd[i-1]+(!ff);
        if(ff)
            date[i]=date[i-1]+1;
        else date[i]=date[i-1]-1;
        // cout<<"date[i]="<<date[i]<<endl;
    }
    date[n+1]=0;
    build(1,1,n);
    // for(int i=1;i<n;i++)
    //     cout<<queryi(1,1,n,i,i+1)<<' '<<querym(1,1,n,i,i+1)<<"lol"<<endl;
    for(int qq=0;qq<m;qq++){
        int l,r;
        cin>>l>>r;
        MIN(r,n);
        MAX(l,1LL);
        if(l==1&&r==n){
            cout<<1<<endl;
            continue;
        }
        int dis=(pru[r]-pru[l-1])-(prd[r]-prd[l-1]);
        // dis=-dis;
        // cout<<"dis="<<dis<<endl;
        int mi=llinf;
        int ma=-llinf;
        if(l!=1){
            MIN(mi,queryi(1,1,n,1,l-1));
            MAX(ma,querym(1,1,n,1,l-1));
            
        }
        MIN(mi,0LL);
        MAX(ma,0LL);
        // cout<<"mip"<<mi<<' '<<ma<<endl;
        if(r!=n){
            MIN(mi,queryi(1,1,n,r+1,n)-dis);
            MAX(ma,querym(1,1,n,r+1,n)-dis);

        }
        
        // cout<<"mif"<<mi<<' '<<ma<<endl;
        cout<<ma-mi+1<<endl;
        
    }
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
cin>>t;
while (t--)
{
work();
}
return 0;
}