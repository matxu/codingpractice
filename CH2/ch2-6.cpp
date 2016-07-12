// Detect loop in linked list and return the beginning of the loop

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The node where the cycle begins. 
     *           if there is no cycle, return null
     */
    ListNode *detectCycle(ListNode *head) {
        // write your code here
        if ( head == NULL || head->next == NULL)
            return NULL;
        ListNode *slow = head, *fast = head;
        // slow goes 1x, fast goes 2x

        while (true) {
            slow = slow->next;
            fast = fast->next;
            if (fast == NULL || fast->next == NULL) return NULL;
            fast = fast->next;
            if (fast == NULL || fast->next == NULL) return NULL;
            if (slow == fast) break;
        }
        
      
        //else: fast and slow meets in cycle
        //Now, position slow to head and goes 1x
        slow = head;
        while (slow != fast) {
            slow = slow -> next;
            fast = fast -> next;
        }
        
        return slow;
        
    }
};


