/*
 * @lc app=leetcode.cn id=70 lang=cpp
 * @lcpr version=30111
 *
 * [70] 爬楼梯
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
    int climbStairs(int n) {
        if (n<2) return 1;
        pair<int,int> Value = {1,1};
        for (int i=2; i<=n; i++) {
            auto count = Value.first+Value.second;
            Value.first = Value.second;
            Value.second = count;
        }
        return Value.second;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */

