// https://leetcode.cn/problems/unique-binary-search-trees-ii
// 递归
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        auto dfs = [&](auto self, int lower, int upper) -> vector<TreeNode *> {
            if (lower > upper) return {nullptr};
            if (lower == upper) {
                return {new TreeNode(lower)};
            }
            vector<TreeNode *> ans;
            for (int middle = lower; middle <= upper; middle++) {
                auto lson = self(self, lower, middle - 1);
                auto rson = self(self, middle + 1, upper);
                for (auto &l : lson) {
                    for (auto &r : rson) {
                        ans.push_back(new TreeNode(middle, l, r));
                    }
                }
            }
            return ans;
        };
        return dfs(dfs, 1, n);
    }
};
