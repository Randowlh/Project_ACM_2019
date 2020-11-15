#include <bits/stdc++.h>
using namespace std;
void work()
{
    int ans=0;
    for(int i=13930;i<=457439;i++){
        int t=i;
        vector<int> v;
        while(t){
            v.push_back(t%10);
            t/=10;
        }
        int flag=0;
        for(int j=0;j<v.size()-1;j++){
            if(abs(v[j]-v[j+1])>7){
                flag=1;
                break;
            }
        }
        if(!flag&&abs(v[0]-v[v.size()-1])>2)
            ans++;
    }
    cout<<ans<<endl;
}
signed main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
//std::ios::sync_with_stdio(false);
//cin.tie(NULL);
int t = 1;
//cin>>t;
while (t--)
{
    cout<<180692<<endl;
//work();
}
return 0;
}