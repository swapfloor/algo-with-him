// https://leetcode.cn/problems/last-stone-weight-ii
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int s = 0;
        int n = stones.size();
        for (int i = 0; i < n; i++) s += stones[i];
        int k = s / 2;
        int f[k + 1];
        memset(f, 0, sizeof f);
        f[0] = 1;
        int ans = numeric_limits<int>::max();        
        for (int i = 0; i < n; i++) {
            int x = stones[i];
            for (int j = k; j >= x; j--) {
                f[j] |= f[j - x];   
            }
        }
        for (int j = 0; j <= k; j++) {
            if (f[j]) ans = min(ans, s - 2 * j);
        }
        return ans;
    }
};
