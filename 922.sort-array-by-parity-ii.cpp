/*
 * @lc app=leetcode.cn id=922 lang=cpp
 * @lcpr version=30204
 *
 * [922] 按奇偶排序数组 II
 *
 * https://leetcode.cn/problems/sort-array-by-parity-ii/description/
 *
 * algorithms
 * Easy (71.58%)
 * Likes:    304
 * Dislikes: 0
 * Total Accepted:    135.2K
 * Total Submissions: 188.7K
 * Testcase Example:  '[4,2,5,7]'
 *
 * 给定一个非负整数数组 nums，  nums 中一半整数是 奇数 ，一半整数是 偶数 。
 *
 * 对数组进行排序，以便当 nums[i] 为奇数时，i 也是 奇数 ；当 nums[i] 为偶数时， i 也是 偶数 。
 *
 * 你可以返回 任何满足上述条件的数组作为答案 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [4,2,5,7]
 * 输出：[4,5,2,7]
 * 解释：[4,7,2,5]，[2,5,4,7]，[2,7,4,5] 也会被接受。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [2,3]
 * 输出：[2,3]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= nums.length <= 2 * 10^4
 * nums.length 是偶数
 * nums 中一半是偶数
 * 0 <= nums[i] <= 1000
 *
 *
 *
 *
 * 进阶：可以不使用额外空间解决问题吗？
 *
 */

// @lcpr-template-start
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int> &nums) {
        int odd = nums.size() / 2 - 1, even = odd;
        while (true) {
            while (odd >= 0 and nums[2 * odd + 1] % 2)
                odd -= 1;
            while (even >= 0 and !(nums[2 * even] % 2))
                even -= 1;
            if (even < 0 or odd < 0)
                break;
            swap(nums[2 * odd + 1],
                 nums[2 * even]);
        }
        return nums;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,2,5,7]\n
// @lcpr case=end

// @lcpr case=start
// [2,3]\n
// @lcpr case=end

 */
