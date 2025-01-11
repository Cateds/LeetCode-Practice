/*
 * @lc app=leetcode.cn id=1275 lang=cpp
 * @lcpr version=30111
 *
 * [1275] 找出井字棋的获胜�?
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
    string tictactoe(vector<vector<int>>& moves) {
        if (moves.size()<=2) return "Pending";
        array<int,8> Lines = {0};
        for (int i=0; i<2; i++) {
            Lines[moves[i][0]]+=(i%2)?-1:1; 
            Lines[moves[i][1]+3]+=(i%2)?-1:1;
            if (moves[i][0]==moves[i][1])       Lines[6]+=(i%2)?-1:1;
            if (moves[i][0]+moves[i][1] == 2)   Lines[7]+=(i%2)?-1:1;
        }
        for (int i=2; i<moves.size(); i++) {
            if ((Lines[moves[i][0]]+=(i%2)?-1:1)==((i%2)?-3:3))     return (i%2)?"B":"A";
            if ((Lines[moves[i][1]+3]+=(i%2)?-1:1)==((i%2)?-3:3))   return (i%2)?"B":"A";
            if (moves[i][0]==moves[i][1])     if ((Lines[6]+=(i%2)?-1:1)==((i%2)?-3:3)) return (i%2)?"B":"A";
            if (moves[i][0]+moves[i][1] == 2) if ((Lines[7]+=(i%2)?-1:1)==((i%2)?-3:3)) return (i%2)?"B":"A";
        }
        return (moves.size()-9)?"Pending":"Draw";
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,0],[2,0],[1,1],[2,1],[2,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0],[1,1]]\n
// @lcpr case=end

 */

