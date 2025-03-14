## **🟢 Problem Statement**

We are given a **read-only array** of `n+1` integers, where each integer is between `1` and `n`.  
Our goal is to **find one repeating number** in:

- **O(n) time complexity**
- **Less than O(n) space complexity**
- **Traversing the stream sequentially O(1) times**

📌 **If multiple numbers repeat, return any one. If no duplicate exists, return `-1`.**

---

## **🔴 Constraints & Observations**

1️⃣ **Array Size**: `1 ≤ |A| ≤ 10⁵` → The array contains `n+1` elements.  
2️⃣ **Element Range**: `1 ≤ A[i] ≤ |A|` → Each value falls within `1` to `n`.  
3️⃣ **Read-Only**: We **cannot modify** the array.  
4️⃣ **Duplicates Exist**: Since we have `n+1` numbers but only `n` unique values, at least one duplicate **must exist** (Pigeonhole Principle).  
5️⃣ **Space Constraint**: We **cannot** use extra space **beyond O(1)**.  
6️⃣ **Single Pass Constraint**: We should find a solution that does **not traverse more than once in a brute force way**.

🔎 **Key Observations**

- Since the array is **read-only**, we **cannot modify it** (e.g., sorting).
- Since `n+1` numbers are in `1` to `n`, a **cycle must exist** if we treat it like a linked list (Floyd's Cycle Detection).
- We need an **O(n) time** solution with **O(1) space**.

---

## **🟡 Approach & Thought Process**

1️⃣ **Brute Force:** Check each number against every other (`O(n²)`). Too slow! ❌  
2️⃣ **Hash Set:** Track seen numbers (`O(n) time, O(n) space`). **Extra space not allowed!** ❌  
3️⃣ **Sorting:** Sort the array (`O(n log n)`). **Not allowed (modifies array)!** ❌  
4️⃣ **Binary Search on Value Range:** Use **counting approach** (`O(n log n), O(1)`). Works ✅  
5️⃣ **Floyd’s Cycle Detection Algorithm:** Treat as a **linked list cycle problem** (`O(n), O(1)`). **Best Approach!** ✅

---

## **🟠 Different Approaches (Brute Force → Optimized)**

### **1️⃣ Brute Force Approach (O(n²), O(1)) ❌**

🔹 Compare each element with every other element.  
🔹 **Time Complexity:** `O(n²)`  
🔹 **Space Complexity:** `O(1)`

💻 **Code**

```cpp
int findDuplicate(const vector<int> &A) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] == A[j]) return A[i];
        }
    }
    return -1;
}
```

🚨 **Too slow for large inputs!**

---

### **2️⃣ Hash Set Approach (O(n), O(n)) ❌**

🔹 Store seen elements in a `set`.  
🔹 **Time Complexity:** `O(n)`  
🔹 **Space Complexity:** `O(n)`

💻 **Code**

```cpp
int findDuplicate(const vector<int> &A) {
    unordered_set<int> seen;
    for (int num : A) {
        if (seen.count(num)) return num;
        seen.insert(num);
    }
    return -1;
}
```

🚨 **Not allowed due to extra space!**

---

### **3️⃣ Binary Search on Value Range (O(n log n), O(1)) ✅**

🔹 **Idea**: Instead of searching in indices, search in value **range `[1, n]`**.  
🔹 **Count elements ≤ mid**, adjust range accordingly.  
🔹 **Time Complexity:** `O(n log n)`  
🔹 **Space Complexity:** `O(1)`.

💻 **Code**

```cpp
int findDuplicate(const vector<int> &A) {
    int low = 1, high = A.size() - 1;

    while (low < high) {
        int mid = (low + high) / 2;
        int count = 0;

        for (int num : A)
            if (num <= mid) count++;

        if (count > mid)
            high = mid;  // Duplicate is in lower half
        else
            low = mid + 1; // Duplicate is in upper half
    }

    return low;
}
```

✅ **Works but slower than Floyd’s algorithm.**

---

### **4️⃣ Floyd’s Cycle Detection (O(n), O(1)) ✅ Best Approach**

🔹 Treat numbers as **pointers (like a linked list)**.  
🔹 **Phase 1:** Detect cycle using **Tortoise and Hare** (slow-fast pointers).  
🔹 **Phase 2:** Reset `slow` to start and move both pointers one step at a time until they meet at the duplicate.  
🔹 **Time Complexity:** `O(n)`  
🔹 **Space Complexity:** `O(1)`

💻 **Code**

```cpp
int findDuplicate(const vector<int> &A) {
    int slow = A[0], fast = A[0];

    // Phase 1: Detect Cycle
    do {
        slow = A[slow];
        fast = A[A[fast]];
    } while (slow != fast);

    // Phase 2: Find Entry Point (Duplicate)
    slow = A[0];
    while (slow != fast) {
        slow = A[slow];
        fast = A[fast];
    }

    return slow;
}
```

✅ **Best solution!**

---

## **🔵 Time & Space Complexity Analysis**

| Approach                    | Time Complexity | Space Complexity | Notes                    |
| --------------------------- | --------------- | ---------------- | ------------------------ |
| **Brute Force**             | `O(n²)`         | `O(1)`           | Too slow 🚫              |
| **Hash Set**                | `O(n)`          | `O(n)`           | Uses extra space 🚫      |
| **Binary Search**           | `O(n log n)`    | `O(1)`           | Works but slower ✅      |
| **Floyd’s Cycle Detection** | `O(n)`          | `O(1)`           | **Best Approach!** 🚀 ✅ |

---

## **🟣 Edge Cases & Important Test Cases**

✅ **Smallest Input:** `[1,1]`  
✅ **All Elements Unique:** `[1,2,3]` → Should return `-1`  
✅ **Multiple Duplicates:** `[3,4,1,4,1]` → Any duplicate is fine  
✅ **Large Input:** `10⁵` elements to check efficiency

---

## **🔶 Mistakes to Avoid**

🚨 **Using extra space (`O(n)`)** → Not allowed!  
🚨 **Sorting (`O(n log n)`)** → Modifies array, not allowed!  
🚨 **Not handling multiple duplicates correctly**

---

## **🔷 Related Problems / Concepts**

✅ **Cycle Detection in Linked Lists**  
✅ **Finding Missing Number (XOR trick)**  
✅ **Finding Two Duplicates (Math / Set Approach)**

---

## **🔶 Real-World Applications**

- **Data Validation:** Finding duplicate records in large databases.
- **Memory Management:** Detecting memory leaks in systems.
- **Cycle Detection:** Detecting fraud in banking transactions.

---

## **🟢 Explaining to the Interviewer**

👨‍💻 **Why Floyd’s Algorithm?**

- Uses **O(1) space** ✅
- Runs in **O(n) time** ✅
- Works like **Cycle Detection in Linked Lists** ✅

👨‍💻 **What if modification was allowed?**

- **Sorting → O(n log n)**
- **Hashing → O(n) but uses extra space**

👨‍💻 **What if elements were NOT between `1` to `n`?**

- Then **Floyd’s algorithm wouldn’t work**. Use **sorting or hashing instead**.

---

🚀 **This is the complete structured breakdown you need! Let me know if you need more depth on any section.** 🔥

### **Hint to Solve the Problem Efficiently**

1. **Key Observations**

   - The numbers in the array range from `1` to `n`, with `n+1` elements.
   - This guarantees at least **one duplicate** due to the **pigeonhole principle**.

2. **Optimized Approach (Floyd’s Cycle Detection - Tortoise & Hare Algorithm)**

   - Think of the array indices as nodes in a **linked list**.
   - Since numbers are in range `1` to `n`, they can be used as **pointers to the next index**.
   - Detect the **cycle** to find the duplicate, similar to **finding a loop in a linked list**.

3. **Key Steps**

   - **Step 1:** Use **slow (tortoise)** and **fast (hare)** pointers to detect a cycle.
   - **Step 2:** Once a cycle is detected, reset one pointer and move both at the same speed to find the duplicate.

4. **Time Complexity & Space Complexity**
   - **Time Complexity:** \(O(n)\)
   - **Space Complexity:** \(O(1)\) (No extra data structures used)

---

💡 **Try implementing this using Floyd's Cycle Detection and let me know if you get stuck!** 🚀

Here’s the **Floyd’s Cycle Detection Algorithm (Tortoise & Hare Method)** to find the duplicate number efficiently:

### **Code:**

```cpp
int Solution::repeatedNumber(const vector<int> &A) {
    int slow = A[0];
    int fast = A[A[0]];

    // Step 1: Detect the cycle using slow & fast pointers
    while (slow != fast) {
        slow = A[slow];
        fast = A[A[fast]];
    }

    // Step 2: Find the start of the cycle (duplicate number)
    slow = 0;
    while (slow != fast) {
        slow = A[slow];
        fast = A[fast];
    }

    return slow;
}
```

---

### **Explanation:**

1. **Cycle Detection (Step 1)**

   - `slow` moves **one step** at a time (`slow = A[slow]`).
   - `fast` moves **two steps** at a time (`fast = A[A[fast]]`).
   - If there's a duplicate, a **cycle** will be detected (both pointers meet at the same index).

2. **Finding the Duplicate (Step 2)**
   - Reset `slow` to **0** and move both `slow` and `fast` **one step at a time**.
   - When they meet again, that index holds the **duplicate number**.

---

### **Complexity Analysis:**

✅ **Time Complexity:** \(O(n)\)  
✅ **Space Complexity:** \(O(1)\) (No extra memory used)

---

🚀 Try running this on different test cases! Let me know if you need further explanation. 😃

Let's dry run the **Floyd’s Cycle Detection Algorithm** step by step using an example.

### **Example Input:**

```
A = [3, 4, 1, 4, 2]
```

Here, **n = 5** (size of array) and numbers are between **1 to 4**.

---

## **Step 1: Detect the Cycle (Tortoise & Hare Method)**

| Iteration | `slow` (moves 1 step) | `fast` (moves 2 steps)            |
| --------- | --------------------- | --------------------------------- |
| **Start** | slow = `A[0]` = **3** | fast = `A[A[0]]` = `A[3]` = **4** |
| **1st**   | slow = `A[3]` = **4** | fast = `A[A[4]]` = `A[2]` = **1** |
| **2nd**   | slow = `A[4]` = **2** | fast = `A[A[2]]` = `A[1]` = **4** |
| **3rd**   | slow = `A[2]` = **1** | fast = `A[A[1]]` = `A[4]` = **2** |
| **4th**   | slow = `A[1]` = **4** | fast = `A[A[4]]` = `A[2]` = **1** |
| **5th**   | slow = `A[4]` = **2** | fast = `A[A[2]]` = `A[1]` = **4** |
| **6th**   | slow = `A[2]` = **1** | fast = `A[A[1]]` = `A[4]` = **2** |
| **7th**   | slow = `A[1]` = **4** | fast = `A[A[4]]` = `A[2]` = **1** |
| **8th**   | slow = `A[4]` = **2** | fast = `A[A[2]]` = `A[1]` = **4** |
| **9th**   | slow = `A[2]` = **1** | fast = `A[A[1]]` = `A[4]` = **2** |
| **10th**  | slow = `A[1]` = **4** | fast = `A[A[4]]` = `A[2]` = **1** |

They meet at `4`, meaning we found a **cycle**.

---

## **Step 2: Find the Duplicate**

- Reset **slow** to `0`, keep **fast** where they met (`4`).
- Move both **one step at a time**.

| Iteration | `slow` (moves 1 step) | `fast` (moves 1 step)             |
| --------- | --------------------- | --------------------------------- |
| **Start** | slow = `A[0]` = **3** | fast = **4** (from previous step) |
| **1st**   | slow = `A[3]` = **4** | fast = `A[4]` = **2**             |
| **2nd**   | slow = `A[4]` = **2** | fast = `A[2]` = **1**             |
| **3rd**   | slow = `A[2]` = **1** | fast = `A[1]` = **4**             |
| **4th**   | slow = `A[1]` = **4** | fast = `A[4]` = **2**             |
| **5th**   | slow = `A[4]` = **2** | fast = `A[2]` = **1**             |
| **6th**   | slow = `A[2]` = **1** | fast = `A[1]` = **4**             |
| **7th**   | slow = `A[1]` = **4** | fast = `A[4]` = **2**             |

They meet at `4`, which is the **duplicate number**.

---

### **Final Output:**

```
4
```

---

### **Key Takeaways:**

✅ **Detects duplicates in O(n) time and O(1) space.**  
✅ **Uses cycle detection technique (Floyd’s Algorithm).**  
✅ **Efficient for large inputs compared to sorting or hashing methods.**

Let me know if you need any clarifications! 🚀
