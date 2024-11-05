/*
 * @lc app=leetcode.cn id=2085 lang=cpp
 * @lcpr version=30113
 *
 * [2085] 统计出现过一次的公共字符串
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
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,pair<int,int>> Words_Count;
        int Ans = 0;
        for (auto &str: words1)
            Words_Count[str].first++;
        for (auto &str: words2)
            Words_Count[str].second++;
        for (auto &[str,count]: Words_Count)
            if (count.first==1 and count.second==1)
                Ans++;
        return Ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["leetcode","is","amazing","as","is"]\n["amazing","leetcode","is"]\n
// @lcpr case=end

// @lcpr case=start
// ["b","bb","bbb"]\n["a","aa","aaa"]\n
// @lcpr case=end

// @lcpr case=start
// ["a","ab"]\n["a","a","a","ab"]\n
// @lcpr case=end

 */

