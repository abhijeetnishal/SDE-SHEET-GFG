/*
Given a Binary Tree, find Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.

Right view of following tree is 1 3 7 8.

          1
       /     \
     2        3
   /   \      /    \
  4     5   6    7
    \
     8

TC: O(N)
SC: O(N)
*/
vector<int> rightView(Node *root)
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
            
            if(i==qs-1)
                ans.push_back(fr->data);
            if(fr->left)
                q.push(fr->left);
            if(fr->right)
                q.push(fr->right);
        }
    }
    
    return ans;
}