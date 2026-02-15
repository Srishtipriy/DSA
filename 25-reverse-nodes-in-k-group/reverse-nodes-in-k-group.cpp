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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL)    return NULL;

        //checking if enough k nodes hai
        int count = 0;
        ListNode* temp = head;
        while(temp != NULL && count <= k){
            temp = temp->next;
            count ++;
        }
        if(count < k)   return head;        //agar chota ho k size se 

        //actual reversal logic
        ListNode* prev = NULL;              
        ListNode* curr = head;
        ListNode* forward = NULL;
        count =0;        //wapis 0 kiya actual reversal karne ke liye

        while(curr != NULL && count < k){

            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            count++;
        } 

        //recursion on next all
        if(forward != NULL)
            head-> next = reverseKGroup(forward , k);

        //return head
        return prev;
    }
};