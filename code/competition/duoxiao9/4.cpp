#include <bits/stdc++.h>
//#include <bits/extc++.h>
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
using namespace std;
#pragma optimize(2)
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rbset(T) tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>
const int inf = 0x7FFFFFFF;
typedef long long ll;
typedef double db;
typedef long double ld;
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
namespace FastIO
{
char buf[1 << 21], buf2[1 << 21], a[20], *p1 = buf, *p2 = buf, hh = '\n';
int p, p3 = -1;
void read() {}
void print() {}
inline int getc()
{
return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++;
}
inline void flush()
{
fwrite(buf2, 1, p3 + 1, stdout), p3 = -1;
}
template <typename T, typename... T2>
inline void read(T &x, T2 &... oth)
{
int f = 0;x = 0;char ch = getc();
while (!isdigit(ch)){if (ch == '-')f = 1;ch = getc();}
while (isdigit(ch)){x = x * 10 + ch - 48;ch = getc();}
x = f ? -x : x;read(oth...);
}
template <typename T, typename... T2>
inline void print(T x, T2... oth)
{
if (p3 > 1 << 20)flush();
if (x < 0)buf2[++p3] = 45, x = -x;
do{a[++p] = x % 10 + 48;}while (x /= 10);
do{buf2[++p3] = a[p];}while (--p);
buf2[++p3] = hh;
print(oth...);
}
} // namespace FastIO
#define read FastIO::read
#define print FastIO::print
#define flush FastIO::flush
#define spt fixed<<setprecision
#define endll '\n'
#define mul(a,b,mod) (__int128)(a)*(b)%(mod) 
#define pii(a,b) pair<a,b>
#define pow powmod
#define X first
#define Y second
#define lowbit(x) (x&-x)
#define MP make_pair
#define pb push_back
#define pt putchar
#define yx_queue priority_queue
#define lson(pos) (pos<<1)
#define rson(pos) (pos<<1|1)
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll llinf = 4223372036854775851;
const ll mod = (0 ? 1000000007 : 998244353);
ll pow(ll a,ll b,ll md=mod) {ll res=1;a%=md; assert(b>=0); for(;b;b>>=1){if(b&1)res=mul(res,a,md);a=mul(a,a,md);}return res;}
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 1;
const int maxn = 510000;
struct BigInteger
{
    static const int BASE = 100000000; 
    static const int WIDTH = 8;//8位位压        
    bool sign;                         
    size_t length;                     
    vector<int> num;                   
    BigInteger(long long x = 0) { *this = x; }
    BigInteger(const string &x) { *this = x; }
    BigInteger(const BigInteger &x) { *this = x; }
    void cutLeadingZero()
    {
        while (num.back() == 0 && num.size() != 1)
        {
            num.pop_back();
        }
        int tmp = num.back();
        if (tmp == 0)
        {
            length = 1;
        }
        else
        {
            length = (num.size() - 1) * WIDTH;
            while (tmp > 0)
            {
                length++;
                tmp /= 10;
            }
        }
    }
    BigInteger &operator=(long long x)
    {
        num.clear();
        if (x >= 0)
        {
            sign = true;
        }
        else
        {
            sign = false;
            x = -x;
        }
        do
        {
            num.push_back(x % BASE);
            x /= BASE;
        } while (x > 0);
        cutLeadingZero();
        return *this;
    }
    BigInteger &operator=(const string &str)
    {
        num.clear();
        sign = (str[0] != '-'); 
        int x, len = (str.size() - 1 - (!sign)) / WIDTH + 1;
        for (int i = 0; i < len; i++)
        {
            int End = str.size() - i * WIDTH;
            int start = max((int)(!sign), End - WIDTH); 
            sscanf(str.substr(start, End - start).c_str(), "%d", &x);
            num.push_back(x);
        }
        cutLeadingZero();
        return *this;
    }
    BigInteger &operator=(const BigInteger &tmp)
    {
        num = tmp.num;
        sign = tmp.sign;
        length = tmp.length;
        return *this;
    }
    BigInteger abs() const
    {
        BigInteger ans(*this);
        ans.sign = true;
        return ans;
    }
    const BigInteger &operator+() const { return *this; }
    BigInteger operator-() const
    {
        BigInteger ans(*this);
        if (ans != 0)
            ans.sign = !ans.sign;
        return ans;
    }
    BigInteger operator+(const BigInteger &b) const
    {
        if (!b.sign)
        {
            return *this - (-b);
        }
        if (!sign)
        {
            return b - (-*this);
        }
        BigInteger ans;
        ans.num.clear();
        for (int i = 0, g = 0;; i++)
        {
            if (g == 0 && i >= num.size() && i >= b.num.size())
                break;
            int x = g;
            if (i < num.size())
                x += num[i];
            if (i < b.num.size())
                x += b.num[i];
            ans.num.push_back(x % BASE);
            g = x / BASE;
        }
        ans.cutLeadingZero();
        return ans;
    }
    BigInteger operator-(const BigInteger &b) const
    {
        if (!b.sign)
        {
            return *this + (-b);
        }
        if (!sign)
        {
            return -((-*this) + b);
        }
        if (*this < b)
        {
            return -(b - *this);
        }
        BigInteger ans;
        ans.num.clear();
        for (int i = 0, g = 0;; i++)
        {
            if (g == 0 && i >= num.size() && i >= b.num.size())
                break;
            int x = g;
            g = 0;
            if (i < num.size())
                x += num[i];
            if (i < b.num.size())
                x -= b.num[i];
            if (x < 0)
            {
                x += BASE;
                g = -1;
            }
            ans.num.push_back(x);
        }
        ans.cutLeadingZero();
        return ans;
    }
    BigInteger operator*(const BigInteger &b) const
    {
        int lena = num.size(), lenb = b.num.size();
        BigInteger ans;
        for (int i = 0; i < lena + lenb; i++)
            ans.num.push_back(0);
        for (int i = 0, g = 0; i < lena; i++)
        {
            g = 0;
            for (int j = 0; j < lenb; j++)
            {
                long long x = ans.num[i + j];
                x += (long long)num[i] * (long long)b.num[j];
                ans.num[i + j] = x % BASE;
                g = x / BASE;
                ans.num[i + j + 1] += g;
            }
        }
        ans.cutLeadingZero();
        ans.sign = (ans.length == 1 && ans.num[0] == 0) || (sign == b.sign);
        return ans;
    }
    BigInteger e(size_t n) const
    {
        int tmp = n % WIDTH;
        BigInteger ans;
        ans.length = n + 1;
        n /= WIDTH;
        while (ans.num.size() <= n)
            ans.num.push_back(0);
        ans.num[n] = 1;
        while (tmp--)
            ans.num[n] *= 10;
        return ans * (*this);
    }
    BigInteger operator/(const BigInteger &b) const
    {
        BigInteger aa((*this).abs());
        BigInteger bb(b.abs());
        if (aa < bb)
            return 0;
        char *str = new char[aa.length + 1];
        memset(str, 0, sizeof(char) * (aa.length + 1));
        BigInteger tmp;
        int lena = aa.length, lenb = bb.length;
        for (int i = 0; i <= lena - lenb; i++)
        {
            tmp = bb.e(lena - lenb - i);
            while (aa >= tmp)
            {
                str[i]++;
                aa = aa - tmp;
            }
            str[i] += '0';
        }
        BigInteger ans(str);
        delete[] str;
        ans.sign = (ans == 0 || sign == b.sign);
        return ans;
    }
    BigInteger operator%(const BigInteger &b) const
    {
        return *this - *this / b * b;
    }
    BigInteger &operator++()
    {
        *this = *this + 1;
        return *this;
    }
    BigInteger &operator--()
    {
        *this = *this - 1;
        return *this;
    }
    BigInteger &operator+=(const BigInteger &b)
    {
        *this = *this + b;
        return *this;
    }
    BigInteger &operator-=(const BigInteger &b)
    {
        *this = *this - b;
        return *this;
    }
    BigInteger &operator*=(const BigInteger &b)
    {
        *this = *this * b;
        return *this;
    }
    BigInteger &operator/=(const BigInteger &b)
    {
        *this = *this / b;
        return *this;
    }
    BigInteger &operator%=(const BigInteger &b)
    {
        *this = *this % b;
        return *this;
    }
    bool operator<(const BigInteger &b) const
    {
        if (sign != b.sign) 
        {
            return !sign;
        }
        else if (!sign && !b.sign)
        {
            return -b < -*this;
        }
        //正正
        if (num.size() != b.num.size())
            return num.size() < b.num.size();
        for (int i = num.size() - 1; i >= 0; i--)
            if (num[i] != b.num[i])
                return num[i] < b.num[i];
        return false;
    }
    bool operator>(const BigInteger &b) const { return b < *this; }                     
    bool operator<=(const BigInteger &b) const { return !(b < *this); }                 
    bool operator>=(const BigInteger &b) const { return !(*this < b); }                 
    bool operator!=(const BigInteger &b) const { return b < *this || *this < b; }       
    bool operator==(const BigInteger &b) const { return !(b < *this) && !(*this < b); } 
    bool operator||(const BigInteger &b) const { return *this != 0 || b != 0; } 
    bool operator&&(const BigInteger &b) const { return *this != 0 && b != 0; } 
    bool operator!() { return (bool)(*this == 0); }                           
    friend ostream &operator<<(ostream &out, const BigInteger &x)
    {
        if (!x.sign)
            out << '-';
        out << x.num.back();
        for (int i = x.num.size() - 2; i >= 0; i--)
        {
            char buf[10];
            sprintf(buf, "%08d", x.num[i]);
            for (int j = 0; j < strlen(buf); j++)
                out << buf[j];
        }
        return out;
    }
    friend istream &operator>>(istream &in, BigInteger &x)
    {
        string str;
        in >> str;
        size_t len = str.size();
        int start = 0;
        if (str[0] == '-')
            start = 1;
        if (str[start] == '\0')
            return in;
        for (int i = start; i < len; i++)
        {
            if (str[i] < '0' || str[i] > '9')
                return in;
        }
        x.sign = !start;
        x = str.c_str();
        return in;
    }
};
void work()
{
    BigInteger a,b;
    cin>>a>>b;
    BigInteger c=a+b;
    cout<<<<endl;   
}
signed main()
{
   #ifndef ONLINE_JUDGE
   //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    //std::ios::sync_with_stdio(false);
    //cin.tie(NULL);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}