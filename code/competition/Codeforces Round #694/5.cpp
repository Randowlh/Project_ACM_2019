#include <bits/stdc++.h>
using namespace std;
#pragma optimize(2)
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
template<class T>inline void rd(T &x){
   x=0;char o,f=1;
   while(o=getchar(),o<48)if(o==45)f=-f;
   do x=(x<<3)+(x<<1)+(o^48);
   while(o=getchar(),o>47);
   x*=f;
}
vector<int> mp[310000];
int date[310000];
int book[310000];
int find(int x){
    if(date[x]==x)
        return x;
    else return date[x]=find(date[x]);
}
void merge(int a,int b){
    int l=find(a);
    int r=find(b);
    if(l^r)
        date[l]=r;
}
void work()
{
    int n,m;
    rd(n),rd(m);
    for(int i=1;i<=n;i++)
        date[i]=i,book[i]=-1,mp[i].clear();
    int u,v;
    for(int i=1;i<=m;i++){
        rd(u),rd(v);
        mp[u].push_back(v);
        mp[v].push_back(u);
        merge(u,v);
    }
    vector<int> ans;
    set<int> s;
    for(int i=1;i<=n;i++)
        s.insert(find(i));
    if(s.size()>1){
        cout<<"NO"<<endl;
        return;
    }
    queue<int> q;
    for(int i=0;i<mp[1].size();i++)
        q.push(mp[1][i]);
    book[1]=1;
    ans.push_back(1);
    while(!q.empty()){
        int t=q.front();
        q.pop();
        for(int i=0;i<mp[t].size();i++){
            int& to=mp[t][i];
            if(book[to]!=-1)
                continue;
            book[to]=1;
            ans.push_back(to);
            for(int j=0;j<mp[to].size();j++){
                book[mp[to][j]]=0;
                q.push(mp[to][j]);
            }
        }
    }
    int flag=0;
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<mp[ans[i]].size();j++){
            int &to=mp[ans[i]][j];
            if(book[to]){
                flag=1;
                break;
            }
        }
    }
    if(flag){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    cout<<ans.size()<<endl;
    sort(ans.begin(), ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}
signed main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
// std::ios::sync_with_stdio(false);
// cin.tie(NULL);
int t = 1;
cin>>t;
while (t--)
{
work();
}
return 0;
}