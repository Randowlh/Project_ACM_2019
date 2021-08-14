#include<bits/stdc++.h>
using namespace std;
#define lson(pos) (pos<<1)
#define rson(pos) (pos<<1|1)
class mint{
    public:
    typedef long long ll;
    static const ll mod=1000000007ll;
    ll num;
    static ll tmod(ll x);
    ll expow(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
    mint(const ll x=0ll):num(tmod(x)){}
    mint(const mint &a):num(a.num){}
    void operator=(const ll x){num=tmod(x);}
    void operator=(const mint &x){num=x.num;}
    mint operator+(const mint &rhs){return mint(tmod(num+rhs.num));}
    mint operator-(const mint &rhs){return mint(tmod(num-rhs.num));}
    mint operator*(const mint &rhs){return mint(tmod(num*rhs.num));}
    operator int(){return num;}
    operator ll(){return num;}
    mint operator/(const mint &rhs){return mint(tmod(num*expow(rhs.num,mod-2)));}
    mint operator+(ll x){return mint(tmod(num+x));}
    mint operator-(ll x){return mint(tmod(num-x));}
    mint operator*(ll x){return mint(tmod(num*x));}
    mint operator/(ll x){return mint(tmod(num*expow(x,mod-2)));}
    mint operator^(ll x){return mint(expow(num,x));}
    friend ostream &operator<<(ostream &output,const mint &x){output<<x.num;return output;}
    friend istream &operator>>(istream &input,mint &x){input>>x.num;return input;}
};
const int maxn=101000;
mint a1[maxn],a2[maxn];
mint s1[maxn<<2],s2[maxn<<2],la[maxn<<2],tg[maxn<<2];
void work(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int tmp;
        cin>>tmp;   
        for(int k=30;k>=0;k--)
            if((1ll<<k)<=tmp){
                a1[i]=1ll<<k;
                a2[i]=tmp-(int)a1[i];
                break;
            }
    }
}
signed main(){
    int t;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>t;
    while(t--){
        work();
    }
}