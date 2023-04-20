// https://www.luogu.com.cn/problem/P2812
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
    std::vector<std::vector<int>> topoG;
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
    int n;
    cin >> n;
    treetree::TarjanScc tarjan(n);
    for (int u = 0; u < n; u++) {
        int v;
        while (cin >> v && v) {
            v--;
            tarjan.addEdge(u, v);
        }
    }
    tarjan.work();
    vector<int> din(tarjan.sccCnt + 1), dout(tarjan.sccCnt + 1);
    for (int u = 0; u < n; u++) {
        for (auto v : tarjan.g[u]) {
            int a = tarjan.id[u], b = tarjan.id[v];
            if (a != b) {
                din[b]++;
                dout[a]++;
            }
        }
    }
    int a = 0, b = 0;
    for (int i = 1; i <= tarjan.sccCnt; i++) {
        if (!din[i]) a++;
        if (!dout[i]) b++;
    }
    cout << a << "\n";
    if (tarjan.sccCnt == 1) {
        cout << 0 << "\n";
    } else {
        cout << max(a, b) << "\n";
    }
    return 0;
}
