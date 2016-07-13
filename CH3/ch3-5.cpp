// Implement queue using two stacks

class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {
        // do intialization if necessary
        
    }

    void push(int element) {
        // write your code here
        stack1.push(element);
    }
    
    int pop() {
        // write your code here
        
       // if ( stack1.empty()) return NULL;
        if ( !stack2.empty()) {
            int val = stack2.top();
            stack2.pop();
            return val;
        }
        
        //If stack2 is empty, pop everything from s1 to s2
        int temp;
        while ( !stack1.empty()){
            temp = stack1.top();
            stack1.pop();
            stack2.push(temp);
        }
        
        // return top of s2 (first element in)
        int val = stack2.top();
        stack2.pop();

        return val;
        
        
    }

    int top() {
        // write your code here
       // if ( stack1.empty()) return NULL;
        
        if ( !stack2.empty()) {
            int val = stack2.top();
            return val;
        }
        
        //If stack2 is empty, pop everything from s1 to s2
        int temp;
        while ( !stack1.empty()){
            temp = stack1.top();
            stack1.pop();
            stack2.push(temp);
        }
        
        // return top of s2 (first element in)
        int val = stack2.top();

        return val;
    }
    


};
