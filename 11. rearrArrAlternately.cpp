/*
Given a sorted array of positive integers. 
Your task is to rearrange the array elements alternatively i.e first element should be max value, 
second should be min value, third should be second max, fourth should be second min and so on.
Note: Modify the original array itself.

Input:
N = 6
arr[] = {1,2,3,4,5,6}
Output: 6 1 5 2 4 3
Explanation: Max element = 6, min = 1, 
second max = 5, second min = 2, and so on... 
Modified array is : 6 1 5 2 4 3.

TC : O(N)
SC : O(1)

How does expression "arr[i] += arr[max_index] % max_element * max_element" work ? 
The purpose of this expression is to store two elements at index arr[i]. 
arr[max_index] is stored as multiplier and "arr[i]" is stored as remainder. 
For example in {1 2 3 4 5 6 7 8 9}, max_element is 10 and we store 91 at index 0. 
With 91, we can get original element as 91%10 and new element as 91/10.

*/

void rearrange(long long *arr, int n) 
{ 
    int maxIndex = n-1;
    int minIndex = 0;
    int maxElement = arr[n-1]+1;
    
    for(int i=0;i<n;i++){
        if(i%2==0){
            arr[i] = (arr[maxIndex]% maxElement) * maxElement + arr[i];
            maxIndex--;
        }
        else{
           arr[i] = (arr[minIndex]% maxElement) * maxElement + arr[i];
           minIndex++;
        }
    }
    
    for(int i=0;i<n;i++)
        arr[i]/=maxElement;
     
}
