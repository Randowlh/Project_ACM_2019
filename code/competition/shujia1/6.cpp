#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define rep(i,l,r) for (int i=(l); i<=(r); i++)
typedef long long ll;
using namespace std;

const int N=1010,M=50010,mod=1e9+7;
int T,n,m,d[20],g[20],ans[N],tr[M][4],cnt[M],f[20][M];
char s[20],c[10]="ACGT";

int main(){
    for (scanf("%d",&T); T--; ){
        scanf("%s%d",s+1,&m); n=strlen(s+1);
        cout<<"n="<<n<<endl;
        for (int S=0; S<1<<n; S++){
            if (S) cnt[S]=cnt[S^(S&-S)]+1;
            rep(i,0,n-1) d[i+1]=d[i]+((S>>i)&1);
            rep(k,0,3){
                rep(i,1,n) g[i]=max(max(d[i],g[i-1]),(c[k]==s[i])?d[i-1]+1:0);
                tr[S][k]=0;
                rep(i,0,n-1) if (g[i+1]-g[i]) tr[S][k]|=1<<i;
            }
        }
        memset(ans,0,sizeof(ans)); memset(f,0,sizeof(f)); f[0][0]=1;
        rep(i,1,m){
            int v=i&1,u=v^1; memset(f[v],0,sizeof(f[v]));
            for (int S=0; S<1<<n; S++)
                rep(k,0,3) f[v][tr[S][k]]=(f[v][tr[S][k]]+f[u][S])%mod;
        }
        for (int S=0; S<1<<n; S++) ans[cnt[S]]=(ans[cnt[S]]+f[m&1][S])%mod;
        rep(i,0,n) printf("%d\n",ans[i]);
    }
    return 0;
}