#include<bits/stdc++.h>
#define ll long long
using namespace std;
char a[1100],b[1100];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    int ans=n;
    for(int i=1;i<=n;i++){
        ans+=(a[i]==b[i]);
    }
    cout<<ans<<" 0"<<endl;
}