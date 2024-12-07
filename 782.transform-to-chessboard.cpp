/*
 * @lc app=leetcode.cn id=782 lang=cpp
 * @lcpr version=30204
 *
 * [782] 变为棋盘
 *
 * https://leetcode.cn/problems/transform-to-chessboard/description/
 *
 * algorithms
 * Hard (59.18%)
 * Likes:    185
 * Dislikes: 0
 * Total Accepted:    14.8K
 * Total Submissions: 24.9K
 * Testcase Example:  '[[0,1,1,0],[0,1,1,0],[1,0,0,1],[1,0,0,1]]'
 *
 * 一个 n x n 的二维网络 board 仅由 0 和 1 组成 。每次移动，你能交换任意两列或是两行的位置。
 *
 * 返回 将这个矩阵变为  “棋盘”  所需的最小移动次数 。如果不存在可行的变换，输出 -1。
 *
 * “棋盘” 是指任意一格的上下左右四个方向的值均与本身不同的矩阵。
 *
 *
 *
 * 示例 1:
 *
 *
 *
 * 输入: board = [[0,1,1,0],[0,1,1,0],[1,0,0,1],[1,0,0,1]]
 * 输出: 2
 * 解释:一种可行的变换方式如下，从左到右：
 * 第一次移动交换了第一列和第二列。
 * 第二次移动交换了第二行和第三行。
 *
 *
 * 示例 2:
 *
 *
 *
 * 输入: board = [[0, 1], [1, 0]]
 * 输出: 0
 * 解释: 注意左上角的格值为0时也是合法的棋盘，也是合法的棋盘.
 *
 *
 * 示例 3:
 *
 *
 *
 * 输入: board = [[1, 0], [1, 0]]
 * 输出: -1
 * 解释: 任意的变换都不能使这个输入变为合法的棋盘。
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == board.length
 * n == board[i].length
 * 2 <= n <= 30
 * board[i][j] 将只包含 0或 1
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
#include <valarray>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    // int movesToChessboard(vector<vector<int>> &board) {
    //     uint8_t n = board.size();
    //     vector<pair<uint32_t, uint8_t>> board_n(n, {0, 0});
    //     for (uint8_t r = 0; r < n; r++) {
    //         auto &[br, cnt] = board_n[r];
    //         for (uint8_t c = 0; c < n; c++) {
    //             if (!board[r][c])
    //                 continue;
    //             br |= 0b1 << c;
    //             cnt++;
    //         }
    //         if (cnt != n / 2 and cnt != (n + 1) / 2)
    //             return -1;
    //     }
    //     // for (auto &[br, cnt] : board_n) {
    //     //     cout << format("{:0{}b} {}\n", br, n, cnt);
    //     // }
    //     uint32_t row[2] = {0};
    //     uint8_t num[2] = {0};
    //     uint32_t col = {0};
    //     row[0] = board_n.front().first;
    //     row[1] = ~row[0] & ((0b1 << n) - 1);
    //     // for (auto &r : row) {
    //     //     cout << format("row: {:0{}b}\n", r, n);
    //     // }
    //     for (uint8_t i = 0; i < n; i++) {
    //         auto &[br, cnt] = board_n[i];
    //         if (br == row[0]) {
    //             num[0] += 1;
    //         } else if (br == row[1]) {
    //             num[1] += 1;
    //             col |= 0b1 << i;
    //         } else
    //             return -1;
    //     }
    //     // cout << format("col: {:0{}b}\n",col,n);
    //     if (abs(num[0] - num[1]) > 1)
    //         return -1;
    //     uint32_t mask = 0xAAAAAAAA & ((0b1 << n) - 1);
    //     uint8_t n1 = popcount(col ^ mask), n2 = popcount(row[0] ^ mask);
    //     // cout << format("n12: {} {}\n",n1,n2);
    //     if (n & 0b1) { // 奇数
    //         return ((n1 & 0b1) ? (n - n1) : n1) / 2 + ((n2 & 0b1) ? (n - n2) : n2) / 2;
    //     } else { // 偶数
    //         return min(n1, uint8_t(n - n1)) / 2 + min(n2, uint8_t(n - n2)) / 2;
    //     }
    // }

    // 优化了内存占用
    int movesToChessboard(vector<vector<int>> &board) {
        uint8_t n = board.size();
        uint32_t tmp_row = 0;   uint8_t tmp_cnt = 0;
        uint32_t row[2];        uint8_t num[2] = {1,0};
        uint32_t col = {0};
        for (uint8_t c = 0; c<n; c++) {
            if (!board[0][c]) continue;
            tmp_row |= 0b1 << c;
            tmp_cnt += 1;
        }
        if (tmp_cnt != n/2 and tmp_cnt!=(n+1)/2)
            return -1;
        row[0] = tmp_row;
        row[1] = ~row[0] & ((0b1 << n) - 1);
        for (uint8_t r = 1; r < n; r++) {
            tmp_row = tmp_cnt = 0;
            for (uint8_t c = 0; c < n; c++) {
                if (!board[r][c])
                    continue;
                tmp_row |= 0b1 << c;
                tmp_cnt++;
            }
            if (tmp_cnt != n / 2 and tmp_cnt != (n + 1) / 2)
                return -1;
            if (tmp_row == row[0]) 
                num[0] += 1;
            else if (tmp_row == row[1]) {
                num[1] += 1;
                col |= 0b1 << r;
            } else return -1;
        }
        if (abs(num[0] - num[1]) > 1)
            return -1;
        uint32_t mask = 0xAAAAAAAA & ((0b1 << n) - 1);
        auto &[n1,n2] = num;
        n1 = popcount(col ^ mask), n2 = popcount(row[0] ^ mask);
        if (n & 0b1)  // odd number
            return ((n1 & 0b1) ? (n - n1) : n1) / 2 + ((n2 & 0b1) ? (n - n2) : n2) / 2;
        else  // even number
            return min(n1, uint8_t(n - n1)) / 2 + min(n2, uint8_t(n - n2)) / 2;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[0,1,1,0],[0,1,1,0],[1,0,0,1],[1,0,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0, 1], [1, 0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1, 0], [1, 0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,0],[0,0,1],[0,0,1]]\n
// @lcpr case=end
 */
