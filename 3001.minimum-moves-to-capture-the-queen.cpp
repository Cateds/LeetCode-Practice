/*
 * @lc app=leetcode.cn id=3001 lang=cpp
 * @lcpr version=30204
 *
 * [3001] 捕获黑皇后需要的最少移动次数
 *
 * https://leetcode.cn/problems/minimum-moves-to-capture-the-queen/description/
 *
 * algorithms
 * Medium (21.79%)
 * Likes:    8
 * Dislikes: 0
 * Total Accepted:    4.3K
 * Total Submissions: 19.4K
 * Testcase Example:  '1\n1\n8\n8\n2\n3'
 *
 * 现有一个下标从 1 开始的 8 x 8 棋盘，上面有 3 枚棋子。
 *
 * 给你 6 个整数 a 、b 、c 、d 、e 和 f ，其中：
 *
 *
 * (a, b) 表示白色车的位置。
 * (c, d) 表示白色象的位置。
 * (e, f) 表示黑皇后的位置。
 *
 *
 * 假定你只能移动白色棋子，返回捕获黑皇后所需的最少移动次数。
 *
 * 请注意：
 *
 *
 * 车可以向垂直或水平方向移动任意数量的格子，但不能跳过其他棋子。
 * 象可以沿对角线方向移动任意数量的格子，但不能跳过其他棋子。
 * 如果车或象能移向皇后所在的格子，则认为它们可以捕获皇后。
 * 皇后不能移动。
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：a = 1, b = 1, c = 8, d = 8, e = 2, f = 3
 * 输出：2
 * 解释：将白色车先移动到 (1, 3) ，然后移动到 (2, 3) 来捕获黑皇后，共需移动 2 次。
 * 由于起始时没有任何棋子正在攻击黑皇后，要想捕获黑皇后，移动次数不可能少于 2 次。
 *
 *
 * 示例 2：
 *
 * 输入：a = 5, b = 3, c = 3, d = 4, e = 5, f = 2
 * 输出：1
 * 解释：可以通过以下任一方式移动 1 次捕获黑皇后：
 * - 将白色车移动到 (5, 2) 。
 * - 将白色象移动到 (5, 2) 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= a, b, c, d, e, f <= 8
 * 两枚棋子不会同时出现在同一个格子上。
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
    int minMovesToCaptureTheQueen(int &x1, int &y1,
                                  int &x2, int &y2,
                                  int &xt, int &yt) {
        if (x1==xt and
            (x2!=xt or x2==xt and (y2-y1)*(y2-yt)>0) or
            y1==yt and
            (y2!=yt or y2==yt and (x2-x1)*(x2-xt)>0))
            return 1;
        if (xt-x2==yt-y2 and
            (xt-x1!=yt-y1 or xt-x1==yt-y1 and (x1-xt)*(x1-x2)>0) or
            x2-xt==yt-y2 and
            (x1-xt!=yt-y1 or x1-xt==yt-y1 and (x1-xt)*(x1-x2)>0))
            return 1;
        return 2;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 1\n1\n8\n8\n2\n3\n
// @lcpr case=end

// @lcpr case=start
// 5\n3\n3\n4\n5\n2\n
// @lcpr case=end

// @lcpr case=start
//4\n3\n3\n4\n5\n2\n
// @lcpr case=end

// @lcpr case=start
//5\n8\n8\n8\n1\n8\n
// @lcpr case=end
 */
