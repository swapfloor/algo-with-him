// https://codeforces.com/contest/1520/problem/C
#include <bits/stdc++.h>

using namespace std;

int a[110][110];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n == 2) {
			cout << -1 << "\n";
			continue;
		}
		int tot = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i % 2; j < n; j += 2) {
				a[i][j] = ++tot;
			}
		}	
		for (int i = 0; i < n; i++) {
			for (int j = !(i % 2); j < n; j += 2) {
				a[i][j] = ++tot;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << a[i][j] << " ";
			}
			cout << "\n";
		} 
	}
	return 0; 
} 
