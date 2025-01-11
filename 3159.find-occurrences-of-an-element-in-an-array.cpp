/*
 * @lc app=leetcode.cn id=3159 lang=cpp
 * @lcpr version=30204
 *
 * [3159] 查询数组中元素的出现位置
 *
 * https://leetcode.cn/problems/find-occurrences-of-an-element-in-an-array/description/
 *
 * algorithms
 * Medium (79.67%)
 * Likes:    6
 * Dislikes: 0
 * Total Accepted:    5.2K
 * Total Submissions: 6.6K
 * Testcase Example:  '[1,3,1,7]\n[1,3,2,4]\n1'
 *
 * 给你一个整数数组 nums ，一个整数数组 queries 和一个整数 x 。
 *
 * 对于每个查询 queries[i] ，你需要找到 nums 中第 queries[i] 个 x 的位置，并返回它的下标。如果数组中 x 的出现次数少于
 * queries[i] ，该查询的答案为 -1 。
 *
 * 请你返回一个整数数组 answer ，包含所有查询的答案。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,3,1,7], queries = [1,3,2,4], x = 1
 *
 * 输出：[0,-1,2,-1]
 *
 * 解释：
 *
 *
 * 第 1 个查询，第一个 1 出现在下标 0 处。
 * 第 2 个查询，nums 中只有两个 1 ，所以答案为 -1 。
 * 第 3 个查询，第二个 1 出现在下标 2 处。
 * 第 4 个查询，nums 中只有两个 1 ，所以答案为 -1 。
 *
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1,2,3], queries = [10], x = 5
 *
 * 输出：[-1]
 *
 * 解释：
 *
 *
 * 第 1 个查询，nums 中没有 5 ，所以答案为 -1 。
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length, queries.length <= 10^5
 * 1 <= queries[i] <= 10^5
 * 1 <= nums[i], x <= 10^4
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
    vector<int> occurrencesOfElement(vector<int> &nums, vector<int> &queries, int x) {
        int n = nums.size();
        vector<int> idx;
        for (int i = 0; i < n; i++) 
            if (nums[i] == x)
                idx.push_back(i);
        int qr_n = queries.size();
        vector<int> ans(qr_n, -1);
        int idx_n = idx.size();
        for (int i = 0; i < qr_n; i++)
            if (queries[i] <= idx_n)
                ans[i] = (idx[queries[i] - 1]);
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,3,1,7]\n[1,3,2,4]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n[10]\n5\n
// @lcpr case=end

 */
