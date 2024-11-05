/*
 * @lc app=leetcode.cn id=689 lang=cpp
 *
 * [689] 三个无重叠子数组的最大和
 * 
 * 2023/11/19 每日一题
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> data; data.resize(nums.size()-k+1);
        data[0] = 0;
        for (int i=1; i<data.size(); i++) {
            data[i] = data[i-1] + nums[i+k-1] - nums[i-1];
        }
        vector<int> Res = {0,k,2*k}; 
        int ptr3=2*k;
        int ptr1_max1=0, ptr1_max2=0, ptr2_max2=k;
        while (ptr3<data.size()-1) {
            ptr3++;
            if (data[ptr3-2*k]>data[ptr1_max1]) ptr1_max1 = ptr3-2*k;
            if ((data[ptr3-k]+data[ptr1_max1])>(data[ptr1_max2]+data[ptr2_max2])) {
                ptr1_max2 = ptr1_max1;
                ptr2_max2 = ptr3-k;
            }
            if ((data[Res[0]]+data[Res[1]]+data[Res[2]])<(data[ptr1_max2]+data[ptr2_max2]+data[ptr3])) {
                Res[0] = ptr1_max2;
                Res[1] = ptr2_max2;
                Res[2] = ptr3;
            }
        }
        return Res;
    }
};
// @lc code=end

