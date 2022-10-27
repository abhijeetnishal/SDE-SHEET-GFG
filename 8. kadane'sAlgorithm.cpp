/*
Given an array Arr[] of N integers. 
Find the contiguous sub-array(containing at least one number) which has the maximum sum and return its sum.

Input:
N = 5
Arr[] = {1,2,3,-2,5}
Output:
9
Explanation:
Max subarray sum is 9 of elements (1, 2, 3, -2, 5) which is a contiguous subarray.

TC : O(N)
SC : O(1)
*/

long long maxSubarraySum(int arr[], int n){
    // Your code here
    long long curSum=0, mxmSum=INT_MIN;
    
    for(int i=0;i<n;i++){
        curSum+=arr[i];
        mxmSum=max(mxmSum,curSum);
        
        if(curSum<0)
            curSum=0;
    }
    
    return mxmSum;
}

