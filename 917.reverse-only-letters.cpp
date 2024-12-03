/*
 * @lc app=leetcode.cn id=917 lang=cpp
 * @lcpr version=30204
 *
 * [917] 仅仅反转字母
 *
 * https://leetcode.cn/problems/reverse-only-letters/description/
 *
 * algorithms
 * Easy (59.29%)
 * Likes:    216
 * Dislikes: 0
 * Total Accepted:    87K
 * Total Submissions: 146.7K
 * Testcase Example:  '"ab-cd"'
 *
 * 给你一个字符串 s ，根据下述规则反转字符串：
 * 
 * 
 * 所有非英文字母保留在原有位置。
 * 所有英文字母（小写或大写）位置反转。
 * 
 * 
 * 返回反转后的 s 。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "ab-cd"
 * 输出："dc-ba"
 * 
 * 
 * 
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "a-bC-dEf-ghIj"
 * 输出："j-Ih-gfE-dCba"
 * 
 * 
 * 
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = "Test1ng-Leet=code-Q!"
 * 输出："Qedo1ct-eeLg=ntse-T!"
 * 
 * 
 * 
 * 
 * 提示
 * 
 * 
 * 1 <= s.length <= 100
 * s 仅由 ASCII 值在范围 [33, 122] 的字符组成
 * s 不含 '\"' 或 '\\'
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
    inline bool isChar(char &c) { return (c|32)>='a' and (c|32)<='z'; }
    string reverseOnlyLetters(string &s) {
        auto st = s.begin(), bk = s.end()-1;
        while (true) {
            while (st<s.end() and !isChar(*st)) st++;
            while (bk>=s.begin() and !isChar(*bk)) bk--;
            if (bk>st)
                swap(*bk,*st);
            else break;
            bk--; st++;
        }
        return s;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "ab-cd"\n
// @lcpr case=end

// @lcpr case=start
// "a-bC-dEf-ghIj"\n
// @lcpr case=end

// @lcpr case=start
// "-"\n
// @lcpr case=end

 */

