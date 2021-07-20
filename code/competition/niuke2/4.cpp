#include<bits/stdc++.h>
#pragma GCC optimize(2)
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
typedef long long ll;
typedef __int128 lxl;
const lxl u = 1;
ll mull(ll a, ll b, ll m) { ll d = ((long double)a / m * b + 1e-8); ll r = a * b - d * m; return r < 0 ? r + m : r; }
ll T, NN, mx;
inline ll gcd(ll a, ll b) {
	if (!a) return b; if (!b) return a;
	int t = __builtin_ctzll(a | b);
	a >>= __builtin_ctzll(a);
	do {
		b >>= __builtin_ctzll(b);
		if (a > b) { ll t = b; b = a, a = t; }
		b -= a;
	} while (b); return a << t;
}
ll qpow(ll a, ll b, ll mod) {
	ll res = 1; a %= mod;
	for (; b; b /= 2, a = mull(a, a, mod)) if (b % 2) res = mull(res, a, mod);
	return res;
}
namespace MR {
	inline ll Quick_Pow(ll a, ll b, ll mod) {
		if (b == 1) return a; if (!b) return 1;
		ll tmp = Quick_Pow(a, b >> 1, mod);
		if (b & 1) return mull(mull(tmp, tmp, mod), a, mod);
		return mull(tmp, tmp, mod);
	}
	ll p[15] = { 2,61,5,7,9,11,13,17,19,21,23,29 }; int lim = 12;
	inline bool check(ll p, ll o, ll q, ll x) {
		if (p == x) return true;
		ll now = Quick_Pow(p, o, x), temp = now;
		for (int i = 1; i <= q; i++) {
			temp = mull(temp, temp, x);
			if (temp == 1 && now != 1 && now != x - 1) return false;
			now = temp;
		}
		return temp == 1;
	}
	inline bool MR(ll x) {
		if (x == 3) return true;
		for (int i = 0; i < lim; i++) if (p[i] == x) return true;
		if (!(x & 1)) return false; if (x % 6 != 1 && x % 6 != 5) return false;
		if (x % 3 == 0 || x % 5 == 0) return false;
		ll temp = x - 1, o = 0;
		while (!(temp & 1)) { o++; temp >>= 1; }
		for (int i = 0; i < lim; i++) if (!check(p[i], temp, o, x)) return false;
		return true;
	}
}
inline ll g(ll x, ll n, ll a) { ll t = mull(x, x, n) + a; return t < n ? t : t - n; }
ll PollardRho(ll n) {
	if (n % 2 == 0) return 2; if (n % 3 == 0) return 3;
	ll x = 0, y = x, t = 1, q = 1, a = (rand() % (n - 1)) + 1;
	for (int k = 2;; k <<= 1, y = x, q = 1) {
		for (int i = 1; i <= k; ++i) {
			x = g(x, n, a);
			q = mull(q, abs(x - y), n);
			if (!(i & 127)) {
				t = gcd(q, n);
				if (t > 1) break;
			}
		}
		if (t > 1 || (t = gcd(q, n)) > 1) break;
	}
	if (t == n) {
		t = 1;
		while (t == 1) t = gcd(abs((x = g(x, n, a)) - y), n);
	}
	return t;
}
void split(ll x) {
	if (x == 1 || x <= mx) return;
	if (MR::MR(x)) return mx = max(mx, x), void();
	ll y = x;
	while (y == x) y = PollardRho(x);
	while (x % y == 0) x /= y;
	split(x), split(y);
}
long long pri[700001], cnt;
bool vis[10000021];
void init() {
	for (int i = 2; i < 100021; i++) {
		if (!vis[i])
			pri[cnt++] = i;
		for (int j = 0; j < cnt && pri[j] * i < 100021; j++) {
			vis[pri[j] * i] = 1;
			if (i % pri[j] == 0)
				break;
		}
	}
}
int t, n, k, x[40001];
long long p, phi, mod, c[31][40001], b[80001];
void mul(long long& a, long long b, long long mod) {
	a = (__int128)a * b % mod;
}
void maxx(int& a, int b) {
	if (a < b)
		a = b;
}
void maxxx(long long& a, long long b) {
	if (a < b)
		a = b;
}
long long mi(long long n, long long k) {
	long long an = 1;
	while (k > 0) {
		if (k & 1)
			mul(an, n, mod);
		mul(n, n, mod), k >>= 1;
	}
	return an;
}
signed main() {
	srand(time(0));
	init();
	for (int i = 0; i < 31; i++)
		c[i][i] = 1;
	for (int i = 1; i < 40001; i++)
		c[0][i] = 1;
	scanf("%d", &t);
	while (t--) {
		mx = 0;
		int ma = 0;
		scanf("%d%d%lld", &n, &k, &p);
		mod = phi = p;
		split(p);
		phi = phi / mx * (mx - 1);
		while (p % mx == 0)
			p /= mx;
		for (int i = 0; pri[i] * pri[i] <= p; i++)
			if (p % pri[i] == 0) {
				phi = phi / pri[i] * (pri[i] - 1);
				while (p % pri[i] == 0)
					p /= pri[i];
			}
		if (p > 1)
			phi = phi / p * (p - 1);
		for (int i = 0; i < n; i++)
			scanf("%d", &x[i]), maxx(ma, x[i]);
		for (int i = 2; i <= ma; i++)
			b[i] = 0;
		for (int i = 0; i < n; i++)
			b[x[i]]++;
		long long mab = 0;
		for (int i = 2; i <= ma; i++) {
			for (int j = i * 2; j <= ma; j += i)
				b[i] += b[j];
			maxxx(mab, b[i]);
		}
		for (int i = 1; i <= k; i++)
			for (int j = i + 1; j <= mab; j++) {
				c[i][j] = c[i][j - 1] + c[i - 1][j - 1];
				if (c[i][j] >= phi)
					c[i][j] -= phi;
			}
		for (int i = ma; i > 1; i--) {
			b[i] = c[k][b[i]];
			for (int j = i * 2; j <= ma; j += i)
				b[i] -= b[j];
			b[i] = b[i] % phi;
			if (b[i] < 0)
				b[i] += phi;
		}
		long long ans = 1;
		for (int i = 2; i <= ma; i++)
			if (b[i])
				mul(ans, mi(i, b[i]), mod);
		printf("%lld\n", ans);
	}
}