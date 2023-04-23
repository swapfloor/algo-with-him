// https://codeforces.com/problemset/problem/467/B
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> a(m + 1);
    for (int i = 0; i <= m; i++) {
	    cin >> a[i];
    }
    
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int diff = 0;
        for (int j = 0; j < n; j++) {
            if ((a[i] >> j & 1) != (a[m] >> j & 1)) {
                diff++;
            }
        }
        if (diff <= k) {
            ans++;
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
