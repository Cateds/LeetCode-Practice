/*
 * @lc app=leetcode.cn id=59 lang=cpp
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
#include <vector>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        char times = n / 2;
        int cnt = 1;
        for (char i = 0; i < times; i++) {
            char row = i, col = i;
            char end = n - i - 1;
            while (col < end)
                ans[row][col++] = cnt++;
            while (row < end)
                ans[row++][col] = cnt++;
            while (col > i)
                ans[row][col--] = cnt++;
            while (row > i)
                ans[row--][col] = cnt++;
        }
        if (n % 2)
            ans[times][times] = cnt;
        return ans;
    }
};
// @lc code=end

/**
  @brief
    螺旋矩阵生成的思路解析：
    1. 分层处理：将矩阵看作由若干个同心正方形组成，从最外层向内层依次填充。
    2. 每一层按照顺时针顺序填充，具体分为四个步骤：
       - 从左到右填充上边界（不含右边界的最后一个元素）
       - 从上到下填充右边界（不含下边界的最后一个元素）
       - 从右到左填充下边界（不含左边界的第一个元素）
       - 从下到上填充左边界（不含上边界的第一个元素）
    3. 边界定义：
       - 当前层左上角坐标为 (i, i)，右下角坐标为 (n-i-1, n-i-1)
    4. 特殊情况：
       - 当矩阵尺寸 n 为奇数时，最后中间的单个元素需要单独赋值。
    5. 算法及复杂度：
       - 使用一个计数器 cnt 从1开始依次填入，每个位置正好访问一次，因此时间复杂度为 O(n^2)。
       - 算法只使用常数级别的辅助变量，空间复杂度为 O(1)（不计算返回矩阵的空间）。
    6. 注意事项：
       - 每次填充时应严格保证边界条件，避免重复覆盖或遗漏填充。
       - 循环过程中需精确更新行列索引，确保顺序正确。
 */

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
