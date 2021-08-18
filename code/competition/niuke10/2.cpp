#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
template<class T>inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }

const int MAXN = 114514;

struct Node{
    map<char,int> nxt;
    int cntb;//子树中白点
    int sz;//
}nd[MAXN*100];

int n;
string s;

void solve(){
    cin>>n;
    rep(i,1,n){
        cin>>s;
    }
    rep(i,1,MAXN*100-1) nd[i].sz = 1;
    while(1);
}

int main(){
    solve();
}