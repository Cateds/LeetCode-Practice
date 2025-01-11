/*
 * @lc app=leetcode.cn id=2706 lang=cpp
 * @lcpr version=30112
 *
 * [2706] 购买两块巧克力
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
    int buyChoco(vector<int>& prices, int money) {
        pair price_min = {min(prices[0],prices[1]), max(prices[0],prices[1])};
        for (auto ptr = prices.begin()+2; ptr!=prices.end(); ptr++) {
            if (*ptr >= price_min.second)
                continue;
            else if (*ptr >= price_min.first)
                price_min.second = *ptr;
            else {
                price_min.second = price_min.first;
                price_min.first = *ptr;
            }
        }
        return money >= price_min.first + price_min.second ?
               money - price_min.first - price_min.second :
               money;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [3,2,3]\n3\n
// @lcpr case=end

 */

