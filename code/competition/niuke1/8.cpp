#include<bits/stdc++.h>
using namespace std;
const int N=(1<<21)+5;
const double PI=cos(-1.0);
int n,m,len=1,rev[N];
struct Complex
{
    double x,y;
    Complex (double xx=0,double yy=0){x=xx,y=yy;}
}a[N],b[N];
Complex operator + (Complex a,Complex b){ return Complex(a.x+b.x , a.y+b.y);}
Complex operator - (Complex a,Complex b){ return Complex(a.x-b.x , a.y-b.y);}
Complex operator * (Complex a,Complex b){ return Complex(a.x*b.x-a.y*b.y , a.x*b.y+a.y*b.x);}
void fft(Complex X[],int op){
	int i,j,k; Complex wn,w,x,y;
	for (i=0;i<len;i++)
	if (rev[i]>i) swap(X[i],X[rev[i]]);
	for (i=1;i<len;i<<=1){
		wn=Complex(cos(PI/i),op*sin(PI/i));
		for (j=0;j<len;j+=i*2){
			w=Complex(1,0);
			for (k=0;k<(i);k++,w=w*wn){
				x=X[j+k]; y=X[j+k+(i)]*w;
				X[j+k]=x+y;
				X[j+k+(i)]=x-y;
			}
		}
	}
	if (op==-1) for (i=0;i<len;i++) X[i].x/=len;
}
int main(){
    freopen("in.txt","r",stdin);
	int i;
	scanf("%d%d",&n,&m);
    int l=0;
     while(len<=n+m) len<<=1,l++;
    for(int i=0;i<len;i++)
        rev[i]= ( rev[i>>1]>>1 )| ( (i&1)<<(l-1) ); 
	// while (len<=n+m) len<<=1;
	// for (i=0;i<len;i++) rev[i]=(rev[i>>1]>>1)|(i&1)*(len>>1);
	for (i=0;i<len;i++) a[i]=b[i]=Complex(0,0);
	for (i=0;i<=n;i++) scanf("%lf",&a[i].x);
	for (i=0;i<=m;i++) scanf("%lf",&b[i].x);
	fft(a,1); fft(b,1);
	for (i=0;i<len;i++) a[i]=a[i]*b[i];
	fft(a,-1);
//	for (i=0;i<20;i++) printf("%d  %.10f\n",i,a[i].x);printf("\n");
	for (i=0;i<=n+m;i++) printf("%d ",int(a[i].x+0.5));
	return 0;
}