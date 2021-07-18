#include<bits/stdc++.h>
#define il inline
#define MAXN 2000100
using namespace std ;
template<class T>inline void rd(T &x){
   x=0;char o,f=1;
   while(o=getchar(),o<48)if(o==45)f=-f;
   do x=(x<<3)+(x<<1)+(o^48);
   while(o=getchar(),o>47);
   x*=f;
}
template<class T>inline void wt(T x){
    static int top,stk[105];
    if(x<0)x=-x,putchar('-');
    if(x==0)putchar('0');
    while(x)stk[++top]=x%10,x/=10;
    while(top)putchar(stk[top--]+'0');
}
char s1[MAXN], s2[MAXN] ;
int date[MAXN];
int N, M, K, res = 0, ans[MAXN], AA, BB ;
int i, j, k, l, Lim = 1, L, R[MAXN] ; 
const double Pi = acos(-1.0) ;
struct node{
    double x, y ;
    node (double xx = 0, double yy = 0){
        x = xx, y = yy ;
    }
}A[MAXN], B[MAXN] ;
int aa[510000];
node operator * (node J, node Q){
    return node(J.x * Q.x - J.y * Q.y , J.x * Q.y + J.y * Q.x);
}
node operator + (node J, node Q){
    return node(J.x + Q.x , J.y + Q.y);
}
node operator - (node J, node Q){
    return node(J.x - Q.x , J.y - Q.y );
}

il int qr(){
    int k = 0, f = 1 ;
    char c = getchar() ;
    while(!isdigit(c)){if(c == '-') f = -1 ;c = getchar() ;}
    while(isdigit(c)) k = (k << 1) + (k << 3) + c - 48 ,c = getchar() ;
    return k * f ;
}
il void FFT(node *J, double flag){
    for(i = 0; i < Lim; i ++)
        if(i < R[i]) swap(J[i], J[R[i]]) ;
    for(j = 1; j < Lim; j <<= 1){
        node T(cos(Pi / j), flag * sin(Pi / j)) ;
        for(k = 0; k < Lim; k += (j << 1) ){
            node t(1, 0) ;
            for(l = 0 ; l < j; l ++, t = t * T){
                node Nx = J[k + l], Ny = t * J[k + j + l] ;
                J[k + l] = Nx + Ny ;
                J[k + j + l] = Nx - Ny ;
            }
        }
    }
}
int main(){
    freopen("in.txt","r",stdin);
    int n;
    N=5e5+10;
    rd(n);
    for(int i=0;i<n;i++)
        rd(date[i]);
    sort(date,date+n);
    int now=0;
    for(int i=0;i<n;i++)
        A[date[i]-date[0]].x=1;
    for(int i=0;i<N;i++)
        B[i]=A[i];
    reverse(A,A+N);
    while(Lim < N + N ) Lim <<= 1, L ++ ;
    for(i = 0; i <= Lim; i ++ ) R[i] = (R[i >> 1] >> 1) | ((i & 1) << (L - 1)) ;
    FFT(A, 1), FFT(B, 1) ;
    for(i = 0; i <= Lim; i ++) A[i] = A[i] * B[i] ;
    FFT(A, -1) ;
    int tot = 0 ;
	for(i = 0; i <= Lim; i++) 
        ans[i] += (int) (A[i].x /Lim+0.5);
	reverse(ans,ans+N);
    for(int i=1;i<=5e5;i++)
        if(ans[i]){
            // cout<<"i="<<i<<endl;
            int t=i;
            for(int j=1;j*j<=t;j++){
                if(t%j==0){
                    ans[j]=1;
                    ans[t/j]=1;
                }
            }
        }
    for(int i=1;i<=N;i++)
        if(!ans[i]){
            wt(i),putchar('\n');
            return 0;
        }
    return 0 ;
}