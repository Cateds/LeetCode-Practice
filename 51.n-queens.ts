/*
 * @lc app=leetcode.cn id=51 lang=typescript
 * @lcpr version=30204
 *
 * [51] N 皇后
 *
 * https://leetcode.cn/problems/n-queens/description/
 *
 * algorithms
 * Hard (74.51%)
 * Likes:    2173
 * Dislikes: 0
 * Total Accepted:    460.1K
 * Total Submissions: 617.2K
 * Testcase Example:  '4'
 *
 * 按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
 * 
 * n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
 * 
 * 
 * 
 * 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：n = 4
 * 输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * 解释：如上图所示，4 皇后问题存在两个不同的解法。
 * 
 * 
 * 示例 2：
 * 
 * 输入：n = 1
 * 输出：[["Q"]]
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
function solveNQueens(n: number): string[][] {
    let ans: string[][] = [];
    let tableStr: string[] =
        new Array(n).fill(
            '.'.repeat(n));
    let table: number[] = new Array(n).fill(0);
    let func = (row: number): void => {
        if (row >= n) {
            // TMD这个垃圾语言只能用.slice()来创建拷贝，默认是引用
            // 真是跟Python学的，难绷完了
            // 跟弱智Javascript爆了
            ans.push(tableStr.slice());
            return;
        }
        let inDanger = 0;
        for (let i = 0; i < row; i++)
            inDanger |= table[i] | table[i] << row - i | table[i] >> row - i;
        for (let col = 0; col < n; col++) {
            if (inDanger & 0b1 << col)
                continue;
            table[row] |= 0b1 << col;
            // 谁家正经语言字符串不能直接改啊？？？？？
            tableStr[row] =
                tableStr[row].substring(0, col) + 'Q' +
                tableStr[row].substring(col + 1);
            func(row+1);
            table[row] &= ~(0b1 << col);
            tableStr[row] =
                tableStr[row].substring(0, col) + '.' +
                tableStr[row].substring(col + 1);
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

