// bitxor分位贪心
// xor对之和最大，考虑某位，则一半取1，一半取0
#include<vector>
#include<iostream>
using namespace std;
#define vc vector
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) {
        long long top;
        int n;
        cin >> top >> n;
        if (top == 1) {
            cout << 0 << "\n";
            continue;
        }
        long long mi = 1LL << 35;
        long long ans = 0;
        long long bin = n / 2;
        constexpr long long mod = 1e9 + 7;
        while (mi) {
            if (top >= mi) {
                ans += mi % mod * bin % mod * (n - bin) % mod;
            }
            mi >>= 1;
        }
        cout << ans % mod << "\n";
    }    
    return 0;
}
