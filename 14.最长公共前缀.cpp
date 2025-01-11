/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int Res = strs[0].length();
        for (int i=1; i<strs.size(); i++) {
            if (strs[i].length() < Res) Res = strs[i].length();
            for (int j=0; j<Res; j++) {
                if (strs[0][j]==strs[i][j]) continue;
                else {
                    Res = j; break;
                }
            }
        }
        return strs[0].substr(0,Res);
    }
};
// @lc code=end

