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
        //ListNode* dummy = new ListNode(0);            //isse start head automatic cover ho jayega
        //dummy->next = head;
        ListNode* temp = head;

        while(head != NULL && head->val == val)         //start node pe val ho
            head = head->next;  

        while(temp != NULL && temp->next != NULL){      //lastnode cover h last it 5 tak hoga temp->next != NULL
            if(temp->next->val == val){
                temp->next = temp->next->next;
            }
            else{
                temp = temp->next;
            }
        }
        return head;
    }
};