// https://leetcode.cn/problems/filling-bookcase-shelves
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> f(n + 1, 1e6);
        f[0] = 0;
        for (int i = 0; i < n; i++) {
            int cntW = 0, maxH = 0;
            for (int j = i; j >= 0; j--) {
                cntW += books[j][0];
                maxH = max(maxH, books[j][1]);
                if (cntW > shelfWidth) {
                    break;
                }
                f[i + 1] = min(f[i + 1], f[j] + maxH);
            }
        }
        return f[n];
    }
};
