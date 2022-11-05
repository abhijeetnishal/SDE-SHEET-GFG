/*
Given an array arr[] of size N, check if it can be partitioned into two parts such that 
the sum of elements in both parts is the same.

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explanation: The two parts are {1, 5, 5} and {11}.

*/

//Recursion-  TC : O(2^N) SC : O(N)
int equalSumPartition(int n,int arr[],int sum){
    if(sum==0)
        return 1;

    if(n<0)
        return 0;
    
    if(arr[n]<=sum)
        return equalSumPartition(n-1,arr,sum-arr[n]) | equalSumPartition(n-1,arr,sum);
    else
        return equalSumPartition(n-1,arr,sum);
}

int equalPartition(int n, int arr[])
{
    // code here
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    
    if(sum%2==1)
        return 0;
    else{
        int findSum=equalSumPartition(n-1,arr,sum/2);
        
        if(findSum==1)
            return 1;
        else
            return 0;
    }
}


//Memoization- TC : O(N*sum of elements) SC : O(N*sum of elements)
int equalSumPartition(int n,int arr[],int sum,vector<vector<int>> &dp){
    if(sum==0)
        return 1;

    if(n<0)
        return 0;
        
    if(dp[n][sum]!=-1)
        return dp[n][sum];
    
    if(arr[n]<=sum)
        return dp[n][sum]=equalSumPartition(n-1,arr,sum-arr[n],dp) | equalSumPartition(n-1,arr,sum,dp);
    else
        return dp[n][sum]=equalSumPartition(n-1,arr,sum,dp);
}

int equalPartition(int n, int arr[])
{
    // code here
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    
    if(sum%2==1)
        return 0;
    else{
        vector<vector<int>> dp(n+1,vector<int>((sum/2)+1,-1));
        int findSum=equalSumPartition(n-1,arr,sum/2,dp);
        
        if(findSum==1)
            return 1;
        else
            return 0;
    }
}

// Iterative- TC : O(N*sum of elements) SC : O(N*sum of elements)
int equalPartition(int n, int arr[])
{
    // code here
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    
    if(sum%2==1)
        return 0;
    else{
        vector<vector<bool>> dp(n+1,vector<bool>(sum/2+1,false));
        
        for(int i=0;i<=n;i++){
            dp[i][0]=true;
        }
        
        for(int i=1;i<=sum/2;i++){
            dp[0][i] = false;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1; j<=sum/2;j++){
                dp[i][j]=dp[i-1][j];
            
                if(j-arr[i-1]>=0 && dp[i-1][j-arr[i-1]]==true){
                    dp[i][j]=true;
                }
            }
        }
        
        return dp[n][sum/2];
    }
}

