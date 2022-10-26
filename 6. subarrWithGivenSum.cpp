/*

Given an unsorted array A of size N that contains only non-negative integers, 
find a continuous sub-array which adds to a given number S.
In case of multiple subarrays, return the subarray which comes first on moving from left to right.

Input:
N = 5, S = 12
A[] = {1,2,3,7,5}
Output: 2 4
Explanation: The sum of elements 
from 2nd position to 4th position 
is 12.

TC : O(N)
SC : O(1)

approach:

Follow the steps given below to implement the approach:

Create two variables, start=0, currentSum = arr[0]
1. Traverse the array from index 1 to end.
2. Update the variable currentSum by adding current element, currentSum = currentSum + arr[i]
3. If the currentSum is greater than the given sum, update the variable currentSum as currentSum = currentSum - arr[start],
and update start as, start++.
4. If the currentSum is equal to given sum, print the subarray and break the loop.
*/

vector<int> subarraySum(int arr[], int n, long long s)
{
    // Your code here
    int str=0,i;
    long long curSum=arr[0];
    
    vector<int> ans;
    
    for(i=1;i<=n;i++){
        while(curSum>s && str<i-1){
            curSum-=arr[str];
            str++;
        }
        
        if(curSum==s){
            ans.push_back(str+1);
            ans.push_back(i);
            return ans;
        }
        
        if(i<n)
            curSum+=arr[i];
    }
    
    ans.push_back(-1);
    return ans;
}