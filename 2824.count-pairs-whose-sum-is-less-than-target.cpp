/*
 * @lc app=leetcode.cn id=2824 lang=cpp
 * @lcpr version=30110
 *
 * [2824] 统计和小于目标的下标对数目
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
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int Ptr_1=0, Res=0;
        for (int Ptr_2=nums.size()-1; Ptr_2>0; Ptr_2--) {
            while (Ptr_1<nums.size() && nums[Ptr_1]+nums[Ptr_2]<target)
                Ptr_1++;
            Res += (Ptr_1>Ptr_2)?Ptr_2:Ptr_1;
        }
        return Res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-1,1,2,3,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [-6,2,5,-2,-7,-1,3]\n-2\n
// @lcpr case=end

 */

