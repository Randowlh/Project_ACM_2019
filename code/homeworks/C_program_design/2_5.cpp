#include <bits/stdc++.h>
using namespace std;
int q[110000],stk[110000];
int qh,qt,st;
int main(){
    int n;
    cin>>n;
    int tmp;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        if(tmp>=0)   
            stk[st++]=tmp;
        else
            q[qt++]=tmp;
    }
    while(st)
        cout<<stk[--st]<<' ';
    cout<<endl;
    while(qh^qt)
        cout<<q[qh++]<<' ';
    cout<<endl;
}