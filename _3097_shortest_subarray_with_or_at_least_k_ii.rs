/*
 * @lc app=leetcode.cn id=3097 lang=rust
 * @lcpr version=30204
 *
 * [3097] 或值至少为 K 的最短子数组 II
 *
 * https://leetcode.cn/problems/shortest-subarray-with-or-at-least-k-ii/description/
 *
 * algorithms
 * Medium (38.07%)
 * Likes:    25
 * Dislikes: 0
 * Total Accepted:    7.2K
 * Total Submissions: 15.9K
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
 * 1 <= nums.length <= 2 * 10^5
 * 0 <= nums[i] <= 10^9
 * 0 <= k <= 10^9
 * 
 * 
 */


// @lcpr-template-start
#[allow(dead_code)]
pub struct Solution;
// @lcpr-template-end
// @lc code=start
#[allow(dead_code)]
impl Solution {
    pub fn minimum_subarray_length(nums: Vec<i32>, k: i32) -> i32 {
        let mut bits = vec![0; 30];
        let calc = |bits: &mut Vec<i32>| -> i32 {
            let mut ans = 0;
            for i in 0..bits.len() {
                if bits[i] > 0 {
                    ans |= 1 << i;
                }
            }
            return ans;
        };
        let mut ans = std::i32::MAX;
        let mut left = 0;
        for right in 0..nums.len() {
            for i in 0..30 {
                bits[i] += (nums[right] >> i) & 1;
            }
            while left <= right && calc(&mut bits) >= k {
                ans = std::cmp::min(ans as usize, right - left + 1) as i32;
                for i in 0..30 {
                    bits[i] -= (nums[left] >> i) & 1;
                }
                left += 1;
            }
        }
        return if ans == std::i32::MAX { -1 } else { ans };
    }
}
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

