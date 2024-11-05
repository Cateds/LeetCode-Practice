/*
 * @lc app=leetcode.cn id=2336 lang=cpp
 * @lcpr version=30111
 *
 * [2336] 无限集中的最小数字
 * 
 * 2023/11/29 每日一题
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
class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        smallest = 1;
    }
    
    int popSmallest() {
        int ans = smallest;
        NotInSet[smallest]++;
        do {
            smallest ++;
        } while (NotInSet[smallest]);
        return ans;
    }
    
    void addBack(int num) {
        if (!NotInSet[num]) return;
        NotInSet[num] --;
        if (num<smallest) smallest = num;
    }
private:
    unordered_map<int,int> NotInSet;
    int smallest;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
// @lc code=end



