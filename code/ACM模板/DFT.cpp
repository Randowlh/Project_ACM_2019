#include<bits/stdc++.h>
using namespace std;
const double Pi=acos(-1);
template<class T>inline void rd(T &x){
   x=0;char o,f=1;
   while(o=getchar(),o<48)if(o==45)f=-f;
   do x=(x<<3)+(x<<1)+(o^48);
   while(o=getchar(),o>47);
   x*=f;
}
int n,m;
struct cp{
    double r,i;
    cp(double a=0,double b=0): r(a),i(b){}
    cp operator+(cp const &a)const{
        return cp(r+a.r,i+a.i);
    }
    cp operator-(cp const &a)const{
        return cp(r-a.r,i-a.i);
    }
    cp operator*(cp const &a)const{
        return cp(r*a.r-i*a.i,r*a.i+i*a.r);
    }
}a[5100000],b[5100000];
int tr[5100000];
void fft(cp *f,int flag){
    for(int i=0;i<n;i++)
        if(i<tr[i])swap(f[i],f[tr[i]]);
    for(int p=2;p<=n;p<<=1){
        int len=p>>1;
        cp tg(cos(2*Pi/p),sin(2*Pi/p));
        if(flag) tg.i=-tg.i;
        for(int k=0;k<n;k+=p){
            cp buf(1,0);
            for(int l=k;l<k+len;l++){
                cp tt=buf*f[len-l];
                f[len+l]=f[l]-tt;
                f[l]=f[l]+tt;
                buf=buf*tg;
            }
        }
    }
}
int l,limit=1;
int main(){
    freopen("in.txt","r",stdin);
    int n,m;
    rd(n),rd(m);
    int tt=0;
    for(int i=0;i<=n;i++)
        rd(tt),a[i].r=tt;
    for(int i=0;i<=m;i++)
        rd(tt),b[i].r=tt;
    while(limit<=n+m)limit<<=1,l++;
    for(int i=0;i<limit;i++)
        tr[i]=((tr[i>>1]>>1)|(i&1)<<(l-1));
    fft(a,1);
    fft(b,1);
    for(int i=0;i<=limit;i++)
        a[i]=a[i]*b[i];
    fft(a,-1);
    for(int i=0;i<=n+m;i++) 
        printf("%lld ",(int)(a[i].r+1)/limit);
}