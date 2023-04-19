// 二分搜索
// https://leetcode.cn/problems/find-right-intervals
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<pair<int,int>>s(n);
        for(int i=0;i<n;i++){
            s[i]={intervals[i][0],i};
        }
        sort(s.begin(),s.end());
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            int l=intervals[i][0],r=intervals[i][1];
            auto it=lower_bound(s.begin(),s.end(),pair<int,int>{r,0});
            if(it!=s.end()){
                ans[i]=it->second;
            }
        }
        return ans;
    }
};
