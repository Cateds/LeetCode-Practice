/*
 * @lc app=leetcode.cn id=2661 lang=cpp
 * @lcpr version=30111
 *
 * [2661] 找出叠涂元素
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
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        struct Point {int Row; int Col;};
        vector<int> Count_Horizonal(mat.size());
        vector<int> Count_Vertical(mat[0].size());
        unordered_map<int,Point> mat_map;
        for (int row=0; row<mat.size(); row++) {
            for (int col=0; col<mat[0].size(); col++) {
                mat_map[mat[row][col]] = Point({row,col});
            }
        }
        for (int num=0; num<arr.size(); num++) {
            auto &point = mat_map[arr[num]];
            if (++Count_Horizonal[point.Row]==mat[0].size()) return num;
            if (++Count_Vertical[point.Col]==mat.size()) return num;
        }
        return 0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,4,2]\n[[1,4],[2,3]]\n
// @lcpr case=end

// @lcpr case=start
// [2,8,7,4,1,3,5,6,9]\n[[3,2,5],[1,4,6],[8,7,9]]\n
// @lcpr case=end

 */
int main(void) {
    Solution obj;
    vector<int> input1 = {1,2,3,4};
    vector<vector<int>> input2 = {
        {1,2},{3,4}
    };
    obj.firstCompleteIndex(input1,input2);
    return 0;
}
