int pre[maxn+100];
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
inline int niyuan(int x, int mod) { return powmod(x, mod - 2); }
void init(){
    pre[0]=1;
    for(int i=1;i<=maxn;i++)
        pre[i]=pre[i-1]*i%mod;
}
int C(int n,int m){
    if(n<m)
        return 0;
    return pre[n]*powmod(pre[n-m],mod-2)%mod*powmod(pre[m],mod-2)%mod;
}