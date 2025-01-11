/*
 * @lc app=leetcode.cn id=1041 lang=cpp
 * @lcpr version=30111
 *
 * [1041] 困于环中的机器人
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
    bool isRobotBounded(string instructions) {
        // enum Direction { Up=0, Right, Down, left };
        // using Coordinate = pair<int,int>;
        pair<pair<int,int>,int> Position = {{0,0},0};
        for (auto &ch: instructions) switch (ch) {
        case 'L': Position.second = (Position.second+3)%4; break;
        case 'R': Position.second = (Position.second+1)%4; break;
        case 'G': 
            if (Position.second%2) // Right & Left
                Position.first.first += (Position.second/2)?-1:1;
            else // Up & Down
                Position.first.second += (Position.second/2)?-1:1;
            break;
        }
        if (Position.second) return true;
        else return Position.first == pair<int,int> {0,0};
    }
};
// @lc code=end



/*
// @lcpr case=start
// "GGLLGG"\n
// @lcpr case=end

// @lcpr case=start
// "GG"\n
// @lcpr case=end

// @lcpr case=start
// "GL"\n
// @lcpr case=end

 */

