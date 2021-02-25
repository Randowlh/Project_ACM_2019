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
const ll llinf = 72036854775807;
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 1;
const int maxn = 510000;
int x[1100],y[1100];
int gcd(int a, int b){ return b ? gcd(b, a % b) : a;}
struct fs{
    mutable int mu,zi;
    fs(){}
    fs(int a,int b):zi(a),mu(b){}
    inline void yue()const{
        int ff=0;
        if(zi<0&&mu<0){
            zi=-zi;
            mu=-mu;
        }
        if(zi<0){
            ff=1;
            zi=-zi;
        }
        int tt=gcd(mu,zi);
        mu/=tt;
        zi/=tt;
        if(ff)
            zi=-zi;
    }
    fs operator-(fs a){
        fs ans(0,1);
        ans.zi=zi*a.mu;
        a.zi=mu*a.zi;
        ans.zi-=a.zi;
        ans.mu=mu*a.mu;
        ans.yue();
        return  ans;
    }
    fs operator/(fs a){
        fs ans(0,1);
        ans.zi=zi*a.mu;
        ans.mu=mu*a.zi;
        ans.yue();
        return  ans;
    }
    bool operator<(const fs a)const {
        a.yue();
        yue();
        if(mu==a.mu)
            return zi<a.zi;
        return mu<a.mu;
    }
    bool operator==(const fs a)const {
        return zi==a.zi&&mu==a.mu;
    }
};
struct node{
    fs a,c;
    node(){}
    node(fs aa,fs cc):a(aa),c(cc){}
    bool operator<(const node aa)const{
        if(a==aa.a)
        return c<aa.c;
        else return a<aa.a;
    }
};
set<node> ss;
map<fs,int> s;
void work()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>x[i]>>y[i];
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++){
            //  cout<<i<<' '<<j<<endl;
            int disx=x[i]-x[j];
            int disy=y[i]-y[j];
            if(disx==0){
                if(ss.count(node(fs(llinf,1),fs(x[i],1))))
                    continue;
                else ss.insert(node(fs(llinf,1),fs(x[i],1)));
                s[fs(llinf,1)]++;
                continue;
            }
            if(disy==0){
                if(ss.count(node(fs(y[i],1),fs(llinf,1))))
                    continue;
                else ss.insert(node(fs(y[i],1),fs(llinf,1)));
                s[fs(1,llinf)]++;
                continue;
            }
            fs aa=fs(disy,disx);
            aa.yue();
            fs tta=fs(y[i],1)-fs(aa.zi*x[i],aa.mu); 
            tta.yue();
            if(ss.count(node(aa,tta)))
                continue;
            else
                ss.insert(node(aa,tta));
            s[aa]++;
        }
    
    int nn=ss.size();
    // cout<<nn<<endl;
    int tt=nn*(nn-1)/2;
    for(auto i=s.begin(); i != s.end(); i++){
        int tmp=i->second;
        tt-=tmp*(tmp-1)/2;
        // cout<<tmp<<endl;
    }
    cout<<tt<<endl;
}
signed main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
//std::ios::sync_with_stdio(false);
//cin.tie(NULL);
int t = 1;
//cin>>t;
while (t--)
{
work();
}
return 0;
}