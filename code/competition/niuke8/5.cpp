#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define endl '\n'
int n,sa,sb;
const int MAXN = 114514;
#define INF 0x3f3f3f3f
vector<int> e[MAXN];
int dep[MAXN];
int maxdep[MAXN];//子树最大dep
bool flag[MAXN];//标记链上的点
void dfs(int pos,int pre){
    //cout<<"dfs "<<pos<<endl;
    dep[pos]=dep[pre]+1;
    maxdep[pos] = 1;
    for(auto to:e[pos]){
        if(to==pre) continue;
        dfs(to,pos);
        if(!flag[to]) MAX(maxdep[pos],maxdep[to]+1);//不往链上的方向算深度
    }
}
int disab;//ab链上点数
vector<int> lian;
bool dfs2(int pos,int pre,int dis){//找ab链上的店
    //cout<<"dfs2 "<<pos<<endl;
    if(pos==sa){
        disab = dis;
        lian.push_back(pos);
        flag[pos] = 1;
        return 1;
    }
    for(auto to:e[pos]){
        if(to==pre) continue;
        if(dfs2(to,pos,dis+1)){
            lian.push_back(pos);
            flag[pos] = 1;
            return 1;
        }
    }
    return 0;
}
int res;
int mfront[MAXN];
int mback[MAXN];
inline void solve(){
    cin>>n>>sa>>sb;
    int u,v;
    rep(i,1,n-1){
        cin>>u>>v;
        e[v].push_back(u);
        e[u].push_back(v);
    }
    dfs2(sb,0,1);
    dfs(sb,0);
    if(sa==sb){
        cout<<maxdep[sa]-1<<endl;
        return;
    }
    cout<<"check lian"<<endl;
    rep(i,0,disab-1) cout<<lian[i]<<':'<<maxdep[lian[i]]<<' ';
    cout<<endl;
    if(disab!=lian.size()) cout<<"error"<<endl;

    //mfront[0] = maxdep[lian[0]];//无用
    //rep(i,1,disab-1) mfront[i] = max(mfront[i-1] , i+maxdep[lian[i]]);
    mback[disab-1] = maxdep[lian[disab-1]];
    repb(i,disab-2,0) mback[i] = max(mback[i+1] , (disab-1-i)+maxdep[lian[i]]);
    
    int now,disa,disb;
    res = -INF;
    int tmp = INF;
    cout<<"disab"<<disab<<endl;
    rep(i,0,disab-1){//disab-1这点a绝对到不了
        now = lian[i];
        disa = i+1;
        disb = disab-i;
        int b_du,b_budu;
        if(disa>disb){//b先到
            b_du = (disa-1) - (disb+maxdep[lian[i]]-1);
            b_budu = (disa+maxdep[lian[i]]-1) - (mback[i+1]);
            if(disb+1!=disa) b_du--;
            cout<<"fjd"<<i<<':'<<b_du<<' '<<b_budu<<endl;
            MIN(tmp,min(b_du,b_budu));
            cout<<"MIN"<<min(b_du,b_budu)<<endl;
        }
        else if(disa<=disb){//a先到
            //a进去

            b_budu = (disa+maxdep[lian[i]]-1) - mback[i+1];
            if(disa==disb)
                b_budu--;
            // cout<<"fjd"<<i<<':'<<b_budu<<endl;
            MAX(res,    b_budu);
        }
    }
    MAX(res,tmp);
    cout<<res<<endl;
}
int main(){
    solve();
}