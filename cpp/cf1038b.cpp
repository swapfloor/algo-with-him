// https://codeforces.com/problemset/problem/1038/B
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    
    int n;
    cin >> n;
    
    if (n == 1 || n == 2) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        if (n & 1) {
            cout << 1 << " " << (n + 1) / 2 << "\n";
            cout << n - 1 << " ";
            for (int i = 1; i < n - i; i++) {
                cout << i << " ";
                cout << n + 1 - i << " ";
            }
            cout << "\n";
        } else {
            cout << 2 << " " << n / 2 << " " << n / 2 + 1 << "\n";
            cout << n - 2 << " ";
            for (int i = 1; i * 2 < n; i++) {
                cout << i << " ";
                cout << n + 1 - i << " ";
            }
            cout << "\n";
        }
    }
    
    return 0;
}
