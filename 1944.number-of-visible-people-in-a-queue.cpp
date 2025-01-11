/*
 * @lc app=leetcode.cn id=1944 lang=cpp
 * @lcpr version=30112
 *
 * [1944] 队列中可以看到的人数
 * 2024/1/5 每日一题
 * 
 * 不是这个为什么Hard啊，压个栈不就完了？
 * 
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
    // 如果用vector模拟stack的话效率会更高
    // vector<pair<int,int>> 能有100%效率10%内存的成绩
    // vector<int> 是效率80%内存30%
    // 反而正儿八经用栈stack<int> 效率50%内存100%
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> Prev; // index
        int size = heights.size();
        vector<int> Ans(size);
        Prev.push(0);
        for (int i=1; i<size; i++) {
            if (heights[i] < heights[Prev.top()]) {
                Ans[Prev.top()]++;
                Prev.push(i);
            }
            else {
                do {
                    Ans[Prev.top()]++;
                    Prev.pop();
                } while (!Prev.empty() and heights[Prev.top()] < heights[i]);
                if (!Prev.empty())
                    Ans[Prev.top()]++;
                Prev.push(i);
            }
        }
        return Ans;
    }
};
// @lc code=end

int main(void) {
    vector data = {11,19,12,15,14,18,7,1,8,9};
    auto ans = Solution().canSeePersonsCount(data);
    for (auto &i: ans) {
        cout << i << ' ';
    }
}

/*
// @lcpr case=start
// [10,6,8,5,11,9]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,2,3,10]\n
// @lcpr case=end

 */

