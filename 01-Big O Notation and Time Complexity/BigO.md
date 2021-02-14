# Big O Notation
The **question** we ask is: **How does algorithm speed scale when input becomes very large?**

Big O Notation gives us an upper bound to functions.

* **O(1)** - "Constant time". Meaning that the runtime of the algorithm stays the same regardless of the input size. 

Example: Getting an element from an array by index requires constant time.

* **O(logN)** - "Logarithmic time"

When talking about logarithms we ask the question: What must I power my base (of 2) by to get N? Here halving is the key!

Example: Binary search, *Balanced* BST traversal.

* **O(N)** - "Linear time"

* **O(N*logN)**

Example: Merge sort - for all logN levels (when halving) we will be working with all N elements.

* **O(N^2)** "N-squared"

Example: Usually naive solutions like Bubble sort.

For a better understanding check out this video https://youtu.be/waPQP2TDOGE.