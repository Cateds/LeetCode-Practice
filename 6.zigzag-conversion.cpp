/*
 * @lc app=leetcode.cn id=6 lang=cpp
 * @lcpr version=30111
 *
 * [6] N 字形变换
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
    string convert(string s, int numRows) {
        if (numRows==1) return s;
        auto Period = 2*numRows-2;
        auto Times = s.length()/(2*numRows-2);
        vector<string> SubStr(numRows);
        for (int i=0; i<Times; i++) {
            SubStr[0].push_back(s[i*Period]);
            for (int j=1; j<numRows-1; j++) {
                SubStr[j].push_back(s[i*Period+j]);
                SubStr[j].push_back(s[(i+1)*Period-j]);
            }
            SubStr[numRows-1].push_back(s[i*Period+numRows-1]);
        }
        if (s.length()%Period) {
            SubStr[0].push_back(s[Times*Period]);
            for (int j=1; j<numRows-1; j++) {
                if (Times*Period+j<s.length()) {
                    SubStr[j].push_back(s[Times*Period+j]);
                    if ((Times+1)*Period-j<s.length())
                        SubStr[j].push_back(s[(Times+1)*Period-j]);
                }
            }
            if (Times*Period+numRows-1<s.length())
                SubStr[numRows-1].push_back(s[Times*Period+numRows-1]);
        }
        string ans;
        for (auto &str: SubStr) ans += str;
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "PAYPALISHIRING"\n3\n
// @lcpr case=end

// @lcpr case=start
// "PAYPALISHIRING"\n4\n
// @lcpr case=end

// @lcpr case=start
// "A"\n1\n
// @lcpr case=end

 */

