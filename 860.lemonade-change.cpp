/*
 * @lc app=leetcode.cn id=860 lang=cpp
 * @lcpr version=30112
 *
 * [860] 柠檬水找零
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
    bool lemonadeChange(vector<int>& bills) {
        pair<int,int> notes = {0,0};
        for (auto &bill: bills) {
            switch (bill) {
            case 5:  
                notes.first++; break;
            case 10: 
                notes.first--; notes.second++;
                if (notes.first<0) return false;
                break;
            case 20:
                if (notes.second==0) {
                    if ((notes.first-=3)<0) return false;
                }
                else {
                    notes.second--;
                    if ((notes.first-=1)<0) return false;
                }
                break;
            }
        }
        return true;
    }
};
// @lc code=end
int main(void) {
    vector<int> Data = {5,5,10,20,5,5,5,5,5,5,5,5,5,10,5,5,20,5,20,5};
    cout << Solution().lemonadeChange(Data);
}


/*
// @lcpr case=start
// [5,5,5,10,20]\n
// @lcpr case=end

// @lcpr case=start
// [5,5,10,10,20]\n
// @lcpr case=end

 */

