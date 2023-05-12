// 当填充使得m个位置相同元素，使用取模为0的时机
#include<bits/stdc++.h>
using namespace std;
#define vc vector
#define vi vector<int>
#define vvi vector<vector<int> >
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _;
    cin >> _;
    while (_--) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        if (n * a != m * b) {
            cout << "NO" << "\n";
            continue;
        }
        int d = a;
        vvi ans(n, vi(m));
        int dx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < a; j++) {
                ans[i][(j + dx) % m] = 1;
            }
            dx += d;
        }
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << ans[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}
