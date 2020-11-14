#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int _,n,m,len;
ull ans,a[1000005],b[1000005],w[1000005];
char s[1000005],str[1000005];
set<ull> v;
signed main(){
    int i,x;
    w[0]=1;
    for (i=1;i<=1e6;i++) w[i]=w[i-1]*27;
    for (scanf("%d",&_);_;_--){
        scanf("%s",s+1);
        n=strlen(s+1);
        a[0]=0;
        for (i=1;i<=n;i++) a[i]=a[i-1]*27+s[i]-96;
        for (scanf("%d",&x);x;x--){
            scanf("%s%d",str+1,&len);
            m=strlen(str+1);
            b[0]=0;
            v.clear();
            for (i=1;i<=m;i++){
                b[i]=b[i-1]*27+str[i]-96;
                if (i>=len) v.insert(b[i]-b[i-len]*w[len]);
            }
            ans=0;
            for (i=len;i<=n;i++)
            if (v.count(a[i]-a[i-len]*w[len])) ans+=i-len+1;
            printf("%llu\n",ans);
        }
    }
    return 0;
}