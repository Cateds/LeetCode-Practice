/*
 * @lc app=leetcode.cn id=54 lang=cpp
 * @lcpr version=30112
 *
 * [54] 螺旋矩阵
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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> Ans;
        pair<int,int> Root = {0,0};
        pair<int,int> Size = {matrix.size(),matrix[0].size()};
        while (Size.first > 0 && Size.second > 0) {
            for (int i=0; i<Size.second; i++)
                Ans.push_back(matrix[Root.first][Root.second+i]);
            for (int i=1; i<Size.first; i++)
                Ans.push_back(matrix[Root.first+i][Root.second+Size.second-1]);
            if (Size.first > 1)
                for (int i=Size.second-2; i>=0; i--)
                    Ans.push_back(matrix[Root.first+Size.first-1][Root.second+i]);
            if (Size.second > 1)
                for (int i=Size.first-2; i>0; i--)
                    Ans.push_back(matrix[Root.first+i][Root.second]);
            Root.first++; Root.second++;
            Size.first -= 2; Size.second -= 2;
        }
        return Ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3,4],[5,6,7,8],[9,10,11,12]]\n
// @lcpr case=end

 */

