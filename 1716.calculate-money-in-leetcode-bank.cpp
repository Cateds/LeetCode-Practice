/*
 * @lc app=leetcode.cn id=1716 lang=cpp
 * @lcpr version=30204
 *
 * [1716] 计算力扣银行的钱
 *
 * https://leetcode.cn/problems/calculate-money-in-leetcode-bank/description/
 *
 * algorithms
 * Easy (69.33%)
 * Likes:    89
 * Dislikes: 0
 * Total Accepted:    46.4K
 * Total Submissions: 67K
 * Testcase Example:  '4'
 *
 * Hercy 想要为购买第一辆车存钱。他 每天 都往力扣银行里存钱。
 *
 * 最开始，他在周一的时候存入 1 块钱。从周二到周日，他每天都比前一天多存入 1 块钱。在接下来每一个周一，他都会比 前一个周一 多存入 1 块钱。
 *
 * 给你 n ，请你返回在第 n 天结束的时候他在力扣银行总共存了多少块钱。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 4
 * 输出：10
 * 解释：第 4 天后，总额为 1 + 2 + 3 + 4 = 10 。
 *
 *
 * 示例 2：
 *
 * 输入：n = 10
 * 输出：37
 * 解释：第 10 天后，总额为 (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4) = 37
 * 。注意到第二个星期一，Hercy 存入 2 块钱。
 *
 *
 * 示例 3：
 *
 * 输入：n = 20
 * 输出：96
 * 解释：第 20 天后，总额为 (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4 + 5 + 6 + 7 + 8) +
 * (3 + 4 + 5 + 6 + 7 + 8) = 96 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 1000
 *
 *
 */

// @lcpr-template-start

using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int totalMoney(int n) {
        int m = (n - 1) / 7;
        n = (n - 1) % 7;
        return 21 * m +
               7 * m * (m + 1) / 2 +
               (2 * m + 2 + n) * (n + 1) / 2;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 10\n
// @lcpr case=end

// @lcpr case=start
// 20\n
// @lcpr case=end

 */
