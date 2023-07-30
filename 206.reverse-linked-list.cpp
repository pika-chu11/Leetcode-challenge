/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    //     ListNode * curr = nullptr;
    //     ListNode * prev = head;
    //     while (prev != NULL)
    //     {
    //         if(prev->next != NULL){
    //             ListNode * temp = prev->next;
    //             prev->next = curr;
    //             curr = prev;
    //             prev = temp;   
    //         }
    //         else {
    //             prev->next = curr;
    //             head = prev;
    //             break;
    //         }
    //     }
    //     return head;


    // RETRY:
    ListNode * prev = nullptr;
    ListNode * curr = head;
    ListNode * temp;
    while (curr)
    {
        // Save the next node of curr
        temp = curr->next;
        
        // Change direction
        curr->next = prev;

        // Updated curr and prev
        prev = curr;
        curr = temp;
    }
        return prev;
    }
    
};
// @lc code=end

