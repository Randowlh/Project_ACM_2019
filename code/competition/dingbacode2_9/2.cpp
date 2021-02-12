#include<bits/stdc++.h>
using namespace std;
#define int long long
map<int,int> A;
const int mo=212370440130137957ll;
int date[110000];
vector<int> prm;
const int maxn=100110;
bool is_prime[110000];
void euler(){
  is_prime[1]=1;
  for(int i=2;i<=maxn;i++){
    if(!is_prime[i])
      prm.push_back(i);
    for(int j=0;j<prm.size()&&i*prm[j]<=maxn;i++){
      is_prime[i*prm[j]]=1;
      if(i%prm[j]==0)
        break;
    }
  }
}
unordered_map<int,int> M;
int lk[maxn];
signed main(){
  euler();
  for(int i=0;i<prm.size();i++){
    lk[prm[i]]=i;
  }
  int n;
  scanf("%lld",&n);
  for(int i=1;i<=n;i++)
    scanf("%lld",&date[i]);
  bitset<110000> aa;
  hash<bitset<110000>> hash;
  M[hash(aa)]++;
  int ans=0;
  for(int i=1;i<=n;i++){
    for(int j=0;j<prm.size()&&prm[j]*prm[j]<=date[i];j++){
      if(date[i]%prm[j]==0){
        int cnt=0;
        while(date[i]%prm[j]==0){
          date[i]/=prm[j];
          cnt^=1;
        }
        if(!cnt)
          continue;
        if(aa[j]){
          aa[j]=0;
        }else aa[j]=1;
      }
    }
    //   cout<<"date[i]="<<date[i]<<endl;
      if(date[i]!=1){
        if(aa[lk[date[i]]]){
          aa[lk[date[i]]]=0;
        }else aa[lk[date[i]]]=1;
      }
      ans+=M[hash(aa)];
      M[hash(aa)]++;
  }
  cout<<ans<<endl;
}