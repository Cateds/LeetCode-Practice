/*
 * @lc app=leetcode.cn id=2315 lang=cpp
 * @lcpr version=30111
 *
 * [2315] 统计星号
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
    int countAsterisks(string s) {
        bool inVerticalLine = false;
        int ans = 0;
        for (auto &ch: s) {
            if (ch=='|') 
                inVerticalLine = !inVerticalLine;
            else if (!inVerticalLine && ch=='*')
                ans ++;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "l|*e*et|c**o|*de|"\n
// @lcpr case=end

// @lcpr case=start
// "iamprogrammer"\n
// @lcpr case=end

// @lcpr case=start
// "yo|uar|e**|b|e***au|tifu|l"\n
// @lcpr case=end

 */

