// https://www.luogu.com.cn/problem/P1656
/*
the life just show what you agly
maximum : max(a, b) this a >= b
*/
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
namespace treetree{
struct TarjanBridge {
    int n;
    int timeStamp;
    int edgeCnt;
    struct Edge {
        int to, edgeId;
        Edge(int to, int edgeId) : to(to), edgeId(edgeId) {}
    };
    std::vector<std::vector<Edge>> g;
    std::vector<int> dfn, low;
    std::vector<std::pair<int, int>> bridges;
    TarjanBridge(int n) : n(n), g(n), dfn(n), low(n), edgeCnt(0), timeStamp(0) {}
    void addEdge(int from,int to){
        assert(from>=0&&from<n&&to>=0&&to<n);
        g[from].emplace_back(Edge(to, edgeCnt++));
        g[to].emplace_back(Edge(from, edgeCnt++));
    }
    void work() {
        for (int i = 0; i < n; i++) {
            if (!dfn[i]) tarjanWork(i, -1);
        }
    }
private:
    void tarjanWork(int x, int inEdge) {
        dfn[x] = low[x] = ++timeStamp;
        
        for (auto &e : g[x]) {
            int y = e.to, edgeId = e.edgeId;
            if (!dfn[y]) {
                tarjanWork(y, edgeId);
                low[x] = std::min(low[x], low[y]);
                if (low[y] > dfn[x]) {
                    if (x < y) bridges.emplace_back(x, y);
                    else bridges.emplace_back(y, x);
                }
            } else if (edgeId != (inEdge ^ 1)) {
                low[x] = std::min(low[x], dfn[y]);
            }
        }
    }
};
}
int main() {
    int n, m;
    cin >> n >> m;
    treetree::TarjanBridge tarjan(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        u--;
        v--;

        tarjan.addEdge(u, v);
    }
    tarjan.work();
    sort(tarjan.bridges.begin(), tarjan.bridges.end(), 
            [](const auto& l, const auto& r) { return l.first != r.first ? l.first < r.first : l.second < r.second; });
    for (auto &e : tarjan.bridges) {
        cout << e.first + 1 << " " << e.second + 1 << "\n";
    }
    return 0;
}
