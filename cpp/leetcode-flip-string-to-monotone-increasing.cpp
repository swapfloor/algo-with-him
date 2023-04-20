// https://leetcode.cn/problems/flip-string-to-monotone-increasing 
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.size();
        int ones=count(s.begin(),s.end(),'1');
        int ans=n-ones;
        int zeros=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0')zeros++;
            else ones--;
            ans=min(ans,n-ones-zeros);
        }
        return ans;
    }
};
