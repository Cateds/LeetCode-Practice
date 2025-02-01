/*
 * @lc app=leetcode.cn id=81 lang=cpp
 * @lcpr version=30204
 *
 * [81] 搜索旋转排序数组 II
 *
 * https://leetcode.cn/problems/search-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Medium (41.04%)
 * Likes:    817
 * Dislikes: 0
 * Total Accepted:    238.4K
 * Total Submissions: 577.6K
 * Testcase Example:  '[2,5,6,0,0,1,2]\n0'
 *
 * 已知存在一个按非降序排列的整数数组 nums ，数组中的值不必互不相同。
 *
 * 在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转 ，使数组变为 [nums[k],
 * nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始
 * 计数）。例如， [0,1,2,4,4,4,5,6,6,7] 在下标 5 处经旋转后可能变为 [4,5,6,6,7,0,1,2,4,4] 。
 *
 * 给你 旋转后 的数组 nums 和一个整数 target ，请你编写一个函数来判断给定的目标值是否存在于数组中。如果 nums 中存在这个目标值
 * target ，则返回 true ，否则返回 false 。
 *
 * 你必须尽可能减少整个操作步骤。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [2,5,6,0,0,1,2], target = 0
 * 输出：true
 *
 *
 * 示例 2：
 *
 * 输入：nums = [2,5,6,0,0,1,2], target = 3
 * 输出：false
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 5000
 * -10^4 <= nums[i] <= 10^4
 * 题目数据保证 nums 在预先未知的某个下标上进行了旋转
 * -10^4 <= target <= 10^4
 *
 *
 *
 *
 * 进阶：
 *
 *
 * 此题与 搜索旋转排序数组 相似，但本题中的 nums  可能包含 重复 元素。这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？
 *
 *
 *
 *
 */

// @lcpr-template-start
#include <vector>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    /**
      @brief 题目限定了这是一个非降序的数组，并且经过了一次旋转。这意味着这个数组
            在一定程度上仍然可以认为是单调的。我们只要先找到旋转处的坐标，然后通过
            一个简单的数组下标变换就能把原本的数组恢复成单调的样子。然后我们就可以
            使用二分查找来块度找到target的下标。
      @param nums
      @param target
      @return true
      @return false
     */
    bool search(vector<int> &nums, int &target) {
        int rotate_index;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] >= nums[i - 1])
                continue;
            rotate_index = i;
            break;
        }
        auto binary_search =
            [&](auto &bs, int l, int r) {
                if (l >= r)
                    return false;
                auto i = (l + r) / 2;
                if (nums[(rotate_index + i) % n] > target)
                    return bs(bs, l, i);
                else if (nums[(rotate_index + i) % n] < target)
                    return bs(bs, i + 1, r);
                else
                    return true;
            };
        return binary_search(
            binary_search,
            0,
            n);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,5,6,0,0,1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [2,5,6,0,0,1,2]\n3\n
// @lcpr case=end

 */
