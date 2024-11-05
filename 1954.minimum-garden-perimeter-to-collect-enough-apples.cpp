/*
 * @lc app=leetcode.cn id=1954 lang=cpp
 * @lcpr version=30112
 *
 * [1954] 收集足够苹果的最小花园周长
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
    long long minimumPerimeter(long long neededApples) {
        long long L = 0, R = 100000;
        while (L<=R) {
            auto mid = (L+R)/2;
            auto Result = 2*mid*(mid+1)*(2*mid+1);
            if (Result >= neededApples) {
                R = mid - 1;
            }
            else
                L = mid + 1;
        }
        return 8*L;
    }
};
// @lc code=end
int main(void) {
    cout << Solution().minimumPerimeter(100000000000000) << endl;
}


/*
// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 13\n
// @lcpr case=end

// @lcpr case=start
// 1000000000\n
// @lcpr case=end

 */

