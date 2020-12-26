#include<bits/stdc++.h>
using namespace std;
#define int long long
const int llinf = 4223372036854775807;
template<class T>inline void rd(T &x){
   x=0;char o,f=1;
   while(o=getchar(),o<48)if(o==45)f=-f;
   do x=(x<<3)+(x<<1)+(o^48);
   while(o=getchar(),o>47);
   x*=f;
}
struct node{
    int a,b;
    node(){}
    node(int a,int b):a(a),b(b){}
    inline bool operator<(node aa){
        if(a==aa.a){
            return b<aa.b;
        }return a>aa.a;
    }
}date[210000];
signed main(){
    int n;
    rd(n);
    int a,b;
    for(int i=1;i<=n;i++){
        rd(date[i].a);
    }
    for(int i=1;i<=n;i++){
        rd(date[i].b);
    }
    date[n+1]=node(0,0);
    sort(date+1,date+n+1);
    int am=date[1].a;
    int bm=0;
    int ans=date[1].a;
    for(int i=1;i<=n;i++){
        am=date[i+1].a;
        bm=max(bm,date[i].b);
        ans=min(ans,bm+am);
    }
    cout<<ans<<endl;
}