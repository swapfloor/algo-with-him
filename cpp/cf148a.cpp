// https://codeforces.com/contest/148/problem/A
#include <bits/stdc++.h>

using namespace std;

int n;
int a[4];
int v[100000 + 12];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 4; i++) cin >> a[i];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 4; j++) {
			if (i % a[j] == 0) {
				v[i] = 1;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += v[i] == 1;
	}
	cout << ans << "\n";
	return 0; 
} 
