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
const int maxn = 5000;
vector<int> primes;
bool is_prime[5100];
void euler()
{
   is_prime[1] = 1;
   for (int i = 2; i < maxn; i++)
   {
      if (!is_prime[i])
      primes.push_back(i);
      for (int j = 0; j < primes.size() && i * primes[j] < maxn; j++)
      {
         is_prime[i * primes[j]] = 1;
         if ((i % primes[j]) == 0)
            break;
      }
   }
}
map<int,int> M[6000],mp,mpp;
void work()
{
    euler();
    for(int i=0;i<primes.size();i++){
        mpp[primes[i]]=i;
    }
    int n;
    cin>>n;
    int tmp;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        for(int j=0;j< primes.size() && primes[j]*primes[j]<=tmp;j++){
            if(tmp%primes[j]==0){
                int cnt=0;
                while(tmp%primes[j]==0){
                    tmp/=primes[j];
                    cnt++;
                }
                M[j][cnt]++;
                M[j][0]++;
            }
        }
        // cout<<"tmp="<<tmp<<endl;
        if(tmp!=1){
            // cout<<"tmp="<<tmp<<endl;
            if(tmp<=primes[primes.size()-1]){
                M[mpp[tmp]][0]++;
                M[mpp[tmp]][1]++;
            }else
                mp[tmp]++;
        }
    }
    int ans=llinf;
    for(auto i=mp.begin();i != mp.end(); i++){
        if(i->second==n)
            continue;
        MIN(ans,n-i->second);
    }
    for(int i=0;i<primes.size();i++){
        if(M[i].size()==0)
            continue;
        if(M[i][0]==n){
            M[i].erase(0);
        }else
            M[i][0]=n-M[i][0];
        // cout<<M[i][0]<<endl;
        if(M[i].size()>=2){
            // cout<<primes[i]<<' '<<endl;
            MIN(ans,M[i].begin()->second);
            // cout<<"ababab"<<endl;
        }
    }
    if(ans==llinf){
        cout<<-1<<endl;
    }else cout<<ans<<endl;
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