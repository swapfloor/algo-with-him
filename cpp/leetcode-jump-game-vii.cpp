// slide window 
// 可以想向成一个队列，不在队列就剔除
// https://leetcode.com/problems/jump-game-vii/
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if (s.back() == '1') return false;
        int n = s.size();
        vector<bool> reach(n);
        reach[0] = true;
        int cur = 0;
        for (int i = minJump; i < n; i++) {
            if (i - maxJump - 1 >= 0) {
                cur -= reach[i - maxJump - 1];
            }
            cur += reach[i - minJump];
            if (cur > 0 && s[i] == '0') reach[i] = true;
        }
        return reach[n - 1];
    }
};
