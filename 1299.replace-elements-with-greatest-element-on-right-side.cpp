/*
 * @lc app=leetcode.cn id=1299 lang=cpp
 * @lcpr version=30204
 *
 * [1299] 将每个元素替换为右侧最大元素
 *
 * https://leetcode.cn/problems/replace-elements-with-greatest-element-on-right-side/description/
 *
 * algorithms
 * Easy (75.55%)
 * Likes:    118
 * Dislikes: 0
 * Total Accepted:    53.1K
 * Total Submissions: 68.8K
 * Testcase Example:  '[17,18,5,4,6,1]'
 *
 * 给你一个数组 arr ，请你将每个元素用它右边最大的元素替换，如果是最后一个元素，用 -1 替换。
 *
 * 完成所有替换操作后，请你返回这个数组。
 *
 *
 *
 * 示例 1：
 *
 * 输入：arr = [17,18,5,4,6,1]
 * 输出：[18,6,6,6,1,-1]
 * 解释：
 * - 下标 0 的元素 --> 右侧最大元素是下标 1 的元素 (18)
 * - 下标 1 的元素 --> 右侧最大元素是下标 4 的元素 (6)
 * - 下标 2 的元素 --> 右侧最大元素是下标 4 的元素 (6)
 * - 下标 3 的元素 --> 右侧最大元素是下标 4 的元素 (6)
 * - 下标 4 的元素 --> 右侧最大元素是下标 5 的元素 (1)
 * - 下标 5 的元素 --> 右侧没有其他元素，替换为 -1
 *
 *
 * 示例 2：
 *
 * 输入：arr = [400]
 * 输出：[-1]
 * 解释：下标 0 的元素右侧没有其他元素。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= arr.length <= 10^4
 * 1 <= arr[i] <= 10^5
 *
 *
 */

// @lcpr-template-start
#include <algorithm>
#include <vector>

using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<int> replaceElements(vector<int> &arr) {
        int maxr = -1;
        for (auto ptr = arr.rbegin(); ptr != arr.rend(); ptr++) {
            int tmp = max(maxr, *ptr);
            *ptr = maxr;
            maxr = tmp;
        }
        return arr;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [17,18,5,4,6,1]\n
// @lcpr case=end

// @lcpr case=start
// [400]\n
// @lcpr case=end

 */
