/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int front = 0, end = nums.size() - 1;
        vector<int> ans(nums.size());
        int i = end;
        while(front <= end) {
            if(abs(nums[front]) < abs(nums[end])) {
                ans[i] = nums[end] * nums[end];
                end--;
            }
            else {
                ans[i] = nums[front] * nums[front];
                front++;
            }
            i--;
        }
        return ans;
    }
};
// @lc code=end

