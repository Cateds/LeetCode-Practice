/*
 * @lc app=leetcode.cn id=1768 lang=cpp
 * @lcpr version=30111
 *
 * [1768] 交替合并字符串
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
    string mergeAlternately(string word1, string word2) {
        string Ans;
        int status = word1.length() - word2.length();
        int length = min(word1.length(),word2.length());
        for (int i=0; i<length; i++) {
            Ans.push_back(word1[i]);
            Ans.push_back(word2[i]);
        }
        if (status>0) Ans += word1.substr(length,word1.length()-length);
        else if (status<0) Ans += word2.substr(length,word2.length()-length);
        return Ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abc"\n"pqr"\n
// @lcpr case=end

// @lcpr case=start
// "ab"\n"pqrs"\n
// @lcpr case=end

// @lcpr case=start
// "abcd"\n"pq"\n
// @lcpr case=end

 */

