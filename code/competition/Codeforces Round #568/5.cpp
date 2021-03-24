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
vector<pair<int,int>>pns[30]; 
char mp[2100][2100];
int n,m;
struct snks{
    int x1,y11,x2,y2,flag;
}ans[30],aa;
void work()
{
    cin>>n>>m;
    for(int i=0;i<26;i++){
        pns[i].clear();
        ans[i].flag=0;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
            if(mp[i][j]!='.'){
                // cout<<"sadasdsa  "<<mp[i][j]<<endl;
                pns[mp[i][j]-'a'].push_back(make_pair(i,j));
            }
        }
    for(int i=0;i<26;i++){
        if(pns[i].empty())
            continue;
        sort(pns[i].begin(), pns[i].end());
        set<int> aa,bb;
        for(int j=0;j<pns[i].size();j++){
            aa.insert(pns[i][j].first);
            bb.insert(pns[i][j].second);
        }
        if(min(aa.size(),bb.size())>=2){
            cout<<"NO"<<endl;
            return;
        }
        if(aa.size()>bb.size()){
            int y=*bb.begin();
            for(int j=*aa.begin();j<=*aa.rbegin();j++){
                if(mp[j][y]=='.'||mp[j][y]-'a'<i){
                    cout<<"NO"<<endl;
                    return;
                }
            }
        }else{
            int x=*aa.begin();
            for(int j=*bb.begin();j<=*bb.rbegin();j++){
                if(mp[x][j]=='.'||mp[x][j]-'a'<i){
                    cout<<"NO"<<endl;
                    return;
                }
            }
        }
        ans[i]=(snks){*aa.begin(),*bb.begin(),*aa.rbegin(),*bb.rbegin(),1};
    }
    int cnt=-1;
    for(int i=0;i<26;i++){
        if(ans[i].flag){
            MAX(cnt,i);
            aa=ans[i];
        }
    }
    cout<<"YES"<<endl;
    cout<<cnt+1<<endl;
    for(int i=0;i<=cnt;i++){
        if(ans[i].flag){
            cout<<ans[i].x1<<' '<<ans[i].y11<<' '<<ans[i].x2<<' '<<ans[i].y2<<endl;
        }else{
            cout<<aa.x1<<' '<<aa.y11<<' '<<aa.x2<<' '<<aa.y2<<endl;
        }
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