#include<iostream>
#include<set>
using namespace std;
#define ll long long
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
const int b = 131;
const int MAXN = 114514<<1;
typedef unsigned long long ull;
ull h[MAXN], pw[MAXN]; // h[k]存储字符串前k个字母的哈希值, pw[k]存储 b^k mod 2^64
//这里的模数M取的就是ull的上限2^64
string str;
int n,k;
void init(int n){//初始化 
    pw[0] = 1;
    for (int i = 1; i <= n; i ++ ) {
        h[i] = h[i-1]*b + str[i];//做每个前缀的哈希值 
        pw[i] = pw[i-1]*b;//预处理b^k的值 
    }
}
// 计算子串 str[l ~ r] 的哈希值
ull get(int l, int r) {
    return h[r] - h[l-1]*pw[r-l+1];
}
int eng[27];
bool flag;
inline int idx(char c){return c-'a';}

set<ull> st;
int sum[MAXN];

inline void solve(){
    st.clear();
    cin>>n>>k;
    cin>>str;
    str=" "+str;
    rep(i,0,25) cin>>eng[i];
    init(n);//初始化哈希前缀和
    rep(i,1,n) sum[i]=sum[i-1]+eng[idx(str[i])];//前缀和
    int l = 1,r = sum[n],mid;
    while(l<r){
        cout<<"lr";
        cout<<l<<' '<<r<<endl;
        mid = (l+r)>>1;
        flag = 1;
        //cal
        int lb = 1;
        ll res = 0;
        rep(i,1,n){
            while(sum[i]-sum[lb-1]>mid) lb++;//滑窗
            int lll = lb,rrr = i,midmid;
            ull tmp;
            while(lll<rrr){
                cout<<"lllrrr"<<lll<<' '<<rrr<<endl;
                midmid = (lll+rrr)>>1;
                tmp = get(midmid,i);
                if(st.count(tmp)) rrr = midmid;//找到最靠左的没出先过的位置
                else lll = midmid+1;//没出现过的情况
            }
            lll--;
            res += lll-lb+1;//lll最小的情况是lb-1
            rep(j,lb,lll) st.insert(get(j,i));//标记
            if(res>k){flag=0;break;}//超过k个直接退出！
        }
        if(flag) r = mid;
        else l=mid+1;//能量值x不够大的情况
    }
    cout<<r<<endl;
}
int main(){
    int z;
    cin>>z;
    while(z--) solve();
}
// int main() {
//     int n, m;
//     scanf("%d%d%s",&n,&m,str+1);//这样读入字符串第一位从1开始 
//     init(n);
//     while (m--) {
//         int l1,r1,l2,r2;
//         scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
//         if(get(l1,r1)!=get(l2,r2))
//         	printf("No\n");
//         else printf("Yes\n");
//     }
//     return 0;
// }