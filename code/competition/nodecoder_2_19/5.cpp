#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1000000007;
inline int exgcd(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
      int q = a1 / b1;
      tie(x, x1) = make_tuple(x1, x - q * x1);
      tie(y, y1) = make_tuple(y1, y - q * y1);
      tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}
inline int niyuan(int a,int b){ int tmp,ans;exgcd(a,b,ans,tmp);return (ans%b+b)%b;}
string opt;
int tot,tmp;
int fa[100010],date[100010],ans[100010];
vector<int> mp[100010];
void dfs(int pos){
    // cout<<"pos="<<pos<<endl;
    ans[pos]=tot;
    for(int i=0;i<mp[pos].size();i++){
        int tt=tot;
        int ttmp=tmp;
        int to=mp[pos][i];
        if(opt[to]=='+'){
            tot=(tot+date[to])%mod;
            tmp=date[to]%mod;
        }else if(opt[to]=='-'){
            tot=((tot-date[to])%mod+mod)%mod;
            tmp=(mod-date[to]%mod)%mod;
        }else if(opt[to]=='*'){
            tot=((tot-tmp)%mod+mod)%mod;
            tmp=tmp*date[to]%mod;
            tot=(tot+tmp)%mod;
        }else if(opt[to]=='/'){
            // cout<<"asdadasd"<<endl;
            tot=((tot-tmp)%mod+mod)%mod;
            tmp=tmp*niyuan(date[to],mod)%mod;
            tot=(tot+tmp)%mod;
        }
        // cout<<"niyuan"<<niyuan(4,mod)<<endl;
        dfs(to);
        tot=tt;
        tmp=ttmp;
    }
}
signed main(){
    // freopen("in.txt","r",stdin);
    int n;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&date[i]);
    for(int i=2;i<=n;i++){
        scanf("%lld",&fa[i]);
        mp[fa[i]].push_back(i);
    }
    cin>>opt;
    opt="  "+opt;
    tot=tmp=date[1];
    dfs(1);
    for(int i=1;i<=n;i++){
        printf("%lld ",ans[i]);
    }
    printf("\n");
}