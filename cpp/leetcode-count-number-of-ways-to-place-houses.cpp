// https://leetcode.cn/problems/count-number-of-ways-to-place-houses
class Solution {
private:
    const int MOD = 1e9 + 7;
    void add(int &a, int b) {
        a += b;
        if (a >= MOD) a -= MOD;
    }
public:
    int countHousePlacements(int n) {
        int f[n + 1][2];
        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for (int i = 0; i < n; i++) {
            add(f[i + 1][0], f[i][0]);
            add(f[i + 1][0], f[i][1]);
            add(f[i + 1][1], f[i][0]);
        }
        int ans = f[n][0];
        add(ans, f[n][1]);
        return 1LL * ans * ans % MOD;
    }
};
