/*
Given a singly linked list of size N. The task is to left-shift the linked list by k nodes, 
where k is a given positive integer smaller than or equal to length of the linked list.

Input:
N = 5
value[] = {2, 4, 7, 8, 9}
k = 3
Output: 8 9 2 4 7
Explanation:
Rotate 1: 4 -> 7 -> 8 -> 9 -> 2
Rotate 2: 7 -> 8 -> 9 -> 2 -> 4
Rotate 3: 8 -> 9 -> 2 -> 4 -> 7

TC : O(N)
SC : O(1)
*/

Node* rotate(Node* head, int k)
{
    
    if(head==NULL){
        return head;
    }
    
    Node *tail=head;
    Node *rotationEnd=head;
    
    while(tail->next!=NULL){
        if(k!=1){
            rotationEnd=rotationEnd->next;
            k--;
        }
        tail=tail->next;
    }
    
    tail->next=head;
    head=rotationEnd->next;
    rotationEnd->next=NULL;

    return head;
}

