// https://leetcode.cn/problems/target-sum
int f[30][50000];
const int de = 25000;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(f, 0, sizeof f);
        f[0][0 + de] = 1;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            for (int j = -20000; j <= 20000; j++) {
                f[i + 1][j + de] += f[i][j + de + x];
                f[i + 1][j + de] += f[i][j + de - x];
            }
        }
        return f[nums.size()][target + de];
    }
};
