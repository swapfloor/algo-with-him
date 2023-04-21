// https://leetcode.cn/problems/minimum-falling-path-sum-ii
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector f(n, vector<int>(m, -1));
        auto tour = [&](auto self, int u, int fa) -> int {
            if (u == n) return 0;
            if (u != 0 && f[u][fa] != -1) {
                return f[u][fa];
            }
            int ans = 2e9;
            for (int ch = 0; ch < m; ch++) {
                if (ch == fa) continue;
                ans = min(ans, grid[u][ch] + self(self, u + 1, ch));
            }
            if (u != 0) f[u][fa] = ans;
            return ans;
        };
        return tour(tour, 0, -1);
    }
};
