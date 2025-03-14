// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1760 lang=cpp
 * @lcpr version=30204
 *
 * [1760] 袋子里最少数目的球
 *
 * https://leetcode.cn/problems/minimum-limit-of-balls-in-a-bag/description/
 *
 * algorithms
 * Medium (64.10%)
 * Likes:    264
 * Dislikes: 0
 * Total Accepted:    29.9K
 * Total Submissions: 46.5K
 * Testcase Example:  '[9]\n2'
 *
 * 给你一个整数数组 nums ，其中 nums[i] 表示第 i 个袋子里球的数目。同时给你一个整数 maxOperations 。
 *
 * 你可以进行如下操作至多 maxOperations 次：
 *
 *
 * 选择任意一个袋子，并将袋子里的球分到 2 个新的袋子中，每个袋子里都有 正整数 个球。
 *
 *
 * 比方说，一个袋子里有 5 个球，你可以把它们分到两个新袋子里，分别有 1 个和 4 个球，或者分别有 2 个和 3 个球。
 *
 *
 *
 *
 * 你的开销是单个袋子里球数目的 最大值 ，你想要 最小化 开销。
 *
 * 请你返回进行上述操作后的最小开销。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [9], maxOperations = 2
 * 输出：3
 * 解释：
 * - 将装有 9 个球的袋子分成装有 6 个和 3 个球的袋子。[9] -> [6,3] 。
 * - 将装有 6 个球的袋子分成装有 3 个和 3 个球的袋子。[6,3] -> [3,3,3] 。
 * 装有最多球的袋子里装有 3 个球，所以开销为 3 并返回 3 。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [2,4,8,2], maxOperations = 4
 * 输出：2
 * 解释：
 * - 将装有 8 个球的袋子分成装有 4 个和 4 个球的袋子。[2,4,8,2] -> [2,4,4,4,2] 。
 * - 将装有 4 个球的袋子分成装有 2 个和 2 个球的袋子。[2,4,4,4,2] -> [2,2,2,4,4,2] 。
 * - 将装有 4 个球的袋子分成装有 2 个和 2 个球的袋子。[2,2,2,4,4,2] -> [2,2,2,2,2,4,2] 。
 * - 将装有 4 个球的袋子分成装有 2 个和 2 个球的袋子。[2,2,2,2,2,4,2] -> [2,2,2,2,2,2,2,2] 。
 * 装有最多球的袋子里装有 2 个球，所以开销为 2 并返回 2 。
 *
 *
 * 示例 3：
 *
 * 输入：nums = [7,17], maxOperations = 2
 * 输出：7
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= maxOperations, nums[i] <= 10^9
 *
 *
 */

// @lcpr-template-start
#include <algorithm>
#include <vector>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int minimumSize(vector<int> &nums, int maxOperations) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int ans = 0;
        while (left <= right) {
            int y = (left + right) / 2;
            long long ops = 0;
            for (int x : nums) {
                ops += (x - 1) / y;
            }
            if (ops <= maxOperations) {
                ans = y;
                right = y - 1;
            } else {
                left = y + 1;
            }
        }
        return ans;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=minimumSize
// paramTypes= ["number[]","number"]
// @lcpr-div-debug-arg-end

/**
  @brief
  代码思路：
    使用二分查找来确定最小可能的最大球数，即答案。从 1 到 nums 数组中的最大值搜索，
    对每个中间值 y，计算将每个袋子中球数降至 y 以下所需的操作次数：
      对于袋子中有 x 个球，最少需要 (x - 1) / y 次操作。
    如果总操作次数不超过 maxOperations，则可能更小的 y 是可行的，否则增加 y 继续搜索。
*/

/*
// @lcpr case=start
// [9]\n2\n
// @lcpr case=end

// @lcpr case=start
// [2,4,8,2]\n4\n
// @lcpr case=end

// @lcpr case=start
// [7,17]\n2\n
// @lcpr case=end

 */
