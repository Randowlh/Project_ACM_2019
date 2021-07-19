#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
//int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
template<class T>inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
#define int ll

const int MAXN = 4400;
const int maxs = 8e4;
int prm[maxs+1];//记录i的最小质因子，用于质因数分解
//si <= 8e4
int s[MAXN];
int cnt[MAXN][110];//数第i个s元素的第j个质因子次数
//初始化质数
int mp[maxs];//质数映射到下标
int vprm[110],cntp=0;
void init(){
    int sqr = sqrt(maxs);
    rep(i,2,sqr){
        if(prm[i]) continue;
        vprm[++cntp] = i;
        for(int j=i+i;j<=maxs;j+=i){
            prm[j] = i;
        }
    }
    rep(i,1,cntp) mp[vprm[i]]=i;
    //小于sqr的质数为60个
    /*
    cout<<cntp<<endl;
    rep(i,1,cntp) cout<<vprm[i]<<' ';
    cout<<endl;
    */
}
int n,k,p;
vector<int> vec[110];//记录每个质因子在每个位置出现的次数
ll qpow(ll d,ll c){//快速幂
    ll res = 1;
    while(c){
        if(c&1) res=res*d%p;
        d=d*d%p;c>>=1;
    }return res;
}
//组合数板子==============================
int zuhe[MAXN+1][100];
int m[MAXN+1][100];//用m标记是否越过了phi
void initc(int ph){
    int i,j;
    rep(i,0,35){
        zuhe[0][i]=0;
    }
    rep(i,0,MAXN){
        zuhe[i][0]=1;
    }
    rep(i,1,MAXN){
        rep(j,1,35){
            zuhe[i][j] = (zuhe[i-1][j]+zuhe[i-1][j-1]);
            if(m[i-1][j-1]||m[i-1][j]||zuhe[i][j]>=ph) m[i][j] = 1;
            zuhe[i][j]%=ph;
        }
    }
}
inline int C(int x,int y){
    return zuhe[x][y];
}
//组合数板子=========================
int euler_phi(int n){
    int sqr = sqrt(n+0.5);
    int res = n; 
    for(int i=2;i<=sqr;i++){
        if(n%i==0){//找到一个质因子 
            res = res/i*(i-1);//先除后乘，防止越界 
            while(n%i==0) n/=i;//把这个因子从n中消除掉 
        }
    }
    if(n>1) res = res/n*(n-1);//大于sqrt的因子最多只有一个 
    return res; 
}
map<int,int> Cbp;//记录大的质数
inline void solve(){
    Cbp.clear();
    read(n),read(k),read(p);
    //清空数组
    rep(i,1,60) vec[i].clear();
    rep(i,1,n)
        rep(j,1,60) cnt[i][j] = 0;//清空

    int tmp;
    rep(i,1,n){
        read(s[i]);//质因数分解
        tmp = s[i];
        //cout<<"check s["<<i<<"]"<<endl;
        while(prm[tmp]){
            //cout<<tmp<<endl;
            cnt[i][mp[prm[tmp]]]++;//记数
            tmp/=prm[tmp];
        }
        if(tmp!=1){//讨论大于sqr的质因,最多一个
            //cout<<"left tmp"<<tmp<<' '<<mp[tmp]<<endl;
            if(mp[tmp]) cnt[i][mp[tmp]]++;
            else Cbp[tmp]++;
            //用map存一下
        }
        rep(j,1,60)
            if(cnt[i][j]!=0) vec[j].push_back(cnt[i][j]);
    }
    int phip = euler_phi(p);
    //拆分完成，之后根据排列组合算
    initc(phip);//初始化阶乘，虽然k比较小，但还是用板子或许更快
    //p会变,所以组合数板子不太好使？除非对每个z都算一次组合数
    int siz;
    ll res = 1;
    rep(i,1,60){
        sort(vec[i].begin(),vec[i].end());
        siz = vec[i].size();
        rep(j,1,siz-k+1){
            res *= qpow(qpow(vprm[i],vec[i][j-1]),C(siz-j,k-1)+m[siz-j][k-1]*phip);
            res %= p;
        }
    }
    map<int,int>::reverse_iterator iter;
    for(iter = Cbp.rbegin();iter!=Cbp.rend();iter++){
        if(iter->second>=k){
            res *= qpow(iter->first,C(iter->second,k)+m[iter->second][k]*phip);
            res %= p;
            //如果某个大质数的数量x超过k,那么就乘上C(x,k)*prm
        }
    }
    printf("%lld\n",res);
}

signed main(){
    freopen("in.txt","r",stdin);
    init();
    int z;
    read(z);
    while(z--) solve();
}