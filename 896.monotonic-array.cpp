/*
 * @lc app=leetcode.cn id=896 lang=cpp
 * @lcpr version=30111
 *
 * [896] 单调数列
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
    bool isMonotonic(vector<int>& nums) {
        long long i=0;
        while (i<nums.size()-1 && nums[i]==nums[i+1]) i++;
        if (i==nums.size()-1) return true;
        long long  kind = nums[i+1] - nums[i];
        for (int j=i+1; j<nums.size()-1; j++) {
            if ((nums[j+1]-nums[j])*kind<0) return false;
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [6,5,4,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,2]\n
// @lcpr case=end

 */

