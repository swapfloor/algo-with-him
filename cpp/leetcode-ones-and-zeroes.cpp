// https://leetcode.cn/problems/ones-and-zeroes
class Solution {
public:
    void chkMax(int &a, int b) {
        if (a < b) a = b;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector f(m + 1, vector<int>(n + 1));
        vector<int> zero(len + 1), one(len + 1);
        for (int i = 1; i <= len; i++) {
            zero[i] = count(strs[i - 1].begin(), strs[i - 1].end(), '0');
            one[i] = strs[i - 1].size() - zero[i];
        }
        for (int i = 1; i <= len; i++) {
            for (int j = m; j >= zero[i]; j--) {
                for (int k = n; k >= one[i]; k--) {
                    chkMax(f[j][k], f[j - zero[i]][k - one[i]] + 1);
                }
            }
        }
        return f[m][n];
    }
};
