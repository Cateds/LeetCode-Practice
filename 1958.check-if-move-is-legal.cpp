/*
 * @lc app=leetcode.cn id=1958 lang=cpp
 * @lcpr version=30204
 *
 * [1958] 检查操作是否合法
 *
 * https://leetcode.cn/problems/check-if-move-is-legal/description/
 *
 * algorithms
 * Medium (45.97%)
 * Likes:    30
 * Dislikes: 0
 * Total Accepted:    10.9K
 * Total Submissions: 19.6K
 * Testcase Example:  '[[".",".",".","B",".",".",".","."],[".",".",".","W",".",".",".","."],[".",".",".","W",".",".",".","."],[".",".",".","W",".",".",".","."],["W","B","B",".","W","W","W","B"],[".",".",".","B",".",".",".","."],[".",".",".","B",".",".",".","."],[".",".",".","W",".",".",".","."]]\n' +
  '4\n' +
  '3\n' +
  '"B"'
 *
 * 给你一个下标从 0 开始的 8 x 8 网格 board ，其中 board[r][c] 表示游戏棋盘上的格子 (r, c) 。棋盘上空格用 '.'
 * 表示，白色格子用 'W' 表示，黑色格子用 'B' 表示。
 * 
 * 游戏中每次操作步骤为：选择一个空格子，将它变成你正在执行的颜色（要么白色，要么黑色）。但是，合法 操作必须满足：涂色后这个格子是 好线段的一个端点
 * （好线段可以是水平的，竖直的或者是对角线）。
 * 
 * 好线段 指的是一个包含 三个或者更多格子（包含端点格子）的线段，线段两个端点格子为 同一种颜色 ，且中间剩余格子的颜色都为 另一种颜色
 * （线段上不能有任何空格子）。你可以在下图找到好线段的例子：
 * 
 * 给你两个整数 rMove 和 cMove 以及一个字符 color ，表示你正在执行操作的颜色（白或者黑），如果将格子 (rMove, cMove)
 * 变成颜色 color 后，是一个 合法 操作，那么返回 true ，如果不是合法操作返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：board =
 * [[".",".",".","B",".",".",".","."],[".",".",".","W",".",".",".","."],[".",".",".","W",".",".",".","."],[".",".",".","W",".",".",".","."],["W","B","B",".","W","W","W","B"],[".",".",".","B",".",".",".","."],[".",".",".","B",".",".",".","."],[".",".",".","W",".",".",".","."]],
 * rMove = 4, cMove = 3, color = "B"
 * 输出：true
 * 解释：'.'，'W' 和 'B' 分别用颜色蓝色，白色和黑色表示。格子 (rMove, cMove) 用 'X' 标记。
 * 以选中格子为端点的两个好线段在上图中用红色矩形标注出来了。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：board =
 * [[".",".",".",".",".",".",".","."],[".","B",".",".","W",".",".","."],[".",".","W",".",".",".",".","."],[".",".",".","W","B",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".","B","W",".","."],[".",".",".",".",".",".","W","."],[".",".",".",".",".",".",".","B"]],
 * rMove = 4, cMove = 4, color = "W"
 * 输出：false
 * 解释：虽然选中格子涂色后，棋盘上产生了好线段，但选中格子是作为中间格子，没有产生以选中格子为端点的好线段。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * board.length == board[r].length == 8
 * 0 <= rMove, cMove < 8
 * board[rMove][cMove] == '.'
 * color 要么是 'B' 要么是 'W' 。
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
#include <format>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    bool checkMove(vector<vector<char>>& board, 
                   int rMove, int cMove, char color) {
        pair size = {board.size(),board[0].size()};
        bool RetVal = false;
        for (int r=-1, R=rMove+r; r<=1; r++,R=rMove+r) {
            if (R<0 or R>=size.first) continue;
            for (int c=-1,C=cMove+c; c<=1; c++,C=cMove+c) {
                if (C<0 or C>=size.second or
                    !(r or c))
                        continue;
                if (board[R][C]==color or board[R][C]=='.') {
                    continue;
                } else {
                    // printf("(%d,%d) try\n",R,C);
                    for (int R_=R+r,C_=C+c;
                         R_>=0 and R_<size.first and
                         C_>=0 and C_<size.second and
                         board[R_][C_]!='.';
                         R_+=r, C_+=c
                    ) {
                        // printf("(%d,%d)\n",R_,C_);
                        if (board[R_][C_]==color) {
                            RetVal = true;
                            goto LoopEd;
                        }
                    }
                }
            }
        }
        LoopEd:
        return RetVal;
    }
};
// @lc code=end

/*
["B","W",".","B","W","W","B","."],
["B",".",".","B","W","W",".","."],
["W","W",".","B","B","X","B","W"],
["B","W","B",".","B",".","B","B"],
["B","W","W","B",".","W","B","B"],
["W","W",".","B","W","B",".","."],
["W",".","B","W","W","B",".","B"],
["W",".","B","B",".","B",".","."]]
' +
  '2
' +
  '5
' +
  '"B"

["W",".","W","W","B","W","B","."]
["W","?",".","W","B","B",".","B"]
["B","B","B","W","B",".","W","B"]
[".","W",".",".","B","B",".","W"]
["W",".","B","W","B","W",".","W"]
[".","B","B","B",".","B","W","W"]
[".","B","W","B","W","B",".","W"]
[".",".","B","W","W",".","W","."]
' +
  '1
' +
  '1
' +
  '"W"
*/


/*
// @lcpr case=start
// [[".",".",".","B",".",".",".","."],[".",".",".","W",".",".",".","."],[".",".",".","W",".",".",".","."],[".",".",".","W",".",".",".","."],["W","B","B",".","W","W","W","B"],[".",".",".","B",".",".",".","."],[".",".",".","B",".",".",".","."],[".",".",".","W",".",".",".","."]]\n4\n3\n"B"\n
// @lcpr case=end

// @lcpr case=start
// [[".",".",".",".",".",".",".","."],[".","B",".",".","W",".",".","."],[".",".","W",".",".",".",".","."],[".",".",".","W","B",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".","B","W",".","."],[".",".",".",".",".",".","W","."],[".",".",".",".",".",".",".","B"]]\n4\n4\n"W"\n
// @lcpr case=end

 */

