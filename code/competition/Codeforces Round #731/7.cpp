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
const int maxn = 10000;
int low[maxn],dfn[maxn];
int belong[maxn];
int cnt1,cnt2;
int ff[maxn];
vector<int> mp[100],mp2[510000];
pair<int,int> eg[maxn];
int flag[maxn];
int sl[maxn];
int du[maxn];
int vl[maxn];
int ans[maxn];
vector<int> fr[maxn];
stack<int> s;
void tarjan(int pos){
    cout<<"pos="<<pos<<endl;
    dfn[pos]=low[pos]=++cnt1;
    flag[pos]=1;
    s.push(pos);
    for(int i=0;i<mp[pos].size();i++){
        int to=mp[pos][i];
        if(!dfn[to]){
            tarjan(to);
            MIN(low[pos],low[to]);
        }else if(!flag[to])
            MIN(low[pos],dfn[to]);
    }
    if(dfn[pos]==low[pos]){
        int fl=0,is1=0;
        cnt2++;
        while(s.top()!=pos){
            fl=1;
            is1|=(s.top()==1);
            belong[s.top()]=cnt2;
            fr[cnt2].push_back(s.top());
            cout<<"s.top("<<s.top()<<endl;
            flag[s.top()]=0;
            s.pop();
        }
        is1|=(s.top()==1);
        s.pop();
        fr[cnt2].push_back(pos);
        flag[pos]=0;
        belong[pos]=cnt2;
        fl|=sl[pos];
        if(fl)
            ff[cnt2]=-llinf;
        if(is1)
            ff[cnt2]++;
    }
}
void work()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        mp[i].clear();
        mp2[i].clear();
        sl[i]=0;
        dfn[i]=low[i]=0;
        cnt1=cnt2=0;
        ff[i]=0;
        fr[i].clear();
    }
    for(int i=1;i<=m;i++){
        cin>>eg[i].X>>eg[i].Y;
        if(eg[i].X==eg[i].Y)
            sl[eg[i].X]=1;
        mp[eg[i].X].push_back(eg[i].Y);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i);
    for(int i=1;i<=m;i++)
        if(belong[eg[i].X]^belong[eg[i].Y]){
            mp2[belong[eg[i].X]].push_back(eg[i].Y);
            du[belong[eg[i].Y]]++;
        }
    for(int i=1;i<=n;i++)
        cout<<belong[i]<<' ';
    cout<<endl;
    cout<<"cnt2="<<cnt2<<endl;
    cout<<"ff=";
    for(int i=1;i<=cnt2;i++){
        cout<<ff[i]<<' '<<fr[i].size()<<endl;
        cout<<"there is:";
        for(int j=0;j<fr[i].size();i++)
            cout<<fr[i][j]<<' ';
        cout<<endl;
    }
    cout<<endl;
    cout<<"dsadsdadsadsasadadsasd"<<endl;
    queue<int> q;
    for(int i=1;i<=cnt2;i++)
        if(!du[i])
            q.push(i);
    while(!q.empty()){
        int t=q.front();
        if(ff[t]>=10)
            ff[t]=2;
        q.pop();
        for(int i=0;i<mp2[t].size();i++){
            int to=mp2[t][i];
            du[to]--;
            ff[to]+=ff[t];
            if(!du[to])
                q.push(to);
        }
    }
    for(int i=1;i<=cnt2;i++)
        for(int j=0;j<fr[i].size();j++)
            ans[fr[i][j]]=ff[i];
    // cout<<"n="<<n<<' '<<m<<endl;
    for(int i=1;i<=n;i++){
        if(ans[i]==1)
            cout<<1<<' ';
        else if(ans[i]<0){
            cout<<-1<<' ';
        }else if(ans[i]==0)
            cout<<0<<' ';
        else
        cout<<2<<' ';
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
cin>>t;
t=1;
while (t--)
{
work();
}
return 0;
}