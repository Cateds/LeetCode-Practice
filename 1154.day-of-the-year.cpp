/*
 * @lc app=leetcode.cn id=1154 lang=cpp
 * @lcpr version=30112
 *
 * [1154] 一年中的第几天
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
    int dayOfYear(string date) {
        array<int,11> Months = {
            31,28,31,30,31,30,31,31,30,31,30
        };
        int year = stoi(date.substr(0,4)),
            day = stoi(date.substr(8,2)),
            month = stoi(date.substr(5,2));
        for (int i=1; i<month; i++)
            day += Months[i-1];
        if ((!(year%400) || year%100 && !(year%4)) && month>2)
            day += 1;
        return day;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "2019-01-09"\n
// @lcpr case=end

// @lcpr case=start
// "2019-02-10"\n
// @lcpr case=end

 */

