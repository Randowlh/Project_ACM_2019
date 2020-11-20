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
inline int read()
{
  register char ch=0;
  while(ch<48||ch>57)ch=getchar();
  return ch-'0';
}
int n,m,l,limit=1;
struct cp{
    double r,i;
    cp(double a=0,double b=0): r(a),i(b){}
    cp operator+(cp const &a)const{return cp(r+a.r,i+a.i);}
    cp operator-(cp const &a)const{return cp(r-a.r,i-a.i);}
    cp operator*(cp const &a)const{return cp(r*a.r-i*a.i,r*a.i+i*a.r);}
}a[5100000],b[5100000];
int tr[5100000];
void fft(cp *f,bool flag)
{
  for (int i=0;i<n;i++)
    if (i<tr[i])swap(f[i],f[tr[i]]);
  for(int p=2;p<=n;p<<=1){
    int len=p>>1;
    cp tG(cos(2*Pi/p),sin(2*Pi/p));
    if(!flag)tG.i*=-1;
    for(int k=0;k<n;k+=p){
      cp buf(1,0);
      for(int l=k;l<k+len;l++){
        cp tt=buf*f[len+l];
        f[len+l]=f[l]-tt;
        f[l]=f[l]+tt;
        buf=buf*tG;
      }
    }
  }
}
int main(){
    rd(n),rd(m);
    int tt=0;
    for(int i=0;i<=n;i++)
        rd(tt),a[i].r=tt;
    for(int i=0;i<=m;i++)
        rd(tt),a[i].i=tt;
    for(m+=n,n=1;n<=m;n<<=1);
    for(int i=0;i<n;i++)
       tr[i]=(tr[i>>1]>>1)|((i&1)?n>>1:0);
    fft(a,1);
    for(int i=0;i<n;i++)
        a[i]=a[i]*a[i];
    fft(a,0);
    for(int i=0;i<=m;i++) 
        printf("%lld ",(int)((a[i].i)/n/2+0.5));
}