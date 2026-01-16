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
    ListNode* insertionSortList(ListNode* head) {
       vector<int>res;
        while(head!=NULL){
            res.push_back(head->val);
            head=head->next;
        }

        sort(res.begin(),res.end());
        ListNode * dummy= new ListNode(-1);
        ListNode *temp=dummy;
        
        for(int &a : res){
            temp->next=new ListNode(a);
            temp=temp->next;
        }
        return dummy->next;
    }
};