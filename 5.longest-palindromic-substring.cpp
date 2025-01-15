/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=30110
 *
 * [5] 最长回文子串
 */

// @lcpr-template-start
#include <string>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int MaxLen = 0, MaxStart = 0;
        for (int i = 0; i < s.length(); i++) {
            int Len = 0;
            while (i - Len >= 0 && i + Len < s.length() && s[i - Len] == s[i + Len])
                Len++;
            if (Len * 2 - 1 > MaxLen) {
                MaxLen = Len * 2 - 1;
                MaxStart = i - Len + 1;
            }
            Len = 0;
            while (i - Len >= 0 && i + Len + 1 < s.length() && s[i - Len] == s[i + Len + 1])
                Len++;
            if (Len * 2 > MaxLen) {
                MaxLen = Len * 2;
                MaxStart = i - Len + 1;
            }
        }
        return s.substr(MaxStart, MaxLen);
    }
};
// @lc code=end

/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */
