/*
 * @lc app=leetcode.cn id=63 lang=cpp
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
#include <utility>
#include <vector>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        char rows = obstacleGrid.size();
        char cols = obstacleGrid.front().size();
        vector<int> prv, nxt(cols, 0);
        nxt.front() = 1;
        for (char row = 0; row < rows; row++) {
            prv = std::move(nxt);
            nxt.resize(cols, 0);
            nxt.front() = prv.front() and !obstacleGrid[row][0];
            for (char col = 1; col < cols; col++)
                if (!obstacleGrid[row][col])
                    nxt[col] = nxt[col - 1] + prv[col];
        }
        return nxt.back();
    }
};
// @lc code=end

/**
  @brief 
    本题使用动态规划求解路线数量。利用一维dp数组，使用滚动数组节省空间
    依次更新每一行的路径数：当前格子可以由左边和上方累加得到，
    如果当前位置存在障碍则路径数置为0，从而实现空间优化。
 */

/*
// @lcpr case=start
// [[0,0,0],[0,1,0],[0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[0,0]]\n
// @lcpr case=end

 */
