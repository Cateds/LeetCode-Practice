/*
 * @lc app=leetcode.cn id=59 lang=typescript
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

// @lcpr-template-end
// @lc code=start
function generateMatrix(n: number): number[][] {
    let ans: number[][] = Array.from(
        { length: n },
        function () {
            return new Array(n).fill(0)
        }
    );  // Typescript定义一个二维数组整这个烂活多少有点抽象了吧
    let cnt = 1;
    let times = Math.floor(n / 2);
    for (let i = 0; i < times; i++) {
        let row = i, col = i;
        let end = n - i - 1;
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
};
// @lc code=end

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

