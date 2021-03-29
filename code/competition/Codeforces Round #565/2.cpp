#include<bits/stdc++.h>
using namespace std;
void work(){
    int n;
    cin>>n;
    // vector<int> v;
    int aa[3];
    memset(aa,0,sizeof aa);
    int tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        aa[tmp%3]++;
    }
    int dis=max(aa[1],aa[2])-min(aa[1],aa[2]);
    cout<<aa[0]+min(aa[1],aa[2])+dis/3<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--) work();
    return 0;    
}