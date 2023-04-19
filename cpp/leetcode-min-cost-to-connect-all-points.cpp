// https://leetcode.cn/problems/min-cost-to-connect-all-points
namespace treetree{
class DisjointSetUnion {
private:
    std::vector<int> f, rank;
    int n;

public:
    DisjointSetUnion(int _n) {
        n = _n;
        rank.resize(n, 1);
        f.resize(n);
        for (int i = 0; i < n; i++) {
            f[i] = i;
        }
    }

    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }

    int unionSet(int x, int y) {
        assert(0 <= x && x < n && 0 <= y && y < n);
        int fx = find(x), fy = find(y);
        if (fx == fy) {
            return false;
        }
        if (rank[fx] < rank[fy]) {
            swap(fx, fy);
        }
        rank[fx] += rank[fy];
        f[fy] = fx;
        return true;
    }

    int size(int x) {
        assert(0 <= x && x < n);
        return rank[find(x)];
    }
};
struct Kruskal {
    struct Edge {
        int x, y, len;
        Edge(int x, int y, int len) : x(x), y(y), len(len) {}
    };
    int n;
    std::vector<Edge> e;
    Kruskal(int n) : n(n) {}
    void addEdge(int from,int to,int len){
        assert(from>=0&&from<n&&to>=0&&to<n);
        e.emplace_back(Edge(from,to,len));
    }
    int work() {
        DisjointSetUnion dsu(n);
        sort(e.begin(), e.end(), [](const Edge& a, const Edge& b) -> int { return a.len < b.len; });
        int ans = 0, num = 1;
        for (int i = 0; i < e.size(); i++) {
            int x = e[i].x, y = e[i].y, len = e[i].len;
            if (dsu.unionSet(x, y)) {
                ans += len;
                num++;
                if (num == n) {
                    break;
                }
            }
        }
        if (num < n) return -1;
        return ans;
    }
};
}
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        treetree::Kruskal krus(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = std::abs(points[i][0] - points[j][0]) + std::abs(points[i][1] - points[j][1]);
                krus.addEdge(i, j, dist);
            }
        }
        return krus.work();
    }
};
