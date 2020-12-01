#include<bits/stdc++.h>
using namespace std;
vector<int> mp[11000];
int tim[11000];
int salt[11000];
void work(){
    int n,m,q;
    cin>>n>>m>>q;
    int a,b;
    for(int i=1;i<=n;i++){
        mp[i].clear();
        salt[i]=0;
    }
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    for(int j=1;j<=q;j++){
        for(int i=1;i<=n;i++)
            tim[i]=-1;
        queue<int> q;
        int a,ti;
        cin>>a>>ti;
        q.push(a);
        salt[a]++;
        tim[a]=0;
        while(!q.empty()){
            int t=q.front();
            q.pop();
            if(tim[t]==ti)
                continue;
            for(int i=0;i<mp[t].size();i++){
                int to=mp[t][i];
                if(tim[to]!=-1)
                    continue;
                tim[to]=tim[t]+1;
                salt[to]++;
                q.push(to);
            }
        }
    }
    for(int i=1;i<n;i++){
        cout<<salt[i]<<' ';
    }
    cout<<salt[n]<<endl;
}
int main(){
    freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        work();
    }
}