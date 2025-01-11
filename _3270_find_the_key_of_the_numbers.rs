/*
 * @lc app=leetcode.cn id=3270 lang=rust
 * @lcpr version=30204
 *
 * [3270] 求出数字答案
 *
 * https://leetcode.cn/problems/find-the-key-of-the-numbers/description/
 *
 * algorithms
 * Easy (84.88%)
 * Likes:    14
 * Dislikes: 0
 * Total Accepted:    13.3K
 * Total Submissions: 15.7K
 * Testcase Example:  '1\n10\n1000'
 *
 * 给你三个 正 整数 num1 ，num2 和 num3 。
 *
 * 数字 num1 ，num2 和 num3 的数字答案 key 是一个四位数，定义如下：
 *
 *
 * 一开始，如果有数字 少于 四位数，给它补 前导 0 。
 * 答案 key 的第 i 个数位（1 <= i <= 4）为 num1 ，num2 和 num3 第 i 个数位中的 最小 值。
 *
 *
 * 请你返回三个数字 没有 前导 0 的数字答案。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：num1 = 1, num2 = 10, num3 = 1000
 *
 * 输出：0
 *
 * 解释：
 *
 * 补前导 0 后，num1 变为 "0001" ，num2 变为 "0010" ，num3 保持不变，为 "1000" 。
 *
 *
 * 数字答案 key 的第 1 个数位为 min(0, 0, 1) 。
 * 数字答案 key 的第 2 个数位为 min(0, 0, 0) 。
 * 数字答案 key 的第 3 个数位为 min(0, 1, 0) 。
 * 数字答案 key 的第 4 个数位为 min(1, 0, 0) 。
 *
 *
 * 所以数字答案为 "0000" ，也就是 0 。
 *
 *
 * 示例 2：
 *
 *
 * 输入： num1 = 987, num2 = 879, num3 = 798
 *
 * 输出：777
 *
 *
 * 示例 3：
 *
 *
 * 输入：num1 = 1, num2 = 2, num3 = 3
 *
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= num1, num2, num3 <= 9999
 *
 *
 */

// @lcpr-template-start
pub struct Solution;
// @lcpr-template-end
// @lc code=start
use std::cmp::min;
impl Solution {
    pub fn generate_key(mut num1: i32, mut num2: i32, mut num3: i32) -> i32 {
        let mut ans = 0;
        let mut i = 1000;
        while i != 0 {
            ans += min(min(num1 / i, num2 / i), num3 / i) * i;
            num1 %= i;
            num2 %= i;
            num3 %= i;
            i /= 10;
        }
        return ans;
    }
}
// @lc code=end

/*
// @lcpr case=start
// 1\n10\n1000\n
// @lcpr case=end

// @lcpr case=start
// 987\n879\n798\n
// @lcpr case=end

// @lcpr case=start
// 1\n2\n3\n
// @lcpr case=end

 */
