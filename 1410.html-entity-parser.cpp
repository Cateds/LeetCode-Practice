/*
 * @lc app=leetcode.cn id=1410 lang=cpp
 * @lcpr version=30110
 *
 * [1410] HTML 实体解析器
 */

// @lcpr-template-start
#include <string>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    string entityParser(string text) {
        string Res;
        for (int i = 0; i < text.length(); i++) {
            if (text[i] != '&')
                Res.push_back(text[i]);
            else {
                string word = "&";
                while (i < text.length() - 1) {
                    i++;
                    if (text[i] == '&') {
                        i--;
                        break;
                    }
                    word.push_back(text[i]);
                    if (text[i] == ';')
                        break;
                }
                if (word == "&quot;")
                    Res.push_back('\"');
                else if (word == "&apos;")
                    Res.push_back('\'');
                else if (word == "&amp;")
                    Res.push_back('&');
                else if (word == "&gt;")
                    Res.push_back('>');
                else if (word == "&lt;")
                    Res.push_back('<');
                else if (word == "&frasl;")
                    Res.push_back('/');
                else
                    Res += word;
            }
        }
        return Res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "& is an HTML entity but &ambassador; is not."\n
// @lcpr case=end

// @lcpr case=start
// "and I quote: "...""\n
// @lcpr case=end

// @lcpr case=start
// "Stay home! Practice on Leetcode :)"\n
// @lcpr case=end

// @lcpr case=start
// "x > y && x < y is always false"\n
// @lcpr case=end

// @lcpr case=start
// "leetcode.com⁄problemset⁄all"\n
// @lcpr case=end

 */
