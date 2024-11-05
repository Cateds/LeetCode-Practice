/*
 * @lc app=leetcode.cn id=2864 lang=cpp
 * @lcpr version=30119
 *
 * [2864] 最大二进制奇数
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
    string maximumOddBinaryNumber(string s) {
        int size = s.size();
        int count = 0;
        for (auto &ch: s)
            count += ch - '0';
        string ans;
        for (int i=1; i<count; i++)
            ans += '1';
        for (int i=count; i<size; i++)
            ans += '0';
        ans += '1';
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "010"\n
// @lcpr case=end

// @lcpr case=start
// "0101"\n
// @lcpr case=end

 */

