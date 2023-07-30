/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_length = INT32_MAX;
        int i = 0; // start index
        int length, sum = 0;

        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];

            while(sum >= target) { // move the start index
                length = j - i + 1;

                // Update mini. length: min(min_length, length)
                min_length = min_length > length? length : min_length;

                // Update start index
                sum -= nums[i];
                i++;
            }

            return min_length == INT32_MAX? 0 : min_length; 
        }

    }
};
// @lc code=end

