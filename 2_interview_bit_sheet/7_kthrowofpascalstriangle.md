### 🔥 Let's Solve the Problem in a Structured Way!  

---

## **1️⃣ Problem Statement**  

We need to return the **k-th row of Pascal’s Triangle** using an optimized approach with **O(k) space**.

📌 **Pascal’s Triangle** follows this rule:  
- The first row is **[1]**.  
- Each element in a row is the **sum of the two elements directly above it** in the previous row.  
- Mathematically, an element at position **C** in row **R** is:  
  \[
  A[R][C] = A[R-1][C-1] + A[R-1][C]
  \]

✅ **Example:**  
For **k = 3**, the output should be **[1, 3, 3, 1]**.  
(From Pascal’s Triangle, the 4th row (0-based index) is: `1 3 3 1`.)

---

## **2️⃣ Constraints & Observations**  

### 🔹 **Constraints**
1. **0 ≤ k ≤ 10⁶** → The row index can be large, so time efficiency is crucial.
2. **Space should be O(k)** → We must avoid storing the entire triangle.
3. **Only the kth row is needed** → No need to compute previous rows explicitly.

### 🔹 **Key Observations**
1. The first and last elements in every row are always **1**.
2. The elements follow the **binomial coefficient formula**:  
   \[
   A[R][C] = \binom{R}{C} = \frac{R!}{C!(R-C)!}
   \]
3. Instead of generating the full Pascal's Triangle, we can **build the row iteratively**.
4. We can compute the next element **using only the previous value**, avoiding extra space.

---

## **3️⃣ Thought Process & Approach**  

### 🔹 **Brute Force (O(k²) Space)**
- Construct the full Pascal's Triangle up to row `k`.
- Store each row completely.
- **Space Complexity = O(k²)** → **Not optimal.**

### 🔹 **Optimized (O(k) Space)**
- Use a **single list** and update it in-place.
- Compute each value using the **previous value** in the row.
- **Use the binomial coefficient formula dynamically**.
- **Time Complexity = O(k)**
- **Space Complexity = O(k)** ✅ **Best approach!**

---

## **4️⃣ Different Approaches (Brute Force → Optimized)**  

### **🔹 Approach 1: Brute Force (Full Pascal’s Triangle)**
📌 **Steps:**
1. Generate all rows up to `k` using the recurrence relation.
2. Store them in a 2D array.
3. Return the `k-th` row.

⏳ **Time Complexity:** `O(k²)`  
💾 **Space Complexity:** `O(k²)` **(bad for large k).**

---

### **🔹 Approach 2: Iterative with O(k) Space (Best)**
📌 **Steps:**
1. **Use a single list** to store the row.
2. Start with `[1]` (since the first element is always 1).
3. Compute elements iteratively using:
   \[
   row[i] = row[i-1] \times \frac{k - (i-1)}{i}
   \]
4. Update the row in-place from **right to left** to avoid overwriting values.

⏳ **Time Complexity:** `O(k)`  
💾 **Space Complexity:** `O(k)` ✅ **(optimal solution).**

---

## **5️⃣ Example & Dry Run**  

### **Example 1:**
#### **Input:**
```cpp
k = 3
```
#### **Pascal's Triangle:**
```
0:   [1]
1:   [1, 1]
2:   [1, 2, 1]
3:   [1, 3, 3, 1]   <-- Required Row
```
#### **Output:**
```cpp
[1, 3, 3, 1]
```

#### **Dry Run (Optimized Approach for k = 3)**  

| Step | Row State |
|------|----------|
| Start | `[1]` |
| Compute 2nd element | `[1, 3]` |
| Compute 3rd element | `[1, 3, 3]` |
| Compute 4th element | `[1, 3, 3, 1]` |

✅ **Final Output:** `[1, 3, 3, 1]`

---

### **🔹 Code (Optimized Approach - O(k) Space)**  
```cpp
vector<int> getRow(int k) {
    vector<int> row(k + 1, 1);  // Initialize row with 1s

    for (int i = 1; i < k; i++) {
        row[i] = (long) row[i - 1] * (k - i + 1) / i;
    }

    return row;
}

### **Understanding Pascal's Triangle**
Pascal's triangle is built using the following rule:

- **First and last element** of each row is always `1`.
- **Each middle element** is the sum of the two elements from the previous row.

#### **Example of Pascal's Triangle:**
```
Row 0:        [1]
Row 1:       [1, 1]
Row 2:      [1, 2, 1]
Row 3:     [1, 3, 3, 1]
Row 4:    [1, 4, 6, 4, 1]
```
For **k = 3**, we return `[1, 3, 3, 1]`.

---

## **Approach 1: Brute Force (Generate Pascal's Triangle up to Row k)**
**Idea:** Generate the Pascal's triangle row by row and return the kth row.

### **Steps:**
1. Initialize `triangle = [[1]]`.
2. For each row `i`, construct it by using the previous row:
   - First and last elements are `1`.
   - Each middle element is the sum of two elements from the previous row.
3. Repeat until reaching the `k`-th row.

### **Code (Brute Force)**
```cpp
vector<int> getRow(int k) {
    vector<vector<int>> triangle(k + 1);
    
    for (int i = 0; i <= k; i++) {
        triangle[i].resize(i + 1, 1);
        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
    
    return triangle[k];
}
```
### **Complexity Analysis:**
- **Time Complexity:** \( O(k^2) \) (since we compute all rows up to `k`).
- **Space Complexity:** \( O(k^2) \) (stores the full Pascal's triangle).

---

## **Approach 2: Optimized Using O(k) Space**
Instead of storing the whole triangle, we can compute just one row using **binomial coefficients**.

### **Mathematical Formula**
Each element in the `k-th` row corresponds to the **binomial coefficient**:
\[
C(n, r) = \frac{n!}{r!(n-r)!}
\]
Where:
- `n` is the row index (`k`).
- `r` is the column index (0 to `k`).

Using this formula, we can compute each element iteratively.

### **Steps:**
1. Start with `row = [1]`.
2. Compute each element using:
   \[
   row[j] = row[j - 1] \times \frac{k - j + 1}{j}
   \]
   This avoids factorial computation and ensures **O(k) space**.

### **Code (Optimized)**
```cpp
vector<int> getRow(int k) {
    vector<int> row(k + 1, 1);
    
    for (int j = 1; j < k; j++) {
        row[j] = (long long) row[j - 1] * (k - j + 1) / j;
    }
    
    return row;
}
```

### **Complexity Analysis**
- **Time Complexity:** \( O(k) \) (we compute only `k` elements).
- **Space Complexity:** \( O(k) \) (only stores one row).

---

## **Dry Run for k = 3**
```
row = [1, 1, 1, 1]  (Initial)

j = 1 → row[1] = row[0] * (3 - 1 + 1) / 1 = 1 * 3 / 1 = 3 → [1, 3, 1, 1]
j = 2 → row[2] = row[1] * (3 - 2 + 1) / 2 = 3 * 2 / 2 = 3 → [1, 3, 3, 1]
```
Final output: `[1, 3, 3, 1]`

---

### **Final Takeaways**
✅ **Brute Force:** Builds Pascal's triangle up to row `k` → \( O(k^2) \) time and space.  
✅ **Optimized Approach:** Uses binomial coefficient formula → \( O(k) \) time and space.  
✅ **Best Approach:** Compute row iteratively using `C(n, r)` formula to keep it **O(k) space-efficient**.

Would you like a detailed explanation of binomial coefficients? 🚀
```

🔹 **Why `(long)`?**  
- To **prevent integer overflow** while calculating binomial coefficients.

---
## **6️⃣ Time & Space Complexity Analysis**  

### **🔹 Optimized Approach (O(k) Space)**
```cpp
vector<int> getRow(int k) {
    vector<int> row(k + 1, 1);  // Initialize row with 1s

    for (int i = 1; i < k; i++) {
        row[i] = (long) row[i - 1] * (k - i + 1) / i;
    }

    return row;
}
```
---

### **🔹 Time Complexity (O(k))**
- The loop runs **k times** to calculate each element.
- Each calculation is **O(1)**.
- **Overall complexity:** **O(k)**.

### **🔹 Space Complexity (O(k))**
- We store **only the kth row** in an array of size `k + 1`.
- **No extra space used for recursion or storing previous rows**.
- **Overall complexity:** **O(k) (optimal).**

---

## **7️⃣ Code Walkthrough (Step-by-Step Execution)**  

Let's take `k = 3`.

### **🔹 Initial Setup**
```cpp
vector<int> row(k + 1, 1);
```
🔹 `row = [1, 1, 1, 1]` (Initialized with 1s)

### **🔹 Iterations**

| `i` | Formula Applied | Updated `row` |
|---|---|---|
| 1 | `row[1] = (row[0] * (3 - 0 + 1)) / 1 = (1 * 3) / 1 = 3` | `[1, 3, 1, 1]` |
| 2 | `row[2] = (row[1] * (3 - 1 + 1)) / 2 = (3 * 2) / 2 = 3` | `[1, 3, 3, 1]` |
| 3 | `row[3] = (row[2] * (3 - 2 + 1)) / 3 = (3 * 1) / 3 = 1` | `[1, 3, 3, 1]` |

✅ **Final Output:** `[1, 3, 3, 1]`  

---

## **8️⃣ Edge Cases & Important Test Cases**  

| **Test Case** | **Reason** | **Expected Output** |
|---|---|---|
| `k = 0` | Smallest case | `[1]` |
| `k = 1` | Simple base case | `[1, 1]` |
| `k = 5` | Larger example | `[1, 5, 10, 10, 5, 1]` |
| `k = 10` | Check if binomial coefficient logic holds | `[1, 10, 45, 120, 210, 252, 210, 120, 45, 10, 1]` |
| `k = 50` | Large value, tests performance | Large array |
| `k = 10⁶` | **Stress test** to check O(k) performance | Very large array |

---

## **9️⃣ Common Mistakes & How to Avoid Them**  

### **❌ Integer Overflow**
🔹 **Issue:** Pascal’s Triangle values grow **very fast** (factorial values).  
🔹 **Fix:** Use **long** for multiplication.  
```cpp
(long) row[i - 1] * (k - i + 1) / i
```

### **❌ Off-by-One Errors**
🔹 **Issue:** Forgetting that `k` is **0-based**, so row size is `k + 1`.  
🔹 **Fix:** Ensure `vector<int> row(k + 1)` is used.

### **❌ Floating Point Errors**
🔹 **Issue:** Using `double` for calculations can introduce precision issues.  
🔹 **Fix:** Always use **integer division**.

---

## **1️⃣0️⃣ Related Problems & Concepts**  
🔥 **Similar Pattern Questions:**
1. **Pascal’s Triangle Generation** (`O(k²) space`)  
2. **Binomial Coefficients (`nCr`) Calculation**  
3. **Dynamic Programming Problems on Combinations**  
4. **Catalan Numbers (Related to Pascal’s Triangle)**  

---

## **1️⃣1️⃣ Real-World Applications**  
✅ **Where is Pascal's Triangle Used?**
1. **Binomial Theorem in Mathematics**  
2. **Combinatorics (Counting, Probability, nCr Calculations)**  
3. **Graphics (Bezier Curves use Pascal’s Triangle)**  
4. **Coding Theory (Error Correction Codes)**  
5. **Data Structures (Tree-Based DP Problems)**  

---

## **1️⃣2️⃣ Explaining to an Interviewer**
**🔹 Key Points to Cover:**
- **Why O(k) space?** Instead of storing all rows, we only store one.
- **How do we calculate values?** Using `row[i] = row[i-1] * (k - i + 1) / i`.
- **How does it work efficiently?** Using iterative **binomial coefficient calculation**.

**🔹 Expected Follow-up Questions:**
1. **What if k = 10⁶?**  
   ✅ `O(k)` ensures **fast execution**.
2. **How does the formula work?**  
   ✅ `nCr = (n-1)C(r-1) * (n-r+1)/r`
3. **Can we do better than O(k) space?**  
   ❌ **No**, because we need to store `k` elements.

---
