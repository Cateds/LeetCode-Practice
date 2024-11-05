/*
 * @lc app=leetcode.cn id=1631 lang=cpp
 * @lcpr version=30111
 *
 * [1631] 最小体力消耗路�?
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
    int minimumEffortPath(vector<vector<int>>& heights) {
        for (int i=1; i<heights[0].size(); i++)
            if (heights[0][i]-heights[0][i-1]>Value_PreSet)
                Value_PreSet = heights[0][i] - heights[0][i-1];
        for (int i=1,j=heights.size()-1; i<heights.size(); i++)
            if (heights[i][j]-heights[i-1][j]>Value_PreSet)
                Value_PreSet = heights[i][j] - heights[i-1][j];
        unordered_map<pair<int,int>,bool> PrevNode;
        function<int(const pair<int,int> &,const pair<int,int> &)> search = 
        [&] (const pair<int,int> &Root,const pair<int,int> &From) -> int {
            vector<pair<int,int>> Tasks;
            if (Root.first>0 && From.first!=Root.first-1) Tasks.push_back({Root.first-1,Root.second});
            if (Root.first<heights[0].size()-1 && From.first!=Root.first+1) Tasks.push_back({Root.first+1,Root.second});
            if (Root.second>0 && From.second!=Root.second-1) Tasks.push_back({Root.first,Root.second});
            
        };
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,2],[3,8,2],[5,3,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[3,8,4],[5,3,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]\n
// @lcpr case=end

 */

