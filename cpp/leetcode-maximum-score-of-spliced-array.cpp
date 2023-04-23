// https://leetcode.cn/problems/maximum-score-of-spliced-array
class Solution {
public:
    int maximumsSplicedArray(vector<int>& a, vector<int>& b) {
        int sum = 0, suma = 0;
        for (int i = 0; i < a.size(); i++) {
            sum += a[i];
            suma += a[i];
        }
        int sumb = 0;
        for (int i = 0; i < b.size(); i++) {
            sum += b[i];
            sumb += b[i];
        }
        int n = a.size();
        vector<int> diffAsubB(n), diffBsubA(n);
        for (int i = 0; i < n; i++) {
            diffAsubB[i] = a[i] - b[i];
            diffBsubA[i] = b[i] - a[i];
        } 
        int maxAsubB = 0, maxBsubA = 0, tmp1 = 0, tmp2 = 0;
        for (int i = 0; i < n; i++) {
            tmp1 = max(diffAsubB[i], tmp1 + diffAsubB[i]);
            tmp2 = max(diffBsubA[i], tmp2 + diffBsubA[i]);
            maxAsubB = max(maxAsubB, tmp1);
            maxBsubA = max(maxBsubA, tmp2);
        }
        int canb = suma + maxBsubA;
        canb = max(canb, sum - canb);
        int cana = sumb + maxAsubB;
        cana = max(cana, sum - cana);
        // cout << suma << " " << maxBsubA << "\n";
        // cout << sumb << " " << maxAsubB << "\n";
        return max(cana, canb);
    }
};
