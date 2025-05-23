/*
 * @lc app=leetcode.cn id=50 lang=cpp
 * @lcpr version=30112
 *
 * [50] Pow(x, n)
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
    double myPow(double x, long long n) {
        if (n==0)
            return 1;
        else if (n==1)
            return x;
        else if (n<0) {
            return 1/myPow(x,-n);
        }
        else if (n%2) {
            auto y = myPow(x, n/2);
            return y*y*x;
        }
        else {
            auto y = myPow(x,n/2);
            return y*y;
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2.00000\n10\n
// @lcpr case=end

// @lcpr case=start
// 2.10000\n3\n
// @lcpr case=end

// @lcpr case=start
// 2.00000\n-2\n
// @lcpr case=end

 */

