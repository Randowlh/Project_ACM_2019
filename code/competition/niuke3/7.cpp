#include <bits/stdc++.h>
//#include <bits/extc++.h>
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
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
namespace FastIO
{
char buf[1 << 21], buf2[1 << 21], a[20], *p1 = buf, *p2 = buf, hh = '\n';
int p, p3 = -1;
void read() {}
void print() {}
inline int getc()
{
return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++;
}
inline void flush()
{
fwrite(buf2, 1, p3 + 1, stdout), p3 = -1;
}
template <typename T, typename... T2>
inline void read(T &x, T2 &... oth)
{
int f = 0;x = 0;char ch = getc();
while (!isdigit(ch)){if (ch == '-')f = 1;ch = getc();}
while (isdigit(ch)){x = x * 10 + ch - 48;ch = getc();}
x = f ? -x : x;read(oth...);
}
template <typename T, typename... T2>
inline void print(T x, T2... oth)
{
if (p3 > 1 << 20)flush();
if (x < 0)buf2[++p3] = 45, x = -x;
do{a[++p] = x % 10 + 48;}while (x /= 10);
do{buf2[++p3] = a[p];}while (--p);
buf2[++p3] = hh;
print(oth...);
}
} // namespace FastIO
#define read FastIO::read
#define print FastIO::print
#define flush FastIO::flush
#define mul(a,b,mod) (__int128)(a)*(b)%(mod) 
#define pii(a,b) pair<a,b>
#define pow powmod
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
ll pow(ll a,ll b,ll md=mod) {ll res=1;a%=md; assert(b>=0); for(;b;b>>=1){if(b&1)res=mul(res,a,md);a=mul(a,a,md);}return res;}
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e7;
const int maxm= 1;
const int maxn = 510000;
int n,m;
vector<double> tmp;
vector<vector<double>> ans;
// vector<vector<int>> biao;
// vector<int> vv;
int biao[][7]={ {0,0,0,0,1,1,1},
                {0,0,0,1,0,1,1},
                {0,0,0,1,1,0,1},
                {0,0,1,0,0,1,1},
                {0,0,1,0,1,0,1}};
inline bool isz(double a){
    return fabs(a-(int)a)>eps;
}
double alu(double a,double b,int opt){
    switch(opt){
        case(1):
            return a+b;
        case(2):
            return a-b;
        case(3):
            return a*b;
        case(4):
            return a/b;
        case(5):
            return -a/b;
        case(6):
            return -a*b;
        case(7):
            return -a-b;
        case(8): 
            return -a+b;
    }
    return 0;
}
void dfs(int step,int lim){
    if(step==n){
        int fen=0,zheng=0;
        while(next_permutation(tmp.begin(),tmp.end())){
            int a[3];
            for(a[0]=1;a[0]<=8;a[0]++)
                for(a[1]=1;a[1]<=8;a[1]++)
                    for(a[2]=1;a[2]<=8;a[2]++)
                        for(int pos=0;pos<7;pos++){
                            stack<double> ss;
                            int cnt0=0;
                            int cnt1=0;
                            int ff=0;
                            for(int i=0;i<7;i++){
                                if(biao[pos][i]){
                                    int opt=a[cnt1++];
                                    db a=ss.top();
                                    ss.pop();
                                    db b=ss.top();
                                    ss.pop();
                                    db a1=alu(a,b,opt);
                                    ss.push(a1);
                                    ff=isz(a1);
                                }else{
                                    ss.push(tmp[cnt0++]);
                                }
                            }
                            int tt=ceil(ss.top());
                            if(tt==m&&abs(ss.top()-tt)<eps){
                                if(ff)
                                    fen++;
                                else zheng++;
                            }
                        }
        }
        sort(tmp.begin(),tmp.end());
        if(fen&&!zheng)
            ans.push_back(tmp);
        cout<<fen<<' '<<zheng<<endl;
        return;
    }
    for(int i=lim+1;i<=13;i++){
        tmp.push_back(i);
        dfs(step+1,i-1);
        tmp.pop_back();
    }
}
void work()
{
    cin>>n>>m;
    // read(n,m);
    dfs(0,0);
    // dfs2(0,0,0);
    // cout<<"dasddsadas"<<endl;
    // for(int i=0;i<biao.size();i++){
    //     for(int j=0;j<biao[i].size();j++)
    //         cout<<biao[i][j]<<',';
    //     cout<<endl;
    // }
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size(); i++){
        for(int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<' ';
        cout<<'\n';
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
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}