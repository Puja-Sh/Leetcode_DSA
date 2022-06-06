/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA=0,lenB=0;
        ListNode *pointA = headA, *pointB=headB;
        ListNode* ans = NULL;
        while(pointA != NULL ) {
            lenA++;
            pointA = pointA->next;
        }
        while(pointB != NULL) {
            lenB++;
            pointB=pointB->next;
        }

        while(lenB > lenA) {
            headB=headB->next; lenB--;
            
        }
        while( lenA > lenB){
            headA = headA->next; lenA--;
            
        }
    
        while(headA!= NULL  && headB!= NULL){
           
            if(headA == headB){
                ans = headA;
                break;
            }
            headA = headA->next;
            headB = headB->next;
        }
        
        return ans;
    }
};