# Module 01: Linked Lists

This folder contains the foundation of the library: Singly and Doubly Linked Lists. These structures are used as the base for more complex implementations like Stacks and Queues.

## Singly Linked List
A basic one-way chain of nodes. Each node contains data and a pointer to the next element. It is highly efficient for adding or removing items from the head of the list.



* **Insert at Head**: $O(1)$.
* **Search/Traversal**: $O(n)$ because we must start from the head.
* **Memory**: Efficient (only stores one pointer per node).

## Doubly Linked List
A two-way chain where each node points to both the next and the previous element. This makes it much easier to traverse backward or delete a node if you already have a pointer to it.



* **Insert at Head**: $O(1)$.
* **Backward Traversal**: Possible via the `prev` pointer.
* **Memory**: Slightly higher usage (stores two pointers per node).

---

## Compilation

To test both implementations, compile the source files together with the driver program:

```bash
gcc singly.c doubly.c main.c -o list_test
