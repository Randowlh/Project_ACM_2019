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
const int maxn = 110000;
map<string,int> M;
string tog[100];
int date[maxn];
string rev(string in){
    string ans;
    int n=in.size()-1;
    if(tog)
    for(int i=0;i<in.size();i++)
        ans.push_back(((in[i]-'0')^1)+tog[]);
    return  ans;
}
void work()
{
    // tog.clear();
    for(int i=0;i<=40;i++)
        tog[i].clear();
    M.clear();
    int n,k;
    rd(n),rd(k);
    string tmp;
    for(int i=1;i<=n;i++)
        rd(date[i]);
    for(int i=30;i>=0;i--){
        if((1<<i)&k){
            tmp.push_back('1');
        }else{
            tmp.push_back('1');
            tog.push_back(tmp);
            tmp.pop_back();
            tmp.push_back('0');
        }
    }
    int ans=llinf;
    int l=0,r=0;
    tog.push_back(tmp);
    tmp.clear();
    for(int i=1;i<=n;i++){
        tmp.clear();
        for(int j=30;j>=0;j--){
            if((1<<j)&date[i]){
                tmp.push_back('1');
            }else tmp.push_back('0');
            string now=rev(tmp);
            if(!now.empty()&&M.count(now)){
                int t=M[now];
                if(i-t<ans){
                    ans=i-t;
                    l=t+1;
                    r=i;
                }
            }
            M[tmp]=i;
        }
    }
    if(ans==llinf)
        wt(-1);
    else wt(l),pt(' '),wt(r);
    pt('\n');
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
rd(t);
//cin>>t;
while (t--)
{
work();
}
return 0;
}