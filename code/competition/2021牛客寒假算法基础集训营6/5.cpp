#include<bits/stdc++.h>
using namespace std;
#define int long long
int fa[5100];
string tt[5100];
int find(int x){
    if(x==fa[x])
        return x;
    else return fa[x]=find(fa[x]);
}
void merge(int a,int b){
    int l=find(a);
    int r=find(b);
    if(l!=r)
        fa[l]=r;
}
int tail=0;
int n,q;
map<string,int> M;
struct node{
    int u,v,w;
    bool operator<(node a){
        return w<a.w;
    }
}egs[210000];
inline int add(string &aa){
    if(M.count(aa))
        return M[aa];
    else {
        tail++;
        M[aa]=tail;
        tt[tail]=aa;
        return tail;
    }
}
signed main(){
    ios::sync_with_stdio(false);
    while(cin>>n>>q){
    string tmp;
    cin>>tmp;
    tail++;
    tt[tail]=tmp;
    M[tmp]=tail;
    string uu,vv;
    for(int i=1;i<=q;i++){
        cin>>uu>>vv>>egs[i].w;
        egs[i].u=add(uu);
        egs[i].v=add(vv);
    }
    for(int i=1;i<=n;i++)
        fa[i]=i;
    sort(egs+1,egs+q+1);
    int tot=0;
    int cnt=0;
    for(int i=1;i<=q;i++){
        if(find(egs[i].u)==find(egs[i].v))
            continue;
        cnt++;
        tot+=egs[i].w;
        merge(egs[i].u,egs[i].v);
    }
    if(cnt!=n-1){
        cout<<"No!"<<endl;
    }else cout<<tot<<endl;
    }
}