/*
 * @lc app=leetcode.cn id=3158 lang=cpp
 * @lcpr version=30204
 *
 * [3158] 求出出现两次数字的 XOR 值
 *
 * https://leetcode.cn/problems/find-the-xor-of-numbers-which-appear-twice/description/
 *
 * algorithms
 * Easy (74.39%)
 * Likes:    24
 * Dislikes: 0
 * Total Accepted:    21.9K
 * Total Submissions: 27.6K
 * Testcase Example:  '[1,2,1,3]'
 *
 * 给你一个数组 nums ，数组中的数字 要么 出现一次，要么 出现两次。
 * 
 * 请你返回数组中所有出现两次数字的按位 XOR 值，如果没有数字出现过两次，返回 0 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,1,3]
 * 
 * 输出：1
 * 
 * 解释：
 * 
 * nums 中唯一出现过两次的数字是 1 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 
 * 输出：0
 * 
 * 解释：
 * 
 * nums 中没有数字出现两次。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1,2,2,1]
 * 
 * 输出：3
 * 
 * 解释：
 * 
 * 数字 1 和 2 出现过两次。1 XOR 2 == 3 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 50
 * 1 <= nums[i] <= 50
 * nums 中每个数字要么出现过一次，要么出现过两次。
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
    int duplicateNumbersXOR(vector<int>& nums) {
        int num_used[50] = {0};
        int ans = 0;
        for (auto &n: nums) {
            if (num_used[n-1])
                ans ^= n;
            else
                num_used[n-1]=1;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,1]\n
// @lcpr case=end

 */

