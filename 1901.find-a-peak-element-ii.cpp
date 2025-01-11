/*
 * @lc app=leetcode.cn id=1901 lang=cpp
 * @lcpr version=30112
 *
 * [1901] 寻找峰值 II
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
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        vector<int> Ans = {0,0};
        while (true) {
            if (Ans[0]<mat.size()-1 && mat[Ans[0]][Ans[1]]<mat[Ans[0]+1][Ans[1]]) {
                Ans[0]++;
            }
            else if (Ans[0]>0 && mat[Ans[0]][Ans[1]]<mat[Ans[0]-1][Ans[1]]) {
                Ans[0]--;
            }
            else if (Ans[1]<mat[0].size()-1 && mat[Ans[0]][Ans[1]]<mat[Ans[0]][Ans[1]+1]) {
                Ans[1]++;
            }
            else if (Ans[1]>0 && mat[Ans[0]][Ans[1]]<mat[Ans[0]][Ans[1]-1]) {
                Ans[1]--;
            }
            else
                return Ans;
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,4],[3,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[10,20,15],[21,30,14],[7,16,32]]\n
// @lcpr case=end

 */

