// https://leetcode.cn/problems/range-product-queries-of-powers
using mint = treetree::modint1000000007;
using i64 = long long;
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        auto factor = [&](int n) {
            vector<int> ans;
            for (int i = 0; i <= 30; i++) {
                if (n >> i & 1) {
                    ans.push_back(1 << i);
                }
            }
            return ans;
        };
        auto a = factor(n);
        vector<mint> pre(a.size() + 1, mint(1));
        for (int i = 0; i < a.size(); i++) {
            pre[i + 1] = pre[i] * a[i];
        }
        int q = queries.size();
        vector<int> ans(q);
        for (int i = 0; i < q; i++) {
            int l = queries[i][0], r = queries[i][1];
            ans[i] = (pre[r + 1] / pre[l]).val();
        }
        return ans;
    }
};
