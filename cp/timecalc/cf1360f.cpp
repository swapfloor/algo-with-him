// 如果你知道时间复杂度就能做出来
// 对一字符串任一位置10*任一字母26*检查10*10样例*100=2600000
#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    string ans = v[0];
    for (int p = 0; p < m; p++) {
        char pre = ans[p];
        for (char c = 'a'; c <= 'z'; c++) {
            ans[p] = c;
            bool bad = false;

            for (int d = 1; d < n; d++) {
                int cntErr = 0;
                for (int u = 0; u < m; u++) {
                    if (v[d][u] != ans[u]) {
                        cntErr++;
                    }
                }

                if (cntErr >= 2) {
                    bad = true;
                    break;
                }
            }

            if (!bad) {
                cout << ans << "\n";
                return;
            }
        }
        
        ans[p] = pre;
    }

    cout << -1 << "\n";
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tests = 1;
    cin >> tests;

    while (tests--) {
        solve();
    }

    return 0;
}
