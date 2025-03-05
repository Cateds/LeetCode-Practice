/*
 * @lc app=leetcode.cn id=1287 lang=rust
 * @lcpr version=30204
 *
 * [1287] 有序数组中出现次数超过25%的元素
 *
 * https://leetcode.cn/problems/element-appearing-more-than-25-in-sorted-array/description/
 *
 * algorithms
 * Easy (58.25%)
 * Likes:    90
 * Dislikes: 0
 * Total Accepted:    31.3K
 * Total Submissions: 53.6K
 * Testcase Example:  '[1,2,2,6,6,6,6,7,10]'
 *
 * 给你一个非递减的 有序 整数数组，已知这个数组中恰好有一个整数，它的出现次数超过数组元素总数的 25%。
 *
 * 请你找到并返回这个整数
 *
 *
 *
 * 示例：
 *
 * 输入：arr = [1,2,2,6,6,6,6,7,10]
 * 输出：6
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= arr.length <= 10^4
 * 0 <= arr[i] <= 10^5
 *
 *
 */

// @lcpr-template-start
#[allow(dead_code)]
pub struct Solution;
#[allow(dead_code)]
// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn find_special_integer(arr: Vec<i32>) -> i32 {
        let n = arr.len();
        let mut cnt = 1;
        for i in 1..n {
            if arr[i] != arr[i - 1] {
                if cnt * 4 > n {
                    return arr[i - 1];
                } else {
                    cnt = 1;
                }
            } else {
                cnt += 1;
            }
        }
        return *arr.last().unwrap();
    }
}
// @lc code=end

/*
// @lcpr case=start
// [1,2,2,6,6,6,6,7,10]\n
// @lcpr case=end

 */
