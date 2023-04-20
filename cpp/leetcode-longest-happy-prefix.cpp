// https://leetcode.cn/problems/longest-happy-prefix
class Solution {
public:
    string longestPrefix(string s) {
        auto p = treetree::kmp(s);
        int n = s.size();
        int len = p.back();
        string ans = s.substr(0, len);
        return ans;
    }
};
