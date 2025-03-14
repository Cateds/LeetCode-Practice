// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2597 lang=cpp
 * @lcpr version=30204
 *
 * [2597] 美丽子集的数目
 *
 * https://leetcode.cn/problems/the-number-of-beautiful-subsets/description/
 *
 * algorithms
 * Medium (37.71%)
 * Likes:    55
 * Dislikes: 0
 * Total Accepted:    9.5K
 * Total Submissions: 24.7K
 * Testcase Example:  '[2,4,6]\n2'
 *
 * 给你一个由正整数组成的数组 nums 和一个 正 整数 k 。
 *
 * 如果 nums 的子集中，任意两个整数的绝对差均不等于 k ，则认为该子数组是一个 美丽 子集。
 *
 * 返回数组 nums 中 非空 且 美丽 的子集数目。
 *
 * nums 的子集定义为：可以经由 nums
 * 删除某些元素（也可能不删除）得到的一个数组。只有在删除元素时选择的索引不同的情况下，两个子集才会被视作是不同的子集。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [2,4,6], k = 2
 * 输出：4
 * 解释：数组 nums 中的美丽子集有：[2], [4], [6], [2, 6] 。
 * 可以证明数组 [2,4,6] 中只存在 4 个美丽子集。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [1], k = 1
 * 输出：1
 * 解释：数组 nums 中的美丽数组有：[1] 。
 * 可以证明数组 [1] 中只存在 1 个美丽子集。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 18
 * 1 <= nums[i], k <= 1000
 *
 *
 */

// @lcpr-template-start
#include <array>
#include <map>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int beautifulSubsets(vector<int> &nums, int k) {
        unordered_map<int, map<int, int>> groups;
        for (int a : nums) {
            ++groups[a % k][a];
        }
        int ans = 1;
        for (auto &[_, g] : groups) {
            int m = g.size();
            vector<vector<int>> f(m, vector<int>(2, 0));
            f[0][0] = 1, f[0][1] = (1 << g.begin()->second) - 1;
            int i = 1;
            for (auto it = next(g.begin()); it != g.end(); it++, i++) {
                f[i][0] = f[i - 1][0] + f[i - 1][1];
                if (it->first - prev(it)->first == k) {
                    f[i][1] = f[i - 1][0] * ((1 << it->second) - 1);
                } else {
                    f[i][1] =
                        (f[i - 1][0] + f[i - 1][1]) * ((1 << it->second) - 1);
                }
            }
            ans *= f[m - 1][0] + f[m - 1][1];
        }
        return ans - 1;
    }
};
// @lc code=end

/**
  @brief Beautiful Subsets Solution
    解法:
    1. 将数组分组，将同余(模k)的元素放在同一组中，因为不同组之间的元素差值不可能为k
    2. 对每个组单独处理，使用动态规划:
        - 按元素值从小到大排序
        - f[i][0] 表示考虑前i个元素，不选择第i个元素的美丽子集数量
        - f[i][1] 表示考虑前i个元素，选择第i个元素的美丽子集数量
    3. 状态转移:
        - f[i][0] = f[i-1][0] + f[i-1][1] (不选第i个元素，前i-1个可选可不选)
        - 如果当前元素与前一个元素差值为k:
        f[i][1] = f[i-1][0] * ((1 << count) - 1) (只能在不选前一个元素的情况下选当前元素)
        - 否则:
        f[i][1] = (f[i-1][0] + f[i-1][1]) * ((1 << count) - 1) (前i-1个可选可不选)
    4. (1 << count) - 1 表示当前值可以选1到count个的方案数
    5. 将各组的结果相乘得到总方案数，最后减1排除空集

    时间复杂度: O(n + m)，其中n是数组长度，m是不同元素的个数
    空间复杂度: O(m)
 */

// @lcpr-div-debug-arg-start
// funName=beautifulSubsets
// paramTypes= ["number[]","number"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [4,2,5,9,10,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// // @lcpr case=start
// [2,4,6]\n2\n
// @lcpr case=end

 */
