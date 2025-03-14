/*
 * @lc app=leetcode.cn id=3340 lang=cpp
 * @lcpr version=30204
 *
 * [3340] 检查平衡字符串
 *
 * https://leetcode.cn/problems/check-balanced-string/description/
 *
 * algorithms
 * Easy (81.58%)
 * Likes:    19
 * Dislikes: 0
 * Total Accepted:    18.6K
 * Total Submissions: 21.4K
 * Testcase Example:  '"1234"'
 *
 * 给你一个仅由数字 0 - 9 组成的字符串 num。如果偶数下标处的数字之和等于奇数下标处的数字之和，则认为该数字字符串是一个 平衡字符串。
 *
 * 如果 num 是一个 平衡字符串，则返回 true；否则，返回 false。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：num = "1234"
 *
 * 输出：false
 *
 * 解释：
 *
 *
 * 偶数下标处的数字之和为 1 + 3 = 4，奇数下标处的数字之和为 2 + 4 = 6。
 * 由于 4 不等于 6，num 不是平衡字符串。
 *
 *
 *
 * 示例 2：
 *
 *
 * 输入：num = "24123"
 *
 * 输出：true
 *
 * 解释：
 *
 *
 * 偶数下标处的数字之和为 2 + 1 + 3 = 6，奇数下标处的数字之和为 4 + 2 = 6。
 * 由于两者相等，num 是平衡字符串。
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= num.length <= 100
 * num 仅由数字 0 - 9 组成。
 *
 *
 */

// @lcpr-template-start
#include <string>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    bool isBalanced(string num) {
        int sum = 0;
        int sign = 1;
        for (auto &ch : num) {
            sum += (ch - '0') * sign;
            sign *= -1;
        }
        return !sum;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "1234"\n
// @lcpr case=end

// @lcpr case=start
// "24123"\n
// @lcpr case=end

 */
