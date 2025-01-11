/*
 * @lc app=leetcode.cn id=746 lang=cpp
 * @lcpr version=30112
 *
 * [746] 使用最小花费爬楼梯
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
    int minCostClimbingStairs(vector<int>& cost) {
        pair<int,int> Steps = {cost.end()[-1],cost.end()[-2]};
        for (int i=cost.size()-3; i>=0; i--) {
            auto Value = cost[i] + min(Steps.first,Steps.second);
            Steps.first = Steps.second;
            Steps.second = Value;
        }
        return min(Steps.first,Steps.second);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,15,20]\n
// @lcpr case=end

// @lcpr case=start
// [1,100,1,1,1,100,1,1,100,1]\n
// @lcpr case=end

 */

