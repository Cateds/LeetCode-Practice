/*
 * @lc app=leetcode.cn id=2332 lang=cpp
 * @lcpr version=30204
 *
 * [2332] 坐上公交的最晚时间
 *
 * https://leetcode.cn/problems/the-latest-time-to-catch-a-bus/description/
 *
 * algorithms
 * Medium (30.63%)
 * Likes:    75
 * Dislikes: 0
 * Total Accepted:    17K
 * Total Submissions: 55.5K
 * Testcase Example:  '[10,20]\n[2,17,18,19]\n2'
 *
 * 给你一个下标从 0 开始长度为 n 的整数数组 buses ，其中 buses[i] 表示第 i 辆公交车的出发时间。同时给你一个下标从 0 开始长度为
 * m 的整数数组 passengers ，其中 passengers[j] 表示第 j
 * 位乘客的到达时间。所有公交车出发的时间互不相同，所有乘客到达的时间也互不相同。
 * 
 * 给你一个整数 capacity ，表示每辆公交车 最多 能容纳的乘客数目。
 * 
 * 每位乘客都会搭乘下一辆有座位的公交车。如果你在 y 时刻到达，公交在 x 时刻出发，满足 y <= x  且公交没有满，那么你可以搭乘这一辆公交。最早
 * 到达的乘客优先上车。
 * 
 * 返回你可以搭乘公交车的最晚到达公交站时间。你 不能 跟别的乘客同时刻到达。
 * 
 * 注意：数组 buses 和 passengers 不一定是有序的。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：buses = [10,20], passengers = [2,17,18,19], capacity = 2
 * 输出：16
 * 解释：
 * 第 1 辆公交车载着第 1 位乘客。
 * 第 2 辆公交车载着你和第 2 位乘客。
 * 注意你不能跟其他乘客同一时间到达，所以你必须在第二位乘客之前到达。
 * 
 * 示例 2：
 * 
 * 输入：buses = [20,30,10], passengers = [19,13,26,4,25,11,21], capacity = 2
 * 输出：20
 * 解释：
 * 第 1 辆公交车载着第 4 位乘客。
 * 第 2 辆公交车载着第 6 位和第 2 位乘客。
 * 第 3 辆公交车载着第 1 位乘客和你。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == buses.length
 * m == passengers.length
 * 1 <= n, m, capacity <= 10^5
 * 2 <= buses[i], passengers[i] <= 10^9
 * buses 中的元素 互不相同 。
 * passengers 中的元素 互不相同 。
 * 
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
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(),buses.end());
        sort(passengers.begin(),passengers.end());
        auto psg = passengers.begin();
        int cap;
        for (auto bus= buses.begin(); bus!=buses.end();bus++) {
            cap = capacity;
            while (psg!=passengers.end() and *psg <= *bus and cap) {
                cap--; psg++;
            }
        }
        int Ans;
        if (cap) {
            Ans = buses.end()[-1];
            if (psg!=passengers.begin()) psg--;
        } else {
            Ans = *(--psg);
        }
        while (true) {
            if (Ans == *psg) {
                if (psg!=passengers.begin())
                    psg--;
                Ans--;
            }
            else return Ans;
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,20]\n[2,17,18,19]\n2\n
// @lcpr case=end

// @lcpr case=start
// [20,30,10]\n[19,13,26,4,25,11,21]\n2\n
// @lcpr case=end

 */

