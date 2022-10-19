/*
Given an array A of n positive numbers. 
The task is to find the first Equilibium Point in the array. 
Equilibrium Point in an array is a position such that the sum of elements before it is equal to the sum of elements after it.
Input: 
n = 5 
A[] = {1,3,5,2,2} 
Output: 3 
Explanation:  
equilibrium point is at position 3 
as elements before it (1+3) = elements after it (2+2). 

*/


//TC : O(N) SC : O(N)
int equilibriumPoint(long long a[], int n) {
    // Your code here
    int pref[n+1]={0},suff[n+1]={0};
    
    for(int i=0;i<n;i++){
        pref[i+1]=pref[i]+a[i];
    }
    
    for(int i=n-1;i>=0;i--){
        suff[i]=suff[i+1]+a[i];
    }
    
    if(n==1)
        return 1;
    
    
    for(int i=0;i<n;i++){
        if(pref[i]==suff[i+1])
            return i+1;
    }
    return -1;
}


//TC : O(N) SC : O(1)
int equilibriumPoint(long long a[], int n){
    long long leftSum=0;
    long long totalSum=0;
    
    for(int i=0;i<n;i++)
        totalSum+=a[i];
    
    for(int i=0;i<n;i++){
        long long rightSum=totalSum-leftSum-a[i];
        
        if(rightSum==leftSum)
            return i+1;
            
        leftSum+=a[i];
    }
    
    return -1;
}
