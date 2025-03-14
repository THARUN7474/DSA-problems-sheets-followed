## **1️⃣ Problem Statement**

Given a **binary tree**, determine whether it is **symmetric** around its center. A tree is symmetric if the left and right subtrees are **mirror images** of each other.

### **Example**

#### **Input 1:**

```
    1
   / \
  2   2
 / \ / \
3  4 4  3
```

#### **Output:** `1` (True)

_The tree is symmetric._

#### **Input 2:**

```
    1
   / \
  2   2
   \   \
   3    3
```

#### **Output:** `0` (False)

_The tree is not symmetric._

---

## **2️⃣ Constraints & Observations**

### **Constraints:**

- `1 <= number of nodes <= 10^5`
- The tree **may be unbalanced or skewed**.
- The input is given as the **root node** of a binary tree.

### **Observations:**

- **Symmetry means left and right subtrees should be mirror images**:
  - The left subtree’s left child should match the right subtree’s right child.
  - The left subtree’s right child should match the right subtree’s left child.
- **Recursive & Iterative approaches are possible**.
- **We need an efficient solution**, preferably `O(N)`, since the tree can have up to `10^5` nodes.

---

## **3️⃣ Approach & Thought Process**

### **High-Level Approach:**

- **If the tree is empty (`root == NULL`), return `1` (true)**.
- **Use recursion or a queue-based iterative approach** to compare left and right subtrees.
- **Mirror property check:**
  - Compare left subtree's left node with right subtree's right node.
  - Compare left subtree's right node with right subtree's left node.

---

## **4️⃣ Different Approaches**

### **1️⃣ Brute Force Approach (Convert to Array & Check Symmetry) → O(N) Time, O(N) Space**

- Traverse the tree and store values in **level-order traversal**.
- Check if the resulting list is **palindromic**.
- **Issues:**
  - Doesn't work for cases where `NULL` values break symmetry.
  - Uses **extra space** for storing the list.

---

### **2️⃣ Recursive Approach (DFS) → O(N) Time, O(H) Space**

**Key Idea:**

- A tree is symmetric **if its left and right subtrees are mirror images**.
- **Check recursively** whether:
  - Left subtree's left matches right subtree's right.
  - Left subtree's right matches right subtree's left.

#### **Recursive Algorithm:**

1. **Base Case:**
   - If both nodes are `NULL`, return `true`.
   - If only one of them is `NULL`, return `false`.
   - If values don’t match, return `false`.
2. **Recursive Call:**
   - Check `isMirror(left.left, right.right) && isMirror(left.right, right.left)`.
3. **Return Result.**

✅ **Best approach for readability and simplicity!**

---

### **3️⃣ Iterative Approach (Using Queue) → O(N) Time, O(N) Space**

**Key Idea:**

- Use a **queue** to simulate level-order traversal **while checking mirror symmetry**.
- At every step, **compare the corresponding nodes** in the left and right subtree.

✅ **Better for large input sizes where recursion might cause stack overflow.**

---

## **5️⃣ Example & Dry Run**

### **Example 1 (Recursive Approach)**

```
    1
   / \
  2   2
 / \ / \
3  4 4  3
```

1. Compare `2` (left) with `2` (right) → ✅
2. Compare `3` (left.left) with `3` (right.right) → ✅
3. Compare `4` (left.right) with `4` (right.left) → ✅
4. Recurse down and all nodes match → **Tree is symmetric.**

---

## **6️⃣ Code (Recursive & Iterative)**

### **Recursive DFS Solution**

```cpp
class Solution {
public:
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;  // Both NULL → symmetric
        if (!left || !right) return false; // Only one NULL → not symmetric
        if (left->val != right->val) return false; // Values should match

        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }

    int isSymmetric(TreeNode* root) {
        if (!root) return 1;  // Empty tree is symmetric
        return isMirror(root->left, root->right);
    }
};
```

⏳ **Time Complexity:** `O(N)` (Every node is visited once)  
💾 **Space Complexity:** `O(H)` (Recursive stack depth, worst-case `O(N)` for skewed trees)

---

### **Iterative BFS (Queue) Solution**

```cpp
class Solution {
public:
    int isSymmetric(TreeNode* root) {
        if (!root) return 1;

        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);

        while (!q.empty()) {
            TreeNode* left = q.front(); q.pop();
            TreeNode* right = q.front(); q.pop();

            if (!left && !right) continue; // Both NULL → symmetric
            if (!left || !right) return 0; // One NULL → asymmetric
            if (left->val != right->val) return 0; // Values should match

            // Add children in mirror order
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        return 1;
    }
};
```

⏳ **Time Complexity:** `O(N)`  
💾 **Space Complexity:** `O(N)` (Queue stores level-order nodes)

---

## **7️⃣ TC & SC Analysis**

| **Approach**                  | **Time Complexity** | **Space Complexity**       | **Best Use Case**                  |
| ----------------------------- | ------------------- | -------------------------- | ---------------------------------- |
| **Brute Force (Array Check)** | `O(N)`              | `O(N)`                     | Not recommended                    |
| **Recursive (DFS)**           | `O(N)`              | `O(H)` (`O(N)` worst case) | Best for simplicity                |
| **Iterative (Queue BFS)**     | `O(N)`              | `O(N)`                     | Best for avoiding recursion limits |

### **Understanding the Problem**

A binary tree is symmetric if it is a **mirror image of itself**. This means the **left subtree** should be a mirror of the **right subtree**.

#### **Example 1: Symmetric Tree**

```
      1
     / \
    2   2
   / \ / \
  3  4 4  3
```

- The left subtree (`2, 3, 4`) is a mirror of the right subtree (`2, 4, 3`).
- Hence, **Output: 1 (True)**.

#### **Example 2: Non-Symmetric Tree**

```
      1
     / \
    2   2
     \   \
     3    3
```

- The left subtree (`2, null, 3`) is **not** a mirror of the right subtree (`2, null, 3`).
- Hence, **Output: 0 (False)**.

---

## **Approach 1: Recursive Solution (DFS)**

### **Concept**

A tree is symmetric if:

1. **Root's left subtree is a mirror of the right subtree**.
2. **Nodes match in value, and their children swap sides**:
   - `left->left` should match `right->right`
   - `left->right` should match `right->left`

### **Algorithm**

1. If the tree is empty (`root == NULL`), return `1` (symmetric).
2. Call a helper function `isMirror(left, right)`:
   - If both subtrees are `NULL`, return `true`.
   - If one is `NULL` and the other is not, return `false`.
   - If `left->val != right->val`, return `false`.
   - Recursively check:
     - `left->left` with `right->right`
     - `left->right` with `right->left`
3. If all conditions pass, return `true`.

### **Code**

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool isMirror(TreeNode* left, TreeNode* right) {
    if (!left && !right) return true; // Both are null, symmetric
    if (!left || !right) return false; // One is null, not symmetric
    if (left->val != right->val) return false; // Values don't match

    // Recursively check mirrored subtrees
    return isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

int Solution::isSymmetric(TreeNode* root) {
    if (!root) return 1; // Empty tree is symmetric
    return isMirror(root->left, root->right);
}
```

### **Complexity Analysis**

- **Time Complexity:** \( O(N) \) (we visit each node once).
- **Space Complexity:** \( O(H) \) (recursion stack, where `H` is the tree height).
  - **Worst-case (skewed tree):** \( O(N) \).
  - **Best-case (balanced tree):** \( O(\log N) \).

---

## **Approach 2: Iterative Solution (BFS Using Queue)**

Instead of recursion, we can use **BFS (Level Order Traversal)** with a queue.

### **Algorithm**

1. Use a **queue** to store node pairs `(left, right)`.
2. Start with `(root->left, root->right)`.
3. While the queue is **not empty**:
   - Dequeue a pair `(L, R)`.
   - If both are NULL, continue.
   - If one is NULL or `L->val != R->val`, return `false`.
   - Push the **mirrored pairs** into the queue:
     - `(L->left, R->right)`
     - `(L->right, R->left)`
4. If all nodes are symmetric, return `true`.

### **Code**

```cpp
#include <queue>

int Solution::isSymmetric(TreeNode* root) {
    if (!root) return 1;

    queue<pair<TreeNode*, TreeNode*>> q;
    q.push({root->left, root->right});

    while (!q.empty()) {
        auto [L, R] = q.front();
        q.pop();

        if (!L && !R) continue;
        if (!L || !R || L->val != R->val) return 0;

        q.push({L->left, R->right});
        q.push({L->right, R->left});
    }
    return 1;
}
```

### **Complexity Analysis**

- **Time Complexity:** \( O(N) \) (each node is visited once).
- **Space Complexity:** \( O(N) \) (queue stores up to all leaf nodes in worst case).

---

## **Final Comparison**

| Approach                       | Time Complexity | Space Complexity         | Best Use Case                       |
| ------------------------------ | --------------- | ------------------------ | ----------------------------------- |
| **Recursive (DFS)**            | \( O(N) \)      | \( O(H) \) (stack depth) | Small trees or balanced trees       |
| **Iterative (BFS with Queue)** | \( O(N) \)      | \( O(N) \) (queue)       | Large trees or iterative preference |

---

## **Conclusion**

- **Use Recursion** when the tree is **not very deep** (to avoid stack overflow).
- **Use Iterative BFS** when dealing with **large or deep trees**.

---

## **8️⃣ Edge Cases**

✅ **Single Node Tree:** `1 → Symmetric`  
✅ **All Left or All Right Tree:** `1 → 2 → 3 → Not Symmetric`  
✅ **NULL Tree:** `root = NULL → Symmetric`  
✅ **Large Input (10⁵ Nodes):** Recursive approach may cause stack overflow → Use Iterative BFS

---

## **🔟 Mistakes to Avoid**

❌ **Forgetting NULL Checks** → Always check for `NULL` nodes!  
❌ **Confusing Left & Right Pairs** → Remember `left.left` matches `right.right`!  
❌ **Using Preorder Instead of Mirror Checks** → Preorder alone doesn’t check mirror symmetry.

---

## **1️⃣1️⃣ Related Problems**

- **Invert a Binary Tree** (Swap left & right recursively)
- **Check if Two Trees are Mirrors**
- **Check if Two Trees are Identical**
- **Find the Height of a Binary Tree**

---

## **1️⃣2️⃣ Real-World Applications**

- **Data Structures Validation** (Check mirrored tree-like structures)
- **Image Processing** (Mirror symmetry detection)
- **Natural Language Processing (NLP)** (Parsing symmetric structures)

---

## **1️⃣3️⃣ Summary**

✅ **Recursive DFS → Best for Readability**  
✅ **Iterative BFS → Best for Large Inputs**  
✅ **`O(N)` Time, `O(H)` or `O(N)` Space**  
✅ **Handles Edge Cases & Large Inputs** 🚀
