// https://leetcode.cn/problems/lowest-common-ancestor-of-deepest-leaves
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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        auto tour = [&](auto self, TreeNode *u, int dep) -> pair<int, TreeNode *> {
            if (u->left && u->right) {
                auto lft = self(self, u->left, dep + 1);
                auto rgt = self(self, u->right, dep + 1);
                if (lft.first == rgt.first) return {lft.first, u};
                else if (lft.first < rgt.first) return rgt;
                else if (lft.first > rgt.first) return lft;
            } else if(u->left) {
                return self(self, u->left, dep + 1);
            } else if(u->right) {
                return self(self, u->right, dep + 1);
            } 
            return {dep, u};
        };
        return tour(tour, root, 0).second;
    }
};
