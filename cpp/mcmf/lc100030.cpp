template<typename K>
class MCMF {
    // he: 头 ne: 链表 e: 终点 cap: 容量 dep: 分层 cur: 当前弧
    vector<int> he, ne, e, vis, cur, inq;
    vector<K> cap, cost, dis;
    int n, m, S, T;
    K INF;
public:
    MCMF(int n_, int S_, int T_) : n(n_), S(S_), T(T_) {
        memset(&INF, 0x3f, sizeof INF);
        he.resize(n, -1);
        dis.resize(n);
        inq.resize(n);
        vis.resize(n, 0);
        cur.resize(n);
    }
    /**
     * @param w 容量
     * @param c 费用
     */
    void addEdge(int a, int b, K _cap, K _cost) {
        cap.emplace_back(_cap), cost.emplace_back(_cost);
        ne.emplace_back(he[a]), he[a] = e.size(), e.emplace_back(b);
        cap.emplace_back(0), cost.emplace_back(-_cost);
        ne.emplace_back(he[b]), he[b] = e.size(), e.emplace_back(a);
    }

    bool spfa() {
        queue<int> q({S});
        fill(begin(dis), end(dis), INF);
        fill(begin(inq), end(inq), 0);
        cur = he;
        dis[S] = 0, cur[S] = he[S], inq[S] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            inq[u] = 0;
            for (auto i = he[u]; ~i; i = ne[i]) {
                int v = e[i];
                if (cap[i] && dis[u] + cost[i] < dis[v]) {
                    dis[v] = dis[u] + cost[i];
                    if (!inq[v]) {
                        q.emplace(v);
                        inq[v] = 1;
                    }
                }
            }
        }
        return dis[T] != INF;
    }

    K find(int u, K limit) {
        if (u == T)
            return limit;
        vis[u] = 1;
        K flow = 0;
        for (auto i = cur[u]; ~i && flow < limit; i = ne[i]) {
            cur[u] = i;
            int v = e[i];
            if (!vis[v] && cap[i] && dis[v] == dis[u] + cost[i]) {
                K t = find(v, min(cap[i], limit - flow));
                cap[i] -= t, cap[i ^ 1] += t, flow += t;
            }
        }
        vis[u] = 0;
        return flow;
    }

    pair<K, K> run() {
        K maxflow = 0, mincost = 0;
        while (spfa()) {
            K t = find(S, INF);
            maxflow += t;
            mincost += t * dis[T];
        }
        return {maxflow, mincost};
    }
};

class Solution {
public:
    int minimumMoves(vector<vector<int>>& g) {
        MCMF<int> mcf(11, 9, 10); // (n, s, t)
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (g[i][j] > 1) {
                    mcf.addEdge(9, i * 3 + j, g[i][j] - 1, 0); // (from, to, cap, cost)
                    for (int k = 0; k < 3; k++) {
                        for (int d = 0; d < 3; d++) {
                            if (g[k][d] == 0) {
                                mcf.addEdge(i * 3 + j, k * 3 + d, 1, abs(i - k) + abs(j - d));
                            }
                        }
                    }
                } else if (g[i][j] == 0) {
                    mcf.addEdge(i * 3 + j, 10, 1, 0);
                }
            }
        }
        return mcf.run().second;      
    }
};
