/*
 * @lc app=leetcode.cn id=2588 lang=cpp
 * @lcpr version=30204
 *
 * [2588] 统计美丽子数组数目
 *
 * https://leetcode.cn/problems/count-the-number-of-beautiful-subarrays/description/
 *
 * algorithms
 * Medium (47.25%)
 * Likes:    56
 * Dislikes: 0
 * Total Accepted:    9.4K
 * Total Submissions: 19.7K
 * Testcase Example:  '[4,3,1,2,4]'
 *
 * 给你一个下标从 0 开始的整数数组nums 。每次操作中，你可以：
 *
 *
 * 选择两个满足 0 <= i, j < nums.length 的不同下标 i 和 j 。
 * 选择一个非负整数 k ，满足 nums[i] 和 nums[j] 在二进制下的第 k 位（下标编号从 0 开始）是 1 。
 * 将 nums[i] 和 nums[j] 都减去 2^k 。
 *
 *
 * 如果一个子数组内执行上述操作若干次后，该子数组可以变成一个全为 0 的数组，那么我们称它是一个 美丽 的子数组。
 *
 * 请你返回数组 nums 中 美丽子数组 的数目。
 *
 * 子数组是一个数组中一段连续 非空 的元素序列。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [4,3,1,2,4]
 * 输出：2
 * 解释：nums 中有 2 个美丽子数组：[4,3,1,2,4] 和 [4,3,1,2,4] 。
 * - 按照下述步骤，我们可以将子数组 [3,1,2] 中所有元素变成 0 ：
 * ⁠ - 选择 [3, 1, 2] 和 k = 1 。将 2 个数字都减去 2^1 ，子数组变成 [1, 1, 0] 。
 * ⁠ - 选择 [1, 1, 0] 和 k = 0 。将 2 个数字都减去 2^0 ，子数组变成 [0, 0, 0] 。
 * - 按照下述步骤，我们可以将子数组 [4,3,1,2,4] 中所有元素变成 0 ：
 * ⁠ - 选择 [4, 3, 1, 2, 4] 和 k = 2 。将 2 个数字都减去 2^2 ，子数组变成 [0, 3, 1, 2, 0] 。
 * ⁠ - 选择 [0, 3, 1, 2, 0] 和 k = 0 。将 2 个数字都减去 2^0 ，子数组变成 [0, 2, 0, 2, 0] 。
 * ⁠ - 选择 [0, 2, 0, 2, 0] 和 k = 1 。将 2 个数字都减去 2^1 ，子数组变成 [0, 0, 0, 0, 0] 。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [1,10,4]
 * 输出：0
 * 解释：nums 中没有任何美丽子数组。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i] <= 10^6
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
    long long beautifulSubarrays(vector<int> &nums) {
        unordered_map<int, int> xor_times;
        int temp = 0;
        xor_times[temp] += 1;
        for (auto &num : nums) {
            temp ^= num;
            xor_times[temp] += 1;
        }
        long long ans = 0;
        for (const auto &[xor_val, times] : xor_times)
            ans += (long long)times * (times - 1) / 2;
        return ans;
    }
};
// @lc code=end

/**
  @brief
    第一眼看过去，官解到底是哪里 O(n) 了，这玩意要输出子数组得有个 O(n^2) 才行
    结果一看只用输出数量，闹麻了

    整体思路和官解保持一致，如果 0 到 k 的异或值为 0 ，到 j 的异或值也为 0，
    那么 k+1 到 j 的区间内的异或值为 0
 */

/*
// @lcpr case=start
// [4,3,1,2,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,10,4]\n
// @lcpr case=end

 */
