// https://leetcode.cn/problems/sum-of-prefix-scores-of-strings
struct Trie {
    int cnt = 0;
    unordered_map<char, Trie *> children;
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie *root = new Trie();
        for (int i = 0; i < words.size(); i++) {
            Trie *cur = root;
            int len = words[i].size();
            for (int j = 0; j < len; j++) {
                char c = words[i][j];
                if (!cur->children.count(c)) {
                    cur->children[c] = new Trie();
                }
                cur = cur->children[c];
                cur->cnt++;
            }
        }
        vector<int> ans(words.size());
        for (int i = 0; i < words.size(); i++) {
            Trie *cur = root;
            int len = words[i].size();
            int cnt = 0;
            for (int j = 0; j < len; j++) {
                char c = words[i][j];
                cur = cur->children[c];
                cnt += cur->cnt;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};
