#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
template<class T>inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
#define int ll
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
int x1,x2,y1,y2;
/*
int ans = 0;
for(int l = 1, r = 0; l <= n; l = r + 1) {
    r = n / (n / l);  			// 求区间的右端，这是一个数学规律 
    ans += (r - l + 1) * (n / l);
} 
*/	
const int MAXN = 1114514;
const ll med = 1e9+7;
ll res;
const ll inv6 = 166666668;//6的逆元

inline ll getpfh(ll x){
    if(x==0) return 0;
    return ((x*(x+1)%med)*(2*x+1)%med)*inv6%med;
}
inline ll getjj(ll x){
    if(x==0) return 0;
    return ((1+x)*x/2)%med;
}
inline ll cal_pf(ll x1,ll x2){
    if(x2==0) return 0;
    ll ret = 0;
    ll tmp = x2/x1;
    ret += x1*getpfh(tmp-1)%med;
    ret %= med;
    ret += ((x2-tmp*x1+1)%med)*(tmp*tmp%med)%med;
    return ret%med;
}
inline ll cal_jj(ll x1,ll x2){//i/x1加起来
    if(x2==0) return 0;
    ll ret = 0;
    ll tmp = x2/x1;
    ret += x1*getjj(tmp-1)%med;
    ret %= med;
    ret += (x2-tmp*x1+1)*tmp%med;
    return ret%med;
}
void solve(){
    cin>>x1>>x2>>y1>>y2;
    ll resx = 0,resy = 0;
    res = 0;
    //数论分块n/i
    ll jjx = cal_jj(x1,x2);
    ll jjy = cal_jj(y1,y2);
    ll tmpb = 0;
    for(int lx = x1, rx = 0; lx <= x2; lx = rx + 1) {
        //cout<<"lx"<<lx<<endl;
        //b^2
        rx = x2 / (x2 / lx);  			// 求区间的右端
        resx += (rx-lx+1)*((x2/rx)*(x2/rx)%med)%med;
        resx%=med;
        //2ab
        resx += ( 2*((cal_jj(x1,rx)-cal_jj(x1,lx-1)+med)%med)*(x2/rx) )%med;
        resx %= med;

        //2cb加到res上
        res += (2*(rx-lx+1)*(x2/rx)%med)*jjy%med;
        
        //算tmpb
        tmpb += (rx-lx+1)*(x2/rx)%med;
        tmpb %= med;
    } 	
    //d^2
    for(int ly = y1, ry = 0; ly <= y2; ly = ry + 1) {
        ry = y2 / (y2 / ly);  			// 求区间的右端
        resy += ((ry-ly+1)*((y2/ry)*(y2/ry)%med)%med);
        resy %= med;
        //2cd
        resy += ( 2*((cal_jj(y1,ry)-cal_jj(y1,ly-1)+med)%med)*(y2/ry) )%med;
        resy %= med;

        //2ad加到res上
        res += (2*((ry-ly+1)*(y2/ry)%med*jjx%med)%med)%med;
        res %= med;

        //根据tmpb算2bd
        res += ((2*(ry-ly+1)*(y2/ry))%med)*tmpb;

    }
    //cout<<"check"<<resx<<' '<<resy<<endl;
    //平方和通项 n*(n+1)*(2n+1)/6
    //a^2
    resx = (resx+cal_pf(x1,x2))%med;
    //cout<<"a^2"<<cal_pf(x1,x2)<<endl;
    //c^2
    resy = (resy+cal_pf(y1,y2))%med;
    //cout<<"c^2"<<cal_pf(y1,y2)<<endl;
    //cout<<"check"<<resx<<' '<<resy<<endl;
    //resx和resy加起来到res上
    res += (resx*(y2-y1+1)%med + resy*(x2-x1+1)%med)%med;
    res %= med;
    //2ac
    //cout<<"2ac"<<2*jjx*jjy<<endl;
    res += ((jjx*jjy)%med)*2%med;
    res%=med;
    
    cout<<res<<endl;
}

signed main(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    #endif
    //cout<<cal_jj(2,6)<<endl;
    //cout<<cal_pf(2,6)<<endl;
    int z;
    cin>>z;
    while(z--) solve();
}