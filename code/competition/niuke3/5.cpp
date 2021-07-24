#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
template<class T>inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }

struct frac{
	ll a,b;
    friend bool operator == (frac x,frac y){
        return x.a==y.a&&x.b==y.b;
    }
	frac(ll _a=0,ll _b=1):a(_a),b(_b){}
	ll gcd(ll a,ll b){
		if(b==0)return a;
		return gcd(b,a%b);
	}
	frac work(ll a,ll b){
		if(b<0)a=-a,b=-b;
		ll tmp=gcd(a,b);
		if(tmp<0)tmp=-tmp;
		return (frac){a/tmp,b/tmp};
	}
	frac operator +(frac A){return work(a*A.b+b*A.a,b*A.b);}
	frac operator -(frac A){return work(a*A.b-b*A.a,b*A.b);}
	frac operator *(frac A){return work(a*A.a,b*A.b);}
	frac operator *(ll x){return work(a*x,b);}
	frac operator /(frac A){return work(a*A.b,b*A.a);}
	frac operator /(ll x){return work(a,b*x);}
	void pt(ll x){
		static int stk[105],top;
		if(x==0)printf("0");
		if(x<0)x=-x,printf("-");
		while(x)stk[++top]=x%10,x/=10;
		while(top)printf("%d",stk[top--]);
	}
	void pt(){
		pt(a),printf("/"),pt(b),printf("  ");
	}
	#undef ll
};
int n,m;
int num[10];
inline frac cal(frac a,frac b,int op){
    if(op==1) return a+b;
    if(op==2) return a-b;
    if(op==3) return a*b;
    if(op==4) return a/b;
}
void solve(){
    frac a,b,c,d;
    bool flagzs,flagfs;
    frac res1,res2,res3;
    rep(i,1,13)rep(j,i,13)rep(k,j,13)rep(l,k,13){//枚举数字
        num[1]=i,num[2]=j,num[3]=k,num[4]=l;
        flagzs=flagfs=0;
        rep(ii,1,4){
            rep(jj,1,4){if(jj==ii) continue;
                rep(kk,1,4){if(kk==ii||kk==jj) continue;
                    rep(ll,1,4){if(ll==ii||ll==jj||ll==kk) continue;
                        a=frac(num[ii]);b=frac(num[jj]);
                        c=frac(num[kk]);d=frac(num[ll]);
                        rep(f1,1,4)rep(f2,1,4)rep(f3,1,4){//枚举符号
                            bool tflag = 0;
                            res1 = cal(a,b,f1);
                            if(res1.b!=1&&res1.a!=0) tflag = 1;
                            res2 = cal(res1,c,f2);
                            if(res2.b!=1&&res2.a!=0) tflag = 1;
                            res3 = cal(res2,d,f3);
                            if(res3==frac(m)){
                                if(tflag) flagfs = 1;
                                else flagzs = 1;
                            }
                            tflag = 0;
                            res1 = cal(a,b,f1);
                            if(res1.b!=1&&res1.a!=0) tflag = 1;
                            res2 = cal(a,b,f3);
                            if(res2.b!=1&&res2.a!=0) tflag = 1;
                            if(res2.a==0&&f2==4);// /0的情况
                            else{
                                res3 =cal(res1,res2,f2);
                                if(res3==frac(m)){
                                    if(tflag) flagfs = 1;
                                    else flagzs = 1;
                                }
                            }
                            tflag = 0;
                            res1 = cal(b,c,f2);
                            if(res1.b!=1&&res1.a!=0) tflag = 1;
                            if(res1.a==0&&f1==4);// /0的情况
                            else{
                                res2 = cal(a,res1,f1);
                                if(res2.b!=1&&res2.a!=0) tflag = 1;
                                res3 = cal(res2,d,f3);
                                if(res3==frac(m)){
                                    if(tflag) flagfs = 1;
                                    else flagzs = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
        if(i==1&&j==5&&k==5&&l==5){
            cout<<"check1555"<<endl;
            cout<<"fs"<<flagfs<<"zs"<<flagzs<<endl;
        }
        if(flagzs==1&&flagfs==0){
            cout<<i<<' '<<j<<' '<<k<<' '<<l<<endl;
        }
    }
}
int main(){
    cin>>n>>m;
    if(n<=3) cout<<0<<endl;
    else solve();
}
