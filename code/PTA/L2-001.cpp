#include<bits/stdc++.h>
using namespace std;
struct egs{
    int to,nxt,w;
}eg[310000];
pair<int,int> dis[1100];
int date[1100],head[1100],ccnt[1100],pr[1100],flag[1100];
int n,m,s,d;
int ecnt=0;
void add(int u,int v,int w){
    eg[++ecnt].nxt=head[u];
    eg[ecnt].w=w;
    eg[ecnt].to=v;
    head[u]=ecnt;
}
void dij(){
    ccnt[s]=1;
    for(int i=0;i<n;i++)
        dis[i]=make_pair(0x3f3f3f3f,0);
    dis[s]=make_pair(0,date[s]);
    int cnt=0;
    while(cnt<n){
        int mi=0x7FFFFFFF,mix;
        for(int i=0;i<n;i++)
            if(dis[i].first<mi&&flag[i]==0)
                mi=dis[i].first,mix=i;
        // cout<<"mix="<<mix<<endl;
        flag[mix]=1;
        cnt++;
        for(int i=head[mix];i;i=eg[i].nxt){
            int to=eg[i].to,w=eg[i].w;
            if(dis[to].first>dis[mix].first+w){
                ccnt[to]=ccnt[mix];
                dis[to]=make_pair(dis[mix].first+w,dis[mix].second+date[to]);
                pr[to]=mix;
                continue;
            }
            if(dis[to].first==dis[mix].first+w)
                ccnt[to]+=ccnt[mix];
            if(dis[to].first==dis[mix].first+w&&dis[to].second<dis[mix].second+date[to]){
                dis[to]=make_pair(dis[mix].first+w,dis[mix].second+date[to]);
                pr[to]=mix;
                continue; 
            }
            
        }
    }
}
int main(){
    // freopen("in.txt","r",stdin);
    cin>>n>>m>>s>>d;
    for(int i=0;i<n;i++)
        cin>>date[i];
    int u,v,w;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }
    dij();
    cout<<ccnt[d]<<' '<<dis[d].second<<endl;
    vector<int> vv;
    int now=d;
    while(now!=s){
        vv.push_back(now);
        now=pr[now];
    }
    vv.push_back(s);
    reverse(vv.begin(),vv.end());
    for(int i=0;i<vv.size()-1;i++)
        cout<<vv[i]<<' ';
    cout<<vv[vv.size()-1]<<endl;
}