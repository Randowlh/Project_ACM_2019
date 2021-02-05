#include <bits/stdc++.h>
using namespace std;
vector<int> mp[110000];
char ans[110000];
struct node{
    int cnt;
    bool cl;
}date[110000];
int main(){
    int n;
    cin>>n;
    if(n%2!=0){
        cout<<-1<<endl;
        return 0;
    }
    int u,v;
    for(int i=1;i<=n-1;i++){
        cin>>u>>v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(mp[i].size()==1)
            q.push(i);
    while(!q.empty()){
        int t=q.front();
        
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i];
    cout<<endl;
}