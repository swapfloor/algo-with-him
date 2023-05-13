// 线性dp
// 记录每个r的左端l，最终遍历所有r，dp[r]=max{dp[l_i]+r-l_i} l_i为r的所有左端，O(max(值域,区间数))
// 如果值域过大，可以使用sort+hashmap，O(区间数*log(区间数))
#include<vector>
#include<iostream>
using namespace std;
typedef long long LL;
#define vc vector
#define PB push_back
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 3e6
    int n;
    cin >> n;
    constexpr int Lim = 3e6 + 2;
    vc<vc<int> > beg(Lim);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        beg[r].PB(l);
        mx = max(mx, r);
    }
    vc<int> dp(Lim);
    for (int i = 1; i <= mx; i++) {
        dp[i] = dp[i - 1];
        for (int l : beg[i]) {
            dp[i] = max(dp[i], dp[l] + i - l);
        }
    }
    cout << dp[mx] << "\n";
    return 0;
}
