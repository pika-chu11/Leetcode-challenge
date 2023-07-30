/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // ListNode * slow = head;
        // ListNode * fast = head;

        // // Stop when the two pointers meet
        // while(fast != nullptr && fast->next != nullptr) {
        //     slow = slow->next;
        //     fast = fast->next->next;

        //     if(fast == slow){
        //         break;
        //     }
        // }

        // // If the fast pointer reached the end of the list, then there is no cycle
        // if (fast == nullptr || fast->next == nullptr) {
        //     return nullptr;
        // }

        // slow = head;

        // while(slow != fast) {
        //     slow = slow->next;
        //     fast = fast->next;
        // }

        // return fast; // or slow, as they are now the same, pointing to the cycle start

        ListNode * fast = head;
        ListNode * slow = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(fast == slow) {
                slow = head;

                while(fast != slow){
                    fast = fast->next;
                    slow = slow->next;
                }

                return fast;
            }
        }

        return nullptr;
    }
};
// @lc code=end

