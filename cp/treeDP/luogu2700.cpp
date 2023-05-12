// dp[u][0]表示将以该点为根的树变成正常态的代价，1是不正常态代价
// 注意当mark[u]==0时，dp[u][1]不需要将所有不正常态子树代价都加上，可以少加一个，贪心的选择。
#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define vc vector
#define vi vc<int>
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vi mark(n);
    for (int i = 0; i < k; i++) {
        int mk;
        cin >> mk;
        mark[mk] = 1;
    }
    vc<vc<pair<int, long long>>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        long long c;
        cin >> u >> v >> c;
        g[u].PB(MP(v, c));
        g[v].PB(MP(u, c));
    }
    constexpr long long inf = 1e12;
    vc<vc<long long>> dp(n, vc<long long>(2));
    function<void(int, int)> dfs = [&](int u, int f) -> void {
        if (mark[u]) {
            dp[u][0] = inf;
        }
        long long sum = 0;
        for (auto& pr : g[u]) {
            int v = pr.F;
            long long c = pr.S;
            if (v == f) continue;
            dfs(v, u);
            sum += min(dp[v][0], dp[v][1] + c);
        }
        if (!mark[u]) {
            dp[u][1] = sum;
        }
        for (auto& pr : g[u]) {
            int v = pr.F;
            long long c = pr.S;
            if (v == f) continue;
            long long remove_c = min(dp[v][0], dp[v][1] + c);
            if (mark[u]) {
                if (dp[u][1] < inf) dp[u][1] += remove_c;
            } else {
                if (dp[u][0] < inf) dp[u][0] += remove_c;
                dp[u][1] = min(dp[u][1], sum - remove_c + dp[v][1]);
            }
        }
    };
    dfs(0, 0);
    cout << min(dp[0][0], dp[0][1]) << "\n";
    return 0;
}
