/*
 * @lc app=leetcode.cn id=2834 lang=cpp
 * @lcpr version=30118
 *
 * [2834] 找出美丽数组的最小和
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
    int minimumPossibleSum(int n, int target) {
        const int mod = 1e9+7;
        if (target/2>=n) {
            return (long long)(n*(n+1)/2)%mod;
        }
        else {
            int m = target/2;
            return (
                ((long long)m*(m+1)/2) + 
                (((long long)target*2 +(n-m-1))*(n-m)/2)
            ) % mod;
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n3\n
// @lcpr case=end

// @lcpr case=start
// 3\n3\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

 */

