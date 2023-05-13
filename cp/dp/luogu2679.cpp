// 线性dp
// 枚举匹配长度l和块数q
// 注意我加了一个总统计dp和上一个新加统计pre
// 只有当当前匹配时可以加入上一个统计块中使得块数保持不变
#include<vector>
#include<iostream>
using namespace std;
typedef long long LL;
#define vc vector
#define str string
void add(LL &a, LL b) {
    a += b;
    if (a >= 1000000007) a -= 1000000007;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 4e7
    int n, m, k;
    cin >> n >> m >> k;
    str A, B;
    cin >> A >> B;
    vc<vc<LL> > dp(m + 1, vc<LL>(k + 1));
    dp[0][0] = 1;
    vc<vc<LL> > pre(m + 1, vc<LL>(k + 1));
    pre[0][0] = 1;
    for (int i = 0; i < n; i++) {
        char c = A[i];
        vc<vc<LL> > ndp(m + 1, vc<LL>(k + 1));
        for (int l = m - 1; l >= 0; l--) {
            if (c == B[l]) {
                for (int q = k - 1; q >= 0; q--) {
                    add(ndp[l + 1][q + 1], dp[l][q]);
                }
            }
        }
        if (i) {
            for (int l = m - 1; l >= 1; l--) {
                if (c == B[l] && A[i - 1] == B[l - 1]) {
                    for (int q = k; q >= 1; q--) {
                        add(ndp[l + 1][q], pre[l][q]);
                    }
                }
            }
        }
        for (int l = m; l >= 0; l--) {
            for (int q = k; q >= 0; q--) {
                add(dp[l][q], ndp[l][q]);
            }
        }
        pre = move(ndp);
    }
    cout << dp[m][k] << "\n";
    return 0;
}
