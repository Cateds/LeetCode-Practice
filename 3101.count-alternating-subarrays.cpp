/*
 * @lc app=leetcode.cn id=3101 lang=cpp
 * @lcpr version=30204
 *
 * [3101] 交替子数组计数
 *
 * https://leetcode.cn/problems/count-alternating-subarrays/description/
 *
 * algorithms
 * Medium (52.57%)
 * Likes:    25
 * Dislikes: 0
 * Total Accepted:    14.6K
 * Total Submissions: 23.6K
 * Testcase Example:  '[0,1,1,1]'
 *
 * 给你一个二进制数组 nums 。
 * 
 * 如果一个子数组中 不存在 两个 相邻 元素的值 相同 的情况，我们称这样的子数组为 交替子数组 。
 * 
 * 返回数组 nums 中交替子数组的数量。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入： nums = [0,1,1,1]
 * 
 * 输出： 5
 * 
 * 解释：
 * 
 * 
 * 以下子数组是交替子数组：[0] 、[1] 、[1] 、[1] 以及 [0,1] 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入： nums = [1,0,1,0]
 * 
 * 输出： 10
 * 
 * 解释：
 * 
 * 
 * 数组的每个子数组都是交替子数组。可以统计在内的子数组共有 10 个。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * nums[i] 不是 0 就是 1 。
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
    long long countAlternatingSubarrays(vector<int>& nums) {
        bool prev = nums[0];
        long long count = 1;
        long long retVal = 0;
        for (int i=1; i<nums.size(); i++)
            if (nums[i]^prev) {
                count++;
                prev = !prev;
            } else {
                retVal += (count)*(count+1)/2;
                count = 1;
            }
        return retVal + count*(count+1)/2;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,1,0]\n
// @lcpr case=end

 */

