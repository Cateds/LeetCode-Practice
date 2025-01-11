/*
 * @lc app=leetcode.cn id=1276 lang=cpp
 * @lcpr version=30112
 *
 * [1276] 不浪费原料的汉堡制作方案
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
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if ((tomatoSlices-2*cheeseSlices)%2 || 
            tomatoSlices>4*cheeseSlices ||
            tomatoSlices<2*cheeseSlices )
            return vector<int>();
        else 
            return vector<int> {
                (tomatoSlices-2*cheeseSlices)/2,
                (4*cheeseSlices-tomatoSlices)/2 
            };
    }
};
// @lc code=end



/*
// @lcpr case=start
// 16\n7\n
// @lcpr case=end

// @lcpr case=start
// 17\n4\n
// @lcpr case=end

// @lcpr case=start
// 4\n17\n
// @lcpr case=end

// @lcpr case=start
// 0\n0\n
// @lcpr case=end

// @lcpr case=start
// 2\n1\n
// @lcpr case=end

 */

