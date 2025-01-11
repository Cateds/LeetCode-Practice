/*
 * @lc app=leetcode.cn id=52 lang=typescript
 * @lcpr version=30204
 *
 * [52] N 皇后 II
 *
 * https://leetcode.cn/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (82.48%)
 * Likes:    535
 * Dislikes: 0
 * Total Accepted:    166.5K
 * Total Submissions: 201.8K
 * Testcase Example:  '4'
 *
 * n 皇后问题 研究的是如何将 n 个皇后放置在 n × n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：n = 4
 * 输出：2
 * 解释：如上图所示，4 皇后问题存在两个不同的解法。
 * 
 * 
 * 示例 2：
 * 
 * 输入：n = 1
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 9
 * 
 * 
 * 
 * 
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
function totalNQueens(n: number): number {
    let ans = 0
    let table: number[] = new Array(n).fill(0);
    let func = (row: number): void => {
        if (row >= n) {
            ans++;
            return;
        }
        let inDanger = 0;
        for (let i = 0; i < row; i++)
            inDanger |= table[i] | table[i] << row - i | table[i] >> row - i;
        for (let col = 0; col < n; col++) {
            if (inDanger & 0b1 << col)
                continue;
            table[row] |= 0b1 << col;
            func(row + 1);
            table[row] &= ~(0b1 << col);
        }
    };
    func(0);
    return ans;
};
// @lc code=end



/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

