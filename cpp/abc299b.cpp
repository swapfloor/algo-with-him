// https://atcoder.jp/contests/abc299/tasks/abc299_b
#include <bits/stdc++.h>

using namespace std;

int C[200000 + 12];
int RK[200000 + 12];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, t;
	cin >> n >> t;
	for (int i = 1; i <= n; i++) {
		cin >> C[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> RK[i];
	}
	int rk = -1, ans = 1;
	for (int i = 1; i <= n; i++) {
		if (C[i] == t) {
			if (RK[i] > rk) {
				rk = RK[i];
				ans = i;
			}
		}
	}
	if (rk == -1) {
		for (int i = 1; i <= n; i++) {
			if (C[i] == C[1]) {
				if (RK[i] > rk) {
					rk = RK[i];
					ans = i;
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
