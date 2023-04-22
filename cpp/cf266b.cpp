// https://codeforces.com/contest/266/problem/B
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, t;
	cin >> n >> t;
	string line;
	cin >> line;
	while (t--) {
		for (int i = n - 1; i - 1 >= 0; i--) {
			if (line[i] == 'G' && line[i - 1] == 'B') {
				swap(line[i], line[i - 1]);
				i--;
			}
		}
	}
	cout << line << "\n";
	return 0; 
} 
