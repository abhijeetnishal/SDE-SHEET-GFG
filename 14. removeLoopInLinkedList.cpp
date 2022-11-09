/*
Detect and Remove Loop in Linked List

Given a linked list of N nodes such that it may contain a loop.
A loop here means that the last node of the link list is connected to the node at position X(1-based index). 
If the link list does not have any loop, X=0.
Remove the loop from the linked list, if it is present, i.e. unlink the last node which is forming the loop.

Input:
N = 3
value[] = {1,3,4}
X = 2
Output: 1
Explanation: The link list looks like
1 -> 3 -> 4
     ^    |
     |____|    
A loop is present. If you remove it 
successfully, the answer will be 1. 

TC : O(N)
SC : O(1)

*/

void removeLoop(Node* head)
{
    if(!head) 
        return;
    
    //using two pointers and moving one pointer(slow) by one node and 
    //another pointer(fast) by two nodes in each iteration.
    Node* fast=head->next;
    Node* slow=head;
    
    while(fast!=slow)
    {
        //if the node pointed by first pointer(fast) or the node 
        //next to it is null, then loop is not present.
        if(!fast || !fast->next) 
            return;
        fast=fast->next->next;
        slow=slow->next;
    }
    //both pointers now point to the same node in the loop.
    
    int size=1;
    fast=fast->next;
    
    //we start iterating the loop with first pointer and continue till 
    //both pointers point to same node again.
    while(fast!=slow)
    {
        //incrementing the counter which stores length of loop.
        size++;
        fast=fast->next;
    }
    
    //updating the pointers again to starting node.
    slow=head;
    fast=head;
    
    //moving pointer (fast) by (size-1) nodes.
    for(int i=0;i<size-1;i++)
        fast=fast->next;
    
    //now we keep iterating with both pointers till fast reaches a node such
    //that the next node is pointed by slow. At this situation slow is at
    //the node where loop starts and first at last node so we simply 
    //update the link part of first.
    while(fast->next!=slow)
    {
        fast=fast->next;
        slow=slow->next;
    }
    //storing null in link part of the last node.
    fast->next=NULL;
}
