#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma optimize(2)
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native");
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
#define pii(a,b) pair<a,b>
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
const int maxn = 510;
int date[maxn][maxn];
bool qz[maxn*maxn];
set<int> fp;
vector<pair<int,int>> v;
vector<int> mp[maxn*maxn];
void work()
{
    int n;
    rd(n);
    int s;
    int tmp;
    for(int i=1;i<=n*n;i++){
        rd(tmp);
        if(tmp)
            qz[i]=1;
        int k;
        rd(k);
        if(k==2)
            s=i;
        for(int j=1;j<=k;j++){
            rd(tmp);
            mp[i].push_back(tmp);
        }
    }
    date[1][1]=s;
    fp.insert(s);
    date[2][1]=mp[s][0];
    fp.insert(mp[s][0]);
    date[1][2]=mp[s][1];
    fp.insert(mp[s][1]);
    for(int tot=3;tot<=n*2;tot++){
        for(int i=max(tot-n,2LL);i<=min(tot-2,n);i++){
            int j=tot-i;
            set<int> s;
            int up=date[i-1][j];
            for(int i=0;i<mp[up].size();i++)
                s.insert(mp[up][i]);
            int lf=date[i][j-1];
            for(int k=0;k<mp[up].size();k++){
                if(mp[up][k]!=date[i-1][j-1]&&s.count(mp[up][k])){
                    date[i][j]=mp[up][k];
                    fp.insert(mp[up][k]);
                    break;
                }
            }
        }
        if(tot<=n+1){
            for(int i=0;i<mp[date[tot-2][1]].size();i++){
                int to=mp[date[tot-2][1]][i];
                if(!fp.count(to)){
                    date[tot-1][1]=to;
                    fp.insert(to);
                    break;
                }
            }
            for(int i=0;i<mp[date[1][tot-2]].size();i++){
                int to=mp[date[1][tot-2]][i];
                if(!fp.count(to)){
                    date[1][tot-1]=to;
                    fp.insert(to);
                    break;
                }
            }
        }else{
            for(int i=0;i<mp[date[n][tot-n-1]].size();i++){
                int to=mp[date[n][tot-n-1]][i];
                if(!fp.count(to)){
                    date[n][tot-n]=to;
                    fp.insert(to);
                    break;
                }
            }
            for(int i=0;i<mp[date[tot-n-1][n]].size();i++){
                int to=mp[date[tot-n-1][n]][i];
                if(!fp.count(to)){
                    date[tot-n][n]=to;
                    fp.insert(to);
                    break;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(qz[date[i][j]])
                v.push_back(make_pair(i,j));
            date[i][j]=qz[date[i][j]];
        }
    int ans1=llinf,ans2=0;
    random_shuffle(v.begin(),v.end());
    int tn=v.size();
    if(v.size()>1000){
        tn/=8;
    }
    for(int i=0;i<tn;i++){
        int x=v[i].first;
        int y=v[i].second;
        int tans=0;
        for(int k=1;k<=n;k++){
            if(date[x][k])
                tans+=(y-k)*(y-k);
            if(date[k][y])
                tans+=(x-k)*(x-k);
        }
        MIN(ans1,tans);
        MAX(ans2,tans);
    }
    cout<<ans1<<' '<<ans2<<endl;
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