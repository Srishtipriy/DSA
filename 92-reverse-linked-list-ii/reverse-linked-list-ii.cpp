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
    ListNode* reverseLL(ListNode* prev, ListNode* head , int count){         //reverse LL
        ListNode* preV = nullptr;
        ListNode* curr = head;

        for(int i=0; i < count && curr != nullptr ; i++){
            ListNode* temp = curr->next;   // store next node
            curr->next = preV;             // reverse pointer
            preV = curr;                   // move preV forward
            curr = temp;                   // move curr forward
        }

        // reconnect:
        prev->next = preV;  // new head of reversed segment
        head->next = curr;  // tail connects to the remaining list

        return preV;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if( !head  || left == right)        return head;

        ListNode* Dummy = new ListNode(0);
        Dummy->next = head;

        ListNode* prev = Dummy;

        // Move prev to the node before 'left'
        for(int i= 1; i< left; i++){        
            prev = prev->next;
        }
        //But segment to reverse starts at prev->next, not at the original head
        reverseLL( prev, prev->next, right-left+1 );  

        return Dummy->next;
    }
};