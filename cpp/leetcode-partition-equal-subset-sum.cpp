// https://leetcode.cn/problems/partition-equal-subset-sum
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s = 0;
        for (auto x : nums) s += x;
        int n = nums.size();
        if (n == 1 || s % 2) return false;
        s /= 2;
        vector<int> f(s + 1);
        f[0] = true;
        for (auto x : nums) {
            for (int j = s; j >= x; j--) {
                f[j] |= f[j - x];
            }
        }
        return f[s];
    }
};
