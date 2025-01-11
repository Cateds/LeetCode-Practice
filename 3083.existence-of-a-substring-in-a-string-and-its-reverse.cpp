/*
 * @lc app=leetcode.cn id=3083 lang=cpp
 * @lcpr version=30204
 *
 * [3083] 字符串及其反转中是否存在同一子字符串
 *
 * https://leetcode.cn/problems/existence-of-a-substring-in-a-string-and-its-reverse/description/
 *
 * algorithms
 * Easy (71.16%)
 * Likes:    26
 * Dislikes: 0
 * Total Accepted:    23K
 * Total Submissions: 30.3K
 * Testcase Example:  '"leetcode"'
 *
 * 给你一个字符串 s ，请你判断字符串 s 是否存在一个长度为 2 的子字符串，在其反转后的字符串中也出现。
 * 
 * 如果存在这样的子字符串，返回 true；如果不存在，返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "leetcode"
 * 
 * 输出：true
 * 
 * 解释：子字符串 "ee" 的长度为 2，它也出现在 reverse(s) == "edocteel" 中。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "abcba"
 * 
 * 输出：true
 * 
 * 解释：所有长度为 2 的子字符串 "ab"、"bc"、"cb"、"ba" 也都出现在 reverse(s) == "abcba" 中。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "abcd"
 * 
 * 输出：false
 * 
 * 解释：字符串 s 中不存在满足「在其反转后的字符串中也出现」且长度为 2 的子字符串。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 100
 * 字符串 s 仅由小写英文字母组成。
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
#include <map>
#include <set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    bool isSubstringPresent(string &s) {
        array<uint32_t,26> after;
        uint8_t n = s.length();
        for (int i=1; i<n; i++) {
            auto &prv = s[i-1], &cur = s[i];
            after[prv-'a'] |= 0b1 << (cur-'a');
        }
        for (int i=n-2; i>=0; i--) {
            auto &prv = s[i+1], &cur = s[i];
            if (after[prv-'a'] & (0b1 << (cur-'a')))
                return true;
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "leetcode"\n
// @lcpr case=end

// @lcpr case=start
// "abcba"\n
// @lcpr case=end

// @lcpr case=start
// "abcd"\n
// @lcpr case=end

 */

