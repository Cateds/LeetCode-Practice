/*
 * @lc app=leetcode.cn id=2275 lang=cpp
 * @lcpr version=30204
 *
 * [2275] 按位与结果大于零的最长组合
 *
 * https://leetcode.cn/problems/largest-combination-with-bitwise-and-greater-than-zero/description/
 *
 * algorithms
 * Medium (62.51%)
 * Likes:    64
 * Dislikes: 0
 * Total Accepted:    16.7K
 * Total Submissions: 23.9K
 * Testcase Example:  '[16,17,71,62,12,24,14]'
 *
 * 对数组 nums 执行 按位与 相当于对数组 nums 中的所有整数执行 按位与 。
 *
 *
 * 例如，对 nums = [1, 5, 3] 来说，按位与等于 1 & 5 & 3 = 1 。
 * 同样，对 nums = [7] 而言，按位与等于 7 。
 *
 *
 * 给你一个正整数数组 candidates 。计算 candidates 中的数字每种组合下 按位与 的结果。
 *
 * 返回按位与结果大于 0 的 最长 组合的长度。
 *
 *
 *
 * 示例 1：
 *
 * 输入：candidates = [16,17,71,62,12,24,14]
 * 输出：4
 * 解释：组合 [16,17,62,24] 的按位与结果是 16 & 17 & 62 & 24 = 16 > 0 。
 * 组合长度是 4 。
 * 可以证明不存在按位与结果大于 0 且长度大于 4 的组合。
 * 注意，符合长度最大的组合可能不止一种。
 * 例如，组合 [62,12,24,14] 的按位与结果是 62 & 12 & 24 & 14 = 8 > 0 。
 *
 *
 * 示例 2：
 *
 * 输入：candidates = [8,8]
 * 输出：2
 * 解释：最长组合是 [8,8] ，按位与结果 8 & 8 = 8 > 0 。
 * 组合长度是 2 ，所以返回 2 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= candidates.length <= 10^5
 * 1 <= candidates[i] <= 10^7
 *
 *
 */

// @lcpr-template-start
#include <algorithm>
#include <array>
#include <climits>
#include <vector>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int largestCombination(vector<int> &candidates) {
        array<int, 24> cnt;
        for (auto can : candidates)
            for (int i = 0; can; i++, can >>= 1)
                cnt[i] += can & 0b1;
        return ranges::max(cnt);
        // return *max_element(cnt.begin(), cnt.end());
    }
};
// @lc code=end

/*
// @lcpr case=start
// [16,17,71,62,12,24,14]\n
// @lcpr case=end

// @lcpr case=start
// [8,8]\n
// @lcpr case=end

 */
