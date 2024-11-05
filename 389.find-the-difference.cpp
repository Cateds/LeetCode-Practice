/*
 * @lc app=leetcode.cn id=389 lang=cpp
 * @lcpr version=30111
 *
 * [389] 找不同
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
    char findTheDifference(string s, string t) {
        array<int,26> Count = {0};
        for (auto &ch: t) Count[ch-'a']++;
        for (auto &ch: s) Count[ch-'a']--;
        for (int i=0; i<26; i++)
            if (Count[i]) return i+'a';
        return 0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcd"\n"abcde"\n
// @lcpr case=end

// @lcpr case=start
// ""\n"y"\n
// @lcpr case=end

 */

