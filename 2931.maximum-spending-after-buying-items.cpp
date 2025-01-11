// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2931 lang=cpp
 * @lcpr version=30204
 *
 * [2931] 购买物品的最大开销
 *
 * https://leetcode.cn/problems/maximum-spending-after-buying-items/description/
 *
 * algorithms
 * Hard (67.33%)
 * Likes:    8
 * Dislikes: 0
 * Total Accepted:    3.5K
 * Total Submissions: 5K
 * Testcase Example:  '[[8,5,2],[6,4,1],[9,7,3]]'
 *
 * 给你一个下标从 0 开始大小为 m * n 的整数矩阵 values ，表示 m 个不同商店里 m * n 件不同的物品。每个商店有 n 件物品，第 i
 * 个商店的第 j 件物品的价值为 values[i][j] 。除此以外，第 i 个商店的物品已经按照价值非递增排好序了，也就是说对于所有 0 <= j <
 * n - 1 都有 values[i][j] >= values[i][j + 1] 。
 *
 * 每一天，你可以在一个商店里购买一件物品。具体来说，在第 d 天，你可以：
 *
 *
 * 选择商店 i 。
 * 购买数组中最右边的物品 j ，开销为 values[i][j] * d 。换句话说，选择该商店中还没购买过的物品中最大的下标 j ，并且花费
 * values[i][j] * d 去购买。
 *
 *
 * 注意，所有物品都视为不同的物品。比方说如果你已经从商店 1 购买了物品 0 ，你还可以在别的商店里购买其他商店的物品 0 。
 *
 * 请你返回购买所有 m * n 件物品需要的 最大开销 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：values = [[8,5,2],[6,4,1],[9,7,3]]
 * 输出：285
 * 解释：第一天，从商店 1 购买物品 2 ，开销为 values[1][2] * 1 = 1 。
 * 第二天，从商店 0 购买物品 2 ，开销为 values[0][2] * 2 = 4 。
 * 第三天，从商店 2 购买物品 2 ，开销为 values[2][2] * 3 = 9 。
 * 第四天，从商店 1 购买物品 1 ，开销为 values[1][1] * 4 = 16 。
 * 第五天，从商店 0 购买物品 1 ，开销为 values[0][1] * 5 = 25 。
 * 第六天，从商店 1 购买物品 0 ，开销为 values[1][0] * 6 = 36 。
 * 第七天，从商店 2 购买物品 1 ，开销为 values[2][1] * 7 = 49 。
 * 第八天，从商店 0 购买物品 0 ，开销为 values[0][0] * 8 = 64 。
 * 第九天，从商店 2 购买物品 0 ，开销为 values[2][0] * 9 = 81 。
 * 所以总开销为 285 。
 * 285 是购买所有 m * n 件物品的最大总开销。
 *
 *
 * 示例 2：
 *
 * 输入：values = [[10,8,6,4,2],[9,7,5,3,2]]
 * 输出：386
 * 解释：第一天，从商店 0 购买物品 4 ，开销为 values[0][4] * 1 = 2 。
 * 第二天，从商店 1 购买物品 4 ，开销为 values[1][4] * 2 = 4 。
 * 第三天，从商店 1 购买物品 3 ，开销为 values[1][3] * 3 = 9 。
 * 第四天，从商店 0 购买物品 3 ，开销为 values[0][3] * 4 = 16 。
 * 第五天，从商店 1 购买物品 2 ，开销为 values[1][2] * 5 = 25 。
 * 第六天，从商店 0 购买物品 2 ，开销为 values[0][2] * 6 = 36 。
 * 第七天，从商店 1 购买物品 1 ，开销为 values[1][1] * 7 = 49 。
 * 第八天，从商店 0 购买物品 1 ，开销为 values[0][1] * 8 = 64 。
 * 第九天，从商店 1 购买物品 0 ，开销为 values[1][0] * 9 = 81 。
 * 第十天，从商店 0 购买物品 0 ，开销为 values[0][0] * 10 = 100 。
 * 所以总开销为 386 。
 * 386 是购买所有 m * n 件物品的最大总开销。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= m == values.length <= 10
 * 1 <= n == values[i].length <= 10^4
 * 1 <= values[i][j] <= 10^6
 * values[i] 按照非递增顺序排序。
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
    long long maxSpending(vector<vector<int>> &values) {
        long long ans = 0;
        uint8_t m = values.size();
        uint32_t n = values.front().size();
        using store_t = pair<uint8_t, uint32_t>;
        auto cmp =
            [&](store_t &l, store_t &r) {
                return values[l.first][l.second] > values[r.first][r.second];
            };
        priority_queue<store_t,
                       vector<store_t>,
                       decltype(cmp)>
            toBuy(cmp);
        for (uint8_t c = 0; c < m; c++) {
            toBuy.push({c, n - 1});
        }
        for (uint64_t cnt = 1; !toBuy.empty(); cnt++) {
            auto [r, c] = toBuy.top();
            ans += values[r][c] * cnt;
            toBuy.pop();
            if (c) {
                toBuy.push({r, c - 1});
            }
        }
        return ans;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=maxSpending
// paramTypes= ["number[][]"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [[8,5,2],[6,4,1],[9,7,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[10,8,6,4,2],[9,7,5,3,2]]\n
// @lcpr case=end

 */
