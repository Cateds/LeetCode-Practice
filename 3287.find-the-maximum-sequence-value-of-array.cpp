/*
 * @lc app=leetcode.cn id=3287 lang=cpp
 * @lcpr version=30204
 *
 * [3287] 求出数组中最大序列值
 *
 * https://leetcode.cn/problems/find-the-maximum-sequence-value-of-array/description/
 *
 * algorithms
 * Hard (47.20%)
 * Likes:    15
 * Dislikes: 0
 * Total Accepted:    1.9K
 * Total Submissions: 3.6K
 * Testcase Example:  '[2,6,7]\n1'
 *
 * 给你一个整数数组 nums 和一个 正 整数 k 。
 *
 * 定义长度为 2 * x 的序列 seq 的 值 为：
 *
 *
 * (seq[0] OR seq[1] OR ... OR seq[x - 1]) XOR (seq[x] OR seq[x + 1] OR ... OR
 * seq[2 * x - 1]).
 *
 *
 * 请你求出 nums 中所有长度为 2 * k 的 子序列 的 最大值 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [2,6,7], k = 1
 *
 * 输出：5
 *
 * 解释：
 *
 * 子序列 [2, 7] 的值最大，为 2 XOR 7 = 5 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [4,2,5,6,7], k = 2
 *
 * 输出：2
 *
 * 解释：
 *
 * 子序列 [4, 5, 6, 7] 的值最大，为 (4 OR 5) XOR (6 OR 7) = 2 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= nums.length <= 400
 * 1 <= nums[i] < 2^7
 * 1 <= k <= nums.length / 2
 *
 *
 */

// @lcpr-template-start
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int maxValue(vector<int> &nums, int k) {
        int ans = 0;
        array<int, 8> cnt_1 = {0},
                      cnt_2 = {0};
        int n = nums.size();
        auto calc =
            [&](void) {
                int ans = 0;
                for (int i = 0; i < 8; i++)
                    ans |= ((cnt_1[i] or cnt_2[i]) and
                            !(cnt_1[i] and cnt_2[i]))
                           << i;
                return ans;
            };
        auto update_val =
            [](array<int, 8> &cnt, int val, bool isAdd) {
                if (isAdd)
                    for (int i = 0; val; i++, val >>= 1)
                        cnt[i] += val & 1;
                else
                    for (int i = 0; val; i++, val >>= 1)
                        cnt[i] -= val & 1;
            };
        for (int i = 0; i < k; i++)
            update_val(cnt_1, nums[i], true);
        for (int i = k; i < 2 * k; i++)
            update_val(cnt_2, nums[i], false);
        for (int i = 2 * k; true; i++) {
            ans = max(
                ans,
                calc());
            if (i == n)
                break;
            update_val(cnt_2, nums[i], true);
            update_val(cnt_2, nums[i - k], false);
            update_val(cnt_1, nums[i - k], true);
            update_val(cnt_1, nums[i - 2 * k], false);
        }
        return ans;

        // 我写完了才意识到原来序列不用是连续的，鉴定为子字符串写多了的后遗症；
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,6,7]\n1\n
// @lcpr case=end

// @lcpr case=start
// [4,2,5,6,7]\n2\n
// @lcpr case=end

 */
