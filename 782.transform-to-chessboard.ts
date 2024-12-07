/*
 * @lc app=leetcode.cn id=782 lang=typescript
 * @lcpr version=30204
 *
 * [782] 变为棋盘
 *
 * https://leetcode.cn/problems/transform-to-chessboard/description/
 *
 * algorithms
 * Hard (59.18%)
 * Likes:    185
 * Dislikes: 0
 * Total Accepted:    14.8K
 * Total Submissions: 24.9K
 * Testcase Example:  '[[0,1,1,0],[0,1,1,0],[1,0,0,1],[1,0,0,1]]'
 *
 * 一个 n x n 的二维网络 board 仅由 0 和 1 组成 。每次移动，你能交换任意两列或是两行的位置。
 * 
 * 返回 将这个矩阵变为  “棋盘”  所需的最小移动次数 。如果不存在可行的变换，输出 -1。
 * 
 * “棋盘” 是指任意一格的上下左右四个方向的值均与本身不同的矩阵。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 
 * 输入: board = [[0,1,1,0],[0,1,1,0],[1,0,0,1],[1,0,0,1]]
 * 输出: 2
 * 解释:一种可行的变换方式如下，从左到右：
 * 第一次移动交换了第一列和第二列。
 * 第二次移动交换了第二行和第三行。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 
 * 输入: board = [[0, 1], [1, 0]]
 * 输出: 0
 * 解释: 注意左上角的格值为0时也是合法的棋盘，也是合法的棋盘.
 * 
 * 
 * 示例 3:
 * 
 * 
 * 
 * 输入: board = [[1, 0], [1, 0]]
 * 输出: -1
 * 解释: 任意的变换都不能使这个输入变为合法的棋盘。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == board.length
 * n == board[i].length
 * 2 <= n <= 30
 * board[i][j] 将只包含 0或 1
 * 
 * 
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
function movesToChessboard(board: number[][]): number {
    let n = board.length;
    let tmp_row = 0, tmp_cnt = 0;
    let row = [0,0], num = [1,0];
    let col = 0;
    for (let i=0; i<n; i++) {
        if (!board[0][i]) continue;
        tmp_row |= 0b1 << i;
        tmp_cnt += 1;
    }
    if (tmp_cnt != Math.floor(n/2) && tmp_cnt != Math.floor((n+1)/2))
        return -1;
    row[0] = tmp_row;
    row[1] = ~row[0] & ((0b1<<n) - 1);
    for (let r=1; r<n; r++) {
        tmp_row = 0; tmp_cnt = 0;
        for (let c=0; c<n; c++) {
            if (!board[r][c])
                continue;
            tmp_row |= 0b1 << c;
            tmp_cnt ++;
        }
        if (tmp_cnt != Math.floor(n/2) && tmp_cnt != Math.floor((n+1)/2))
            return -1;
        if (tmp_row == row[0])
            num[0] ++;
        else if (tmp_row == row[1]) {
            num[1] ++;
            col |= 0b1 << r;
        } else return -1;
    }
    if (Math.abs(num[0]-num[1])>1)
        return -1;
    let mask = 0xAAAAAAAA & ((0b1<<n)-1);
    function popcount(n: number): number {
        let count = 0;
        while (n !== 0) {
            count += n & 1;
            n >>>= 1;
        }
        return count;
    }
    let n1 = popcount(col^mask), n2 = popcount(row[0]^mask);
    if (n&0b1)
        return (((n1 & 0b1)?(n-n1):n1) + ((n2&0b1)?(n-n2):n2))/2;
    else
        return (Math.min(n1,n-n1)+Math.min(n2,n-n2))/2;

};
// @lc code=end



/*
// @lcpr case=start
// [[0,1,1,0],[0,1,1,0],[1,0,0,1],[1,0,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0, 1], [1, 0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1, 0], [1, 0]]\n
// @lcpr case=end

 */

