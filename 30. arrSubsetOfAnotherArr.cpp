/*
Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m. 
Task is to check whether a2[] is a subset of a1[] or not. 
Both the arrays can be sorted or unsorted.

Input:
a1[] = {11, 1, 13, 21, 3, 7}
a2[] = {11, 3, 7, 1}
Output:
Yes
Explanation:
a2[] is a subset of a1[]

TC : O(N) SC : O(N)
*/

string isSubset(int a[], int b[], int n, int m) {
    unordered_map<int,int> mpA;
    
    for(int i=0;i<n;i++){
        mpA[a[i]]++;
    }
    
    for(int i=0;i<m;i++){
        if(mpA[b[i]]==0)
            return "No";
        else{
            mpA[b[i]]--;
        }
    }
    
    return "Yes";
}