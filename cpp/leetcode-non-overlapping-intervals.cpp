/*
经典贪心：右值排序
sort(a,[](l, r) { return l.r < r.r; })
r = a[0].r
ans = 0
for i = 1; i < n; i++ :
  if r <= a[i].l:
    ans++
    r = a[i].r
ans # 为不相交的最大段
ans = n - ans # 去掉 n - 不相交最大段
*/
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const auto& l,const auto& r){
            return l[1] < r[1];
        });
        int r=intervals[0][1];
        int ans=1;
        int n=intervals.size();
        for(int i=1;i<n;i++){
            if(r<=intervals[i][0]){
                r=intervals[i][1];
                ans++;
            }
        }
        return n-ans;
    }
};
