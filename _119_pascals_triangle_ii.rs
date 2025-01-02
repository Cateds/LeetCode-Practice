/*
 * @lc app=leetcode.cn id=119 lang=rust
 * @lcpr version=30204
 *
 * [119] 杨辉三角 II
 *
 * https://leetcode.cn/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (69.22%)
 * Likes:    554
 * Dislikes: 0
 * Total Accepted:    324.1K
 * Total Submissions: 468.2K
 * Testcase Example:  '3'
 *
 * 给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。
 *
 * 在「杨辉三角」中，每个数是它左上方和右上方的数的和。
 *
 *
 *
 *
 *
 * 示例 1:
 *
 * 输入: rowIndex = 3
 * 输出: [1,3,3,1]
 *
 *
 * 示例 2:
 *
 * 输入: rowIndex = 0
 * 输出: [1]
 *
 *
 * 示例 3:
 *
 * 输入: rowIndex = 1
 * 输出: [1,1]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 0 <= rowIndex <= 33
 *
 *
 *
 *
 * 进阶：
 *
 * 你可以优化你的算法到 O(rowIndex) 空间复杂度吗？
 *
 */

// @lcpr-template-start
pub struct Solution;
// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn get_row(row_index: i32) -> Vec<i32> {
        let mut ans: Vec<i32> = Vec::new();
        ans.resize((row_index + 1) as usize, 0);
        ans[row_index as usize] = 1;
        ans[0] = 1;
        for idx in 1..=row_index / 2 {
            ans[idx as usize] =
                (ans[(idx - 1) as usize] as i64 * (row_index - idx + 1) as i64 / idx as i64) as i32;
            ans[(row_index - idx) as usize] = ans[idx as usize];
        }
        return ans;
    }
}
// @lc code=end

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 0\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
