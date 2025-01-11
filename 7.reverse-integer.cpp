/*
 * @lc app=leetcode.cn id=7 lang=cpp
 * @lcpr version=30204
 *
 * [7] 整数反转
 *
 * https://leetcode.cn/problems/reverse-integer/description/
 *
 * algorithms
 * Medium (35.57%)
 * Likes:    4041
 * Dislikes: 0
 * Total Accepted:    1.4M
 * Total Submissions: 3.8M
 * Testcase Example:  '123'
 *
 * 给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
 *
 * 如果反转后整数超过 32 位的有符号整数的范围 [−2^31,  2^31 − 1] ，就返回 0。
 * 假设环境不允许存储 64 位整数（有符号或无符号）。
 *
 *
 *
 * 示例 1：
 *
 * 输入：x = 123
 * 输出：321
 *
 *
 * 示例 2：
 *
 * 输入：x = -123
 * 输出：-321
 *
 *
 * 示例 3：
 *
 * 输入：x = 120
 * 输出：21
 *
 *
 * 示例 4：
 *
 * 输入：x = 0
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * -2^31 <= x <= 2^31 - 1
 *
 *
 */

// @lcpr-template-start
#include <cstdlib>

using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int reverse(int &x) {
        int ans = 0;
        for (; x != 0; x /= 10) {
            if ((0x7FFFFFFF - abs(x % 10))/10 < abs(ans))
                return 0;
            ans = ans * 10 + x % 10;
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 123\n
// @lcpr case=end

// @lcpr case=start
// -123\n
// @lcpr case=end

// @lcpr case=start
// 120\n
// @lcpr case=end

// @lcpr case=start
// 0\n
// @lcpr case=end

 */
