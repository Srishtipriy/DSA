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
 //Let's say next pair node ( =npn )
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
    if(head == NULL || head->next == NULL)    return head;
        
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* prev = dummy;
    while(prev->next != NULL && prev->next->next != NULL){
        ListNode* curr = prev->next;        //first node
        ListNode* forward = curr->next;     //second node

        //swapp
        curr->next = forward->next;    // 1-> connected to 3 .........jo 4 ban jayega
        forward->next = curr;          //2-> connected to  1
        prev->next = forward;          //0-> connected to  2

        prev = curr;  //prev moved forwarded to curr 
    }
    return dummy->next;     //jo head hoga
    }
};