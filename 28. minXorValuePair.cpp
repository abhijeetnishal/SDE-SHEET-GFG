/*
Given an array of integers of size N find minimum xor of any 2 elements.

Input:
N = 3
arr[] = {9,5,3}
Output: 6
Explanation: 
There are 3 pairs -
9^5 = 12
5^3 = 6
9^3 = 10
Therefore output is 6.

*/

//TC : O(N*Log(N)) SC : O(1)
//XOR of two no with min diff is smaller than larger diff. number.
int minxorpair(int N, int arr[]){    
    sort(arr,arr+N);
    
    int ans=INT_MAX;
    for(int i=0;i<N-1;i++){
        ans=min(ans,arr[i]^arr[i+1]);
    }
    
    return ans;
}
