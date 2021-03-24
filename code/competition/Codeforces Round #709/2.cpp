#include<bits/stdc++.h>
using namespace std;
int date[110000],dis[110000];
void work(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>date[i];
    for(int i=1;i<n;i++)
        dis[i]=date[i+1]-date[i];
    set<int> s;
    int c=-1;
    int f=1;
    for(int i=1;i<n;i++){
        s.insert(dis[i]);
        if(dis[i]>0)
            c=dis[i];
        if(dis[i]<0)
            f=dis[i];
    }
    int m=c-f;
    if(s.size()<=1){
        cout<<0<<endl;
        return;
    }
    int now=date[1];
    if(date[1]>=m){
        cout<<-1<<endl;
        return;
    }
    for(int i=2;i<=n;i++){
        now=(now+c)%m;
        if(date[i]!=now){
            cout<<-1<<endl;
            return;
        }
    }
    cout<<m<<' '<<c<<endl;
}
int main(){
    // freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    while(t--){
        work();
    }
}