#include<bits/stdc++.h>
#define il inline
#define MAXN 3000100

using namespace std ;
char s1[MAXN], s2[MAXN] ;
int N, M, K, res = 0, ans[MAXN], AA, BB ;
int i, j, k, l, Lim = 1, L, R[MAXN] ; 
const double Pi = acos(-1.0) ;
struct node{
    double x, y ;
    node (double xx = 0, double yy = 0){
        x = xx, y = yy ;
    }
}A[MAXN], B[MAXN] ;
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
    scanf("%s%s", s1, s2) ;
    N=strlen(s1) ;
    int M=strlen(s2);
    for(i = N - 1; i >= 0; i --) A[AA ++].x = s1[i] - 48;
    for(i = M- 1; i >= 0; i --) B[BB ++].x = s2[i] - 48;
    for(int i=0;i<N;i++)
        cout<<A[i].x<<' ';
    cout<<endl;
    for(int i=0;i<M;i++)
        cout<<B[i].x<<' ';
    cout<<endl;
    while(Lim < N + M) Lim <<= 1, L ++ ;
    for(i = 0; i <= Lim; i ++ ) R[i] = (R[i >> 1] >> 1) | ((i & 1) << (L - 1)) ;
    FFT(A, 1), FFT(B, 1) ;
    for(i = 0; i <= Lim; i ++) A[i] = A[i] * B[i] ;
    FFT(A, -1) ;
    int tot = 0 ;
    for(int i=0;i<=Lim;i++){
    ans[i] += (int) (A[i].x / Lim + 0.5) ;
        // cout<<ans[i];
    }
    // cout<<endl;
	for(i = 0; i <= Lim; i++) {
        
        if(ans[i] >= 10) 
            ans[i + 1] += ans[i] / 10, ans[i] %= 10, Lim += (i == Lim);
    }
    while(!ans[Lim] && Lim >= 1) Lim -- ;
    Lim ++ ;
	// while( -- Lim >= 0) cout << ans[Lim] ; 
    return 0 ;
}