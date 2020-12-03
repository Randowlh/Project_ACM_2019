#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
const int maxa=1010;
int _,n,m,tot,b[10];
struct record{
	int X1,X2,Y1,Y2;
}a[1000050];
struct seg_tree{
	int w,s,U,D,L,R,son[4];
}t[15000000];
void read(int &x){
	char ch=getchar();
	x=0;
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=10*x+ch-48,ch=getchar();
}
void build(int x,int U,int D,int L,int R){
	t[x].U=U; t[x].D=D; t[x].L=L; t[x].R=R;
	memset(t[x].son,0,sizeof(t[x].son));
	if (U<D&&L==R){
		t[x].son[0]=++tot;
		t[x].son[1]=++tot;
		int mid=U+D>>1;
		build(t[x].son[0],U,mid,L,R);
		build(t[x].son[1],mid+1,D,L,R);
	}
	if (U==D&&L<R){
		t[x].son[0]=++tot;
		t[x].son[1]=++tot;
		int mid=L+R>>1;
		build(t[x].son[0],U,D,L,mid);
		build(t[x].son[1],U,D,mid+1,R);
	}
	if (U<D&&L<R){
		t[x].son[0]=++tot;
		t[x].son[1]=++tot;
		t[x].son[2]=++tot;
		t[x].son[3]=++tot;
		int mid1=U+D>>1;
		int mid2=L+R>>1;
		build(t[x].son[0],U,mid1,L,mid2);
		build(t[x].son[1],U,mid1,mid2+1,R);
		build(t[x].son[2],mid1+1,D,L,mid2);
		build(t[x].son[3],mid1+1,D,mid2+1,R);
	}
}
void push_up(int x){
	if (t[x].w) t[x].s=(t[x].D-t[x].U+1)*(t[x].R-t[x].L+1);
	else{
		t[x].s=0;
		for (int i=0;i<4;i++)
		if (t[x].son[i]) t[x].s+=t[t[x].son[i]].s;
	}
}
void update(int x,int U,int D,int L,int R,int w){
	if (U<=t[x].U&&D>=t[x].D&&L<=t[x].L&&R>=t[x].R){
		t[x].w+=w;
		push_up(x);
		return;
	}
	for (int i=0;i<4;i++)
	if (t[x].son[i]){
		if (U>t[t[x].son[i]].D) continue;
		if (D<t[t[x].son[i]].U) continue;
		if (L>t[t[x].son[i]].R) continue;
		if (R<t[t[x].son[i]].L) continue;
		update(t[x].son[i],U,D,L,R,w);
	}
	push_up(x);
}
int main(){
	int i,x;
	tot=1;
	build(1,1,maxa,1,maxa);
	for (read(_);_;_--){
		for (i=1;i<=tot;i++) t[i].w=t[i].s=0;
		read(n); read(m);
		for (i=1;i<=n;i++){
			read(a[i].X1); read(a[i].X2);
			read(a[i].Y1); read(a[i].Y2);
			update(1,a[i].X1,a[i].X2,a[i].Y1,a[i].Y2,1);
		}
		while (m--){
			read(x);
			for (i=1;i<=x;i++){
				read(b[i]);
				update(1,a[b[i]].X1,a[b[i]].X2,a[b[i]].Y1,a[b[i]].Y2,-1);
			}
			printf("%d\n",t[1].s);
			for (i=1;i<=x;i++) update(1,a[b[i]].X1,a[b[i]].X2,a[b[i]].Y1,a[b[i]].Y2,1);
		}
	}
	return 0;
}