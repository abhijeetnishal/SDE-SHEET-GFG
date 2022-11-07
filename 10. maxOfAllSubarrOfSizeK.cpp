/*
Given an array arr[] of size N and an integer K. 
Find the maximum for each and every contiguous subarray of size K.

Input:
N = 9, K = 3
arr[] = 1 2 3 1 4 5 2 3 6
Output: 
3 3 4 5 5 5 6 
Explanation: 
1st contiguous subarray = {1 2 3} Max = 3
2nd contiguous subarray = {2 3 1} Max = 3
3rd contiguous subarray = {3 1 4} Max = 4
4th contiguous subarray = {1 4 5} Max = 5
5th contiguous subarray = {4 5 2} Max = 5
6th contiguous subarray = {5 2 3} Max = 5
7th contiguous subarray = {2 3 6} Max = 6

TC : O(N)
SC : O(k)

Steps:
1.Create a deque to store k elements.
2.Run a loop and insert first k elements in the deque. Before inserting the element, check if the element at the back 
  of the queue is smaller than the current element, if it is so remove the element from the back of the deque, until 
  all elements left in the deque are greater than the current element. Then insert the current element, at the back of the deque.
3.Now, run a loop from k to end of the array.
4.Print the front element of the deque.
5.Remove the element from the front of the queue if they are out of the current window.
6.Insert the next element in the deque. Before inserting the element, check if the element at the back of the queue is smaller 
  than the current element, if it is so remove the element from the back of the deque, until all elements left in the deque are 
  greater than the current element. Then insert the current element, at the back of the deque.
7.Print the maximum element of the last window.

*/

vector <int> max_of_subarrays(int *arr, int n, int k)
{
    vector<int> res;
    deque<int> q;
    
    int i=0;
    
    //iterating over first k elements or first window of array.
    for(i=0;i<k;i++)
    {
        //for every element, the previously smaller elements 
        //are useless so removing them from deque.
        while((!q.empty()) && (arr[i]>=arr[q.back()]))
            q.pop_back();
        
        //adding new element at back of deque.   
        q.push_back(i);
        
    }
    
    //iterating over the rest of the elements.
    for(;i<n;i++)
    {
        //the element at the front of the deque is the largest 
        //element of previous window, so adding it to the list.
        res.push_back(arr[q.front()]);
        
        //removing the elements which are out of this window.
        while((!q.empty()) && (q.front()<=i-k))
        q.pop_front();
        
        //removing all elements smaller than the element being  
        //added currently (removing useless elements).
        while((!q.empty()) && (arr[i]>=arr[q.back()])) 
        q.pop_back();
        
        //adding new element at back of deque. 
        q.push_back(i);
    }
    
    //the element at the front of the deque is the largest 
    //element of last window, so adding it to the list.
    res.push_back(arr[q.front()]);
    q.pop_front();
    
    //returning the list.
    return res;
}
