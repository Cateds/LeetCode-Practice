/*
 * @lc app=leetcode.cn id=2549 lang=cpp
 * @lcpr version=30119
 *
 * [2549] 统计桌面上的不同数字
 */


// @lcpr-template-start
using namespace std;
#include <unordered_set>
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
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int distinctIntegers(int n) {
        return (n==1)?1:(n-1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */

