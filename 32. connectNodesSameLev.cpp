/*
Given a binary tree, connect the nodes that are at same level. 
You'll be given an addition nextRight pointer for the same.

Initially, all the nextRight pointers point to garbage values. 
Your function should set these pointers to point next right for each node.

       10                       10 ------> NULL
      / \                       /      \
     3   5       =>     3 ------> 5 --------> NULL
    / \     \               /  \           \
   4   1   2          4 --> 1 -----> 2 -------> NULL


TC : O(N)  SC : O(N)
*/
void connect(Node *root)
{
   // Your Code Here
   if(root==NULL)
    return;
    
   queue<Node*> q;
   q.push(root);
   
   while(!q.empty()){
        int qs=q.size();
       
        for(int i=0;i<qs;i++){
            Node* fr=q.front();
            q.pop();
           
            if(i==qs-1)
                fr->nextRight=NULL;
            else
                fr->nextRight=q.front();
            
            if(fr->left)
                q.push(fr->left);
            if(fr->right)
                q.push(fr->right);
       }
   }
}