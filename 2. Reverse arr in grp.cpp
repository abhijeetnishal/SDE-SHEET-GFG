/*
Given an array arr[] of positive integers of size N. Reverse every sub-array group of size K.

Note: If at any instance, there are no more subarrays of size greater than or equal to K,
then reverse the last subarray (irrespective of its size).

Input:
N = 5, K = 3
arr[] = {1,2,3,4,5}
Output: 3 2 1 5 4
Explanation: First group consists of elements
1, 2, 3. Second group consists of 4,5.

*/

void reverseInGroups(vector<long long>& arr, int n, int k){
    for(int i=0;i<n;i+=k){
        if(n-i>=k){
            reverse(arr.begin()+i,arr.begin()+i+k);
        }
    }
    
    reverse(arr.begin()+n-(n%k),arr.end());
}