/*
 * @lc app=leetcode.cn id=59 lang=rust
 * @lcpr version=30204
 *
 * [59] 螺旋矩阵 II
 *
 * https://leetcode.cn/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (70.59%)
 * Likes:    1375
 * Dislikes: 0
 * Total Accepted:    497.9K
 * Total Submissions: 705.5K
 * Testcase Example:  '3'
 *
 * 给你一个正整数 n ，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 3
 * 输出：[[1,2,3],[8,9,4],[7,6,5]]
 *
 *
 * 示例 2：
 *
 * 输入：n = 1
 * 输出：[[1]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 20
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
    pub fn generate_matrix(n: i32) -> Vec<Vec<i32>> {
        let mut ans = vec![vec![0; n as usize]; n as usize];
        let mut cnt = 1;
        for i in 0..(n / 2) {
            let mut row = i;
            let mut col = i;
            let end = n - i - 1;
            while col < end {
                ans[row as usize][col as usize] = cnt;
                cnt += 1;
                col += 1;
            }
            while row < end {
                ans[row as usize][col as usize] = cnt;
                cnt += 1;
                row += 1;
            }
            while col > i {
                ans[row as usize][col as usize] = cnt;
                cnt += 1;
                col -= 1;
            }
            while row > i {
                ans[row as usize][col as usize] = cnt;
                cnt += 1;
                row -= 1;
            }
        }
        if n % 2 == 1 {
            ans[(n / 2) as usize][(n / 2) as usize] = cnt;
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
// 1\n
// @lcpr case=end

 */
