/*
 * @lc app=leetcode.cn id=688 lang=cpp
 * @lcpr version=30204
 *
 * [688] 骑士在棋盘上的概率
 *
 * https://leetcode.cn/problems/knight-probability-in-chessboard/description/
 *
 * algorithms
 * Medium (57.99%)
 * Likes:    355
 * Dislikes: 0
 * Total Accepted:    39.9K
 * Total Submissions: 68.7K
 * Testcase Example:  '3\n2\n0\n0'
 *
 * 在一个 n x n 的国际象棋棋盘上，一个骑士从单元格 (row, column) 开始，并尝试进行 k 次移动。行和列是 从 0 开始
 * 的，所以左上单元格是 (0,0) ，右下单元格是 (n - 1, n - 1) 。
 *
 * 象棋骑士有8种可能的走法，如下图所示。每次移动在基本方向上是两个单元格，然后在正交方向上是一个单元格。
 *
 *
 *
 * 每次骑士要移动时，它都会随机从8种可能的移动中选择一种(即使棋子会离开棋盘)，然后移动到那里。
 *
 * 骑士继续移动，直到它走了 k 步或离开了棋盘。
 *
 * 返回 骑士在棋盘停止移动后仍留在棋盘上的概率 。
 *
 *
 *
 * 示例 1：
 *
 * 输入: n = 3, k = 2, row = 0, column = 0
 * 输出: 0.0625
 * 解释: 有两步(到(1,2)，(2,1))可以让骑士留在棋盘上。
 * 在每一个位置上，也有两种移动可以让骑士留在棋盘上。
 * 骑士留在棋盘上的总概率是0.0625。
 *
 *
 * 示例 2：
 *
 * 输入: n = 1, k = 0, row = 0, column = 0
 * 输出: 1.00000
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= n <= 25
 * 0 <= k <= 100
 * 0 <= row, column <= n - 1
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
#include <cmath>
#include <valarray>
#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    double knightProbability(int &n, int &k, int &row, int &column) {
        using value_t = double;
        vector<valarray<value_t>> board(n, valarray<value_t>(n));
        decltype(board) temp;
        vector<pair<int8_t, int8_t>> step = {
            {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}};
        board[row][column] = 1;
        for (uint8_t i = 0; i < k; i++) {
            temp.resize(n, valarray<value_t>(n));
            for (uint8_t r = 0; r < n; r++) {
                for (uint8_t c = 0; c < n; c++) {
                    if (board[r][c])
                    for (auto &[dx, dy] : step) {
                        if (r + dy < 0 or r + dy >= n or c + dx < 0 or c + dx >= n)
                            continue;
                        temp[r + dy][c + dx] += board[r][c];
                    }
                }
            }
            board = move(temp);
        }
        value_t ans = 0;
        for (auto &row: board)
            // ans += accumulate(row.begin(),row.end(),0.);
            ans += row.sum();
        return ans / pow(8,k);
    }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n2\n0\n0\n
// @lcpr case=end

// @lcpr case=start
// 1\n0\n0\n0\n
// @lcpr case=end

 */
