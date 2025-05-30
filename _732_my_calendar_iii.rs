/*
* @lc app=leetcode.cn id=732 lang=rust
* @lcpr version=30204
*
* [732] 我的日程安排表 III
*
* https://leetcode.cn/problems/my-calendar-iii/description/
*
* algorithms
* Hard (70.29%)
* Likes:    230
* Dislikes: 0
* Total Accepted:    28.9K
* Total Submissions: 41.1K
* Testcase Example:  '["MyCalendarThree","book","book","book","book","book","book"]\n' +
 '[[],[10,20],[50,60],[10,40],[5,15],[5,10],[25,55]]'
*
* 当 k 个日程存在一些非空交集时（即, k 个日程包含了一些相同时间），就会产生 k 次预订。
*
* 给你一些日程安排 [startTime, endTime) ，请你在每个日程安排添加后，返回一个整数 k ，表示所有先前日程安排会产生的最大 k
* 次预订。
*
* 实现一个 MyCalendarThree 类来存放你的日程安排，你可以一直添加新的日程安排。
*
*
* MyCalendarThree() 初始化对象。
* int book(int startTime, int endTime) 返回一个整数 k ，表示日历中存在的 k 次预订的最大值。
*
*
*
*
* 示例：
*
* 输入：
* ["MyCalendarThree", "book", "book", "book", "book", "book", "book"]
* [[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]
* 输出：
* [null, 1, 1, 2, 3, 3, 3]
*
* 解释：
* MyCalendarThree myCalendarThree = new MyCalendarThree();
* myCalendarThree.book(10, 20); // 返回 1 ，第一个日程安排可以预订并且不存在相交，所以最大 k 次预订是 1 次预订。
* myCalendarThree.book(50, 60); // 返回 1 ，第二个日程安排可以预订并且不存在相交，所以最大 k 次预订是 1 次预订。
* myCalendarThree.book(10, 40); // 返回 2 ，第三个日程安排 [10, 40) 与第一个日程安排相交，所以最大 k
* 次预订是 2 次预订。
* myCalendarThree.book(5, 15); // 返回 3 ，剩下的日程安排的最大 k 次预订是 3 次预订。
* myCalendarThree.book(5, 10); // 返回 3
* myCalendarThree.book(25, 55); // 返回 3
*
*
*
*
* 提示：
*
*
* 0 <= startTime < endTime <= 10^9
* 每个测试用例，调用 book 函数最多不超过 400次
*
*
*/

// @lcpr-template-start
/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * let obj = MyCalendarThree::new();
 * let ret_1: i32 = obj.book(startTime, endTime);
 */
#[allow(dead_code)]
pub struct Solution;
// @lcpr-template-end
// @lc code=start
use std::collections::BTreeMap;
use std::cmp::max;
struct MyCalendarThree {
    cnt: BTreeMap<i32, i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
#[allow(dead_code)]
impl MyCalendarThree {
    fn new() -> Self {
        return MyCalendarThree {
            cnt: BTreeMap::new(),
        };
    }

    fn book(&mut self, start_time: i32, end_time: i32) -> i32 {
        let mut ans = 0;
        let mut max_book = 0;
        self.cnt
            .entry(start_time)
            .and_modify(|val| *val += 1)
            .or_insert(1);
        self.cnt
            .entry(end_time)
            .and_modify(|val| *val -= 1)
            .or_insert(-1);
        for (_, val) in self.cnt.iter() {
            max_book += val;
            ans = max(ans, max_book);
        }
        return ans;
    }
}

// @lc code=end

/*
// @lcpr case=start
// ["MyCalendarThree", "book", "book", "book", "book", "book", "book"][[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]\n
// @lcpr case=end

 */
