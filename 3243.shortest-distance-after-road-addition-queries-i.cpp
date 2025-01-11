// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3243 lang=cpp
 * @lcpr version=30204
 *
 * [3243] 新增道路查询后的最短距离 I
 *
 * https://leetcode.cn/problems/shortest-distance-after-road-addition-queries-i/description/
 *
 * algorithms
 * Medium (40.97%)
 * Likes:    44
 * Dislikes: 0
 * Total Accepted:    13.1K
 * Total Submissions: 24.7K
 * Testcase Example:  '5\n[[2,4],[0,2],[0,4]]'
 *
 * 给你一个整数 n 和一个二维整数数组 queries。
 *
 * 有 n 个城市，编号从 0 到 n - 1。初始时，每个城市 i 都有一条单向道路通往城市 i + 1（ 0 <= i < n - 1）。
 *
 * queries[i] = [ui, vi] 表示新建一条从城市 ui 到城市 vi 的单向道路。每次查询后，你需要找到从城市 0 到城市 n - 1
 * 的最短路径的长度。
 *
 * 返回一个数组 answer，对于范围 [0, queries.length - 1] 中的每个 i，answer[i] 是处理完前 i + 1
 * 个查询后，从城市 0 到城市 n - 1 的最短路径的长度。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入： n = 5, queries = [[2, 4], [0, 2], [0, 4]]
 *
 * 输出： [3, 2, 1]
 *
 * 解释：
 *
 *
 *
 * 新增一条从 2 到 4 的道路后，从 0 到 4 的最短路径长度为 3。
 *
 *
 *
 * 新增一条从 0 到 2 的道路后，从 0 到 4 的最短路径长度为 2。
 *
 *
 *
 * 新增一条从 0 到 4 的道路后，从 0 到 4 的最短路径长度为 1。
 *
 *
 * 示例 2：
 *
 *
 * 输入： n = 4, queries = [[0, 3], [0, 2]]
 *
 * 输出： [1, 1]
 *
 * 解释：
 *
 *
 *
 * 新增一条从 0 到 3 的道路后，从 0 到 3 的最短路径长度为 1。
 *
 *
 *
 * 新增一条从 0 到 2 的道路后，从 0 到 3 的最短路径长度仍为 1。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 3 <= n <= 500
 * 1 <= queries.length <= 500
 * queries[i].length == 2
 * 0 <= queries[i][0] < queries[i][1] < n
 * 1 < queries[i][1] - queries[i][0]
 * 查询中没有重复的道路。
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
    vector<int> shortestDistanceAfterQueries(
        const int &n,
        vector<vector<int>> &queries) {
        vector<int> ans;
        struct Node {
            vector<uint16_t> link;
            uint16_t val;
        };
        vector<Node> dp(n);
        for (int i = 0; i < n - 1; i++) {
            dp[i].val = i;
            dp[i].link.push_back(i + 1);
        }
        dp.back().val = n - 1;
        for (auto &qr : queries) {
            dp[qr[0]].link.push_back(qr[1]);
            if (dp[qr[1]].val > dp[qr[0]].val + 1) {
                dp[qr[1]].val = dp[qr[0]].val + 1;
                auto dfs =
                    [&](auto &dfs, const int &cur, const int &prv) -> void {
                        if (dp[cur].val > dp[prv].val + 1) {
                            dp[cur].val = dp[prv].val + 1;
                            for (auto &li : dp[cur].link)
                                dfs(dfs, li, cur);
                        }
                    };
                for (auto &li : dp[qr[1]].link)
                    dfs(dfs, li, qr[1]);
            }
            ans.push_back(dp.back().val);
        }
        return ans;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=shortestDistanceAfterQueries
// paramTypes= ["number","number[][]"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// 5\n[[2, 4], [0, 2], [0, 4]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[0, 3], [0, 2]]\n
// @lcpr case=end

 */
