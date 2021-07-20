#include<bits/stdc++.h>
#include <random>
#include <chrono>
using namespace std;
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 sd(seed);
uniform_int_distribution <long long> dist(0, 0x7ffffffffffff);//设定随机范围;
// dist(myrand); 这就是个在范围内的随机数; 
int d(int l, int r) {
	return dist(sd) % (r - l + 1) + l;
}
long long p;
int n, m;
int main() {
	cout << 1 << endl;
	for (int i = 0; i < 1; i++) {
		n = d(30000, 40000), m = d(1, min(n, 30)), p = d(1000000, 1e14);
		cout << n << ' ' << m << ' ' << p << endl;
		for (int i = 0; i < n; i++)
			cout << d(1, 40) << ' ';
		cout << endl;
	}
}