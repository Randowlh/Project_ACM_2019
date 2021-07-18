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
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
const int MAXN = 314514;

int n,m;
struct Node{
    int l,r;
}pool[MAXN];

int st[MAXN];//连表头编号100000+x
int ed[MAXN];//连表尾编号200000+x
inline int tst(int x){return x+100000;}
inline int ted(int x){return x+200000;}
inline bool OK(int x){return x<=100000;}//判断是否为连表头/尾位置
int tmp[MAXN],cnttmp;
void dfs(int now,int pre){
    if(!OK(now)) return;
    tmp[++cnttmp]=now;
    if(pool[now].l!=pre)
        dfs(pool[now].l,now);
    else if(pool[now].r!=pre)
        dfs(pool[now].r,now);
}

void solve(){
    rep(i,1,n){
        st[i]=i;
        ed[i]=i;
        pool[i].l=tst(i);
        pool[i].r=ted(i);
    }
    int a,b;
    //pull a to b;
    while(m--){
        cin>>a>>b;
        if(st[a]==ted(a)) continue;//连表为空，不操作
        int now = ed[a];
        if(pool[ed[a]].r==ted(a)){
            if(pool[ed[b]].r==ted(b)){
                pool[ed[a]].r=ed[b];
                pool[ed[b]].r=ed[a];
                pool[st[a]].l=ted(b);
            }
            else{//pool[ed[b]].l==ted(b)
                pool[ed[a]].r=ed[b];
                pool[ed[b]].l=ed[a];
                pool[st[a]].l=ted(b);
            }
        }
        else{//pool[ed[a]].l==a+200000
            if(pool[ed[b]].r==ted(b)){
                //连接
                pool[ed[a]].l=ed[b];
                pool[ed[b]].r=ed[a];
                pool[st[a]].r=ted(b);
            }
            else{//pool[ed[b]].l==ted(b)
                //连接
                pool[ed[a]].l=ed[b];
                pool[ed[b]].l=ed[a];
                pool[st[a]].r=ted(b);
            }
        }
        ed[b]=st[a];//更新b尾
        //清空连表a
        ed[a]=tst(a);
        st[a]=ted(a);

        cout<<"===check==="<<endl;
        rep(i,1,n){
            cnttmp = 0;
            dfs(st[i],tst(i));
            rep(i,1,cnttmp){
                cout<<tmp[i];
                if(i!=cnttmp) cout<<' ';
            }
            if(!cnttmp) cout<<0;
            cout<<endl;
        }
        /*
        cout<<"===check_lr==="<<endl;
        rep(i,1,n){
            cout<<i<<"----l:"<<pool[i].l<<"  r:"<<pool[i].r<<endl;
        }
        cout<<"===check_sted==="<<endl;
        rep(i,1,n){
            cout<<i<<"----st:"<<st[i]<<"  ed:"<<ed[i]<<endl;
        }
        */
    }
    rep(i,1,n){
        cnttmp = 0;
        dfs(st[i],tst(i));
        
        rep(i,1,cnttmp){
            cout<<tmp[i];
            if(i!=cnttmp) cout<<' ';
        }
        if(!cnttmp) cout<<0;
        cout<<endl;
    }
}

int main(){
    while(cin>>n>>m){
        solve();
    }
}