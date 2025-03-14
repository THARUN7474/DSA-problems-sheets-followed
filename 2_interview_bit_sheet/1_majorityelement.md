### **1️⃣ Question (Problem Statement)**
Given an array of size **N**, find the **majority element**. The majority element is the element that appears more than **floor(N/2) times**.

- **Constraints**:  
  - The array is **non-empty**.
  - The majority element **always exists** in the array.
  
### **2️⃣ Constraints & Observations**
- **1 ≤ N ≤ 10⁶** → **O(N²) is not feasible**, we need an **O(N) or O(N log N) solution**.  
- **1 ≤ A[i] ≤ 10⁹** → Values are large, so we should avoid extra space usage like frequency maps.  
- **The majority element always exists** → We don’t need to check for cases where there is **no majority**.  

### **3️⃣ Approach & Thought Process**
We need to find the **element that appears more than N/2 times**.  
#### **Brute Force (O(N²))**:
1. Count occurrences of each element.
2. If any element appears more than `floor(N/2)`, return it.

🚨 **Issue**: This is **O(N²)** due to repeated counting.

#### **Better Approach (O(N log N)) - Sorting**:
1. **Sort the array** (O(N log N)).
2. The **middle element** will be the majority element.  

🚨 **Issue**: Sorting takes **O(N log N)** and we want **O(N)**.

#### **Optimal Approach (O(N), O(1) Space) - Boyer-Moore Voting Algorithm** ✅
1. **Step 1: Candidate Selection**  
   - Maintain a **count** variable.
   - Iterate through the array, selecting a **candidate**.
   - If count = 0, set `candidate = A[i]`.
   - If `candidate == A[i]`, increment count.
   - Otherwise, decrement count.
   
2. **Step 2: Verification (if needed)**  
   - Since the majority element **always exists**, we don’t need extra verification.

⏳ **Time Complexity**: **O(N)**  
📦 **Space Complexity**: **O(1)**  

---

### **4️⃣ Different Approaches (Brute Force → Optimal)**
| Approach         | Time Complexity | Space Complexity | Notes |
|-----------------|----------------|------------------|-------|
| Brute Force (Nested Loop) | **O(N²)** | **O(1)** | Count occurrences manually |
| Sorting | **O(N log N)** | **O(1)** | Middle element is majority |
| HashMap | **O(N)** | **O(N)** | Count occurrences using extra space |
| **Boyer-Moore Voting** ✅ | **O(N)** | **O(1)** | Best approach |

---

### **5️⃣ Example & Dry Run**
#### **Example 1**
**Input:** `A = [3, 3, 4, 2, 3, 3, 3, 2, 3]`  
**Steps:**
```
i = 0, ans = 3, count = 1
i = 1, ans = 3, count = 2
i = 2, ans = 3, count = 1  (4 ≠ 3, decrement)
i = 3, ans = 3, count = 0  (2 ≠ 3, decrement)
i = 4, ans = 3, count = 1
i = 5, ans = 3, count = 2
i = 6, ans = 3, count = 3
i = 7, ans = 3, count = 2  (2 ≠ 3, decrement)
i = 8, ans = 3, count = 3
```
**Output:** `3`

---

### **6️⃣ Code (Clean & Commented)**
```cpp
int Solution::majorityElement(const vector<int> &A) {
    int count = 0;   // Count variable
    int candidate = 0; // Majority candidate

    // Step 1: Finding the majority element
    for(int i = 0; i < A.size(); i++){
        if(count == 0){
            candidate = A[i];  // Select new candidate
        }
        if(candidate == A[i]){
            count++;
        } else {
            count--;
        }
    }

    return candidate; // Since majority element is guaranteed to exist
}
```

---

### **7️⃣ TC & SC Analysis (Explained Clearly)**
**🕒 Time Complexity: `O(N)`**
- We iterate the array **once** → `O(N)`.  

**💾 Space Complexity: `O(1)`**
- We use only two variables (`count`, `candidate`) → **constant space**.

---

### **8️⃣ Code Walkthrough (Step-by-Step Execution)**
#### **Input:** `A = [2,2,1,1,1,2,2]`
| Index | Element | Candidate | Count |
|--------|-----------|-------------|--------|
| 0 | 2 | 2 | 1 |
| 1 | 2 | 2 | 2 |
| 2 | 1 | 2 | 1 |
| 3 | 1 | 2 | 0 (decrement) |
| 4 | 1 | 1 | 1 (new candidate) |
| 5 | 2 | 1 | 0 (decrement) |
| 6 | 2 | 2 | 1 (new candidate) |

**Output:** `2`

---

### **9️⃣ Edge Cases**
✅ **Only One Element** → `[1]` (Output: `1`)  
✅ **All Same Elements** → `[2,2,2,2,2]` (Output: `2`)  
✅ **Large Array (`N = 10⁶`)** → Handles efficiently  
✅ **Different Orderings** → `[3,3,4,2,3,3,3,2,3]`  

---

### **🔟 Mistakes to Avoid**
🚨 **Not resetting `candidate` when `count = 0`**  
🚨 **Forgetting that the majority element is guaranteed to exist**  

---

### **1️⃣1️⃣ Related Problems / Concepts / Patterns**
- **Moore’s Voting Algorithm**  
- **Finding Elements Appearing > N/3 Times**  
- **Find Element Appearing Exactly K Times**  

---

### **1️⃣2️⃣ Real-World Applications**
- **Election Vote Counting** (Finding the most voted candidate efficiently).  
- **Database Majority Query** (Finding the most occurring item).  

---

### **💡 Final Verdict**
✅ **Best Approach**: **Boyer-Moore Voting Algorithm** (O(N), O(1)).  
✅ **Clear understanding with dry runs, edge cases, and explanation**.  
✅ **Strong Interview Approach**.  