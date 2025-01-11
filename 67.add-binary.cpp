/*
 * @lc app=leetcode.cn id=67 lang=cpp
 * @lcpr version=30112
 *
 * [67] 二进制求和
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
    string addBinary(string a, string b) {
        if (a=="0" || b=="0")
            return a=="0"?b:a;
        stack<char> output;
        bool flag = 0;
        int i;
        for (i=1; i<=min(a.length(),b.length()); i++) {
            auto count = flag + a.end()[-i] + b.end()[-i] - ('0'*2);
            flag = count >> 1;
            output.push(count%2);
        }
        for (auto &c = a.length()>=b.length()?a:b; i<=c.length(); i++) {
            auto count = flag + c.end()[-i] - '0';
            flag = count >> 1;
            output.push(count%2);
        }
        if (flag)
            output.push(1);
        string Ans;
        for (auto j=output.top(); !output.empty(); output.pop(),j=output.top())
            Ans += j + '0';
        return Ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "11"\n"1"\n
// @lcpr case=end

// @lcpr case=start
// "1010"\n"1011"\n
// @lcpr case=end

 */

