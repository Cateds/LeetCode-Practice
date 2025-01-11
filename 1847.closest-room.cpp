// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1847 lang=cpp
 * @lcpr version=30204
 *
 * [1847] 最近的房间
 *
 * https://leetcode.cn/problems/closest-room/description/
 *
 * algorithms
 * Hard (40.98%)
 * Likes:    44
 * Dislikes: 0
 * Total Accepted:    4.6K
 * Total Submissions: 11.1K
 * Testcase Example:  '[[2,2],[1,2],[3,2]]\n[[3,1],[3,3],[5,2]]'
 *
 * 一个酒店里有 n 个房间，这些房间用二维整数数组 rooms 表示，其中 rooms[i] = [roomIdi, sizei] 表示有一个房间号为
 * roomIdi 的房间且它的面积为 sizei 。每一个房间号 roomIdi 保证是 独一无二 的。
 *
 * 同时给你 k 个查询，用二维数组 queries 表示，其中 queries[j] = [preferredj, minSizej] 。第 j
 * 个查询的答案是满足如下条件的房间 id ：
 *
 *
 * 房间的面积 至少 为 minSizej ，且
 * abs(id - preferredj) 的值 最小 ，其中 abs(x) 是 x 的绝对值。
 *
 *
 * 如果差的绝对值有 相等 的，选择 最小 的 id 。如果 没有满足条件的房间 ，答案为 -1 。
 *
 * 请你返回长度为 k 的数组 answer ，其中 answer[j] 为第 j 个查询的结果。
 *
 *
 *
 * 示例 1：
 *
 * 输入：rooms = [[2,2],[1,2],[3,2]], queries = [[3,1],[3,3],[5,2]]
 * 输出：[3,-1,3]
 * 解释：查询的答案如下：
 * 查询 [3,1] ：房间 3 的面积为 2 ，大于等于 1 ，且号码是最接近 3 的，为 abs(3 - 3) = 0 ，所以答案为 3 。
 * 查询 [3,3] ：没有房间的面积至少为 3 ，所以答案为 -1 。
 * 查询 [5,2] ：房间 3 的面积为 2 ，大于等于 2 ，且号码是最接近 5 的，为 abs(3 - 5) = 2 ，所以答案为 3 。
 *
 * 示例 2：
 *
 * 输入：rooms = [[1,4],[2,3],[3,5],[4,1],[5,2]], queries = [[2,3],[2,4],[2,5]]
 * 输出：[2,1,3]
 * 解释：查询的答案如下：
 * 查询 [2,3] ：房间 2 的面积为 3 ，大于等于 3 ，且号码是最接近的，为 abs(2 - 2) = 0 ，所以答案为 2 。
 * 查询 [2,4] ：房间 1 和 3 的面积都至少为 4 ，答案为 1 因为它房间编号更小。
 * 查询 [2,5] ：房间 3 是唯一面积大于等于 5 的，所以答案为 3 。
 *
 *
 *
 * 提示：
 *
 *
 * n == rooms.length
 * 1 <= n <= 10^5
 * k == queries.length
 * 1 <= k <= 10^4
 * 1 <= roomIdi, preferredj <= 10^7
 * 1 <= sizei, minSizej <= 10^7
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
#include <map>
#include <queue>
#include <set>
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
    vector<int> closestRoom(vector<vector<int>> &rooms,     // [roomID, size]
                            vector<vector<int>> &queries) { // [Prefer, MinSize]
        int qr_n = queries.size();
        for (int i = 0; i < qr_n; i++)
            queries[i].push_back(i); // -> [Prefer, MinSize, Idx]
        ranges::sort(queries, [](decltype(queries.front()) &l, decltype(l) r) -> bool {
            return l[1] > r[1];
        });

        ranges::sort(rooms, [](decltype(rooms.front()) &l, decltype(l) r) -> bool {
            return l[1] > r[1];
        });
        auto p = rooms.begin();

        set<int> available;
        vector<int> ans(qr_n);

        for (auto &qr : queries) {
            auto &Prefer = qr[0], &MinSize = qr[1], &idx = qr[2];
            while (p != rooms.end() and (*p)[1] >= MinSize) {
                available.insert((*p)[0]);
                p++;
            }
            int ansVal = -1;

            if (!available.empty()) {
                auto itr = available.lower_bound(Prefer);
                ansVal = INT_MAX;
                if (itr != available.end())
                    ansVal = *itr;
                if (itr != available.begin()) {
                    itr--;
                    ansVal = ((long)ansVal + *itr - 2 * Prefer) >= 0 ? *itr : ansVal;
                }
            }

            ans[idx] = ansVal;
        }

        return ans;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=closestRoom
// paramTypes= ["number[][]","number[][]"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [[2,2],[1,2],[3,2]]\n[[3,1],[3,3],[5,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,4],[2,3],[3,5],[4,1],[5,2]]\n[[2,3],[2,4],[2,5]]\n
// @lcpr case=end

 */
