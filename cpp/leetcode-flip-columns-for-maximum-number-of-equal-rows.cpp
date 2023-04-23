// https://leetcode.cn/problems/flip-columns-for-maximum-number-of-equal-rows
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        map<vector<int>, int> mp;
        for(int i = 0; i < n; i++){
            vector<int>a, b;
            for(int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    a.push_back(j);
                } else {
                    b.push_back(j);
                }
            }
            mp[a]++;
            mp[b]++;
        }

        int ans = 0;
        for (auto &[_, cnt] : mp) {
            ans = max(ans, cnt);
        }

        return ans;
    }
};
