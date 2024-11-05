/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> Ret;
        sort(nums.begin(),nums.end());
        for (int i=0; i<nums.size()-2&&nums[i]<=0; i++) {
            if (i>0&&nums[i]==nums[i-1]) continue;
            int ptr1=i+1, ptr2=nums.size()-1;
            while (ptr1<ptr2) {
                if (nums[i]+nums[ptr1]+nums[ptr2]<0) ptr1++;
                else if (nums[i]+nums[ptr1]+nums[ptr2]>0) ptr2--;
                else {
                    Ret.push_back(vector<int>({nums[i],nums[ptr1],nums[ptr2]}));
                    ptr1++; ptr2--;
                    while (ptr1>i+1&&ptr1<nums.size()&&nums[ptr1]==nums[ptr1-1])
                        ptr1++;
                    while (ptr2<nums.size()-1&&ptr2>0&&nums[ptr2]==nums[ptr2+1])
                        ptr2--;
                }
            }
        }
        return Ret;
    }
};
// @lc code=end

int main(void) {
    vector<int> a = {0,0,0,0};
    Solution obj;
    for (auto &i: obj.threeSum(a)) {
        for (auto &j: i)
            std::cout << j << ' ';
        std::cout << std::endl;
    }
}