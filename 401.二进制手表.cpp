/*
 * @lc app=leetcode.cn id=401 lang=cpp
 *
 * [401] 二进制手�?
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<vector<int>> nums = {
            {0},
            {1,2,4,8,16,32},
            {3,5,6,9,10,12,17,18,20,24,33,34,36,40,48},
            {7,11,13,14,19,21,22,25,26,28,35,37,38,41,42,44,49,50,52,56},
            {15,23,27,29,30,39,43,45,46,51,53,54,57,58},
            {31,47,55,59}
        };
        vector<string> Res;
        if (turnedOn>8) return Res;
        for (int i=0; i<=3&&(turnedOn-i)>=0; i++) {
            if (turnedOn-i>5) continue;
            for (auto &hour: nums[i]) {
                if (hour>=12) break;
                for (auto &minutes: nums[turnedOn-i]) {
                    Res.push_back(to_string(hour)+':'+(minutes<10?"0":"")+to_string(minutes));
                }
            }
        }
        return Res;
    }
};
// @lc code=end

