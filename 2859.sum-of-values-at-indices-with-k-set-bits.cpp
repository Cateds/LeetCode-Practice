/*
 * @lc app=leetcode.cn id=2859 lang=cpp
 * @lcpr version=30113
 *
 * [2859] 计算 K 置位下标对应元素的和
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
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int Ans = 0;
        for (int i=0; i<nums.size(); i++)
            if (__builtin_popcount(i)==k)
                Ans += nums[i];
            else
                continue;
        return Ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,10,1,5,2]\n1\n
// @lcpr case=end

// @lcpr case=start
// [4,3,2,1]\n2\n
// @lcpr case=end

 */

