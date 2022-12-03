/*
Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function)
in the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, 
should be considered as a group and must be reversed.

Input:
LinkedList: 1->2->3->4->5
K = 3
Output: 3 2 1 5 4 
Explanation: 
The first 3 elements are 1,2,3 are reversed first and then elements 4,5 are reversed.
Hence, the resultant linked list is 3->2->1->5->4.

TC: O(N)  SC:O(N)
*/

struct node *reverse (struct node *head, int k)
{ 
    //base case
    if (!head)
        return NULL;
        
    node* current = head;
    node* next = NULL;
    node* prev = NULL;
    int count = 0;
 
    /*reverse first k nodes of the linked list */
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
 
    /* current is now a pointer to (k+1)th node
    Recursively call for the list starting from current.
    */
    head->next = reverse(current, k);
        
    return prev;
}

