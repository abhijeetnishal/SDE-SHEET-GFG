/*
Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of 
nodes visible when tree is visited from Left side. The task is to complete the function 
leftView(), which accepts root of the tree as argument.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8   

TC : O(N)  SC : O(N)
*/
vector<int> leftView(Node *root)
{
    vector<int> ans;
    
    if(root==NULL)
        return ans;
        
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        int qs=q.size();
        
        for(int i=0;i<qs;i++){
            Node* fr=q.front();
            q.pop();
            
            if(i==0)
                ans.push_back(fr->data);
                
            if(fr->left)
                q.push(fr->left);
            if(fr->right)
                q.push(fr->right);
        }
    }
    
    return ans;
}