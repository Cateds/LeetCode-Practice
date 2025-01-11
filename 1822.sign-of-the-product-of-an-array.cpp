/*
 * @lc app=leetcode.cn id=1822 lang=cpp
 * @lcpr version=30111
 *
 * [1822] 数组元素积的符号
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
    int arraySign(vector<int>& nums) {
        int count = 0;
        for (auto &n: nums) {
            if (!n) return 0;
            if (n<0) count++;
        }
        return (count%2)?-1:1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-1,-2,-3,-4,3,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,5,0,2,-3]\n
// @lcpr case=end

// @lcpr case=start
// [-1,1,-1,1,-1]\n
// @lcpr case=end

 */

