/*
 * @lc app=leetcode.cn id=118 lang=rust
 * @lcpr version=30204
 *
 * [118] 杨辉三角
 *
 * https://leetcode.cn/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (76.65%)
 * Likes:    1196
 * Dislikes: 0
 * Total Accepted:    581.2K
 * Total Submissions: 757.6K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
 *
 * 在「杨辉三角」中，每个数是它左上方和右上方的数的和。
 *
 *
 *
 *
 *
 * 示例 1:
 *
 * 输入: numRows = 5
 * 输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 *
 *
 * 示例 2:
 *
 * 输入: numRows = 1
 * 输出: [[1]]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= numRows <= 30
 *
 *
 */

use std::vec;

// @lcpr-template-start
#[allow(dead_code)]
pub struct Solution;
// @lcpr-template-end
// @lc code=start
impl Solution {
    #[allow(dead_code)]
pub fn generate(num_rows: i32) -> Vec<Vec<i32>> {
        let mut ans: Vec<Vec<i32>> = Vec::new();
        ans.push(Vec::from([1]));
        for i in 1..num_rows {
            let i = i as usize;
            ans.push(vec![1; i+1]);
            for j in 1..=i/2 {
                let j = j as usize;
                ans[i][j] = ans[i-1][j] + ans[i-1][j-1];
                ans[i][i-j] = ans[i][j];
            }
        }
        return ans;
    }
}
// @lc code=end

/*
// @lcpr case=start
// 5\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
