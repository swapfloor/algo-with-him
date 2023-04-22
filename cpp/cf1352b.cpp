// https://codeforces.com/contest/1352/problem/B
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		if ((n % 2) && (k % 2 == 0)) cout << "NO\n";
		else if ((n % 2 == 0) && (k % 2)) {
			if (n >= k * 2) {
				cout << "YES\n";
				for (int i = 1; i <= k - 1; i++) {
					cout << 2 << " ";
					n -= 2;
				}
				cout << n << "\n";
			} else {
				cout << "NO\n";
			}
		} else if ((n % 2) && (k % 2)) {
			if (n >= k) {
				cout << "YES\n";
				for (int i = 1; i <= k - 1; i++) {
					cout << 1 << " ";
					n -= 1;
				}
				cout << n << "\n";
			} else {
				cout << "NO\n";
			}
		} else {
			if (n >= k) {
				cout << "YES\n";
				for (int i = 1; i <= k - 1; i++) {
					cout << 1 << " ";
					n -= 1;
				}
				cout << n << "\n";
			} else {
				cout << "NO\n";
			} 
		}
	}
	return 0; 
} 
