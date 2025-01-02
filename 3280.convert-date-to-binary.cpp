/*
 * @lc app=leetcode.cn id=3280 lang=cpp
 * @lcpr version=30204
 *
 * [3280] 将日期转换为二进制表示
 *
 * https://leetcode.cn/problems/convert-date-to-binary/description/
 *
 * algorithms
 * Easy (88.85%)
 * Likes:    22
 * Dislikes: 0
 * Total Accepted:    16.8K
 * Total Submissions: 18.2K
 * Testcase Example:  '"2080-02-29"'
 *
 * 给你一个字符串 date，它的格式为 yyyy-mm-dd，表示一个公历日期。
 *
 * date 可以重写为二进制表示，只需要将年、月、日分别转换为对应的二进制表示（不带前导零）并遵循 year-month-day 的格式。
 *
 * 返回 date 的 二进制 表示。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入： date = "2080-02-29"
 *
 * 输出： "100000100000-10-11101"
 *
 * 解释：
 *
 * 100000100000, 10 和 11101 分别是 2080, 02 和 29 的二进制表示。
 *
 *
 * 示例 2：
 *
 *
 * 输入： date = "1900-01-01"
 *
 * 输出： "11101101100-1-1"
 *
 * 解释：
 *
 * 11101101100, 1 和 1 分别是 1900, 1 和 1 的二进制表示。
 *
 *
 *
 *
 * 提示：
 *
 *
 * date.length == 10
 * date[4] == date[7] == '-'，其余的 date[i] 都是数字。
 * 输入保证 date 代表一个有效的公历日期，日期范围从 1900 年 1 月 1 日到 2100 年 12 月 31 日（包括这两天）。
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
#include <sstream>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    string convertDateToBinary(string &date) {
        return format("{:b}-{:b}-{:b}",
                      strtol(date.data(), nullptr, 10),
                      strtol(date.data() + 5, nullptr, 10),
                      strtol(date.data() + 8, nullptr, 10));
    }
};
// @lc code=end

/*
// @lcpr case=start
// "2080-02-29"\n
// @lcpr case=end

// @lcpr case=start
// "1900-01-01"\n
// @lcpr case=end

 */
