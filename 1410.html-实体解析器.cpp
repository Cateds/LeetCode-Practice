/*
 * @lc app=leetcode.cn id=1410 lang=cpp
 *
 * [1410] HTML 实体解析�?
 * 
 * 2023/11/23 每日一�?
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    string entityParser(string text) {
        string Res;
        for (int i=0; i<text.length(); i++) {
            if (text[i]!='&') Res.push_back(text[i]);
            else {
                string word;
                do {
                    word.push_back(text[i]);
                    i++;
                } while (text[i]!=';' && text[i]!='&');
                if (text[i]=='&') {
                    Res += word;
                    i--; continue;
                }
                word.push_back(';');
                if (word=="&quot;") Res.push_back('\"');
                else if (word=="&apos;") Res.push_back('\'');
                else if (word=="&amp;") Res.push_back('&');
                else if (word=="&gt;") Res.push_back('>');
                else if (word=="&lt;") Res.push_back('<');
                else if (word=="&frasl;") Res.push_back('/');
                else Res+=word;
            }
        }
        return Res;
    }
};
// @lc code=end
