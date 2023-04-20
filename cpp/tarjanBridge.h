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
