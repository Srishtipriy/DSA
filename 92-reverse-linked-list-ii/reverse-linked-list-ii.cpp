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
    ListNode* reverseLL(ListNode* prev, int count){
        ListNode* curr = prev->next;
        ListNode* temp = NULL;

        for(int i=0; i< count; i++){
            temp = curr->next;
            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }
        return curr;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if( !head  || left == right)        return head;

        ListNode* Dummy = new ListNode(0);
        Dummy->next = head;

        ListNode* prev = Dummy;

        for(int i= 1; i< left; i++){        // Move prev to the node before 'left'
            prev = prev->next;
        }
        reverseLL(prev, right-left);

        return Dummy->next;
    }
};