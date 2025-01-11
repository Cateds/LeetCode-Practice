/*
 * @lc app=leetcode.cn id=1962 lang=cpp
 * @lcpr version=30112
 *
 * [1962] 移除石子使总数最小
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
#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        make_heap(piles.begin(),piles.end());
        for (int i=0; i<k; i++) {
            pop_heap(piles.begin(),piles.end());
            piles.back() -= piles.back()/2;
            push_heap(piles.begin(),piles.end());
        }
        return accumulate(piles.begin(),piles.end(),0);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,4,9]\n2\n
// @lcpr case=end

// @lcpr case=start
// [4,3,6,7]\n3\n
// @lcpr case=end

 */

