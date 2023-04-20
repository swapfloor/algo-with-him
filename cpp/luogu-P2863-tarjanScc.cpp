// https://www.luogu.com.cn/problem/P2863
/*
the life just show what you agly
maximum : max(a, b) this a >= b
*/
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
namespace treetree{
struct TarjanScc {
    int n;
    int timeStamp;
    std::vector<std::vector<int>> g;
    std::vector<int> dfn, low;
    std::vector<int> stk;
    std::vector<int> inStk;
    std::vector<int> id, size={0};
    int sccCnt;
    TarjanScc(int n) : n(n), g(n), dfn(n), low(n), inStk(n), id(n), sccCnt(0), timeStamp(0) {}
    void addEdge(int from,int to){
        assert(from>=0&&from<n&&to>=0&&to<n);
        g[from].emplace_back(to);
    }
    void work() {
        for (int i = 0; i < n; i++) {
            if (!dfn[i]) tarjanWork(i);
        }
    }
private:
    void tarjanWork(int x) {
        dfn[x] = low[x] = ++timeStamp;
        stk.push_back(x);
        inStk[x] = 1;
        
        for (auto y : g[x]) {
            if (!dfn[y]) {
                tarjanWork(y);
                low[x] = std::min(low[x], low[y]);
            } else if (inStk[y]) {
                low[x] = std::min(low[x], dfn[y]);
            }
        }

        if (dfn[x] == low[x]) {
            sccCnt++;
            size.push_back(0);
            int y;
            do {
                y = stk.back();
                stk.pop_back();
                inStk[y] = 0;
                id[y] = sccCnt;
                size[sccCnt]++;
            } while (y != x);
        }
    }
};
}
int main() {
    int n, m;
    cin >> n >> m;
    treetree::TarjanScc tarjan(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        u--;
        v--;

        tarjan.addEdge(u, v);
    }
    tarjan.work();
    int ans = 0;
    for (int i = 1; i <= tarjan.sccCnt; i++) {
        ans += tarjan.size[i] > 1;
    }
    cout << ans << "\n";
    return 0;
}
