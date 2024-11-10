// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=540 lang=cpp
 * @lcpr version=30204
 *
 * [540] 有序数组中的单一元素
 *
 * https://leetcode.cn/problems/single-element-in-a-sorted-array/description/
 *
 * algorithms
 * Medium (60.25%)
 * Likes:    689
 * Dislikes: 0
 * Total Accepted:    134.1K
 * Total Submissions: 222.6K
 * Testcase Example:  '[1,1,2,3,3,4,4,8,8]'
 *
 * 给你一个仅由整数组成的有序数组，其中每个元素都会出现两次，唯有一个数只会出现一次。
 *
 * 请你找出并返回只出现一次的那个数。
 *
 * 你设计的解决方案必须满足 O(log n) 时间复杂度和 O(1) 空间复杂度。
 *
 *
 *
 * 示例 1:
 *
 * 输入: nums = [1,1,2,3,3,4,4,8,8]
 * 输出: 2
 *
 *
 * 示例 2:
 *
 * 输入: nums =  [3,3,7,7,10,11,11]
 * 输出: 10
 *
 *
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i] <= 10^5
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
    int singleNonDuplicate(vector<int> &nums) {
        auto find =
            [&](auto &find, const unsigned &l, const unsigned &r) -> int {
            if (r == l) // 二分查找推出条件
                return nums[l];
            unsigned i = (long(l) + r) / 2;       // 取最中间的数组下标
            if (nums[i] == nums[i + 1] ^ i & 0b1) // 奇数和偶数单独讨论
                return find(find, i + 1, r);
            else
                return find(find, l, i);
        };
        return find(find, 0, nums.size() - 1);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,2,3,3,4,4,8,8]\n
// @lcpr case=end

// @lcpr case=start
// [3,3,7,7,10,11,11]\n
// @lcpr case=end

 */
