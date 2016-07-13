// Sort a stack in ascending order (biggest on top). Can use an additional stack.


// sort stack s in ascending order: biggest on top
void sort(Stack* s){
    Stack buffer;
    int min , n = s->size, step=1;

    // initialize min to be the top of s, push elements to buffer and update min.
    int temp;
    while ( n > 0 ){
        min = s->pop();
        step=1;
        while (step<n ){
        temp = s->pop();
        if (temp < min){
            buffer.push(min);
            min = temp;
        }else {
            buffer.push(temp);
        }
            step++;
        }
        
        s->push(min);
        
        while (buffer.size > 0){
            temp = buffer.pop();
            s->push(temp);
        }
        
        n--;
    }
    
}


int main(int argc, const char * argv[]) {
    
    vector<int> vals={1,2,3,3,4,4,5};
    
    Stack s1;

    for( int i = 0;i<vals.size(); i++)
        s1.push(vals[i]);
    
    sort(&s1);
  

   
    return 0;
}
