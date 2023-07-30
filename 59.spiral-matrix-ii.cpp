/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // A vector of n:
        // each element contains a vector of n with initialization of 0
        // 2D array
        vector<vector<int>> ans(n, vector<int>(n,0));
        // limit the edges for:
        // 1. left to right
        // 2. top to bottom
        int offset = 0; // limit the edges

        // 3. for right to left
        // 4. bottom to top
        int left = 0, top = 0;

        // determine how many complete loop we need to done
        int loop = n/2;

        // determine the middle count if n == ODD
        int mid = n/2;

        // numbers need to fill
        int num = 1; 

        int i,j; // keep track so that find the right pos

        while (loop --) // while current loop > 0
        {
            // left to right (左闭右开)
            for (i = left; i < n - offset; i++) {
                ans[top][i] = num++; // i.e. ans[top][i] = num; num++;
            }

            // top to bottom (左闭右开)
            for (j = top; j < n - offset; j++) {
                ans[j][i] = num++;
            }

            // right to left
            for (; i > left; i--) {
                ans[j][i] = num++;
            }

            // bottom to top
            for (; j > top; j--) {
                ans[j][i] = num++;
            }

            top++;
            left++;
            offset++;
        }

        // if n == ODD
        // fill the middle space manually
        if (n % 2) {
            ans[mid][mid] = num;
        }
        
        return ans;

    }
};
// @lc code=end

