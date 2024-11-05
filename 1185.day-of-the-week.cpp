/*
 * @lc app=leetcode.cn id=1185 lang=cpp
 * @lcpr version=30112
 *
 * [1185] 一周中的第几天
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
    string dayOfTheWeek(int day, int month, int year) {
        // 1971-1-1 Fri.
        auto isLeap = 
        [](const int &year) {
            return !(year%400) || year%100 && !(year%4);
        };
        array<string,7> Ans = {
            "Friday","Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday"
        };
        array<int,11> Month = {
            31,28,31,30,31,30,31,31,30,31,30
        };
        int days_total = day - 1;
        for (int i=1971; i<year; i++) {
            days_total += 1 + isLeap(i);
        }
        for (int i=1; i<month; i++) {
            days_total += Month[i-1] % 7;
        }
        if (isLeap(year) && month>2)
            days_total += 1;
        return Ans[days_total%7];
    }
};
// @lc code=end

int main(void) {
    cout << Solution().dayOfTheWeek(1,2,1971);
}

/*
// @lcpr case=start
// 31\n8\n2019\n
// @lcpr case=end

// @lcpr case=start
// 18\n7\n1999\n
// @lcpr case=end

// @lcpr case=start
// 15\n8\n1993\n
// @lcpr case=end

 */

