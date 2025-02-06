/*
 * @lc app=leetcode.cn id=47 lang=cpp
 * @lcpr version=30204
 *
 * [47] 全排列 II
 *
 * https://leetcode.cn/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (66.16%)
 * Likes:    1646
 * Dislikes: 0
 * Total Accepted:    616.7K
 * Total Submissions: 931.3K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,1,2]
 * 输出：
 * [[1,1,2],
 * ⁠[1,2,1],
 * ⁠[2,1,1]]
 *
 *
 * 示例 2：
 *
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 8
 * -10 <= nums[i] <= 10
 *
 *
 */

// @lcpr-template-start
#include <climits>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        char size = nums.size();
        auto remain = size;
        vector<vector<int>> nxt =
            {vector<int>(size, INT_MAX)};
        decltype(nxt) prv;
        vector<int> tmp;
        unordered_map<char, char> nums_map;
        for (auto &n : nums)
            nums_map[n] += 1;
        auto gen_permu = [&](auto &func, char val,
                             char depth, char start_idx) {
            if (depth == 0) {
                nxt.push_back(tmp);
                return;
            }
            char loop_times = remain - depth + 1;
            for (char i = 0, idx = start_idx; i < loop_times; i++, idx++) {
                while (idx < size and tmp[idx] != INT_MAX)
                    idx++;
                if (idx == size)
                    break;
                tmp[idx] = val;
                func(func, val, depth - 1, idx + 1);
                tmp[idx] = INT_MAX;
            }
        };
        for (auto &[val, times] : nums_map) {
            prv = std::move(nxt);
            for (auto &arr : prv) {
                tmp = std::move(arr);
                gen_permu(gen_permu, val, times, 0);
            }
            remain -= times;
        }
        return nxt;
    }
};
// @lc code=end

/**
  @brief 
    这道题是求一个包含重复数字的数组的所有不重复全排列。解题思路如下：

    1. 首先统计每个数字出现的次数，使用 unordered_map 存储

    2. 使用回溯法，但与普通全排列不同的是：
        - 对每个不同的数字，我们一次性处理其所有重复出现的情况
        - 每次在数组的剩余空位中插入相同的数字
        - 递归处理下一个不同的数字

    3. 具体实现：
        - 维护一个临时数组 tmp，初始值为 INT_MAX 表示空位
        - 对每个不同的数字，通过 gen_permu 递归函数生成其所有可能的位置组合
        - 使用 nxt 和 prv 两个vector存储中间结果和最终结果
        - remain 记录剩余待处理的数字个数

    4. 时间复杂度：O(n!)，其中 n 为数组长度
        空间复杂度：O(n)，递归调用栈的深度
 */

/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */
