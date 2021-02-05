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
int c[3][110000];
vector<int> mp[110000];
int ans[110000];
int tt[110000];
void work()
{
    int n;
    cin>>n;
    for(int j=0;j<3;j++)
        for(int i=1;i<=n;i++)
            cin>>c[j][i];
    int u,v;
    for(int i=1;i<=n-1;i++){
        cin>>u>>v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    int s=0,s2;
    int aa=llinf;
    for(int i=1;i<=n;i++){
        if(mp[i].size()>2){
            cout<<-1<<endl;
            return;
        }
        if(mp[i].size()==1)
            s=i;
    }
    s2=mp[s][0];
    int fa=s,now=s2;
    int cls[3];
    set<int> ss;
    for(int fst=0;fst<3;fst++)
        for(int scd=0;scd<3;scd++)
            if(fst!=scd){
                ss.clear();
                int tmp=c[fst][s]+c[scd][s2];
                tt[s]=fst;
                tt[s2]=scd;
                fa=s;
                now=s2;
                ss.insert(llinf);
                cls[0]=llinf;
                cls[1]=fst;
                ss.insert(fst);
                cls[2]=scd;
                ss.insert(scd);
                while(mp[now].size()!=1){
                    for(int i=0;i<mp[now].size(); i++){
                        if(mp[now][i]==fa)
                            continue;
                        fa=now;
                        now=mp[now][i];
                        ss.erase(cls[0]);
                        cls[0]=cls[1];
                        cls[1]=cls[2];
                        int nowc=0;
                        for(int i=0;i<3;i++)
                            if(!ss.count(i)){
                                nowc=i;
                                break;
                            }
                        ss.insert(nowc);
                        cls[2]=nowc;
                        tt[now]=nowc;
                        tmp+=c[nowc][now];
                        break;
                    }
                }
                if(aa>tmp){
                    aa=tmp;
                    for(int i=1;i<=n;i++)
                        ans[i]=tt[i];
                }
            }
    cout<<aa<<endl;
    for(int i=1;i<=n;i++)
        cout<<ans[i]+1<<' ';
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
//cin>>t;
while (t--)
{
work();
}
return 0;
}