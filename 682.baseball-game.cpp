/*
 * @lc app=leetcode.cn id=682 lang=cpp
 * @lcpr version=30111
 *
 * [682] 棒球比赛
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
    int calPoints(vector<string>& operations) {
        vector<int> Scores;
        for (auto &str: operations) {
            if (str=="C") Scores.pop_back();
            else if (str=="+") 
                Scores.push_back(*(Scores.end()-1)+*(Scores.end()-2));
            else if (str=="D")
                Scores.push_back(2* *(Scores.end()-1));
            else Scores.push_back(atoi(str.c_str()));
        }
        int Ans = 0;
        for (auto &score: Scores)
            Ans += score;
        return Ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["5","2","C","D","+"]\n
// @lcpr case=end

// @lcpr case=start
// ["5","-2","4","C","D","9","+","+"]\n
// @lcpr case=end

// @lcpr case=start
// ["1"]\n
// @lcpr case=end

 */

