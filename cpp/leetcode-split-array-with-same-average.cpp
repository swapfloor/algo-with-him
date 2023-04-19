// https://leetcode.cn/problems/split-array-with-same-average
using i64 = long long;
class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        int n = A.size();
        if (n == 1) return false;
        int s = 0;
        for (auto a : A) s += a;
        for (int i = 0; i < n; i++) {
            A[i] = A[i] * n - s;
        }
        vector<int> B{0}, C{0};
        for (auto a : A) {
            for (int i = B.size(); i--; ) B.push_back(B[i] + a);
            swap(B, C);
        }
        int sb = 0;
        if (n % 2) {
            for (int i = 1; i < n; i += 2) sb += A[i];
        } else {
            for (int i = 0; i < n; i += 2) sb += A[i];
        }
        B.erase(B.begin());
        C.erase(C.begin());
        for (auto b : B) if (!b) return true;
        for (auto c : C) if (!c) return true;
        sort(B.begin(), B.end());
        for (auto c : C) {
            auto it = lower_bound(B.begin(), B.end(), -c);
            if (it != B.end() && *it != sb && *it == -c) {
                return true;
            }
        }
        return false;
    }
};
