#include<bits/stdc++.h>
using namespace std;
#define int long long
const int llinf = 4223372036854775807;
const int maxn=510;
signed main(){
    int n,k;
    cin>>n>>k;
    vector<int> pr(maxn,0),dis(maxn,llinf);
    queue<int> q;
    q.push(0);
    dis[0]=0;
    while(!q.empty()){
        int t=q.front();
        q.pop();
        for(int i=0;i<=k;i++){
            if(t-i*2+k<=n&&t-i*2+k>=0&&t>=i&&t+k-i<=n){
                int to=t-i*2+k;
                if(dis[to]==llinf){
                    dis[to]=dis[t]+1;
                    pr[to]=t;
                    q.push(to);
                }
            }
        }
    }
    if(dis[n]==llinf){
        cout<<-1<<endl;
        return 0;
    }
    vector<int> gj;
    gj.push_back(n);
    int now=n;
    while(now){
        now=pr[now];
        gj.push_back(now);
    }
    reverse(gj.begin(), gj.end());
    set<int> s;
    int ans=0;
    int dd=0;
    for(int i=1;i<gj.size();i++){
        
        dd=gj[i]-gj[i-1];
        // cout<<"dis="<<dd<<' '<<s.size()<<' '<<gj[i-1]<<endl;
        int yy=-(dd-k)/2;
        int byy=k-yy;
        // cout<<yy<<' '<<byy<<endl;
        vector<int> ss,aa;
        ss.clear();
        for(int j=1;j<=n;j++){
            if(!s.count(j)&&byy){
                byy--;
                ss.push_back(j);
            }
        }
        while(yy--){
            aa.push_back(*s.begin());
            s.erase(s.begin());
        }
        cout<<"? ";
        for(int i=0;i<ss.size();i++)
            cout<<ss[i]<<' ';
        for(int i=0;i<aa.size();i++)
            cout<<aa[i]<<' ';
        cout<<endl;
        int tmp;
        cin>>tmp;
        ans^=tmp;
        for(int i=0;i<ss.size();i++)
            s.insert(ss[i]);
    }
    cout<<"!"<<endl;
    cout<<ans<<endl;
}