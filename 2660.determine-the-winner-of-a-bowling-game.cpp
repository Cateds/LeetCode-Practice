/*
 * @lc app=leetcode.cn id=2660 lang=cpp
 * @lcpr version=30112
 *
 * [2660] 保龄球游戏的获胜者
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
    int isWinner(vector<int>& player1, vector<int>& player2) {
        if (player1.size()<=1) {
            if (player1[0]==player2[0])
                return 0;
            else
                return 1 + (player1[0]<player2[0]);
        }
        pair needDouble = {player1[0]==10,player1[1]==10};
        int Val_1 = player1[0] + (needDouble.first + 1)*player1[1];
        for (auto i=2; i<player1.size(); i++) {
            Val_1 += ((needDouble.first || needDouble.second) + 1) * player1[i];
            needDouble.first = needDouble.second;
            needDouble.second = player1[i]==10;
        }
        needDouble = {player2[0]==10,player2[1]==10};
        int Val_2 = player2[0] + (needDouble.first + 1)*player2[1];
        for (auto i=2; i<player2.size(); i++) {
            Val_2 += ((needDouble.first || needDouble.second) + 1) * player2[i];
            needDouble.first = needDouble.second;
            needDouble.second = player2[i]==10;
        }
        if (Val_1==Val_2)
            return 0;
        else
            return 1 + (Val_1 < Val_2);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,10,7,9]\n[6,5,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [3,5,7,6]\n[8,10,10,2]\n
// @lcpr case=end

// @lcpr case=start
// [2,3]\n[4,1]\n
// @lcpr case=end

 */

