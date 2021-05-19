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
struct node{
    int dir,lo,num;
    bool operator<(const node a)const{
        return lo<a.lo;
    }
}date[310000],date2[310000];
int ans[310000];
int n,m;
int calc(int i,int j){
    if(date2[i].lo>date2[j].lo)
        swap(i,j);
    int len=date2[j].lo-date2[i].lo;
    if(date2[i].dir==0)
        len+=date2[i].lo*2;
    if(date2[j].dir==1)
        len+=(m-date2[j].lo)*2;
    return len/2;
}
void work()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>date[i].lo;
        ans[i]=-1;
        date[i].num=i;
    }
    char aa;
    for(int i=1;i<=n;i++){
        cin>>aa;
        date[i].dir=(aa=='R');
        date2[i]=date[i];
    }
    stable_sort(date+1,date+n+1);
    stack<int> ss[2];
    vector<int>bk[2];
    for(int i=1;i<=n;i++){
        int t=date[i].lo%2;
        if(date[i].dir==0){
            if(ss[t].empty()){
                bk[t].push_back(i);
            }else{
                ans[date[i].num]=ans[date[ss[t].top()].num]=calc(date[ss[t].top()].num,date[i].num);
                // cout<<"dasdsad"<<date[i].num<<' '<<date[ss[t].top()].num<<endl;
                ss[t].pop();
            }
        }else
            ss[t].push(i);
    }
    // cout<<"size()="<<ss[0].size()<<' '<<ss[1].size()<<endl;
    for(int i=0;i<2;i++){
        while(ss[i].size()>=2){
            int a=ss[i].top();
            ss[i].pop();
            int b=ss[i].top();
            ss[i].pop();
            // cout<<"a="<<a<<' '<<b<<endl;
            ans[date[a].num]=ans[date[b].num]=calc(date[b].num,date[a].num);
        }
        for(int j=0;j<bk[i].size();j++){
            if(j+1<bk[i].size()){
                ans[date[bk[i][j]].num]=ans[date[bk[i][j+1]].num]=calc(date[bk[i][j+1]].num,date[bk[i][j]].num);
                j++;
            }else 
                break;
        }
        if(ss[i].size()&&bk[i].size()%2)
            ans[date[ss[i].top()].num]=ans[date[*(bk[i].end()-1)].num]=calc(date[ss[i].top()].num,date[*(bk[i].end()-1)].num);
    }
    // cout<<"test"<<calc(3,6)<<endl;
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