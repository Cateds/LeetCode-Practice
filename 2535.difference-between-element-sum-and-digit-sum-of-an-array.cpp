/*
 * @lc app=leetcode.cn id=2535 lang=cpp
 * @lcpr version=30204
 *
 * [2535] 数组元素和与数字和的绝对差
 *
 * https://leetcode.cn/problems/difference-between-element-sum-and-digit-sum-of-an-array/description/
 *
 * algorithms
 * Easy (82.23%)
 * Likes:    31
 * Dislikes: 0
 * Total Accepted:    36.1K
 * Total Submissions: 41.8K
 * Testcase Example:  '[1,15,6,3]'
 *
 * 给你一个正整数数组 nums 。
 * 
 * 
 * 元素和 是 nums 中的所有元素相加求和。
 * 数字和 是 nums 中每一个元素的每一数位（重复数位需多次求和）相加求和。
 * 
 * 
 * 返回 元素和 与 数字和 的绝对差。
 * 
 * 注意：两个整数 x 和 y 的绝对差定义为 |x - y| 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,15,6,3]
 * 输出：9
 * 解释：
 * nums 的元素和是 1 + 15 + 6 + 3 = 25 。
 * nums 的数字和是 1 + 1 + 5 + 6 + 3 = 16 。
 * 元素和与数字和的绝对差是 |25 - 16| = 9 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [1,2,3,4]
 * 输出：0
 * 解释：
 * nums 的元素和是 1 + 2 + 3 + 4 = 10 。
 * nums 的数字和是 1 + 2 + 3 + 4 = 10 。
 * 元素和与数字和的绝对差是 |10 - 10| = 0 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 2000
 * 1 <= nums[i] <= 2000
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
    int differenceOfSum(vector<int>& nums) {
        int count_digits = 0;
        int count_num = 0;
        for (auto &n: nums) {
            count_num += n;
            for (auto i=n; i!=0; i/=10)
                count_digits += i%10;
        }
        return abs(count_digits-count_num);
    }
};
// @lc code=end

int main(void) {
    
}

/*
// @lcpr case=start
// [1,15,6,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

 */

