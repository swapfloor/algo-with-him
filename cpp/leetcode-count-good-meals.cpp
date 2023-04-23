// https://leetcode.cn/problems/count-good-meals
class Solution {
public:
    int countPairs(vector<int>& nice) {
        vector<int> cnt((1 << 21) + 1);
        for (int i = 0; i < nice.size(); i++) {
            cnt[nice[i]]++;
        }
        int ans = 0;
        const int mod = 1e9 + 7;
        for (int j = 0; j <= 21; j++) {
            int mask = 1 << j;
            for (int i = 0; i <= mask - i; i++) {
                if (i == mask - i) {
                    ans = (ans + 1LL * cnt[i] * (cnt[i] - 1) / 2 % mod) % mod;
                } else {
                    ans = (ans + 1LL * cnt[i] * cnt[mask - i] % mod) % mod;
                }
            }
        }
        return ans;
    }
};
