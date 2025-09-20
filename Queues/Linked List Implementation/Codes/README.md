### operations implemented ###

1) Enqueue (add element to rear)

2) Dequeue (remove element from front)

3) Peek (view front element)

4) Display (print all elements)

5) Count (number of elements)

6) SearchFor (search for a value)

7) DeleteQueue (delete all elements)
   

### Current caveats / honesty corner ###

The front and rear pointers are part of the Node class instead of a dedicated Queue class.

Conceptually, I think this is not ideal for multiple queues or if we want a clean separation for readability and reusability.


### Next steps ###

I plan to refactor this code into a “perfect” version with a dedicated Queue class while keeping all functionality intact.

This improved version will handle edge cases robustly and follow professional design practices.

For now, this code works for a single queue and demonstrates all core queue operations in a linked list context.
