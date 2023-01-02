/*
You have a list of all-natural numbers and an 'arr'. Your task is to find the Kth 
smallest natural number after removing all numbers in 'arr' from the list of all-natural numbers.
Note: 'arr' will be sorted in ascending order.

You are given, 'arr' = [1, 2, 4], 'K' = '5', You have the natural numbers as
[1, 2, 3, 4, 5, 6, 7 .. .1, after removing all the integers in the array from
natural numbers, we have, [3, 5, 6, 7, 8]. Here 8 is the 5th smallest number.
Hence the answer is 8.

TC: O(mxm(a[i]))   SC: O(N)
*/

int kthSmallest(vector<int> &arr, int k){
    // Write your code here.
    unordered_map<int,int> mp;
    int mxm=0;
    
    for(int i=0;i<arr.size();i++){
        mp[arr[i]]++;
        mxm=max(mxm,arr[i]);
    }
    
    int cnt=0;
    for(int i=1;i<mxm;i++){
        if(mp[i]==0)
            cnt++;
        if(cnt==k)
            return i;
    }
    
    return mxm+(k-cnt);
}
