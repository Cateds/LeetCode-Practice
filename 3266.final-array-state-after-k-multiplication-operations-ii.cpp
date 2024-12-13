// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3266 lang=cpp
 * @lcpr version=30204
 *
 * [3266] K 次乘运算后的最终数组 II
 *
 * https://leetcode.cn/problems/final-array-state-after-k-multiplication-operations-ii/description/
 *
 * algorithms
 * Hard (23.64%)
 * Likes:    19
 * Dislikes: 0
 * Total Accepted:    3.1K
 * Total Submissions: 11.4K
 * Testcase Example:  '[2,1,3,5,6]\n5\n2'
 *
 * 给你一个整数数组 nums ，一个整数 k  和一个整数 multiplier 。
 *
 * 你需要对 nums 执行 k 次操作，每次操作中：
 *
 *
 * 找到 nums 中的 最小 值 x ，如果存在多个最小值，选择最 前面 的一个。
 * 将 x 替换为 x * multiplier 。
 *
 *
 * k 次操作以后，你需要将 nums 中每一个数值对 10^9 + 7 取余。
 *
 * 请你返回执行完 k 次乘运算以及取余运算之后，最终的 nums 数组。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [2,1,3,5,6], k = 5, multiplier = 2
 *
 * 输出：[8,4,6,5,6]
 *
 * 解释：
 *
 *
 *
 *
 * 操作
 * 结果
 *
 *
 * 1 次操作后
 * [2, 2, 3, 5, 6]
 *
 *
 * 2 次操作后
 * [4, 2, 3, 5, 6]
 *
 *
 * 3 次操作后
 * [4, 4, 3, 5, 6]
 *
 *
 * 4 次操作后
 * [4, 4, 6, 5, 6]
 *
 *
 * 5 次操作后
 * [8, 4, 6, 5, 6]
 *
 *
 * 取余操作后
 * [8, 4, 6, 5, 6]
 *
 *
 *
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [100000,2000], k = 2, multiplier = 1000000
 *
 * 输出：[999999307,999999993]
 *
 * 解释：
 *
 *
 *
 *
 * 操作
 * 结果
 *
 *
 * 1 次操作后
 * [100000, 2000000000]
 *
 *
 * 2 次操作后
 * [100000000000, 2000000000]
 *
 *
 * 取余操作后
 * [999999307, 999999993]
 *
 *
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^4
 * 1 <= nums[i] <= 10^9
 * 1 <= k <= 10^9
 * 1 <= multiplier <= 10^6
 *
 *
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cstdint>
#include <deque>
#include <format>
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
    vector<int> getFinalState(vector<int> &nums, int &k, int &multiplier) {
        if (multiplier == 1)
            return nums; // 沟槽的面向逆天 test case 编程
        const auto limit = 1000000000 + 7;
        using idx_t = uint16_t;
        idx_t n = nums.size();
        auto cmp = [&](idx_t &l, idx_t &r) {
            return nums[l] > nums[r] or (nums[l] == nums[r] and l > r);
        };
        priority_queue<idx_t, vector<idx_t>, decltype(cmp)> heap(cmp);
        for (idx_t i = 0; i < n; i++)
            heap.push(i);
        auto maxVal = *ranges::max_element(nums);
        for (; k; k--) {
            auto idx = heap.top();
            if ((long)nums[idx] * multiplier > maxVal) 
                break;
            nums[idx] *= multiplier;
            heap.pop(); heap.push(idx);
        }
        if (k) {
            for (idx_t i = k % n; i; i--, heap.pop())
                nums[heap.top()] = ((long)nums[heap.top()] * multiplier) % limit;
            auto pwrVal = [&](void) -> long {
                long res = 1, mul = multiplier, pwr = k/n;
                while (pwr) {
                    if (pwr & 0b1)
                        res = (res * mul) % limit;
                    pwr >>= 1;
                    mul = (mul * mul) % limit;
                }
                return res;
            }();
            for (auto &val : nums)
                val = ((long)val * pwrVal) % limit;
        }
        return nums;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=getFinalState
// paramTypes= ["number[]","number","number"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [2,1,3,5,6]\n5\n2\n
// @lcpr case=end

// @lcpr case=start
// [100000,2000]\n2\n1000000\n
// @lcpr case=end

// @lcpr case=start
// [4,2,4]\n3\n2\n
// @lcpr case=end
 */
