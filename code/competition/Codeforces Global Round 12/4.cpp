#include<bits/stdc++.h>
using namespace std;
int main(){
    int _;
    while(_--){
        int n = 0;
        cin>>n;
        vector<int> v;
        int tmp;
        int mi=999;
        for(int i=1;i<=n;i++){
            cin>>tmp;
            v.push_back(tmp);
            mi=min(tmp,mi);
        }
        if(mi!=1){
            for(int i=1;i<=n;i++){
                cout<<0;
            }
            cout<<endl;
            continue;
        }
        int l=0,r=n-1;
        vector<int> ans;
        ans.push_back(0);
        for(int i=1;i<=n;i++){
            
        }
    }   
}