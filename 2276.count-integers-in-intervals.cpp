/*
 * @lc app=leetcode.cn id=2276 lang=cpp
 * @lcpr version=30111
 *
 * [2276] 统计区间中的整数数目
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
class CountIntervals
{
private:
    using interval_struct = pair<int, int>;
    vector<interval_struct> Intervals;
    int count_value = 0;
public:
    CountIntervals() {}

    void add(int left, int right)
    {
        if (Intervals.empty())
        {
            Intervals.push_back({left, right});
            count_value += right - left + 1;
            return;
        }
        auto Ins_Left =
            upper_bound(Intervals.begin(), Intervals.end(), pair<int,int>{left,left},
                [](const interval_struct &in1, const interval_struct &in2) -> bool {
                    return in1.first < in2.first;
                });
        auto Ins_Right = 
            upper_bound(Intervals.begin(),Intervals.end(), pair<int,int>{right,right},
                [](const interval_struct &in1, const interval_struct &in2) -> bool {
                    return in1.first < in2.first;
                });
        if (Ins_Left != Intervals.begin() && Ins_Left[-1].second >= left) {
                Ins_Left--;
                left = Ins_Left->first;
        }
        if (Ins_Right != Intervals.begin() && Ins_Right[-1].second > right) {
            right = Ins_Right[-1].second;
        }
        for (auto ptr = Ins_Left; ptr!=Ins_Right; ptr++)
            count_value -= ptr->second - ptr->first + 1;
        Intervals.erase(Ins_Left,Ins_Right);
        Intervals.insert(Ins_Left,{left,right});
        count_value += right - left + 1;
    }
    int count() {
        return count_value;
    }
};

// @lc code=end
int main(void) {
    // Your CountIntervals object will be instantiated and called as such:
    CountIntervals* obj = new CountIntervals();
    obj->add(5,10);
    cout << obj->count() << endl;
    obj->add(3,5);
    cout << obj->count() << endl;
}

