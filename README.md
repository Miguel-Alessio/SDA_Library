# SDA Library (C)

A collection of data structures and algorithms implemented in C. This project is a personal library focused on low-level memory management and pointer logic.

## 1. Stack (LIFO)
The current module is a **Linked List-based Stack**. Unlike a fixed-size array stack, this implementation uses dynamic allocation to handle variable data sizes.

### Technical Details
* **Memory Management:** Manual allocation via `malloc` and `free`.
* **Safety:** Includes input buffer clearing and null-pointer checks to prevent segmentation faults during pop operations.
* **Complexity:**
  * Push: $O(1)$
  * Pop: $O(1)$
  * Peek: $O(1)$



## 2. Usage

### Compilation
Build the project using `gcc`:
```bash
gcc main.c -o sda_stack
