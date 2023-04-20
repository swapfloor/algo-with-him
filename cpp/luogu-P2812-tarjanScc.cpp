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
        assert(sccCnt > 0);
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
        assert(sccCnt > 0);
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
    tarjan.buildTopoDin();
    tarjan.buildTopoDout();
    int a = 0, b = 0;
    for (int i = 0; i < tarjan.sccCnt; i++) {
        if (!tarjan.din[i]) a++;
        if (!tarjan.dout[i]) b++;
    }
    cout << a << "\n";
    if (tarjan.sccCnt == 1) {
        cout << 0 << "\n";
    } else {
        cout << max(a, b) << "\n";
    }
    return 0;
}
