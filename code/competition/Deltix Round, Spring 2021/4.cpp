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
const int maxn = 510000;
map<int,int> M;
bitset<110000> a[61];
int aa;
vector<pair<int,bitset<110000>>> bb;
vector<pair<int,bitset<110000>>> v;
int ans=0;
int n,m,p;
int tog;
void dfs(int pos,int step){
   if(v.empty()){
      v.push_back(MP(1<<bb[pos].first,bb[pos].second));
   }else v.push_back(MP(v[v.size()-1].first|(1<<bb[pos].first),v[v.size()-1].second&bb[pos].second));
   if(step>ans){
      ans=step;
      aa=v[v.size()-1].first;
   }
   for(int i=pos+1;i<bb.size();i++){
      if((v[v.size()-1].second&bb[i].second).count()<tog)
         continue;
      dfs(i,step+1);
   }
}
void work()
{
   cin>>n>>m>>p;
   tog=(n+1)>>1;
   string tmp;
   for(int i=1;i<=n;i++){
      cin>>tmp;
      // cout<<"tmp="<<tmp<<endl;
      for(int j=0;j<tmp.size();j++)
         if(tmp[j]=='1')
            a[j][i-1]=tmp[j]-'0';
   }
   // cout<<tog<<endl;
   for(int i=0;i<m;i++){
      if(a[i].count()>=(n+1)/2)
         bb.push_back(MP(i,a[i]));
   }
   // cout<<"bb"<<bb.size()<<endl;
   for(int i=0;i<bb.size();i++){
      dfs(i,1);
   }
   vector<bool> aaa;
   for(int i=1;i<=m;i++){
      aaa.push_back(aa&1);
      aa>>=1;
   }
   for(int i=0;i<m;i++){
      cout<<aaa[i];
   }
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
// cin>>t;
while (t--)
{
work();
}
return 0;
}