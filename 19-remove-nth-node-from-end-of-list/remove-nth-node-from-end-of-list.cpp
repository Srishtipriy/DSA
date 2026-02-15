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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = new ListNode (0);     //start mai yek 0 dummy node hai
        first->next = head;
        ListNode* slow = first;
        ListNode* fast = first;

        //if(head->next == NULL)   return NULL;

        for(int i=0 ; i<=n; i++){           //n+1 times chalega
            fast = fast->next;
        }

        while(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        } 
        slow->next = slow->next->next ;

        return first->next;
    }
};