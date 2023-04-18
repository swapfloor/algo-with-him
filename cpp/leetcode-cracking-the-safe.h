// https://leetcode.cn/problems/cracking-the-safe
// 欧拉回路
class Solution {
private:
    int k;
    unordered_set<int> seen;
    string ans;
    int highest;
public:
    string stk;

    void dfs(int node) {
        for (int i = 0; i < k; i++) {
            int nei = 10 * node + i;
            nei %= highest;
            if (!seen.count(nei)) {
                seen.insert(nei);
                dfs(nei);
                ans += i + '0';
            }
        }        
    }

    string crackSafe(int n, int k) {
        highest = pow(10, n);
        this->k = k;
        dfs(0);
        ans += string(n - 1, '0');
        return ans;
    }
};
