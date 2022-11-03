/*
Given a matrix of size n x m, where every row and column is sorted in increasing order, and a number x. 
Find whether element x is present in the matrix or not.

Input:
n = 1, m = 6, x = 55
matrix[][] = {{18, 21, 27, 38, 55, 67}}
Output: 1
Explanation: 55 is present in the matrix.

*/

//TC : O(N*Log(M))
bool search(vector<vector<int>> mat, int n, int m, int x) 
{
    // code here
    for(int i=0;i<n;i++){
        if(binary_search(mat[i].begin(),mat[i].end(),x))
            return true;
    }
    
    return false;
}


//TC : O(N+M) SC : O(1)
bool search(vector<vector<int>> mat, int n, int m, int x) 
{
    // code here
    int i=0, j=m-1;
    
    while(i<n && j<m){
        if(mat[i][j]==x)
            return true;
        else if(mat[i][j]>x)
            j--;
        else
            i++;
    }
    
    return false;
}