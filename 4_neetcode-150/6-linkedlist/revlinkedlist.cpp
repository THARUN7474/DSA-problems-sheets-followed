#include <bits/stdc++.h>

using namespace std;

//  * Definition for singly-linked list.
/// its like custom data structure to store the linked list node
/// here we define a struct ListNode which has two members val and next 
/// val is the value of the node and next is a pointer to the next node in the linked list
/// we can use this to implement various data structures like stack, queue, linked list, etc
/// here we have 3 constructors to initialize the node with value, next pointer or both
/// we can use this to create a linked list by creating nodes and linking them together

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// we access element of that by that poinet->val and poinet->next to access next attached or pointer value 
// this is a singly linked list where each node has a value and a pointer to the next node
// we can use this to implement various data structures like stack, queue, linked list, etc
// here p->val or (p*).val is used to access the value of the node and p->next or (p*).next is used to access the next node in the linked list but for simplicity we will use p->val and p->next
// this is a basic implementation of a singly linked list in C++


// here we access the head of the linked list and reverse it in place 

//iterative solution using two pointers 
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;

        while (curr)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;

        while (curr)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head)
        {
            return nullptr;
        }

        ListNode *newHead = head;
        if (head->next)
        {
            newHead = reverseList(head->next);
            head->next->next = head;
        }
        head->next = nullptr;

        return newHead;
    }
};