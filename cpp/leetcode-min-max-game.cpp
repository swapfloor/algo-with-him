// https://leetcode.cn/problems/min-max-game
class Solution {
public:
    int minMaxGame(const vector<int>& a) {
        int n = a.size();
        if (n == 1) return a[0];
        auto b = a;
        while (b.size() > 1) {
            vector<int> nb;
            int mn = 1;
            for (int i = 0; i < b.size(); i += 2) {
                if (mn) nb.push_back(min(b[i], b[i + 1]));
                else nb.push_back(max(b[i], b[i + 1]));
                mn ^= 1;
            }
            b = move(nb);
        }
        return b[0];
    }
};
