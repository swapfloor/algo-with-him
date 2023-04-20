// https://leetcode.cn/problems/partition-array-such-that-maximum-difference-is-k
class Solution {
public:
    int partitionArray(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int cur = a[0], cnt = 1;
        for (int i = 1; i < a.size(); i++) {
            if (a[i] > cur + k) {
                cur = a[i];
                cnt++;
            }
        }
        return cnt;
    }
};
