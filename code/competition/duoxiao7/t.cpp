#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
template<class T>inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
#define ll long long
#define endl '\n'
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define int ll
const int med = 998244353;
const int MAXN = 114514;
string s;
int a[MAXN],n;
ll cnt[32],pre[32];
ll sumxf[32],sumcnt[32];
// ll nxt[32][MAXN];//记录下个位置
void solve(){
    cin>>s;
    n = s.length();
    rep(i,1,n) a[i] = s[i-1]-'a';
    rep(i,0,30) cnt[i]=sumcnt[i]=sumxf[i]=pre[i] = 0;
    rep(i,1,n){

        sumxf[a[i]] += (i-pre[a[i]]) * (cnt[a[i]]*cnt[a[i]]%med)%med;
        sumxf[a[i]] %= med;
        sumcnt[a[i]] += (i-pre[a[i]])*cnt[a[i]]%med;
        sumxf[a[i]] %= med;

        pre[a[i]] = i;
        cnt[a[i]]++;
    }
    rep(k,0,30){
        sumxf[k] += ((n+1)-pre[k]) * (cnt[k]*cnt[k]%med)%med;
        sumxf[k] %= med;
        sumcnt[k] += ((n+1)-pre[k]) * cnt[k]%med;
        sumcnt[k] %= med;
    }
    ll res = 0;
    rep(i,1,n){
        rep(k,0,30){
            res += sumxf[k];
            res %= med;
        }
        sumxf[a[i]] -= (2*sumcnt[a[i]]%med-(n-i+1)+med)%med;
        sumxf[a[i]] = (sumxf[a[i]]+med)%med;
        sumcnt[a[i]] = (sumcnt[a[i]]-(n-i+1)+med)%med;
    }
    cout<<res<<endl;
}

signed main(){
    int z;
    cin>>z;
    while(z--) solve();
}
