/*
 * @lc app=leetcode.cn id=1599 lang=cpp
 * @lcpr version=30112
 *
 * [1599] 经营摩天轮的最大利润
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
    int minOperationsMaxProfit(vector<int> &customers, int boardingCost, int runningCost) {
        int Earn = 0, Earn_max = 0, Ans = -1;
        int current_customer = 0;
        for (int i=0; i<customers.size() || current_customer!=0; i++) {
            if (i<customers.size())
                current_customer += customers[i];
            auto upload = current_customer>=4?4:current_customer;
            current_customer -= upload;
            Earn += boardingCost * upload - runningCost;
            if (Earn > Earn_max) {
                Earn_max = Earn;
                Ans = i+1;
            }
        }
        return Ans;
    }
};
// @lc code=end

int main(void) {
    vector data = {8,3};
    cout << Solution().minOperationsMaxProfit(data,5,6);
}

/*
// @lcpr case=start
// [8,3]\n5\n6\n
// @lcpr case=end

// @lcpr case=start
// [10,9,6]\n6\n4\n
// @lcpr case=end

// @lcpr case=start
// [3,4,0,5,1]\n1\n92\n
// @lcpr case=end

 */

