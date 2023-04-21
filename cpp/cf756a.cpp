// https://codeforces.com/problemset/problem/756/A
#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

int p[200000 + 12];
int v[200000 + 12];
void dfs(int u) {
	v[u] = 1;
	if (!v[p[u]]) {
		dfs(p[u]);
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	int c = 0;
	for (int i = 1; i <= n; i++) {
		int b;
		cin >> b;
		c += (b==1);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!v[i]) dfs(i), ans++;
	}
	if (ans == 1) ans = 0;
	cout << ans + (c % 2 == 0) << "\n";
	return 0;
}
