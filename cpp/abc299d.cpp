// https://atcoder.jp/contests/abc299/tasks/abc299_d
#include <bits/stdc++.h>

using namespace std;

int ask(int p) {
	cout << "? " << p << endl;
	char c;
	cin >> c;
	return c - '0';
}

void answer(int p) {
	cout << "! " << p << endl;
	exit(0);
}

int ans = -1;
int f[200000 + 12];

bool tour(int l, int r) {
	if (ans != -1) return true;
	if (l >= r) return false;
	if (f[l] == -1) f[l] = ask(l);
	if (f[r] == -1) f[r] = ask(r);
	if (l + 1 == r) {
		if (f[l] != f[r]) {
			ans = l;
			return true;
		}
	}
	int m = (l + r) / 2;
	if (f[m] == -1) f[m] = ask(m);
	if (f[l] != f[m]) return tour(l, m);
	else if (f[m] != f[r]) return tour(m, r);
	else {
		if (tour(l, m)) return true;
		else return tour(m, r);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	memset(f, -1, (n + 1) * sizeof *f);
	tour(1, n);
	answer(ans);
	return 0;
}
