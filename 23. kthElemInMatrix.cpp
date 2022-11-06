/*
Given a N x N matrix, where every row and column is sorted in non-decreasing order. 
Find the kth smallest element in the matrix.

Input:
N = 4
mat[][] =     {{16, 28, 60, 64},
               {22, 41, 63, 91},
               {27, 50, 87, 93},
               {36, 78, 87, 94 }}
K = 3
Output: 27
Explanation: 27 is the 3rd smallest element.

*/

//Using vectors   TC : O(N*N) SC : O(N*N)
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    vector<int> ans;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans.push_back(mat[i][j]);
        }
    }
    
    sort(ans.begin(),ans.end());
    
    return ans[k-1];
}


//Using priority queue  TC : O(N*N) SC : O(N)
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    priority_queue<int,vector<int>,greater<int>> pq;
    
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
          pq.push(mat[i][j]);
      }
    }
    
    int res;
    while(k--){
      res=pq.top();
      pq.pop();
    }
    
    return res;
}

//Using Binary Seach  TC : O(y * n*logn) ,Where y=log(abs(Mat[0][0]-Mat[n-1][n-1])) SC : O(1)
bool possible(int mat[MAX][MAX], int n, int k, int mid){
    int cnt = 0;
    
    for(int i=0;i<n;i++){
        cnt+=(lower_bound(mat[i],mat[i]+n,mid)-mat[i]);
    }
    
    return cnt<k;
}

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    int low=mat[0][0],high=mat[n-1][n-1],ans;
    
    while(low<=high){
        int mid=low+(high-low)/2;
        
        if(possible(mat,n,k,mid)){
            ans=mid;
            low=mid+1;
        }
        else 
            high=mid-1;
    }
    
    return ans;
}
