inline ll mul(ll a,ll b,ll mod){
	return (__int128)a*b%mod;
}
inline ll pow(ll a,ll b,ll mod){
	ll res=1;
	if(a>=mod)a%=mod;
	while(b){
		if(b&1)res=mul(res,a,mod);
		a=mul(a,a,mod);
		b>>=1;
	}
	return res;
}
bool miller_rabin(ll a,ll n){
	ll d=n-1,r=0;
	while(!(d&1))d>>=1,r++;
	ll x=pow(a,d,n);
	if(x==1)return 1;
	for(int i=0;i<r;i++){
		if(x==n-1)return 1;
		x=mul(x,x,n);
	}
	return 0;
}
bool is_prime(ll x){
	if(x<=1)return 0;
	static int num[]={2,3,5,7,13,29,37,89};
	for(int i=0;i<8;i++)if(x==num[i])return 1;
	for(int i=0;i<8;i++)if(!miller_rabin(num[i],x))return 0;
	return 1;
}
ll fun(ll x,ll c,ll mod){
	return (mul(x,x,mod)+c)%mod;
}
ll gcd(ll n,ll m){
	if(m==0)return n;
	return gcd(m,n%m);
}
ll pollard_rho(ll x){
	ll c=rand()%(x-1)+1;
	ll s=0,t=0;
	for(int goal=1;;goal<<=1,s=t){
		ll val=1;
		for(int step=1;step<=goal;step++){
			t=fun(t,c,x);
			val=mul(val,abs(s-t),x);
			if(step%127==0){
				ll d=gcd(val,x);
				if(d>1)return d;
			}
		}
		ll d=gcd(val,x);
		if(d>1)return d;
	}
}
void find_fac(ll x){
	if(x==1)return;
	if(is_prime(x)){
		//找到了质因子x
		return;
	}
	ll y=x;
	while(y==x)y=pollard_rho(x);
	find_fac(y),find_fac(x/y);
}