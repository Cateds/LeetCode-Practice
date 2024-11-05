/*
 * @lc app=leetcode.cn id=2708 lang=cpp
 * @lcpr version=30204
 *
 * [2708] 一个小组的最大实力值
 *
 * https://leetcode.cn/problems/maximum-strength-of-a-group/description/
 *
 * algorithms
 * Medium (31.06%)
 * Likes:    54
 * Dislikes: 0
 * Total Accepted:    21K
 * Total Submissions: 65.5K
 * Testcase Example:  '[3,-1,-5,2,5,-9]'
 *
 * 给你一个下标从 0 开始的整数数组 nums ，它表示一个班级中所有学生在一次考试中的成绩。老师想选出一部分同学组成一个 非空 小组，且这个小组的
 * 实力值 最大，如果这个小组里的学生下标为 i0, i1, i2, ... , ik ，那么这个小组的实力值定义为 nums[i0] * nums[i1]
 * * nums[i2] * ... * nums[ik​] 。
 * 
 * 请你返回老师创建的小组能得到的最大实力值为多少。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [3,-1,-5,2,5,-9]
 * 输出：1350
 * 解释：一种构成最大实力值小组的方案是选择下标为 [0,2,3,4,5] 的学生。实力值为 3 * (-5) * 2 * 5 * (-9) = 1350
 * ，这是可以得到的最大实力值。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [-4,-5,-4]
 * 输出：20
 * 解释：选择下标为 [0, 1] 的学生。得到的实力值为 20 。我们没法得到更大的实力值。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 13
 * -9 <= nums[i] <= 9
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
#include <cmath>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long minValue=nums[0], maxValue=nums[0];
        for (int i=1; i<nums.size(); i++) {
            auto temp = minValue;
            long long n = nums[i];
            // 这里如果使用auto的话会识别成int，然后初始化列表里类型不统一会导致min和max无法重载
            // 好史的特性
            minValue = min({minValue,n,maxValue*n,minValue*n});
            maxValue = max({maxValue,n,maxValue*n,temp*n});
        }
        return maxValue;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,-1,-5,2,5,-9]\n
// @lcpr case=end

// @lcpr case=start
// [-4,-5,-4]\n
// @lcpr case=end

 */

