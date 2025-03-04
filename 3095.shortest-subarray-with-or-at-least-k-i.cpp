/*
 * @lc app=leetcode.cn id=3095 lang=cpp
 * @lcpr version=30204
 *
 * [3095] 或值至少 K 的最短子数组 I
 *
 * https://leetcode.cn/problems/shortest-subarray-with-or-at-least-k-i/description/
 *
 * algorithms
 * Easy (46.80%)
 * Likes:    10
 * Dislikes: 0
 * Total Accepted:    6.4K
 * Total Submissions: 13.1K
 * Testcase Example:  '[1,2,3]\n2'
 *
 * 给你一个 非负 整数数组 nums 和一个整数 k 。
 *
 * 如果一个数组中所有元素的按位或运算 OR 的值 至少 为 k ，那么我们称这个数组是 特别的 。
 *
 * 请你返回 nums 中 最短特别非空 子数组的长度，如果特别子数组不存在，那么返回 -1 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,2,3], k = 2
 *
 * 输出：1
 *
 * 解释：
 *
 * 子数组 [3] 的按位 OR 值为 3 ，所以我们返回 1 。
 *
 * 注意，[2] 也是一个特别子数组。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [2,1,8], k = 10
 *
 * 输出：3
 *
 * 解释：
 *
 * 子数组 [2,1,8] 的按位 OR 值为 11 ，所以我们返回 3 。
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [1,2], k = 0
 *
 * 输出：1
 *
 * 解释：
 *
 * 子数组 [1] 的按位 OR 值为 1 ，所以我们返回 1 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 50
 * 0 <= nums[i] <= 50
 * 0 <= k < 64
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
    int minimumSubarrayLength(vector<int> &nums, int k) {
        array<int, 30> bits = {0};
        array<bool, 30> bits_k = {0};
        for (int i = 0, k_val = k; k_val; i++, k_val >>= 1)
            bits_k[i] = k_val & 1;
        auto is_bigger = [&](void) -> bool {
            for (int i = 29; i >= 0; i--)
                if (!bits_k[i] and bits[i])
                    return true;
                else if (bits_k[i] and !bits[i])
                    return false;
            return true;
        };
        int res = INT_MAX;
        int n = nums.size();
        for (int left = 0, right = 0; right < n; right++) {
            for (int i = 0, val = nums[right]; val; i++, val >>= 1)
                bits[i] += val & 1;
            while (left <= right and is_bigger()) {
                res = min(res, right - left + 1);
                for (int i = 0, val = nums[left]; val; i++, val >>= 1)
                    bits[i] -= val & 1;
                left++;
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [2,1,8]\n10\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n0\n
// @lcpr case=end

 */
