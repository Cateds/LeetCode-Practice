/*
 * @lc app=leetcode.cn id=53 lang=cpp
 * @lcpr version=30204
 *
 * [53] 最大子数组和
 *
 * https://leetcode.cn/problems/maximum-subarray/description/
 *
 * algorithms
 * Medium (55.79%)
 * Likes:    6880
 * Dislikes: 0
 * Total Accepted:    1.9M
 * Total Submissions: 3.5M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 *
 * 子数组 是数组中的一个连续部分。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
 * 输出：6
 * 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [1]
 * 输出：1
 *
 *
 * 示例 3：
 *
 * 输入：nums = [5,4,-1,7,8]
 * 输出：23
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 *
 *
 * 进阶：如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的 分治法 求解。
 *
 */

// @lcpr-template-start
#include <vector>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        vector<int> data;
        int data_count = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == 0)
                continue;
            else if (nums[i - 1] * nums[i] > 0 or
                     i > 1 and
                         nums[i - 1] == 0 and
                         nums[i] * nums[i - 2] > 0) {
                data_count += nums[i];
            } else {
                data.push_back(data_count);
                data_count = nums[i];
            }
        }
        data.push_back(data_count);
        if (data.size() == 1 and data[0] <= 0) {
            int Res = nums[0];
            for (int i = 1; i < nums.size(); i++)
                if (nums[i] > Res)
                    Res = nums[i];
            return Res;
        } else {
            int ptr = 0, count1_min = 0, count1 = 0, count2 = data[0];
            int Res = data[0];
            while (ptr < data.size() - 1) {
                do {
                    ptr++;
                    count2 += data[ptr];
                    count1 += data[ptr - 1];
                } while (data[ptr] < 0 and ptr < data.size() - 1);
                if (count1 < count1_min)
                    count1_min = count1;
                if (count2 - count1_min > Res)
                    Res = count2 - count1_min;
            }
            return Res;
        }
    }
};

// @lc code=end

/*
// @lcpr case=start
// [-2,1,-3,4,-1,2,1,-5,4]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,-1,7,8]\n
// @lcpr case=end

 */
