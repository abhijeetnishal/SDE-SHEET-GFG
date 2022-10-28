/*
Given an array arr[] of N non-negative integers representing the height of blocks. 
If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 

Input:
N = 6
arr[] = {3,0,0,2,0,4}
Output:
10

TC : O(N)
SC : O(N)
*/

long long trappingWater(int a[], int n){
    int maxl[n],maxr[n];

    maxl[0]=a[0];
    for(int i=1;i<n;i++){
        maxl[i]=max(a[i],maxl[i-1]);
    }

    maxr[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--){
        maxr[i]=max(maxr[i+1],a[i]);
    }

    long long sum=0;
    for(int i=0;i<n;i++){
        sum+=(min(maxl[i],maxr[i])-a[i]);
    }
    
    return sum;
}
