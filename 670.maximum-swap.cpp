/*
 * @lc app=leetcode.cn id=670 lang=cpp
 * @lcpr version=30113
 *
 * [670] 最大交换
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
#include <cmath>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int maximumSwap(int num) {
        if (num < 10) 
            return num;
        vector<char> number;
        for (auto i=num; i!=0; i/=10) {
            number.push_back(i%10);
        }
        if (number.empty()) 
            return 0;
        auto maxNumber = number.begin();
        for (auto p=number.begin()+1; p!=number.end(); p++) {
            if (*p > *maxNumber) maxNumber = p;
        }
        if (*maxNumber <= number.back()) 
            return num;
        else {
            auto temp = *maxNumber;
            *maxNumber = *number.rbegin();
            *number.rbegin() = temp;
        }
        int Ans = 0;
        for (int i=0; i<number.size(); i++) {
            Ans += number[i] * (int) pow(10,i);
        }
        return Ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2736\n
// @lcpr case=end

// @lcpr case=start
// 9973\n
// @lcpr case=end

 */

