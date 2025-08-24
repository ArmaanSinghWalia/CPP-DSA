### STACK IMPLEMENTATION IN ARRAYS ###

### IMPORTANT POINTS ###

1) Top pointer/index → Keep an integer top that tracks the current top element’s index.
2) Dynamic array → Use new to allocate the array, and delete[] to free it.
3) Push operation → Insert element at arr[++top].
4) Pop operation → Return arr[top--].

### PRECAUTIONS ###

1) Overflow → occurs when you try to push onto a full stack.
2) Underflow → occurs when you try to pop from an empty stack.









