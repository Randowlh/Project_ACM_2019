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
vector<pair<int,int>> a[2]; 
void work()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int ff=(i&1);
        for(int j=1;j<=n;j++)
        {
            a[ff].push_back(make_pair(i,j));
            ff^=1;
        }
    }
    int one=0,two=0;
    int ed[2];
    ed[0]=a[0].size()-1;
    ed[1]=a[1].size()-1;
    while(1){
        if(one>ed[0]&&two>ed[1])
            break;
        int opt;
        cin>>opt;
        if(opt==1){
            if(two<=ed[1]){
                cout<<2<<' '<<a[1][two].first<<' '<<a[1][two].second<<endl;
                two++;
            }else{
                cout<<3<<' '<<a[0][one].first<<' '<<a[0][one].second<<endl;
                one++;
            }
        }else if(opt==2){
            if(one<=ed[0]){
                cout<<1<<' '<<a[0][one].first<<' '<<a[0][one].second<<endl;
                one++;
            }else{
                cout<<3<<' '<<a[1][two].first<<' '<<a[1][two].second<<endl;
                two++;
            }
        }else{
            if(one<=ed[0]){
                cout<<1<<' '<<a[0][one].first<<' '<<a[0][one].second<<endl;
                one++;
            }else{
                cout<<2<<' '<<a[1][two].first<<' '<<a[1][two].second<<endl;
                two++;
            }
        }
    }
    return;
}
signed main()
{
   #ifndef ONLINE_JUDGE
//    freopen("in.txt","r",stdin);
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