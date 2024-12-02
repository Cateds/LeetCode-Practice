/*
 * @lc app=leetcode.cn id=52 lang=cpp
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
    int totalNQueens(int &n) {
        uint16_t ans = 0;
        vector<uint16_t> table(n, 0);
        auto func =
            [&](auto &func, int &&row) -> void {
            if (row >= n) {
                ans++;
                return;
            }
            uint16_t inDanger = 0;
            for (uint8_t i = 0; i < row; i++)
                inDanger |= table[i] | table[i] << row - i | table[i] >> row - i;
            for (uint8_t col = 0; col < n; col++) {
                if (inDanger & 0b1 << col)
                    continue;
                table[row] |= 0b1 << col;
                func(func, row + 1);
                table[row] &= ~(0b1 << col);
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
