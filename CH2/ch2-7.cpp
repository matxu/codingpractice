// Check if a linked list is a palindrome

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
    /**
     * @param head a ListNode
     * @return a boolean
     */
    bool isEqual(ListNode* l1, ListNode* l2) {
        if ( l1 == NULL && l2 == NULL) return true;
        while (l1 != NULL && l2 != NULL){
            if ( l1->val != l2->val ) return false;
            l1 = l1->next; l2 = l2->next;
        }
        if ( l1 != NULL || l2 != NULL) return false;
        return true;
        
    }
    
    bool isPalindrome(ListNode* head) {
        // Write your code here
        // generate a new List which is the reverse of given list
        if ( head == NULL || head -> next == NULL ) return true;
        ListNode* lst2, *p = head -> next, *temp;
        lst2 = new ListNode(head->val);
        
        while ( p != NULL ) {
            temp = new ListNode(p->val);
            temp -> next = lst2;
            lst2 = temp;
            p = p->next; 
        }
        
        return isEqual(lst2, head);
    }
    
};
