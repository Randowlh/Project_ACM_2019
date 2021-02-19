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
const ll llinf = 4223372036854775807;
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 1;
const int maxn = 510000;
struct sttable{
    pair<int,int> mix[11000][200];
    inline void RMQ(int num){
        for(int j=1;j<=20;j++){
            for(int i=1;i<=num;i++){
                if(i+(1<<j)-1<=num)
                    mix[i][j]=max(mix[i][j-1],mix[i+(1<<(j-1))][j-1]);
            }
        }
    }
    inline pair<int,int> query(int l,int r){
        int k=log2(r-l+1)/ log2(2);
        // cout<<"k="<<k<<endl;
        return max(mix[l][k],mix[r-(1<<k)+1][k]);
    }
}a;
int n;
int ans[1100];
void dfs(int dep,int l,int r){
    if(l>r)
        return;
    int now=a.query(l,r).second;
    ans[now]=dep;
    // cout<<l<<' '<<r<<' '<<now<<endl;
    dfs(dep+1,l,now-1);
    dfs(dep+1,now+1,r);
}
void work()
{   
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a.mix[i][0].first;
        a.mix[i][0].second=i;
    }
    a.RMQ(n);
    dfs(0,1,n);
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    cout<<endl;
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