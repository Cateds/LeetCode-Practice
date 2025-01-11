/*
 * @lc app=leetcode.cn id=3174 lang=cpp
 * @lcpr version=30204
 *
 * [3174] 清除数字
 *
 * https://leetcode.cn/problems/clear-digits/description/
 *
 * algorithms
 * Easy (76.16%)
 * Likes:    29
 * Dislikes: 0
 * Total Accepted:    23.3K
 * Total Submissions: 28.5K
 * Testcase Example:  '"abc"'
 *
 * 给你一个字符串 s 。
 *
 * 你的任务是重复以下操作删除 所有 数字字符：
 *
 *
 * 删除 第一个数字字符 以及它左边 最近 的 非数字 字符。
 *
 *
 * 请你返回删除所有数字字符以后剩下的字符串。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "abc"
 *
 * 输出："abc"
 *
 * 解释：
 *
 * 字符串中没有数字。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "cb34"
 *
 * 输出：""
 *
 * 解释：
 *
 * 一开始，我们对 s[2] 执行操作，s 变为 "c4" 。
 *
 * 然后对 s[1] 执行操作，s 变为 "" 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 100
 * s 只包含小写英文字母和数字字符。
 * 输入保证所有数字都可以按以上操作被删除。
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
    string clearDigits(string s) {
        string ans;
        int toSkip = 0;
        for (auto p = s.rbegin();
             p != s.rend();
             p++)
            if (*p >= '0' and *p <= '9')
                toSkip++;
            else if (toSkip)
                toSkip--;
            else
                ans += *p;
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "abc"\n
// @lcpr case=end

// @lcpr case=start
// "cb34"\n
// @lcpr case=end

 */
