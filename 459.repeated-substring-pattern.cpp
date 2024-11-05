/*
 * @lc app=leetcode.cn id=459 lang=cpp
 * @lcpr version=30111
 *
 * [459] 重复的子字符串
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
    bool repeatedSubstringPattern(string s) {
        vector<int> index_collection;
        for (int i=1; i<=s.length()/2; i++) {
            if (s[i]==s[0]) index_collection.push_back(i);
        }
        for (auto &num: index_collection) {
            if (num>s.length()/2) break;
            if ((s.length())%(num)) continue;
            bool flag = true;
            for (int j=num; j<s.length(); j++) {
                if (s[j%(num)]!=s[j]) {
                    flag=false; break;
                }
            }
            if (flag) return true;
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abab"\n
// @lcpr case=end

// @lcpr case=start
// "aba"\n
// @lcpr case=end

// @lcpr case=start
// "abcabcabcabc"\n
// @lcpr case=end

 */

