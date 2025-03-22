/*
 * @lc app=leetcode.cn id=2643 lang=rust
 * @lcpr version=30204
 *
 * [2643] 一最多的行
 *
 * https://leetcode.cn/problems/row-with-maximum-ones/description/
 *
 * algorithms
 * Easy (79.75%)
 * Likes:    19
 * Dislikes: 0
 * Total Accepted:    23.7K
 * Total Submissions: 28.6K
 * Testcase Example:  '[[0,1],[1,0]]'
 *
 * 给你一个大小为 m x n 的二进制矩阵 mat ，请你找出包含最多 1 的行的下标（从 0 开始）以及这一行中 1 的数目。
 *
 * 如果有多行包含最多的 1 ，只需要选择 行下标最小 的那一行。
 *
 * 返回一个由行下标和该行中 1 的数量组成的数组。
 *
 *
 *
 * 示例 1：
 *
 * 输入：mat = [[0,1],[1,0]]
 * 输出：[0,1]
 * 解释：两行中 1 的数量相同。所以返回下标最小的行，下标为 0 。该行 1 的数量为 1 。所以，答案为 [0,1] 。
 *
 *
 * 示例 2：
 *
 * 输入：mat = [[0,0,0],[0,1,1]]
 * 输出：[1,2]
 * 解释：下标为 1 的行中 1 的数量最多。该行 1 的数量为 2 。所以，答案为 [1,2] 。
 *
 *
 * 示例 3：
 *
 * 输入：mat = [[0,0],[1,1],[0,0]]
 * 输出：[1,2]
 * 解释：下标为 1 的行中 1 的数量最多。该行 1 的数量为 2 。所以，答案为 [1,2] 。
 *
 *
 *
 * 提示：
 *
 *
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 100
 * mat[i][j] 为 0 或 1
 *
 *
 */

// @lcpr-template-start
#[allow(dead_code)]
pub struct Solution;
// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn row_and_maximum_ones(mat: Vec<Vec<i32>>) -> Vec<i32> {
        let mut ans: Vec<i32> = vec![-1; 2];
        for i in 0..mat.len() {
            let cnt = mat[i].iter().filter(|x| **x == 1).count();
            if cnt as i32 > *ans.last().unwrap() {
                ans[0] = i as i32;
                ans[1] = cnt as i32;
            }
        }
        return ans;
    }
}
// @lc code=end

/*
// @lcpr case=start
// [[0,1],[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,0],[0,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0],[1,1],[0,0]]\n
// @lcpr case=end

 */
