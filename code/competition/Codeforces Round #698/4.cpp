#include <bits/stdc++.h>
using namespace std;
typedef long long ll;  // 用ll来代替long long
/*really[]
	题目给的是计算出的差值和，是无序且重复的
	这个really数组就是用来有序地记录这些差值和的一半的
	比如上文所举的例子，±2、±7、±9
	那么题目所给的差值和就是 36 36 46 46 54 54
	而really数组中要记录的就是 18 23 27 （差值和的一半）
	除以二是因为表格二，差值和都是原数和的两倍
*/
ll really[100010]; 
int main()
{
    freopen("in.txt", "r", stdin);
	int N;
	cin >> N;  //共有N个test cases
	while (N--)
	{
		int n;
		scanf("%d", &n);
		bool buxing = false; //“不行”的拼音，一旦为true就说明这组样例“不行”
		map<ll, int> ma; //用map记录出现了几次（条件一）
		for (int i = 0; i < 2 * n; i++)
		{
			ll t;
			scanf("%lld", &t);
			if (t % 2) //差值和是否为偶数（条件二）
				buxing = 1; //如果t%2有余数，则说明这个数是奇数
			ma[t]++; //t出现的次数加一
		}
		int sum = 1; //really数组中需要放置的数的下标，笔者选择从下标1开始存放
		ll realOriSum = 0; // 这是计算出来的原数组中的数，上文样例中便是 9  7  3
		/*ma的迭代器，这个for循环从小到大遍历了插入ma中的差值和*/
		for (map<ll, int>::iterator it = ma.begin(); it != ma.end(); it++)
		{
			/*it->second就是这个差值和出现的次数*/
			if (it->second != 2) // 差值和是否都出现了两处（条件一）
				buxing = 1;
			/*it->first是这个差值和*/
			really[sum++] = (it->first) / 2; // 差值和的一半存放到really数组中
		}
		for (sum--; sum > 0; sum--)
		{
			ll all = really[sum] - realOriSum; //减去原来的数
			if (all % sum)	//是否可以整除
				buxing = 1;
			ll thisReal = all / sum; // 这个是原始数组（计算差值和之前那个±2±7±9的数组）
			realOriSum += thisReal; // 求出的原始的数的和
			if (thisReal <= 0)  // 按上述方法，原来的数必须是正数
				buxing = 1;
		}
		if (buxing) //如果不行buxing就会为true，这个样例从头到尾都可以，buxing就还是原来初始的false
			puts("NO");
		else //否则就可以
			puts("YES");
	}
	return 0;
}