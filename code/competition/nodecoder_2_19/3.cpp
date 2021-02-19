#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
int mod= 1000000007; 
const int maxn =11000;
vector<int> primes;
bool is_prime[11100];
void euler()
{
   is_prime[1] = 1;
   for (int i = 2; i < maxn; i++)
   {
      if (!is_prime[i])
      primes.push_back(i);
      for (int j = 0; j < primes.size() && i * primes[j] < maxn; j++)
      {
         is_prime[i * primes[j]] = 1;
         if ((i % primes[j]) == 0)
            break;
      }
   }
}
int x[11000],p[11000];
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
signed main(){
    // freopen("in.txt","r",stdin);
    euler();
    int n;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&x[i]);
    for(int i=1;i<=n;i++)
        scanf("%lld",&p[i]);
    map<int,int> M;
    int tmp=x[1];
    for(int i=0;i<primes.size()&&primes[i]*primes[i]<=tmp;i++){
        while(tmp%primes[i]==0){
            // cout<<"asdasdas"<<endl;/
            M[primes[i]]++;
            tmp/=primes[i];
        }
    }
    // cout<<"dsadsada"<<endl;
    if(tmp!=1)
        M[tmp]++;
    for(auto i=M.begin();i!=M.end();i++)
        i->second*=p[1];
    for(int i=2;i<=n;i++){
        for(auto j=M.begin();j!=M.end();j++){
            int cnt=0;
            while(x[i]%j->first==0){
                x[i]/=j->first;
                cnt++;
            }
            cnt*=p[i];
            j->second=min(cnt,j->second);
        }
    }
    int ans=1;
    for(auto i=M.begin();i!=M.end();i++)
        ans=ans*powmod(i->first,i->second)%mod;
    printf("%lld\n",ans);
}