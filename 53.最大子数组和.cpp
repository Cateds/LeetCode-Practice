/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 * 
 * 2023/11/20 每日一题
 * 
 * 25% 效率 22% 内存占用，鉴定为寄
 * 
 */
#include <iostream>
#include <vector>
#include <stdbool.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> data;
        int data_count = nums[0];
        for (int i=1; i<nums.size(); i++) {
            if (nums[i]==0) continue;
            else if (nums[i-1]*nums[i]>0 || i>1 && nums[i-1]==0 && nums[i]*nums[i-2]>0) {
                data_count += nums[i];
            }
            else {
                data.push_back(data_count);
                data_count = nums[i];
            }
        }
        data.push_back(data_count);
        if (data.size()==1 && data[0]<=0) {
            int Res = nums[0];
            for (int i=1; i<nums.size(); i++)
                if (nums[i] > Res) Res = nums[i];
            return Res;
        }
        else {
            int ptr=0, count1_min=0, count1=0, count2=data[0];
            int Res=data[0];
            while (ptr<data.size()-1) {
                do {
                    ptr++; count2 += data[ptr]; count1 += data[ptr-1];
                } while(data[ptr]<0 && ptr<data.size()-1);
                if (count1 < count1_min) count1_min = count1;
                if (count2-count1_min > Res) Res = count2-count1_min;
            }
            return Res;
        }
    }
};
// @lc code=end

/*
    你也该买本算法导论看看动态规划了

    class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int pre = 0, maxAns = nums[0];
            for (const auto &x: nums) {
                pre = max(pre + x, x);
                maxAns = max(maxAns, pre);
            }
            return maxAns;
        }
    };

    作者：力扣官方题解
    链接：https://leetcode.cn/problems/maximum-subarray/description/
    来源：力扣（LeetCode）
    著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */