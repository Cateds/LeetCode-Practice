/*
 * @lc app=leetcode.cn id=1014 lang=cpp
 * @lcpr version=30204
 *
 * [1014] 最佳观光组合
 *
 * https://leetcode.cn/problems/best-sightseeing-pair/description/
 *
 * algorithms
 * Medium (57.42%)
 * Likes:    453
 * Dislikes: 0
 * Total Accepted:    82.7K
 * Total Submissions: 142.2K
 * Testcase Example:  '[8,1,5,2,6]'
 *
 * 给你一个正整数数组 values，其中 values[i] 表示第 i 个观光景点的评分，并且两个景点 i 和 j 之间的 距离 为 j - i。
 * 
 * 一对景点（i < j）组成的观光组合的得分为 values[i] + values[j] + i - j ，也就是景点的评分之和 减去
 * 它们两者之间的距离。
 * 
 * 返回一对观光景点能取得的最高分。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：values = [8,1,5,2,6]
 * 输出：11
 * 解释：i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11
 * 
 * 
 * 示例 2：
 * 
 * 输入：values = [1,2]
 * 输出：2
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= values.length <= 5 * 10^4
 * 1 <= values[i] <= 1000
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
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0, mx = values[0] + 0;
        for (int j = 1; j < values.size(); ++j) {
            ans = max(ans, mx + values[j] - j);
            // 边遍历边维护
            mx = max(mx, values[j] + j);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [8,1,5,2,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */

