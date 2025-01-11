/*
 * @lc app=leetcode.cn id=2865 lang=cpp
 * @lcpr version=30113
 *
 * [2865] 美丽塔 I
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
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        long long Ans = 0;
        vector<int> peak_index;
        bool isGrowing = true;
        for (int i=0; i<maxHeights.size()-1; i++)
            if (maxHeights[i+1]<maxHeights[i]) {
                peak_index.push_back(i);
                isGrowing = false;
            }
            else if (maxHeights[i+1]>maxHeights[i])
                isGrowing = true;
            else
                continue;
        if (isGrowing)
            peak_index.push_back(maxHeights.size()-1);
        for (auto &index: peak_index) {
            auto peak = maxHeights[index];
            long long Count = peak;
            for (int i=index-1, max=peak; i>=0; i--) {
                if (maxHeights[i]<max)
                    max = maxHeights[i];
                Count += max;
            }
            for (int i=index+1, max=peak; i<maxHeights.size(); i++) {
                if (maxHeights[i]<max)
                    max = maxHeights[i];
                Count += max;
            }
            if (Count > Ans)
                Ans = Count;
        }
        return Ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,3,4,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [6,5,3,9,2,7]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,5,5,2,3]\n
// @lcpr case=end

 */

