/*
 * @lc app=leetcode.cn id=90 lang=cpp
 * @lcpr version=30204
 *
 * [90] 子集 II
 *
 * https://leetcode.cn/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (63.53%)
 * Likes:    1247
 * Dislikes: 0
 * Total Accepted:    403.4K
 * Total Submissions: 634.9K
 * Testcase Example:  '[1,2,2]'
 *
 * 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的 子集（幂集）。
 *
 * 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,2,2]
 * 输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
 *
 *
 * 示例 2：
 *
 * 输入：nums = [0]
 * 输出：[[],[0]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 *
 *
 *
 *
 */

// @lcpr-template-start
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        unordered_map<int, char> nums_map;
        for (auto &n : nums)
            nums_map[n] += 1;
        vector<vector<int>> ans;
        vector<int> tmp;
        auto dfs = [&](auto &dfs,
                       decltype(nums_map.begin()) p) {
            if (p == nums_map.end()) {
                ans.push_back(tmp);
                return;
            }
            auto val = p->first;
            auto n = p->second;
            p++;
            for (int i = 0; i <= n; i++) {
                dfs(dfs, p);
                tmp.push_back(val);
            }
            tmp.erase(tmp.end() - n - 1, tmp.end());
            return;
        };
        dfs(dfs, nums_map.begin());
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */
