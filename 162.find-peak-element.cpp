/*
 * @lc app=leetcode.cn id=162 lang=cpp
 * @lcpr version=30112
 *
 * [162] 寻找峰值
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
    int findPeakElement(vector<int>& nums) {
        if (nums.size()==1) return 0;
        int L = 0, R = nums.size()-1;
        for (int mid = (L+R)/2; L<R; mid = (L+R)/2) {
            if (R-L==1) return nums[R]>nums[L]?R:L;
            if (nums[mid-1]-nums[mid]<0 && nums[mid]-nums[mid+1]>0)
                return mid;
            else if (nums[mid-1]-nums[mid]>0)
                R = mid;
            else
                L = mid;
        }
        return R;
    }
};
// @lc code=end

int main(void) {
    vector<int> nums = {1,2,3,1};
    cout << Solution().findPeakElement(nums) << endl;
}

/*
// @lcpr case=start
// [1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,1,3,5,6,4]\n
// @lcpr case=end

 */

