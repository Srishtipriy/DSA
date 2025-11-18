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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        // Create dummy node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        // Step 1: Move `prev` to the node before `left`
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // Step 2: Start reversing between left and right
        ListNode* curr = prev->next;
        ListNode* next = nullptr;

        for (int i = 0; i < right - left; i++) {
            next = curr->next;                //stores value 3
            curr->next = next->next;          // 2 connects to 4 and no. 3 is deteached floats
            next->next = prev->next;          //connect 3 before 2
            prev->next = next;                //move prev to 3 
        }

        // Step 3: Return the updated head      curr still at 2
        return dummy->next;
    }
};

/*   inside for loop    curr->next = next->next;  
                        1 → 2 → 4 → 5
                        next->next = prev->next;
                        3 → 2 → 4 → 5
                        prev->next = next;
                        1 → 3 → 2 → 4 → 5
                                ↑
                               curr (still at 2)
    iteration 2:
                        prev
                        ↓
                        1 → 3 → 2 → 4 → 5
                                ↑
                                curr
                        next = curr->next = 4
                        detach next : 2 → 5
                        insert 4 after prev: 1 → 4 → 3 → 2 → 5     */