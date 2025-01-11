/*
 * @lc app=leetcode.cn id=28 lang=cpp
 * @lcpr version=30111
 *
 * [28] 找出字符串中第一个匹配项的下�?
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
    int strStr(string haystack, string needle) {
        if (haystack.length()<needle.length()) return -1;
        for (int i=0; i<=haystack.length()-needle.length(); i++) {
            if (haystack[i]!=needle[0]) continue;
            bool isRight = true;
            for (int j=1; j<needle.length(); j++) {
                if (haystack[i+j]!=needle[j]) isRight = false;
            }
            if (isRight) return i;
        }
        return -1;
    }
};
// @lc code=end

int main(void) {
    Solution obj;
    cout << obj.strStr("leetcode","leet");
}


/*
// @lcpr case=start
// "sadbutsad"\n"sad"\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n"leeto"\n
// @lcpr case=end


 */

