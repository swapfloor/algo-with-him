// https://codeforces.com/problemset/problem/1381/A2
#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int ts;
	cin >> ts;
	while (ts--) {
		auto turnOp = [&](const string& s) {
			vector<int> ans;
			int n = s.size();
			for (int i = 1; i < n; i++) {
				if (s[i] != s[i - 1]) {
					ans.push_back(i);
				}
			}
			if (s.back() == '1') ans.push_back(n);
			return ans;
		};
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		auto vs = turnOp(s);
		auto vt = turnOp(t);
		reverse(vt.begin(), vt.end());
		for (auto x : vt) vs.push_back(x);
		cout << vs.size();
		if (vs.size()) {
			for (int i = 0; i < vs.size(); i++) {
				cout << " ";
				cout << vs[i];
			}
		}
		cout << "\n";
	}
	return 0;
}
