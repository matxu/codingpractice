// Design a stack that can return min value in O(1) time

// Use LinkedList
class myStack{

   void push(int val){
      if ( size == 0 ) {
          top = new ListNode(val);
          minList = new ListNode(val);
          size++;
      }else {
          ListNode *temp = new ListNode(val);
          temp->next = top;
          top = temp;
          size++;
          if (val <= minList->val){
             temp = new ListNode(val);
             temp->next = minList;
             minList = temp;
          }
      }
   }
   
   ListNode* pop(){
       if ( size == 0 ) return nullptr; // does not exist
       ListNode* poptop = top;
       top = top->next;
       if ( poptop->val ==minList->val ) {
          minList = mintList->val;
       }
   }
   
   int min(){
      if ( size == 0 ) return NULL;
      return minList->val;
   }
   
  private:
   int size;
   Node *top;
   Node *minList;
}
