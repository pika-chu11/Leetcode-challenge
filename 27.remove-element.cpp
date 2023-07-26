/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()) return 0;
        int tail = nums.size() - 1;
        int iter = 0; // iterate through the vector
        while(iter < tail) {
            if (nums[iter] == val) {
                nums[iter] = nums[tail];
                tail -= 1;
            }else{
                iter++;
            }
        }
        if (nums[tail] == val) {
            nums.pop_back();
            return iter;
        }
        return iter+1;
    }
};
// @lc code=end

