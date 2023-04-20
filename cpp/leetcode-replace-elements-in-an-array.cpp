// https://leetcode.cn/problems/replace-elements-in-an-array
// 灵茶山
class Solution {
public:
    vector<int> arrayChange(vector<int>& a, vector<vector<int>>& ope) {
        unordered_map<int, int> f; 
        // f[x] 表示 x 经过一系列变化后最后变成的数值 f[x]，一定可以从前往后变化，
        // 对于一组 [x, y] f[x] = f[y] or default : y，而从前往后变化，就从后往前面求，这是从小状态往打的顺序dp。
        for (int i = int(ope.size()) - 1; i >= 0; i--) {
            int x = ope[i][0], y = ope[i][1];
            f[x] = f.find(y) == f.end() ? y : f[y];
        }
        for (int i = 0; i < a.size(); i++) {
            if (f.find(a[i]) != f.end()) {
                a[i] = f[a[i]];
            }
        }
        return a;
    }
};
// treetree
class Solution {
public:
    vector<int> arrayChange(vector<int>& a, vector<vector<int>>& ope) {
        vector<int> idx(1000000 + 12);
        for (int i = 0; i < a.size(); i++) {
            idx[a[i]] = i;
        }
        for (auto &v : ope) {
            int pre = v[0], cur = v[1];
            int pos = idx[pre];
            a[pos] = cur;
            idx[cur] = pos;
            idx[pre] = 0;
        }
        return a;
    }
};
