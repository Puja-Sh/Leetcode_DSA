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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        int n = 0;
        
        while(temp){         // finding length of the Linked List
            n++;
            temp = temp->next;
        }
        
        int endPos = n-k; int startPos = k-1;   // Calculate kth node from the end and from the start
        ListNode* start = head; 
        ListNode* end = head;
        
        while(startPos--){          // Reaching to postion kth from the start
            start = start->next;
        }
        
        while(endPos--){            // Reaching to postion kth from the end
            end = end->next;
        }
        
        swap(start->val, end->val); // After reaching swap the value
        
        return head;
    }
};