#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios::sync_with_stdio(false);
    int n,cnt;
    while(cin>>n>>cnt){
    int tot=0;
    int tmp;
    int flag=0;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        if(tmp==cnt&&!flag){
            flag=1;
            continue;
        }
        tot+=tmp;
    }
    if(n!=2)
    cout<<(tot)%11<<endl;
    else cout<<tot<<endl;
    }
}