/*
 * @lc app=leetcode.cn id=709 lang=cpp
 * @lcpr version=30111
 *
 * [709] 转换成小写字母
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
    string toLowerCase(string s) {
        for (auto &ch: s)
            if (ch<='Z'&&ch>='A') ch += 32;
            // 'a' - 'A' = 32
        return s;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "Hello"\n
// @lcpr case=end

// @lcpr case=start
// "here"\n
// @lcpr case=end

// @lcpr case=start
// "LOVELY"\n
// @lcpr case=end

 */

