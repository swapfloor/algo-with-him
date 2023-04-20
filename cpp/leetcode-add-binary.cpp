// https://leetcode.cn/problems/add-binary
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int cut=0;
        string ans;
        for(int i=0;i<a.size()||i<b.size()||cut;i++){
            if(i<a.size())cut+=a[i]=='1';
            if(i<b.size())cut+=b[i]=='1';
            ans+='0'+(cut%2);
            cut/=2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
