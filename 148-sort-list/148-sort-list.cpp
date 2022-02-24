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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* mid = middleNodeHelper(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        
        return mergeHelper(left, right);
    }
    
    ListNode* middleNodeHelper(ListNode* head){     // find the middle of the node
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* mid = slow->next;
        
        slow->next = NULL;
        
        return mid;
    }
    
    ListNode* mergeHelper(ListNode* node1, ListNode* node2){       // merge sorting using pointer left and right
        ListNode* root = new ListNode(-1);
        ListNode* temp = root;
        
        while(node1 != NULL && node2 != NULL){
            
            if(node1->val <= node2->val){
                temp->next = node1;
                node1 = node1->next;
            } else {
                temp->next = node2;
                node2 = node2->next;
            }      
            
            temp = temp->next;
        }
        
        temp->next = node1 != NULL ? node1 : node2;
       
        return root->next;
    }
};

