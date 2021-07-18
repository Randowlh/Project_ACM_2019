#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize(3)
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int, int> P;
int phi(int n)
{
    int t = 1, i;
    for (i = 2; i * i <= n; i++)
        if (n % i == 0)
            for (n /= i, t *= i-1; n % i == 0; n /= i, t *= i);
    if (n > 1)
        t *= n-1;
    return t;
}
int pow(ll a, int b, int m)
{
    ll t = 1;
    for (; b; b >>= 1, a = a * a % m)
        if (b & 1)
            t = t * a % m;
    return t;
}
int bsgs(int a, int r, int m)
{
    if (r >= m)
        return -1;
    int i, g, x, c = 0, at = int(2 + sqrt(m));
    for (i = 0, x = 1 % m; i < 50; i++, x = ll(x) * a % m)
        if (x == r)
            return i;
    for (g = x = 1; __gcd(int(ll(x) * a % m), m) != g; c++)
        g = __gcd(x = ll(x) * a % m, m);
    if (r % g)
        return -1;
    if (x == r)
        return c;
    unordered_map<int, int> u;
    g = phi(m / g), u[x] = 0;
    g = pow(a, g-at % g, m);
    for (i = 1; i < at; i++)
    {
        u.insert(P(x = ll(x) * a % m, i));
        if (x == r)
            return c + i;
    }
    for (i = 1; i < at; i++)
    {
        unordered_map<int, int>::iterator t = u.find(r = ll(r) * g % m);
        if (t != u.end())
            return c + i * at + t -> second;
    }
    return -1;
}

const int med = 998244353;
const int llinf = 1ll<<61;
int n,x;
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
inline void solve(){
    rd(n);rd(x);
    int reso = bsgs((n-1)*(n-1)%med,(x*n%med-(n-1)+med)%med,med);
    if(reso!=-1) reso = reso*2%med;
    int resj = bsgs((n-1)*(n-1)%med,((x*n%med+(n-1))%med)*(n-1)%med,med);
    if(resj!=-1) resj = resj*2-1;
    int minn = llinf;
    if(resj!=-1) minn = min(minn,resj);
    if(reso!=-1) minn = min(minn,reso);
    if(minn==llinf)minn = -1;
    wt(minn);printf("\n");
}
signed main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int z;
    rd(z);
    while(z--) solve();
    // printf("Time used = %.2f\n", (double)clock() / CLOCKS_PER_SEC);
}