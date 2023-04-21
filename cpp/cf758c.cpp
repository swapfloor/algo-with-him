// https://codeforces.com/problemset/problem/758/C
#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

i64 cnt[110][110];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m, x, y;
	i64 k;
	cin >> n >> m >> k >> x >> y;
	i64 ru;
	if (n == 1) {
		i64 base = k / (n * m);
		for (int c = 1; c <= m; c++) {
			cnt[1][c] = base;
		}
		ru = k - base * n * m;
	} else {
		int nn = 2 * n - 2;
		i64 base = k / (nn * m);
		for (int r = 1; r <= n; r++) {
			for (int c = 1; c <= m; c++) {
				if (r == 1 || r == n) cnt[r][c] += base;
				else cnt[r][c] += 2 * base;
			}
		}
		ru = k - base * nn * m;
	}
	auto done = [&](int p) {
		int rb = 1;
		int add = 1;
		while (p > 0) {
			for (int j = 1; j <= m && p; j++) {
				cnt[rb][j]++;
				p--;
			}
			if (n == 1) continue;
			if (rb + add > n) {
				add = -add;
			} else if (rb + add < 1) {
				add = -add;
			}
			rb += add;
		}
	};
	done(ru);
	i64 mx = 0, mn = 1e18;
//	i64 s = 0;
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= m; c++) {
			mx = max(mx, cnt[r][c]);
			mn = min(mn, cnt[r][c]);
//			s += cnt[r][c];
//			cout << cnt[r][c] << " ";
		}
//		cout << "\n";
	}
	cout << mx << " " << mn << " " << cnt[x][y] << "\n";
	return 0;
}
