// https://leetcode.cn/problems/unique-binary-search-trees
// f(i, n) 表示以 i 为根，序列长度为 n 的 bst 种类数
// g(n) 表示序列长度为 n 的 bst 种类数
// f(i, n) = sum(g[j] * g[n - j - 1]) 0 <= j <= n - 1
class Solution {
public:
    int numTrees(int n) {
        vector<int> f(20);
        f[0] = f[1] = 1;
        for (int i = 2; i <= n; i++) {
            int s = 0;
            for (int j = 0; j < i; j++) {
                s += f[j] * f[i - j - 1];
            }
            f[i] = s;
        }
        return f[n];
    }
};
