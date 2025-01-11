// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3244 lang=cpp
 * @lcpr version=30204
 *
 * [3244] 新增道路查询后的最短距离 II
 *
 * https://leetcode.cn/problems/shortest-distance-after-road-addition-queries-ii/description/
 *
 * algorithms
 * Hard (34.55%)
 * Likes:    12
 * Dislikes: 0
 * Total Accepted:    3.6K
 * Total Submissions: 10K
 * Testcase Example:  '5\n[[2,4],[0,2],[0,4]]'
 *
 * 给你一个整数 n 和一个二维整数数组 queries。
 * 
 * 有 n 个城市，编号从 0 到 n - 1。初始时，每个城市 i 都有一条单向道路通往城市 i + 1（ 0 <= i < n - 1）。
 * 
 * queries[i] = [ui, vi] 表示新建一条从城市 ui 到城市 vi 的单向道路。每次查询后，你需要找到从城市 0 到城市 n - 1
 * 的最短路径的长度。
 * 
 * 所有查询中不会存在两个查询都满足 queries[i][0] < queries[j][0] < queries[i][1] <
 * queries[j][1]。
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
 * 提示:
 * 
 * 
 * 3 <= n <= 10^5
 * 1 <= queries.length <= 10^5
 * queries[i].length == 2
 * 0 <= queries[i][0] < queries[i][1] < n
 * 1 < queries[i][1] - queries[i][0]
 * 查询中不存在重复的道路。
 * 不存在两个查询都满足 i != j 且 queries[i][0] < queries[j][0] < queries[i][1] <
 * queries[j][1]。
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
        vector<uint32_t> dp(n,1);
        vector<int> ans;
        uint32_t minusCount = 0;
        for (auto &qr: queries) {
            if (qr[1]-qr[0] > dp[qr[0]] and dp[qr[0]]) {
                minusCount += qr[1]-qr[0]-dp[qr[0]];
                for (int i=qr[0]+dp[qr[0]]; i<qr[1];) {
                    auto temp = dp[i];
                    minusCount -= temp-1;
                    dp[i] = 0;
                    i += temp;
                }
                dp[qr[0]] = qr[1]-qr[0];
            }
            ans.push_back(n-1-minusCount);
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

