/*
 * @lc app=leetcode.cn id=2656 lang=cpp
 *
 * [2656] K 个元素的最大和
 */
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int ptr = 0;
        for (int i=1; i<nums.size(); i++) 
            if (nums[i]>nums[ptr])
                ptr = i;
        return (nums[ptr]*k+k*(k-1)/2);
    }
};
// @lc code=end

