/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start

#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int head_ind = 0, tail_ind = nums.size() - 1;
        int mid_ind = tail_ind/2;


        while (head_ind <= tail_ind) {
            if (nums[mid_ind] == target) {
                return mid_ind;
            }
            else if (nums[mid_ind] > target) {
                tail_ind = mid_ind - 1;
            }
            else {
                head_ind = mid_ind + 1;
            }
            mid_ind = (head_ind + tail_ind) /2;
        }
        return -1;
    };
};


int main() {
    Solution sln;
    vector<int> test{2,5};
    cout << sln.search(test, 5) << endl;
}
// @lc code=end

