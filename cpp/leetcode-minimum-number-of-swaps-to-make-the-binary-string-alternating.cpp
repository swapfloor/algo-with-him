// https://leetcode.cn/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating
class Solution {
public:
    int minSwaps(string s) {
        int n=s.size();
        int ones=count(s.begin(),s.end(),'1');
        int zeros=n-ones;
        if(std::abs(ones-zeros)>1)return -1;
        if(n&1){
            if(ones>zeros){
                int o=0;
                for(int i=0;i<n;i+=2)o+=s[i]=='1';
                return max(std::abs(ones-o),std::abs(zeros-(n-o)));
            }else{
                int o=0;
                for(int i=0;i<n;i+=2)o+=s[i]=='0';
                return max(std::abs(zeros-o),std::abs(ones-(n-o)));
            }
        }else{
            int o=0;
            for(int i=0;i<n;i+=2)o+=s[i]=='1';
            int ans=max(std::abs(ones-o),std::abs(zeros-(n-o)));
            o=0;
            for(int i=0;i<n;i+=2)o+=s[i]=='0';
            ans=min(ans,max(std::abs(zeros-o),std::abs(ones-(n-o))));
            return ans;
        }
    }
};
