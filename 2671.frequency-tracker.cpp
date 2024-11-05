/*
 * @lc app=leetcode.cn id=2671 lang=cpp
 * @lcpr version=30119
 *
 * [2671] 频率跟踪器
 */


// @lcpr-template-start
using namespace std;
#include <unordered_map>
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
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class FrequencyTracker {
private:
    unordered_map<int,int> Number_Count;
    unordered_map<int,int> Count_Count;
public:
    FrequencyTracker() {

    }
    
    void add(int number) {
        if (auto n = Number_Count[number]) {
            Count_Count[n]--;
            Count_Count[n+1] ++;
            Number_Count[number] += 1;
        }
        else {
            Number_Count[number] = 1;
            Count_Count[1]++;
        }
    }
    
    void deleteOne(int number) {
        if (auto n = Number_Count[number]) {
            Count_Count[n]--;
            Count_Count[n-1]++;
            Number_Count[number]--;
        }
    }
    
    bool hasFrequency(int frequency) {
        return Count_Count[frequency];
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
// @lc code=end



