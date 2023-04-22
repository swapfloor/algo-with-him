// https://atcoder.jp/contests/abc299/tasks/abc299_c
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int g = 0;
	int cur = 0;
	int ans = -1;
	for (int i = 0; i < n; i++) {
		if (s[i] == '-') {
			g = 1;
			if (cur) ans = max(ans, cur), cur = 0;
		} else {
			cur++;
		}
	}
	if (g && cur) ans = max(ans, cur);
	cout << ans << "\n";
	return 0;
}
