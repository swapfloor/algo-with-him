// https://www.luogu.com.cn/problem/P3387
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
    bool isWork;
    std::vector<std::vector<int>> g;
    std::vector<std::vector<int>> topoG;
    std::vector<int> din, dout;
    std::vector<int> dfn, low;
    std::vector<int> stk;
    std::vector<int> inStk;
    std::vector<int> id, size;
    int sccCnt;
    TarjanScc(int n) : n(n), g(n), dfn(n), low(n), inStk(n), id(n), sccCnt(0), timeStamp(0), isWork(false) {}
    void addEdge(int from,int to){
        assert(from>=0&&from<n&&to>=0&&to<n);
        g[from].emplace_back(to);
    }
    void work() {
        isWork = true;
        for (int i = 0; i < n; i++) {
            if (!dfn[i]) tarjanWork(i);
        }
    }
    void buildTopoDin() {
        assert(isWork);
        din = std::vector<int>(sccCnt);
        for (int u = 0; u < n; u++) {
            for (auto v : g[u]) {
                int a = id[u], b = id[v];
                if (a != b) {
                    din[b]++;
                }
            }
        }
    }
    void buildTopoDout() {
        assert(isWork);
        dout = std::vector<int>(sccCnt);
        for (int u = 0; u < n; u++) {
            for (auto v : g[u]) {
                int a = id[u], b = id[v];
                if (a != b) {
                    dout[a]++;
                }
            }
        }
    }
    void buildTopoGraph() {
        topoG = std::vector<std::vector<int>>(n);
        for (int u = 0; u < n; u++) {
            for (auto v : g[u]) {
                int a = id[u], b = id[v];
                if (a != b) {
                    topoG[a].push_back(b);
                }
            }
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
            size.push_back(0);
            int y;
            do {
                y = stk.back();
                stk.pop_back();
                inStk[y] = 0;
                id[y] = sccCnt;
                size[sccCnt]++;
            } while (y != x);
            sccCnt++;
        }
    }
};
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    treetree::TarjanScc tarjan(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        
        u--;
        v--;
        
        tarjan.addEdge(u, v);
    }
    tarjan.work();
    tarjan.buildTopoGraph();
    vector<int> nw(tarjan.sccCnt);
    for (int i = 0; i < n; i++) {
        nw[tarjan.id[i]] += w[i];
    }
    vector<int> f(tarjan.sccCnt);
    for (int u = tarjan.sccCnt; u--; ) {
        f[u] = max(f[u], nw[u]);
        for (auto v : tarjan.topoG[u]) {
            f[v] = max(f[v], f[u] + nw[v]);
        }
    }
    int ans = 0;
    for (int u = tarjan.sccCnt; u--; ) {
        ans = max(ans, f[u]);
    }
    cout << ans << "\n";
    return 0;
}
