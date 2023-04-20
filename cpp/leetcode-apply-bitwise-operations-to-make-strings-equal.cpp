// https://leetcode.cn/problems/apply-bitwise-operations-to-make-strings-equal
class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        // 1 1 : 1 0
        // 1 0 : 1 1
        // 0 1 : 1 1
        // 0 0 : 0 0
        int n = s.size();
        int lft = 0, rgt = 0;
        for (int i = n; i--; ) {
            if (s[i] != target[i]) (s[i] == '1' ? lft : rgt)++;
            if (s[i] == '1' && target[i] == '1') return true;
        }
        return lft == rgt || (lft && rgt);
    }
};
