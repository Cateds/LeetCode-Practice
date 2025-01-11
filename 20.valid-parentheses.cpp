/*
 * @lc app=leetcode.cn id=20 lang=cpp
 * @lcpr version=30111
 *
 * [20] 有效的括号
 */

// @lcpr-template-start
#include <stack>
#include <unordered_map>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> Pair_Stack;
        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}};
        for (auto &ch : s) {
            if (pairs.count(ch)) {
                if (!Pair_Stack.empty() && Pair_Stack.top() == pairs[ch])
                    Pair_Stack.pop();
                else
                    return false;
            } else
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
