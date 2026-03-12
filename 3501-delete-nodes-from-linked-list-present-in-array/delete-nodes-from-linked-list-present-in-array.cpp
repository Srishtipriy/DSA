class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end()); // fast lookup
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* temp = dummy;

        while(temp->next != NULL){
            if(st.count(temp->next->val)){
                temp->next = temp->next->next;  
            } else {
                temp = temp->next;             
            }
        }

        return dummy->next;
    }
};