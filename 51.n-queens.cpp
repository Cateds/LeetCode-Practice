/*
 * @lc app=leetcode.cn id=51 lang=cpp
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
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    // // 最开始用的直接回溯法
    // // 现在看来都用vector<bool>还不考虑状态压缩和位运算多少沾点
    // vector<vector<string>> solveNQueens(int &n) {
    //     vector<vector<string>> ans;
    //     vector<string> table(n, string(n, '.'));
    //     uint8_t remain = n;
    //     vector<uint8_t>
    //         Cols(n, 0), Diag(2 * n - 1, 0),
    //         Antid(2 * n - 1, 0);
    //     auto func =
    //         [&](auto &func, int &&curPosi) -> void {
    //         if (!remain) {
    //             ans.push_back(table);
    //             return;
    //         }
    //         for (uint8_t cur = curPosi; cur < n * n; cur++) {
    //             if (Cols[cur % n] or
    //                 Antid[cur / n + cur % n] or
    //                 Diag[n - 1 + cur / n - cur % n])
    //                 continue;
    //             table[cur / n][cur % n] = 'Q';
    //             Cols[cur % n] = 1;
    //             Antid[cur / n + cur % n] = 1;
    //             Diag[n - 1 + cur / n - cur % n] = 1;
    //             remain--;
    //             func(func, (cur / n + 1) * n);
    //             table[cur / n][cur % n] = '.';
    //             Cols[cur % n] = 0;
    //             Antid[cur / n + cur % n] = 0;
    //             Diag[n - 1 + cur / n - cur % n] = 0;
    //             remain++;
    //         }
    //     };
    //     func(func, 0);
    //     return ans;
    // }

    // 位运算
    vector<vector<string>> solveNQueens(int &n) {
        vector<vector<string>> ans;
        vector<string> tableStr(n, string(n, '.'));
        vector<uint16_t> table(n,0);
        auto func =
            [&](auto &func, int &&row) -> void {
            if (row >= n) {
                ans.push_back(tableStr);
                return;
            }
            uint16_t inDanger = 0;
            for (uint8_t i=0; i<row; i++) 
                inDanger |= table[i] | table[i]<<row-i | table[i]>>row-i;
            for (uint8_t col=0; col<n; col++) {
                if (inDanger & 0b1<<col)
                    continue;
                table[row] |= 0b1<<col;
                tableStr[row][col] = 'Q';
                func(func,row+1);
                tableStr[row][col] = '.';
                table[row] &= ~(0b1<<col);
            }
        };
        func(func, 0);
        return ans;
    }
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
