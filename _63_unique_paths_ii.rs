/*
 * @lc app=leetcode.cn id=63 lang=rust
 * @lcpr version=30204
 *
 * [63] 不同路径 II
 *
 * https://leetcode.cn/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (41.79%)
 * Likes:    1346
 * Dislikes: 0
 * Total Accepted:    572.5K
 * Total Submissions: 1.4M
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * 给定一个 m x n 的整数数组 grid。一个机器人初始位于 左上角（即 grid[0][0]）。机器人尝试移动到 右下角（即 grid[m -
 * 1][n - 1]）。机器人每次只能向下或者向右移动一步。
 *
 * 网格中的障碍物和空位置分别用 1 和 0 来表示。机器人的移动路径中不能包含 任何 有障碍物的方格。
 *
 * 返回机器人能够到达右下角的不同路径数量。
 *
 * 测试用例保证答案小于等于 2 * 10^9。
 *
 *
 *
 * 示例 1：
 *
 * 输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
 * 输出：2
 * 解释：3x3 网格的正中间有一个障碍物。
 * 从左上角到右下角一共有 2 条不同的路径：
 * 1. 向右 -> 向右 -> 向下 -> 向下
 * 2. 向下 -> 向下 -> 向右 -> 向右
 *
 *
 * 示例 2：
 *
 * 输入：obstacleGrid = [[0,1],[0,0]]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == obstacleGrid.length
 * n == obstacleGrid[i].length
 * 1 <= m, n <= 100
 * obstacleGrid[i][j] 为 0 或 1
 *
 *
 */



// @lcpr-template-start
# [allow(dead_code)]
pub struct Solution;
# [allow(dead_code)]
// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn unique_paths_with_obstacles(obstacle_grid: Vec<Vec<i32>>) -> i32 {
        let rows = obstacle_grid.len();
        let cols = obstacle_grid.first().unwrap().len();
        let mut prv;
        let mut nxt = vec![0; cols];
        *nxt.first_mut().unwrap() = 1;
        for row in 0..rows {
            prv = nxt;
            nxt = vec![0; cols];
            *nxt.first_mut().unwrap() =
                if obstacle_grid[row][0] == 0 && *prv.first().unwrap() == 1 {
                    1
                } else {
                    0
                };
            for col in 1..cols {
                if obstacle_grid[row][col] == 0 {
                    nxt[col] = nxt[col - 1] + prv[col];
                }
            }
        }
        return *nxt.last().unwrap();
    }
}
// @lc code=end

/*
// @lcpr case=start
// [[0,0,0],[0,1,0],[0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[0,0]]\n
// @lcpr case=end

 */
