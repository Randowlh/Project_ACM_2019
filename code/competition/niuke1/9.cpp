#include<bits/stdc++.h>
using namespace std;
const int N=(1<<21)+5;
const double PI=cos(-1.0);
int n,m,len=1,rev[N];
struct Complex{
	double x,y;
    Complex(double x=0,double y=0):x(x),y(y){}
	Complex operator+(const Complex &a) const{return Complex(x+a.x,y+a.y);}
	Complex operator-(const Complex &a) const{return Complex(x-a.x,y-a.y);}
	Complex operator*(const Complex &a) const{return Complex(x*a.x-y*a.y,x*a.y+y*a.x);}
}a[N],b[N];
void fft(Complex X[],int op){
	int i,j,k; Complex wn,w,x,y;
	for (i=0;i<len;i++)
	if (rev[i]>i) swap(X[i],X[rev[i]]);
	for (i=2;i<=len;i<<=1){
		wn=Complex(cos(2*PI/i),op*sin(2*PI/i));
		for (j=0;j<len;j+=i){
			w=Complex(1,0);
			for (k=0;k<(i>>1);k++,w=w*wn){
				x=X[j+k]; y=X[j+k+(i>>1)]*w;
				X[j+k]=x+y;
				X[j+k+(i>>1)]=x-y;
			}
		}
	}
	if (op==-1) for (i=0;i<len;i++) X[i].x/=len;
}
int main(){
    freopen("in.txt","r",stdin);
	int i;
	scanf("%d%d",&n,&m);
	while (len<=n+m) len<<=1;
	for (i=0;i<len;i++) rev[i]=(rev[i>>1]>>1)|(i&1)*(len>>1);
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