// https://leetcode.cn/problems/maximum-subarray-sum-with-one-deletion
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        vector<int> noRm(arr.size() + 1), rm(arr.size() + 1);
        noRm[0] = arr[0];
        rm[0] = max(0, arr[0]);
        int ans = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            noRm[i] = max(arr[i], arr[i] + noRm[i - 1]);
            rm[i] = max(noRm[i - 1], rm[i - 1] + arr[i]);
            ans = max(ans, noRm[i]);
            ans = max(ans, rm[i]);
        }
        return ans;
    }
};
