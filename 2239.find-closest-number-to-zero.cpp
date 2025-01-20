/*
 * @lc app=leetcode.cn id=2239 lang=cpp
 * @lcpr version=30204
 *
 * [2239] 找到最接近 0 的数字
 *
 * https://leetcode.cn/problems/find-closest-number-to-zero/description/
 *
 * algorithms
 * Easy (53.67%)
 * Likes:    31
 * Dislikes: 0
 * Total Accepted:    27.3K
 * Total Submissions: 46.4K
 * Testcase Example:  '[-4,-2,1,4,8]'
 *
 * 给你一个长度为 n 的整数数组 nums ，请你返回 nums 中最 接近 0 的数字。如果有多个答案，请你返回它们中的 最大值 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [-4,-2,1,4,8]
 * 输出：1
 * 解释：
 * -4 到 0 的距离为 |-4| = 4 。
 * -2 到 0 的距离为 |-2| = 2 。
 * 1 到 0 的距离为 |1| = 1 。
 * 4 到 0 的距离为 |4| = 4 。
 * 8 到 0 的距离为 |8| = 8 。
 * 所以，数组中距离 0 最近的数字为 1 。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [2,-1,1]
 * 输出：1
 * 解释：1 和 -1 都是距离 0 最近的数字，所以返回较大值 1 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 1000
 * -10^5 <= nums[i] <= 10^5
 *
 *
 */

// @lcpr-template-start
#include <cstdint>
#include <cstdlib>
#include <stdint.h>
#include <vector>

using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int findClosestNumber(vector<int> &nums) {
        int32_t ans = INT32_MAX;
        for (auto &n : nums) {
            if (abs(n) > abs(ans))
                continue;
            else if (abs(n) < abs(ans))
                ans = n;
            else if (n > 0)
                ans = n;
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [-4,-2,1,4,8]\n
// @lcpr case=end

// @lcpr case=start
// [2,-1,1]\n
// @lcpr case=end

 */
