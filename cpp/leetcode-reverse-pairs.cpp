/*---------逆序对模板写法----------*/
// https://leetcode.cn/problems/reverse-pairs/
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return treetree::mergeSort<
                int,
                g
                >(nums,0,int(nums.size()));
    }
};
