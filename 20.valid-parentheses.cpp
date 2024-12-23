/*
 * @lc app=leetcode.cn id=20 lang=cpp
 * @lcpr version=30111
 *
 * [20] 有效的括号
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
    bool isValid(string s) {
        unordered_map<char> Pair_Stack;
        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        for (auto &ch: s) {
            if (pairs.count(ch)) {
                if (!Pair_Stack.empty() && Pair_Stack.top()==pairs[ch])
                    Pair_Stack.pop();
                else return false;
            }
            else
                Pair_Stack.push(ch);
        }
        return Pair_Stack.empty();
    }
};
// @lc code=end



/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "()[]{}"\n
// @lcpr case=end

// @lcpr case=start
// "(]"\n
// @lcpr case=end

 */

