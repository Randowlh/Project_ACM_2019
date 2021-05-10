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
const int maxn = 10;
mt19937 rnd(114514);
int date[11000];
void merge(int left, int mid, int right)
{
    int l1 = mid - left + 1;
    int l2 = right - mid;
    vector<int> l, r;
    for (int i = 1; i <= l1; i++)
        l.push_back(date[left + i - 1]);
    for (int i = 1; i <= l2; i++)
        r.push_back(date[mid + i]);
    l.push_back(llinf);
    r.push_back(llinf);
    int i = 0;
    int j = 0;
    for (int k = left; k <= right; k++)
    {
        if (l[i] <= r[j])
        {
            date[k] = l[i];
            i++;
        }
        else
        {
            date[k] = r[j];
            j++;
        }
    }
    return;
}
void merge_sort(int l,int r){
    if(l>=r)
        return;
    int dis=(r-l+1);
    int ss=sqrt(dis);
    int now=1;
    while(now+ss<=r){
        merge_sort(now+1,now+ss);
        merge(l,now,now+ss);
        now+=ss;
    }
    merge_sort(now+1,r);
    merge(l,now,r);
    return;
}
void work()
{
    for(int i=1;i<=maxn;i++)
        date[i]=rand();
    cout<<"pre_sort"<<endl;
    for(int i=1;i<=maxn;i++)
        cout<<date[i]<<' ';
    cout<<endl;
    merge_sort(1,maxn);
    for(int i=1;i<=maxn;i++)
        cout<<date[i]<<' ';
    cout<<endl;
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