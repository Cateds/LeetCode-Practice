/*
 * @lc app=leetcode.cn id=3115 lang=cpp
 * @lcpr version=30204
 *
 * [3115] 质数的最大距离
 *
 * https://leetcode.cn/problems/maximum-prime-difference/description/
 *
 * algorithms
 * Medium (58.81%)
 * Likes:    28
 * Dislikes: 0
 * Total Accepted:    23.8K
 * Total Submissions: 37.2K
 * Testcase Example:  '[4,2,9,5,3]'
 *
 * 给你一个整数数组 nums。
 * 
 * 返回两个（不一定不同的）质数在 nums 中 下标 的 最大距离。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入： nums = [4,2,9,5,3]
 * 
 * 输出： 3
 * 
 * 解释： nums[1]、nums[3] 和 nums[4] 是质数。因此答案是 |4 - 1| = 3。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入： nums = [4,8,2,8]
 * 
 * 输出： 0
 * 
 * 解释： nums[2] 是质数。因为只有一个质数，所以答案是 |2 - 2| = 0。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 3 * 10^5
 * 1 <= nums[i] <= 100
 * 输入保证 nums 中至少有一个质数。
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
#include <map>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        map<int,bool> isPrime = {
            {2,1}, {3,1}, {5,1}, {7,1}, {11,1},
            {13,1}, {17,1}, {19,1}, {23,1}, {29,1},
            {31,1}, {37,1}, {41,1}, {43,1}, {47,1},
            {53,1}, {59,1}, {61,1}, {67,1}, {71,1},
            {73,1}, {79,1}, {83,1}, {89,1}, {97,1}
        };
        int lptr, rptr;
        for (lptr=0; !isPrime[nums[lptr]]; lptr++);
        for (rptr=nums.size()-1; !isPrime[nums[rptr]]; rptr--);
        return rptr - lptr;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,2,9,5,3]\n
// @lcpr case=end

// @lcpr case=start
// [4,8,2,8]\n
// @lcpr case=end

 */

