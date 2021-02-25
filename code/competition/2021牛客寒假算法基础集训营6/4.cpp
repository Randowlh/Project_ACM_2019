#include <bits/stdc++.h>
using namespace std;
const int mod =998244353;
void work(){
    int n;
    cin>>n;
    if(n%2){
        cout<<0<<endl;
        return;
    }
    if(n==0){
        cout<<1<<endl;
        return;
    }
    n/=2;
    n/=2;
    cout<<n+1<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    int t ;
    cin>>t;
    while(t--){
        work();
    }
    return 0;
}