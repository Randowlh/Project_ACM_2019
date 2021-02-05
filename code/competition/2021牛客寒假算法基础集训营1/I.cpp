#include <bits/stdc++.h>
using namespace std;
int vis[110000];
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v;
    v.push_back(2);
    vis[2]=1;
    for(int i=4;i<=n&&k;i+=2,k--){
        if(i==6){
            k++;
            continue;
        }
        v.push_back(i);
        vis[i]=1;
    }
    if(k){
        v.push_back(6);
        vis[6]=1;
        k--;
        if(k){
            v.push_back(3);
            vis[3]=1;
            k--;
        }
    }
    for(int i=1;i<=n;i++){
        if(!vis[i])
            v.push_back(i);
    }
    if(v.size()==n&&!k){
        for(int i=0;i<n;i++){
            cout<<v[i]<<' ';
        }
        cout<<endl;
    }else cout<<-1<<endl;
}