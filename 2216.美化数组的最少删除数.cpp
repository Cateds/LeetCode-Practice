/*
 * @lc app=leetcode.cn id=2216 lang=cpp
 *
 * [2216] 美化数组的最少删除数
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int Res = 0;
        for (int i=0; i<nums.size()-1;) {
            if (nums[i]==nums[i+1]) {
                Res++;
                i++;
            } else i+=2;
        }
        if ((nums.size()-Res)%2!=0) Res++;
        return Res;
    }
};
// @lc code=end

