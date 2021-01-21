#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> date;
#define get_part(n,i) ((n>>p[i])&(15LL))
int p[]={0,4,8,12,16,20,24,28,32,36,40,44};
int get_max()
{
    int ma = date[0];
    for (int i = 1; i < date.size(); i++)
    {
        ma = max(date[i], ma);
    }
    int t = 1;
    while (ma > 0)
    {
        t++;
        ma >>=4;
    }
    return t;
}
void radix_sort()
{
    int d = get_max();
    // cout << d << endl;
    vector<int> tmp[16];
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < date.size(); j++)
        {
            tmp[get_part(date[j],i)].push_back(date[j]);
        }
        date.clear();
        for (int j = 0; j < 16; j++)
        {
            for (int k = 0; k < tmp[j].size(); k++)
            {
                date.push_back(tmp[j][k]);
            }
        }
        for (int j = 0; j < 16; j++)
        {
            tmp[j].clear();
        }
    }
    return;
}
signed main()
{
    int n;
    scanf("%lld", &n);
    int tmp;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &tmp);
        date.push_back(tmp);
    }
    radix_sort();
    for (int i = 0; i < n; i++)
    {
        printf("%lld ", date[i]);
    }
    printf("\n");
    return 0;
}