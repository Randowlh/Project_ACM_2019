#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=510000;
string tmp;
string l,r;
int dp[maxn];
set<int> s;
bool ck(int l,int r,string& tt){
    if(tmp[l]=='0'){
        s.insert(l);
        auto i=s.find(l);
        i++;
        int tt=*i;
        s.erase(l);
        l=tt;
    }
    if(l>r)
        return true;
    if(r-l+1<tt.size())
        return true;
    if(r-l+1>tt.size())
        return false;
    for(int i=l;i<=r;i++){
        if(tt[i-l]>tmp[i])
            return true;
        else if(tt[i-l]<tmp[i])
            return false;
    }
    return true;
}
signed main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    #endif
    cin>>l>>r;
    cin>>tmp;
    for(int i=0;i<tmp.size();i++)
        if(tmp[i]!='0')
            s.insert(i);
    s.insert(tmp.size()+100);
    int ans1=0,ans2=0;
    int n=tmp.size();
    int ll=0,rr=0;
    int now=l.size()-1;
    while(1){
        if(l[now]!='0'){
            l[now]--;
            for(int i=now+1;i<l.size();i++)
                l[i]='9';
            break;
        }
        now--;
    }
    for(int i=0;i<n;i++){
        while(ck(ll,rr,l)&&rr<n)
            rr++;
        rr--;
        dp[i]=rr;
        ll++;
    }
    for(int i=0;i<n;i++)
        ans1+=dp[i]-i+1;
    ll=0,rr=0;
    for(int i=0;i<n;i++){
        while(ck(ll,rr,r)&&rr<n)
            rr++;
        rr--;
        dp[i]=rr;
        ll++;
    }
    for(int i=0;i<n;i++)
        ans2+=dp[i]-i+1;
    cout<<ans2-ans1<<endl;
}