#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod= 1e9+7;
vector<ll> primes;
bool is_prime[160000100];
void euler(int n)
{
   is_prime[1] = 1;
   for (ll i = 2; i < n+10; i++)
   {
      if (!is_prime[i])
      primes.push_back(i);
      for (ll j = 0; j < primes.size() && i * primes[j] < n+10; j++)
      {
         is_prime[i * primes[j]] = 1;
         if ((i % primes[j]) == 0)
            break;
      }
   }
}
int main(){
    ll n;
    cin>>n;
    euler(n);
    if(n<6){
        cout<<"empty"<<endl;
        return 0;
    }
    vector<ll> v;
    for(int i=0;i<primes.size();i++){
        ll tt=primes[i];
        ll now=1;
        for(int j=1;j<1000;j++){
            if(now*tt*(2+(tt==2))>n)
                break;
            now*=tt;
        }
        v.push_back(now);
    }
    ll ans=1;
    for(int i=0;i<primes.size();i++)
        ans=(ans*(v[i]%mod))%mod;
    cout<<ans<<endl;
}