### 1️⃣ Question (Problem Statement)

The task is to swap every two adjacent nodes in a given singly linked list. You are required to modify the links of the nodes and return the modified linked list's head. The solution should use constant space (i.e., not use any extra data structures like arrays or stacks).

**Key Notes**:
- Modify only the `next` pointers of the nodes, without altering their `val`.
- If the list has an odd number of nodes, the last node remains unchanged.
- You are given the head of the list, and you must return the new head after performing the swaps.

---

### 2️⃣ Constraints & Observations in Detail

- **Input Size**: The linked list can have up to \(10^6\) nodes, which means the solution must be time-efficient (ideally \(O(n)\)) and space-efficient (i.e., \(O(1)\) space complexity).
- **Edge Case Considerations**:
  - If the list has only one node or is empty, no swapping is required.
  - The list could have an even or odd number of nodes, which means the last node (if there's no pair) remains unchanged.

- **Linked List Properties**:
  - We are given a singly linked list, where each node has two fields: `val` (the value) and `next` (the pointer to the next node).
  - We must avoid using extra space beyond a constant number of pointers. This implies that the solution should modify the linked list in place, without creating any additional structures like arrays or hashmaps.

---

### 3️⃣ Approach & Thought Process

At a glance, the idea is to iterate through the list in pairs. For each pair of adjacent nodes, we will:
1. Swap the two nodes' `next` pointers.
2. Continue with the next pair of adjacent nodes until we've processed the entire list.

**Steps**:
- Use a dummy node that points to the head of the list to simplify edge handling.
- Maintain three pointers:
  - **P**: A pointer to the node before the current pair (initially the dummy node).
  - **f**: The first node of the pair to swap.
  - **s**: The second node of the pair to swap.
- Swap the two nodes' `next` pointers, then move the pointers forward to the next pair of nodes.
- Continue this until you either run out of nodes or find a node with no adjacent node to swap.

---

### 4️⃣ Different Approaches (Brute Force → Optimized)

- **Brute Force**: 
  - One brute force approach could involve using an array to store all nodes and then re-arranging them. However, this approach would use extra space and is inefficient for large lists (O(n) space complexity).
  
- **Optimized (Current Solution)**:
  - This approach works in-place using constant space, and it operates in O(n) time complexity, where n is the number of nodes in the list.
  - We maintain constant space by using only a few pointer variables and performing the swaps by directly manipulating the node `next` pointers.

---

### 5️⃣ Example & Dry Run

**Example 1**:

Input: `A = 1 -> 2 -> 3 -> 4`

- Step 1: Start with the dummy node pointing to the head.
- Step 2: Swap nodes `1` and `2`. The new list is: `2 -> 1 -> 3 -> 4`.
- Step 3: Swap nodes `3` and `4`. The new list is: `2 -> 1 -> 4 -> 3`.
- Return the new list: `2 -> 1 -> 4 -> 3`.

**Example 2**:

Input: `A = 7 -> 2 -> 1`

- Step 1: Start with the dummy node pointing to the head.
- Step 2: Swap nodes `7` and `2`. The new list is: `2 -> 7 -> 1`.
- Step 3: No adjacent node for `1`, so the list remains `2 -> 7 -> 1`.
- Return the new list: `2 -> 7 -> 1`.

---

### 6️⃣ Code (Clean + Commented)

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    // If the list is empty or has only one node, no need to swap
    if (!A || !A->next) return A;
    
    // Create a dummy node to simplify edge case handling
    ListNode *dummy = new ListNode(0);
    dummy->next = A;
    
    // P will point to the node before the current pair
    ListNode *P = dummy, *f = A, *s = A->next;
    
    // Loop through the list in pairs
    while (f && s) {
        // Swap the pair (f, s)
        f->next = s->next;  // f points to the next pair
        s->next = f;        // s becomes the first node in the pair
        P->next = s;        // P now points to the new first node in the pair
        
        // Move P, f, s to the next pair
        P = f;
        f = f->next;
        if (f) s = f->next;   // If f exists, set s to the next node after f
    }
    
    // Return the modified list, starting from the node after dummy
    return dummy->next;
}
```

---

### 7️⃣ TC & SC Analysis (Explained in Detail)

- **Time Complexity**:  
  The algorithm iterates through the list once, and at each step, it processes exactly two nodes (swapping them). Therefore, the time complexity is **O(n)**, where `n` is the number of nodes in the linked list.

- **Space Complexity**:  
  The space complexity is **O(1)** because we are only using a few extra pointers (i.e., constant space) for the algorithm, and no additional data structures are used. The space for the dummy node is constant as well.

---

### 8️⃣ Code Walkthrough (Step-by-Step Execution)

- **Initialization**:  
  The dummy node is initialized with a value of 0 and points to the head of the list. This helps in simplifying the edge cases, such as when the list has only one or two nodes.

- **Main Loop**:  
  We loop through the list with two pointers: `f` (first node) and `s` (second node). If both are valid nodes, we swap them by adjusting their `next` pointers.

- **Swapping**:
  - `f->next = s->next`: This makes `f` point to the node after `s`.
  - `s->next = f`: This makes `s` point to `f`, completing the swap.
  - `P->next = s`: `P` points to the new first node (`s`) in the swapped pair.

- **End Condition**:  
  The loop terminates when there are no more pairs to swap. Finally, the list starting from `dummy->next` is returned.

---

### 9️⃣ Edge Cases, Corner Cases, Important Test Cases

- **Empty list**: Input: `[]`. No pairs to swap, return the list as it is.
- **Single node list**: Input: `[1]`. No pair to swap, return the list as it is.
- **Odd number of nodes**: Input: `[1, 2, 3]`. Swap `1` and `2`, but `3` remains as it is.
- **Even number of nodes**: Input: `[1, 2, 3, 4]`. Swap both pairs: `1` with `2` and `3` with `4`.

---

### 🔟 Mistakes to Avoid

- **Not handling the edge case**: If the list has fewer than two nodes, make sure to return the list as-is.
- **Swapping pointers incorrectly**: Ensure that when swapping, you adjust the `next` pointers correctly for both nodes in the pair.
- **Incorrect pointer movement**: After each swap, make sure to move `P`, `f`, and `s` to the correct next positions.

---

### 1️⃣1️⃣ Related Problems / Concepts / Patterns

- **Linked List Manipulation**: Understanding how to modify linked lists, especially with respect to node pointers, is fundamental.
- **In-Place Swapping**: This problem involves performing operations without using extra space, which is a common pattern in algorithmic problems.
- **Pairwise Swap**: Other problems involve swapping nodes or elements in pairs (e.g., swapping adjacent elements in an array).

---

### 1️⃣2️⃣ Real-World Applications

- **Data Structure Operations**: Linked lists are often used in operating systems, memory management, and in scenarios requiring dynamic memory allocation.
- **Data Stream Processing**: This algorithm is useful in scenarios where elements need to be processed in pairs, such as in streaming algorithms or certain types of buffers.

---

### 1️⃣3️⃣ Explaining to Interviewer

- **Why this Approach**: This is the most space-efficient solution because it operates in constant space while maintaining an O(n) time complexity. By manipulating pointers directly, we achieve the required swaps without using extra space.
- **Alternative Approaches**: A brute force approach would involve copying the list to another structure (e.g., array) and swapping the elements there, but that would require O(n) space.
- **What if the list is



## **Brute Force Approach (Extra Space - Not Allowed)**

### **Concept:**
1. Store all nodes in an array/vector.
2. Swap adjacent nodes in the array.
3. Reconstruct the linked list.

### **Time Complexity:**
- \(O(N)\) (for traversal) + \(O(N)\) (reconstructing) → **\(O(N)\)**

### **Space Complexity:**
- **\(O(N)\)** (extra array storage).

This approach is not allowed as we must use **constant extra space**.

---

## **Optimized Approach (Constant Space & Iterative Solution)**

### **Concept:**
1. Use **three pointers**:
   - `prev` (points to the node before the swapping pair).
   - `first` (points to the first node in the pair).
   - `second` (points to the second node in the pair).
2. Swap the pair:
   - `first->next = second->next`
   - `second->next = first`
   - Adjust previous node’s link.
3. Move forward to the next pair.

### **Time Complexity:**
- **\(O(N)\)** (one pass through the list).

### **Space Complexity:**
- **\(O(1)\)** (no extra space used).

---

### **Optimized Code (Iterative Approach)**

```cpp
ListNode* Solution::swapPairs(ListNode* A) {
    if (!A || !A->next) return A;  // If less than 2 nodes, return as is.

    ListNode *dummy = new ListNode(0); // Dummy node before head.
    dummy->next = A;

    ListNode *prev = dummy, *first = A, *second = A->next;

    while (first && second) {
        // Swapping the adjacent nodes
        first->next = second->next;
        second->next = first;
        prev->next = second;

        // Move to the next pair
        prev = first;
        first = first->next;
        if (first) second = first->next;
    }

    return dummy->next;  // New head is the second node after the swap.
}
```

---

## **Best Approach (Recursive Solution)**

### **Concept:**
1. Swap the first two nodes.
2. Recursively call for the rest of the list.
3. Link the swapped pair with the result of the recursion.

### **Time Complexity:**
- **\(O(N)\)** (each node is visited once).

### **Space Complexity:**
- **\(O(N)\)** (recursive call stack).

---

### **Best Code (Recursive Approach)**

```cpp
ListNode* Solution::swapPairs(ListNode* head) {
    if (!head || !head->next) return head; // Base case: If less than 2 nodes.

    ListNode* first = head;
    ListNode* second = head->next;

    // Swap first and second
    first->next = swapPairs(second->next);
    second->next = first;

    return second;  // New head after swapping.
}
```

---

## **Comparison of Approaches**
| Approach | Time Complexity | Space Complexity | Extra Space? | Iterative/Recursive |
|----------|----------------|------------------|--------------|---------------------|
| **Brute Force (Array)** | \(O(N)\) | \(O(N)\) | Yes | Iterative |
| **Optimized (Iterative)** | \(O(N)\) | \(O(1)\) | No | Iterative |
| **Best (Recursive)** | \(O(N)\) | \(O(N)\) | No (but uses recursion stack) | Recursive |

### **Final Recommendation:**
- **Use the Iterative Approach** for efficiency.
- **Use the Recursive Approach** for a cleaner and elegant solution.

---

### **Key Takeaways:**
1. **Pointer Manipulation is Key**: We must carefully adjust `next` pointers without breaking the linked list.
2. **Iterative vs. Recursive Tradeoff**: Iterative is more space-efficient, while recursion provides cleaner code.
3. **Dummy Nodes Help**: Using a dummy node avoids handling edge cases separately.

Would you like a dry run of the iterative approach for better understanding? 🚀

Let's perform a **dry run** of the iterative swapping approach with examples.

---

### **Example 1: A = 1 → 2**
#### **Initial Linked List:**  
```
1 -> 2
```

#### **Step-by-Step Execution:**
| Step | `p` | `f` (first) | `s` (second) | List Status |
|------|-----|------------|------------|-------------|
| Start | dummy (0) → 1 | 1 | 2 | `0 -> 1 -> 2` |
| Swap `f` and `s` | dummy (0) → **2** → **1** | 1 | 2 | `0 -> 2 -> 1` |
| Move Pointers | `p = 1`, `f = NULL`, `s = NULL` | - | - | No more pairs to swap |

#### **Final Output:**  
```
2 -> 1
```

---

### **Example 2: A = 1 → 2 → 3 → 4 → 5**
#### **Initial Linked List:**  
```
1 -> 2 -> 3 -> 4 -> 5
```

---

#### **Step-by-Step Execution:**

| Step | `p` | `f` (first) | `s` (second) | List Status |
|------|-----|------------|------------|-------------|
| Start | dummy (0) → 1 | 1 | 2 | `0 -> 1 -> 2 -> 3 -> 4 -> 5` |
| Swap `f` and `s` | dummy (0) → **2** → **1** → 3 | 1 | 2 | `0 -> 2 -> 1 -> 3 -> 4 -> 5` |
| Move Pointers | `p = 1`, `f = 3`, `s = 4` | 3 | 4 | `0 -> 2 -> 1 -> 3 -> 4 -> 5` |
| Swap `f` and `s` | `1 -> 4 -> 3 -> 5` | 3 | 4 | `0 -> 2 -> 1 -> 4 -> 3 -> 5` |
| Move Pointers | `p = 3`, `f = 5`, `s = NULL` | 5 | NULL | No more pairs to swap |

#### **Final Output:**  
```
2 -> 1 -> 4 -> 3 -> 5
```

---

### **Key Observations:**
1. **Pairs Are Swapped in Place**: Only the `next` pointers are changed; node values remain the same.
2. **Last Node (Odd Length Case) Stays Unchanged**: If there's a node without a pair (like `5`), it remains as is.
3. **Uses a Dummy Node**: Helps maintain a reference to the new head.

---
### **Clarifying `p` and `dummy` Relationship**
No, `p` and `dummy` are **not the same**, but they are related. Let's break it down step by step.

---

## **1. Are `p` and `dummy` the same?**
- Initially, **yes**, `p` is assigned to `dummy`:
  ```cpp
  ListNode *dummy = new ListNode(0);
  dummy->next = A;
  ListNode *p = dummy;
  ```
  - `dummy` is a new node with value `0`, and its `next` points to the original head `A` (`1`).
  - `p` is initialized to **point at `dummy`**, so at this moment:
    ```
    dummy (0) -> 1 -> 2 -> 3 -> 4 -> 5
    p (0) -> 1 -> 2 -> 3 -> 4 -> 5  (same as dummy initially)
    ```

- Later, **`p` moves forward**, but `dummy` **remains fixed**.
  - `p` moves after each swap to point to the last swapped node.
  - `dummy` **never moves**, ensuring that `dummy->next` always points to the new head.

---

## **2. How does `dummy->next` point to `2`?**
Even though we never explicitly say `dummy->next = 2`, it **happens indirectly** because:
```cpp
p->next = s;  // Here, p (which was initially dummy) now points to 2
```
### **Step-by-Step Breakdown**
1. **Initial setup:**  
   ```
   dummy (0) -> 1 -> 2 -> 3 -> 4 -> 5
   p = dummy, f = 1, s = 2
   ```
2. **Swapping `1` and `2`:**
   ```cpp
   f->next = s->next;  // 1->next = 3
   s->next = f;        // 2->next = 1
   p->next = s;        // dummy->next = 2
   ```
   - Now the linked list becomes:
     ```
     dummy (0) -> 2 -> 1 -> 3 -> 4 -> 5
     ```

   - Since `p` was `dummy`, and we did `p->next = s`, it **automatically** makes `dummy->next = 2`, making `2` the new head.

3. **Updating `p` (Moving Forward)**
   ```cpp
   p = f;  // p = 1 (end of swapped pair)
   ```
   - This ensures that in the next iteration, we correctly link `1` to the next swapped pair (`4 -> 3`).

---

## **3. Is `dummy` ever updated?**
**No**, `dummy` remains fixed at the start of the list:
```
dummy (0) -> 2 -> 1 -> 4 -> 3 -> 5
```
At the end, we return:
```cpp
return dummy->next;
```
which correctly gives `2 -> 1 -> 4 -> 3 -> 5`.

---

## **Final Answer**
✅ **`dummy` and `p` are initially the same, but `p` moves forward while `dummy` remains fixed**.  
✅ **`dummy->next` points to `2` because we updated `p->next = s`, and `p` was pointing at `dummy` initially**.  
✅ **Returning `dummy->next` ensures that we always return the new swapped head**.
