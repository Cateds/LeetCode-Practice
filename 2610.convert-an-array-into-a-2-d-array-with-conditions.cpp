/*
 * @lc app=leetcode.cn id=2610 lang=cpp
 * @lcpr version=30204
 *
 * [2610] 转换二维数组
 *
 * https://leetcode.cn/problems/convert-an-array-into-a-2d-array-with-conditions/description/
 *
 * algorithms
 * Medium (84.20%)
 * Likes:    47
 * Dislikes: 0
 * Total Accepted:    26.1K
 * Total Submissions: 29.9K
 * Testcase Example:  '[1,3,4,1,2,3,1]'
 *
 * 给你一个整数数组 nums 。请你创建一个满足以下条件的二维数组：
 *
 *
 * 二维数组应该 只 包含数组 nums 中的元素。
 * 二维数组中的每一行都包含 不同 的整数。
 * 二维数组的行数应尽可能 少 。
 *
 *
 * 返回结果数组。如果存在多种答案，则返回其中任何一种。
 *
 * 请注意，二维数组的每一行上可以存在不同数量的元素。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,3,4,1,2,3,1]
 * 输出：[[1,3,4,2],[1,3],[1]]
 * 解释：根据题目要求可以创建包含以下几行元素的二维数组：
 * - 1,3,4,2
 * - 1,3
 * - 1
 * nums 中的所有元素都有用到，并且每一行都由不同的整数组成，所以这是一个符合题目要求的答案。
 * 可以证明无法创建少于三行且符合题目要求的二维数组。
 *
 * 示例 2：
 *
 * 输入：nums = [1,2,3,4]
 * 输出：[[4,3,2,1]]
 * 解释：nums 中的所有元素都不同，所以我们可以将其全部保存在二维数组中的第一行。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 200
 * 1 <= nums[i] <= nums.length
 *
 *
 */

// @lcpr-template-start
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
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int> &nums) {
        unordered_map<int, int> num_cnt;
        for (const auto &n : nums)
            num_cnt[n] += 1;
        vector<vector<int>> ans;
        while (!num_cnt.empty()) {
            ans.push_back(vector<int>());
            vector<int> toDel;
            for (auto &[num, cnt] : num_cnt) {
                ans.back().push_back(num);
                if (--cnt == 0) 
                    toDel.push_back(num);
            }
            for (const auto &del: toDel)
                num_cnt.erase(del);
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,3,4,1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

 */
