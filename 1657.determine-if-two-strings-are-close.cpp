/*
 * @lc app=leetcode.cn id=1657 lang=cpp
 * @lcpr version=30111
 *
 * [1657] 确定两个字符串是否接近
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
    bool closeStrings(string word1, string word2) {
        if (word1.length()!=word2.length()) return false;
        vector<int> charNums_1(26), charNums_2(26);
        for (const auto &ch: word1)
            charNums_1[ch-'a']++;
        for (const auto &ch: word2)
            charNums_2[ch-'a']++;
        for (int i=0; i<26; i++)
            if (!charNums_1[i] ^ !charNums_2[i]) return false;
        sort(charNums_1.begin(),charNums_1.end());
        sort(charNums_2.begin(),charNums_2.end());
        for (int i=0; i<26; i++)
            if (charNums_1[i]!=charNums_2[i]) return false;
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abc"\n"bca"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"aa"\n
// @lcpr case=end

// @lcpr case=start
// "cabbba"\n"abbccc"\n
// @lcpr case=end

// @lcpr case=start
// "cabbba"\n"aabbss"\n
// @lcpr case=end

 */

