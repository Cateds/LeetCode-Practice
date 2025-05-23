/*
 * @lc app=leetcode.cn id=632 lang=cpp
 * @lcpr version=30204
 *
 * [632] 最小区间
 *
 * https://leetcode.cn/problems/smallest-range-covering-elements-from-k-lists/description/
 *
 * algorithms
 * Hard (61.62%)
 * Likes:    483
 * Dislikes: 0
 * Total Accepted:    36.1K
 * Total Submissions: 57.1K
 * Testcase Example:  '[[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]'
 *
 * 你有 k 个 非递减排列 的整数列表。找到一个 最小 区间，使得 k 个列表中的每个列表至少有一个数包含在其中。
 * 
 * 我们定义如果 b-a < d-c 或者在 b-a == d-c 时 a < c，则区间 [a,b] 比 [c,d] 小。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
 * 输出：[20,24]
 * 解释： 
 * 列表 1：[4, 10, 15, 24, 26]，24 在区间 [20,24] 中。
 * 列表 2：[0, 9, 12, 20]，20 在区间 [20,24] 中。
 * 列表 3：[5, 18, 22, 30]，22 在区间 [20,24] 中。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [[1,2,3],[1,2,3],[1,2,3]]
 * 输出：[1,1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * nums.length == k
 * 1 <= k <= 3500
 * 1 <= nums[i].length <= 50
 * -10^5 <= nums[i][j] <= 10^5
 * nums[i] 按非递减顺序排列
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
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[1,2,3],[1,2,3]]\n
// @lcpr case=end

 */

