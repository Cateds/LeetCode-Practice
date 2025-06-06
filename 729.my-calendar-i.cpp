/*
 * @lc app=leetcode.cn id=729 lang=cpp
 * @lcpr version=30204
 *
 * [729] 我的日程安排表 I
 *
 * https://leetcode.cn/problems/my-calendar-i/description/
 *
 * algorithms
 * Medium (58.26%)
 * Likes:    304
 * Dislikes: 0
 * Total Accepted:    59.2K
 * Total Submissions: 101.4K
 * Testcase Example:  '["MyCalendar","book","book","book"]\n[[],[10,20],[15,25],[20,30]]'
 *
 * 实现一个 MyCalendar 类来存放你的日程安排。如果要添加的日程安排不会造成 重复预订 ，则可以存储这个新的日程安排。
 * 
 * 当两个日程安排有一些时间上的交叉时（例如两个日程安排都在同一时间内），就会产生 重复预订 。
 * 
 * 日程可以用一对整数 startTime 和 endTime 表示，这里的时间是半开区间，即 [startTime, endTime), 实数 x
 * 的范围为，  startTime <= x < endTime 。
 * 
 * 实现 MyCalendar 类：
 * 
 * 
 * MyCalendar() 初始化日历对象。
 * boolean book(int startTime, int endTime) 如果可以将日程安排成功添加到日历中而不会导致重复预订，返回 true
 * 。否则，返回 false 并且不要将该日程安排添加到日历中。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：
 * ["MyCalendar", "book", "book", "book"]
 * [[], [10, 20], [15, 25], [20, 30]]
 * 输出：
 * [null, true, false, true]
 * 
 * 解释：
 * MyCalendar myCalendar = new MyCalendar();
 * myCalendar.book(10, 20); // return True
 * myCalendar.book(15, 25); // return False ，这个日程安排不能添加到日历中，因为时间 15
 * 已经被另一个日程安排预订了。
 * myCalendar.book(20, 30); // return True ，这个日程安排可以添加到日历中，因为第一个日程安排预订的每个时间都小于
 * 20 ，且不包含时间 20 。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= start < end <= 10^9
 * 每个测试用例，调用 book 方法的次数最多不超过 1000 次。
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
#include <map>
#include <set>
// @lcpr-template-end
// @lc code=start
class MyCalendar {
    set<pair<int, int>> booked;

public:
    bool book(int start, int end) {
        auto it = booked.lower_bound({end, 0});
        if (it == booked.begin() || (--it)->second <= start) {
            booked.emplace(start, end);
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
// @lc code=end



/*
// @lcpr case=start
// ["MyCalendar", "book", "book", "book"][[], [10, 20], [15, 25], [20, 30]]\n
// @lcpr case=end

 */

