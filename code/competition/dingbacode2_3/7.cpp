#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int tmp;
    vector<int> v;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    int ans=1;
    for(int i=0;i<n;i++){
        if(v[i]==i+1){
            continue;
        }else{
            for(int j=i+1;j<n;j++){
                if(v[j]==i+1){
                    cout<<"Yes"<<endl;
                    cout<<j-i+1<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"Yes"<<endl;
    cout<<1<<endl;
}