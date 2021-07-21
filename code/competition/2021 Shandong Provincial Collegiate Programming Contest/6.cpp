#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10, M = 500;
int f[2][M + 10];
int T, n, k, X[N], Y[N];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k);
        for (int i = 1, r; i <= n; i++)
            scanf("%d", &r), scanf("%d%d", &X[r], &Y[r]);
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            memset(f[i & 1], -0x3f, sizeof(int) * (min(n, M) + 1));
            for (int j = 0; j <= min(i, M); j++) {
                if (j)f[i & 1][j] = max(f[i & 1][j], f[i - 1 & 1][j - 1] - X[i]);
                if (j + 1 <= min(i - 1, M))f[i & 1][j] = max(f[i & 1][j], f[i - 1 & 1][j + 1] - Y[i] + k);
                if (!j)f[i & 1][j] = max(f[i & 1][j], f[i - 1 & 1][j] - Y[i]);
            }
        }
        printf("%d\n", *max_element(f[n & 1], f[n & 1] + 1 + min(n, M)));
    }
    return 0;
}