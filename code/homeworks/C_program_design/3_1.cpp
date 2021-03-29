#include<bits/stdc++.h>
using namespace std;
int date[1100];
int getmi(int l,int r){
    if(l==r)
        return date[l];
    int mid=(l+r)>>1;
    return min(getmi(l,mid),getmi(mid+1,r));
}
int getma(int l,int r){
    if(l==r)
        return date[l];
    int mid=(l+r)>>1;
    return max(getma(l,mid),getma(mid+1,r));
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>date[i];
    cout<<"The min value="<<getmi(1,n)<<endl;
    cout<<"The max value="<<getma(1,n)<<endl;
}