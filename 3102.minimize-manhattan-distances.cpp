/*
 * @lc app=leetcode.cn id=3102 lang=cpp
 * @lcpr version=30204
 *
 * [3102] 最小化曼哈顿距离
 *
 * https://leetcode.cn/problems/minimize-manhattan-distances/description/
 *
 * algorithms
 * Hard (38.08%)
 * Likes:    17
 * Dislikes: 0
 * Total Accepted:    2.8K
 * Total Submissions: 7.4K
 * Testcase Example:  '[[3,10],[5,15],[10,2],[4,4]]'
 *
 * 给你一个下标从 0 开始的数组 points ，它表示二维平面上一些点的整数坐标，其中 points[i] = [xi, yi] 。
 * 
 * 两点之间的距离定义为它们的曼哈顿距离。
 * 
 * 请你恰好移除一个点，返回移除后任意两点之间的 最大 距离可能的 最小 值。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：points = [[3,10],[5,15],[10,2],[4,4]]
 * 输出：12
 * 解释：移除每个点后的最大距离如下所示：
 * - 移除第 0 个点后，最大距离在点 (5, 15) 和 (10, 2) 之间，为 |5 - 10| + |15 - 2| = 18 。
 * - 移除第 1 个点后，最大距离在点 (3, 10) 和 (10, 2) 之间，为 |3 - 10| + |10 - 2| = 15 。
 * - 移除第 2 个点后，最大距离在点 (5, 15) 和 (4, 4) 之间，为 |5 - 4| + |15 - 4| = 12 。
 * - 移除第 3 个点后，最大距离在点 (5, 15) 和 (10, 2) 之间的，为 |5 - 10| + |15 - 2| = 18 。
 * 在恰好移除一个点后，任意两点之间的最大距离可能的最小值是 12 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：points = [[1,1],[1,1],[1,1]]
 * 输出：0
 * 解释：移除任一点后，任意两点之间的最大距离都是 0 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= points.length <= 10^5
 * points[i].length == 2
 * 1 <= points[i][0], points[i][1] <= 10^8
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
#include <set>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        multiset<int> sx, sy;
        for (auto &p: points) {
            sx.emplace(p[0] - p[1]);
            sy.emplace(p[0] + p[1]);
        }
        int res = INT_MAX;
        for (auto &p: points) {
            sx.erase(sx.find(p[0] - p[1]));
            sy.erase(sy.find(p[0] + p[1]));
            res = min(res, max(*sx.rbegin() - *sx.begin(), *sy.rbegin() - *sy.begin()));
            sx.emplace(p[0] - p[1]);
            sy.emplace(p[0] + p[1]);
        }
        return res;
    }
};

// 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/minimize-manhattan-distances/solutions/2829782/zui-xiao-hua-man-ha-dun-ju-chi-by-leetco-dipa/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
// @lc code=end



/*
// @lcpr case=start
// [[3,10],[5,15],[10,2],[4,4]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[1,1],[1,1]]\n
// @lcpr case=end

 */

