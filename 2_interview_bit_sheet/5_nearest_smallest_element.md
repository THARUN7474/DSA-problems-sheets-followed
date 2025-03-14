### **🔹 1️⃣ Problem Statement (Rewritten for Clarity)**
Given an array **A**, we need to find the **nearest smaller element** for each element in **A** such that:  
- The smaller element is **to the left** of the current element.  
- If no smaller element exists, return **-1**.  

#### **Example 1**
```cpp
Input:  A = [4, 5, 2, 10, 8]
Output: G = [-1, 4, -1, 2, 2]
```
**Explanation:**
- `4` has no smaller element → `-1`
- `5` has `4` as the nearest smaller element → `4`
- `2` has no smaller element → `-1`
- `10` has `2` as the nearest smaller element → `2`
- `8` has `2` as the nearest smaller element → `2`

#### **Example 2**
```cpp
Input:  A = [3, 2, 1]
Output: G = [-1, -1, -1]
```
**Explanation:**
- `3` has no smaller element → `-1`
- `2` has no smaller element → `-1`
- `1` has no smaller element → `-1`

---

### **🔹 2️⃣ Constraints & Observations**
#### **Constraints:**
- \( 1 \leq |A| \leq 10^6 \) (up to 1 million elements)
- \( -10^9 \leq A[i] \leq 10^9 \) (large range of values)

#### **Observations:**
1. **Brute Force (O(N²)) is inefficient**  
   - For each element, scanning all previous elements would be **too slow**.
2. **Using a Stack can optimize the search**  
   - A **monotonic increasing stack** can efficiently track previous smaller elements.

---

### **🔹 3️⃣ Approach & Thought Process**
We use a **stack** to efficiently find the nearest smaller element in **O(N) time**.

1. **Use a stack to store elements** from left to right.
2. **For each element `A[i]`:**
   - Remove elements from the stack if they are **greater than or equal to `A[i]`**.
   - The **top of the stack** is the nearest smaller element.
   - If stack is empty, **push `-1`** into the result.
   - Otherwise, **push `stack.top()`** into the result.
   - Finally, **push `A[i]` onto the stack** for future comparisons.

---

### **🔹 4️⃣ Different Approaches (Brute Force → Optimized)**  

#### **1️⃣ Brute Force Approach (O(N²)) → Inefficient**
- For each element, scan all previous elements.
- **Time Complexity:** \( O(N^2) \)

```cpp
vector<int> prevSmaller(vector<int>& A) {
    int n = A.size();
    vector<int> G(n, -1);
    
    for (int i = 0; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (A[j] < A[i]) {
                G[i] = A[j];
                break;
            }
        }
    }
    return G;
}
```
🔴 **Too slow for large inputs**.

---

#### **2️⃣ Optimized Approach (Using Stack) → O(N)**
- Instead of scanning all previous elements, **use a stack to keep track of candidates**.

```cpp
vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int> G;
    stack<int> s;

    for (int i = 0; i < A.size(); i++) {
        // Remove elements that are NOT smaller
        while (!s.empty() && s.top() >= A[i])
            s.pop();
        
        // If stack is empty, there is no smaller element
        if (s.empty())
            G.push_back(-1);
        else
            G.push_back(s.top());  // Nearest smaller element
        
        // Push current element into stack for future checks
        s.push(A[i]);
    }
    return G;
}
```

**🔹 Time Complexity:**  
- Each element is pushed & popped **once** → **O(N)**
- **Space Complexity:** **O(N)** (for the result array + stack)

✅ **Efficient solution with a stack!**

---

### **🔹 5️⃣ Example & Dry Run**
#### **Example 1:**
```cpp
A = [4, 5, 2, 10, 8]
```
| **i** | **A[i]** | **Stack Before** | **Pop Elements** | **G[i] (Nearest Smaller)** | **Stack After** |
|---|---|---|---|---|---|
| 0 | 4  | []  | - | -1  | [4]  |
| 1 | 5  | [4] | - | 4   | [4, 5] |
| 2 | 2  | [4, 5] | 5, 4 | -1  | [2]  |
| 3 | 10 | [2] | - | 2   | [2, 10] |
| 4 | 8  | [2, 10] | 10 | 2   | [2, 8] |

🔹 **Output:** `[-1, 4, -1, 2, 2]`

---

### **🔹 6️⃣ Time & Space Complexity Analysis**
#### **Time Complexity:**
- **Each element is pushed & popped once from the stack → O(N)**.
- **Final complexity: O(N)**.

#### **Space Complexity:**
- **Stack stores elements at most once → O(N)** in the worst case.
- **Final complexity: O(N)**.

---

### **🔹 7️⃣ Code Walkthrough**
#### **Example Walkthrough:**
```cpp
Input: A = [4, 5, 2, 10, 8]
Stack operations:
1. Push 4
2. Push 5
3. Pop 5, Pop 4, Push 2
4. Push 10
5. Pop 10, Push 8
```
Final output: `[-1, 4, -1, 2, 2]`

---

### **🔹 8️⃣ Edge Cases & Important Test Cases**
#### ✅ **Basic Cases**
| **Test Case** | **Expected Output** |
|--------------|----------------|
| `[3, 2, 1]` | `[-1, -1, -1]` |
| `[1, 2, 3, 4, 5]` | `[-1, 1, 2, 3, 4]` |

#### ✅ **Large Input Cases**
- \( A = [1, 2, ..., 10^6] \) should run in **O(N)**.

---

### **🔹 9️⃣ Mistakes to Avoid**
🔴 **Forgetting to pop elements from the stack**  
🔴 **Using extra loops leading to O(N²)**  
🔴 **Not handling edge cases (empty array, decreasing sequence, etc.)**  

---

### **🔹 1️⃣1️⃣ Related Problems**
✅ **Next Greater Element**  
✅ **Stock Span Problem**  
✅ **Largest Rectangle in Histogram**  

---

### **🔹 1️⃣2️⃣ Real-World Applications**
📌 **Stock Market** – Finding past support levels  
📌 **Temperature Monitoring** – Finding previous lower temperatures  

---

### **🔹 1️⃣3️⃣ Explaining to Interviewer**
- "I used a **monotonic increasing stack** to track the nearest smaller elements."
- "Each element is pushed/popped **once**, making it **O(N) time complexity**."
- "The space complexity is **O(N)** due to the stack."

---

🔥 **This is the complete structured explanation!** Let me know if you need modifications. 🚀