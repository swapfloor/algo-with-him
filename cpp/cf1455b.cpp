// https://codeforces.com/problemset/problem/1455/B
#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int ts;
	cin >> ts;
	while (ts--) {
		int x;
		cin >> x;
		// k : (1 + 2 + ... + (k - 1), 1 + 2 + ... + k] except 1 + 2 + ... + k + (-1) solve by (k + 1)
		int w = 0;
		while (x>0) {
			x -= ++w;
		}
		if (x==-1) w++;
		cout << w << "\n";
	}
	return 0;
}
