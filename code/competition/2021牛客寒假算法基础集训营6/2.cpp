#include <bits/stdc++.h>
using namespace std;
char mp[110][110];
int vis[110][110];
int n,m;
int biao[][2]={{1,0},{0,1},{-1,0},{0,-1}};
bool ck(int x,int y){
    if(x<=0||x>n)
        return false;
    if(y<=0||y>m)
        return false;
    return !vis[x][y]&&mp[x][y]!='#';
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    pair<int,int> st,ed;
    cin>>st.first>>st.second>>ed.first>>ed.second;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>mp[i][j];
    vis[st.first][st.second]=1;
    queue<pair<int,int>> q;
    q.push(st);
    while(!q.empty()){
        pair<int,int> t=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            if(ck(t.first+biao[i][0],t.second+biao[i][1])){
                q.push(make_pair(t.first+biao[i][0],t.second+biao[i][1]));
                vis[t.first+biao[i][0]][t.second+biao[i][1]]=vis[t.first][t.second]+1;
            }
        }
    }
    if(!vis[ed.first][ed.second]){
        cout<<-1<<endl;
        return 0;
    }else cout<<vis[ed.first][ed.second]*100-100<<endl;
}