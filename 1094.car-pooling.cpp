/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 * @lcpr version=30111
 *
 * [1094] 拼车
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
#include <map>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> stopPosition;
        for (auto &passenger: trips) {
            stopPosition[passenger[1]] += passenger[0];
            stopPosition[passenger[2]] -= passenger[0];
        }
        int count = 0;
        for (auto &position: stopPosition) {
            count += position.second;
            if (count>capacity) return false;
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[2,1,5],[3,3,7]]\n4\n
// @lcpr case=end

// @lcpr case=start
// [[2,1,5],[3,3,7]]\n5\n
// @lcpr case=end

 */

