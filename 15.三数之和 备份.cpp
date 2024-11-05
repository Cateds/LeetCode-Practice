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
    int find(vector<int>& nums, const int& n, int left, int right) {
        if (left>right||n>nums[right]||n<nums[left]) return -1;
        while (true) {
            if (right-left==1) {
                if (nums[left]==n) return left;
                else if (nums[right]==n) return right;
                else return -1;
            }
            else {
                int mid = (left+right)/2;
                if (nums[mid]==n) return mid;
                else if (nums[mid]>n) right=mid;
                else /*nums[mid]<n*/ left=mid;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> Ret;
        sort(nums.begin(),nums.end());
        for (int i=0; i<nums.size() && nums[i]<=0; i++) {
            if (i>0&&nums[i]==nums[i-1]) continue;
            for (int j=i+1; j<nums.size()&&nums[j]<=(-nums[i]/2); j++) {
                if (j>i+1&&nums[j]==nums[j-1]) continue;
                int p = find(nums,-nums[i]-nums[j],j+1,nums.size()-1);
                if (p!=-1) Ret.push_back(vector<int>({nums[i],nums[j],nums[p]}));
            }
        }
        return Ret;
    }
};
// @lc code=end

int main(void) {
    vector<int> a = {3,-2,1,0};
    Solution obj;
    // for (auto &i: obj.threeSum(a)) {
    //     for (auto &j: i)
    //         std::cout << j << ' ';
    //     std::cout << std::endl;
    // }
    sort(a.begin(),a.end());
    for (auto &j: a)
        std::cout << j << ' ';
    std::cout << std::endl;
    std::cout << obj.find(a,2,0,a.size()-1);
}