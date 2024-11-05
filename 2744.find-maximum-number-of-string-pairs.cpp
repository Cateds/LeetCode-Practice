/*
 * @lc app=leetcode.cn id=2744 lang=cpp
 * @lcpr version=30113
 *
 * [2744] 最大字符串配对数目
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
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_map<string,bool> Count;
        int Ans = 0;
        for (auto &word: words)
            if (Count[word])
                Ans ++;
            else
                Count[string(word.rbegin(),word.rend())] = true;
        return Ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["cd","ac","dc","ca","zz"]\n
// @lcpr case=end

// @lcpr case=start
// ["ab","ba","cc"]\n
// @lcpr case=end

// @lcpr case=start
// ["aa","ab"]\n
// @lcpr case=end

 */

