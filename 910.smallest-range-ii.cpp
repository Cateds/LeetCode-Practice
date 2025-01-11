// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=910 lang=cpp
 * @lcpr version=30204
 *
 * [910] 最小差值 II
 *
 * https://leetcode.cn/problems/smallest-range-ii/description/
 *
 * algorithms
 * Medium (37.07%)
 * Likes:    252
 * Dislikes: 0
 * Total Accepted:    26K
 * Total Submissions: 62.1K
 * Testcase Example:  '[1]\n0'
 *
 * 给你一个整数数组 nums，和一个整数 k 。
 * 
 * 对于每个下标 i（0 <= i < nums.length），将 nums[i] 变成  nums[i] + k 或 nums[i] - k 。
 * 
 * nums 的 分数 是 nums 中最大元素和最小元素的差值。
 * 
 * 在更改每个下标对应的值之后，返回 nums 的最小 分数 。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1], k = 0
 * 输出：0
 * 解释：分数 = max(nums) - min(nums) = 1 - 1 = 0 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [0,10], k = 2
 * 输出：6
 * 解释：将数组变为 [2, 8] 。分数 = max(nums) - min(nums) = 8 - 2 = 6 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [1,3,6], k = 3
 * 输出：3
 * 解释：将数组变为 [4, 6, 3] 。分数 = max(nums) - min(nums) = 6 - 3 = 3 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^4
 * 0 <= nums[i] <= 10^4
 * 0 <= k <= 10^4
 * 
 * 
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
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int minVal = nums.front(), maxVal = nums.back();
        int retVal = maxVal - minVal;
        for (int i=0; i<nums.size()-1; i++) {
            int t_a = nums[i], t_b = nums[i+1];
            retVal = min(retVal,max(maxVal-k,t_a+k) - min(minVal+k,t_b-k));
        }
        return retVal;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

// @lcpr case=start
// [0,10]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,3,6]\n3\n
// @lcpr case=end

 */

