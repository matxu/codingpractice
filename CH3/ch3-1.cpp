// Describe how you would use a single array to implement three stacks.

/*Method 1: equal capacity
Assign capacity of each stack to be one-third of the capacity (size) of the array arr
The beginning of each stack will be int start[3] = { arr[0], arr[size*1/3-1], arr[size*2/3-1]}
The size of each stack will be int stack_size[3]
'push(i)' will check if stack_size[i] == 1/3*size. If so, push will be rejected. 
Otherwise, stack_size[i]++, and arr[start[i]+stack_size[i]-1]=new value
'Pop(i)' will check if stack_size[i] == 1, if so, pop will be rejected. 
Otherwise, return arr[start[i]+stack_size[i]-1], and stack_size[i]--
'Top(i)' returns arr[start[i]+stack_size[i]-1]
*/

/*Method 2: Flexible capacity
Start with equal capacity. 
When one stack size = 1/3 of size and a push operation occurs, move everything back one step if there are vacancy.
*/
