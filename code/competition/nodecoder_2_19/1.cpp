#include<bits/stdc++.h>
using namespace std;
int tot[100],ac[100];
int ff[100];
int main(){
    // freopen("in.txt","r",stdin);
    int n,m;
    cin>>m>>n;
    memset(ff,1,sizeof ff);
    for(int i=1;i<=m;i++){
        int tmp;
        string ss;
        cin>>tmp>>ss;
        if(ss=="AC"){
            ac[tmp]++;
        } tot[tmp]++;
        if(ac[tmp]*2<tot[tmp])
            ff[tmp]=0;
    }
    int fl=0;
    for(auto i=1; i<=n; i++){
        if(!tot[i])
            continue;
        if(ff[i]){
            cout<<i<<' ';
            fl=1;
        }
    }
    if(!fl){
        cout<<-1<<' ';
    }
    cout<<endl;
}