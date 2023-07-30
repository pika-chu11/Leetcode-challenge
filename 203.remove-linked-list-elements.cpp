/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prev = nullptr;
        ListNode* walker = head;
        while(!walker->next) {
            if (walker->val == val)
            {
                if(!prev){
                    head = walker->next;
                }

                prev->next = walker->next;
                prev = walker->next;
                delete walker;
                walker = prev->next;
            }
            
        }
        return head;
    }
};
// @lc code=end

