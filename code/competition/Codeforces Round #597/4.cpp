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
struct pnt{
    int x,y;
    pnt(int a=0,int b=0):x(a),y(b){}
}date[2100];
int kk[2100],cc[2100],fa[2100];
inline int calc(int a,int b){
    int tot=kk[a]+kk[b];
    return tot*(abs(date[a].x-date[b].x) + abs(date[a].y-date[b].y));
}
int n;
int dis[2100],flag[2100];
void dij(int a){
   for(int i=1;i<=n;i++)
      dis[i]=llinf;
   dis[a]=0;
   int cnt=0;
   while(cnt<n){
        int mi=llinf+100;
        int mix=0;
        for(int i=1;i<=n;i++){
            if(mi>dis[i]&&!flag[i]){
                mi=dis[i];
                mix=i;
            }
        }
        flag[mix]=1;
        for(int i=1;i<=n;i++){
            if(!flag[i]&&dis[i]>calc(i,mix)){
                dis[i]=calc(i,mix);
                fa[i]=mix;
            }
        }
        cnt++;
    }
}
bool isdz[2100];
vector<int> mp[2100];
set<int> s[2100];
int getmin(int now,int fa){
    int ans=cc[now];
    int aa=now;
    for(int i=0;i<mp[now].size();i++){
        if(mp[now][i]!=fa&&!s[now].count(mp[now][i])){
            int tt=getmin(mp[now][i],now);
            if(ans>cc[tt]){
                ans=cc[tt];
                aa=tt;
            }
        }
    }
    return aa;
}
bool ck(int tt,int fa){
    int ans=isdz[tt];
    for(int i=0;i<mp[tt].size();i++){
        if(mp[tt][i]!=fa&&!s[tt].count(mp[tt][i]))
            ans|=ck(mp[tt][i],tt);
    }
    return ans;
}
struct node{
    int val,fr,ed;
    inline bool operator<(node a){
        return val>a.val;
    }
};
void work()
{
    cin>>n;
    int aa=0;
    for(int i=1;i<=n;i++)
        cin>>date[i].x>>date[i].y;
    int mii=llinf;
    int mix=1;
    vector<int> ans;
    vector<pair<int,int>> egs;
    for(int i=1;i<=n;i++){
        cin>>cc[i];
        if(cc[i]<mii){
            mii=cc[i];
            mix=i;
        }
    }
    aa+=mii;
    ans.push_back(mix);
    isdz[mix]=1;
    for(int i=1;i<=n;i++)
        cin>>kk[i];
    dij(1);
    vector<node> v;
    for(int i=2;i<=n;i++){
        mp[i].push_back(fa[i]);
        mp[fa[i]].push_back(i);
        v.push_back((node){calc(i,fa[i]),fa[i],i});
    }
    sort(v.begin(), v.end());
    for(int i=0;i<v.size();i++){
        if(ck(v[i].fr,v[i].ed)){
            int tt=getmin(v[i].ed,v[i].fr);
            if(cc[tt]<v[i].val){
                ans.push_back(tt);
                isdz[tt]=1;
                aa+=cc[tt];
                s[v[i].fr].insert(v[i].ed);
                s[v[i].ed].insert(v[i].fr);
            }else {egs.push_back(make_pair(v[i].fr,v[i].ed));aa+=v[i].val;};
        }else{
            int tt=getmin(v[i].fr,v[i].ed);
            if(cc[tt]<v[i].val){
                ans.push_back(tt);
                isdz[tt]=1;
                aa+=cc[tt];
                s[v[i].fr].insert(v[i].ed);
                s[v[i].ed].insert(v[i].fr);
            }else{ egs.push_back(make_pair(v[i].fr,v[i].ed));aa+=v[i].val;}
        }
    }
    cout<<aa<<endl;
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<' ';
    cout<<endl;
    cout<<egs.size()<<endl;
    for(int i=0;i<egs.size();i++)
        cout<<egs[i].first<<' '<<egs[i].second<<endl;
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