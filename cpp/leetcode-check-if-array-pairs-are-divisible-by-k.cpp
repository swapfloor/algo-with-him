// https://leetcode.cn/problems/check-if-array-pairs-are-divisible-by-k
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int>cnt(k);
        for (int i=0;i<arr.size();i++){
            arr[i]%=k;
            if(arr[i]<0)arr[i]+=k;
            cnt[arr[i]]++;
        }
        if(cnt[0]%2)return false;
        for(int i=1;i<k-i;i++)if(cnt[i]!=cnt[k-i])return false;
        if(k%2==0&&cnt[k/2]%2!=0)return false;
        return true;
    }
};
