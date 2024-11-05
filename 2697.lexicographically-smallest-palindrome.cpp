/*
 * @lc app=leetcode.cn id=2697 lang=cpp
 * @lcpr version=30111
 *
 * [2697] 字典序最小回文串
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
    string makeSmallestPalindrome(string s) {
        for (int i=0; i<s.length()/2; i++)
            if (s[i]>s[s.length()-1-i])
                s[i] = s[s.length()-1-i];
            else if (s[i]<s[s.length()-1-i])
                s[s.length()-1-i] = s[i];
        return s;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "egcfe"\n
// @lcpr case=end

// @lcpr case=start
// "abcd"\n
// @lcpr case=end

// @lcpr case=start
// "seven"\n
// @lcpr case=end

 */

