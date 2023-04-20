// https://leetcode.cn/problems/min-cost-to-connect-all-points
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
