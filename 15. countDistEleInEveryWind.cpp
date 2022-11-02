/*
Given an array of integers and a number K. 
Find the count of distinct elements in every window of size K in the array.

Input:
N = 7, K = 4
A[] = {1,2,1,3,4,2,3}
Output: 3 4 4 3

TC : O(N)
SC : O(N)
*/

vector<int> countDistinct(int arr[], int n, int k)
{
    unordered_map<int,int> mp;
    
    for(int i=0;i<k;i++){
        mp[arr[i]]++;
    }
    
    vector<int> ans;
    ans.push_back(mp.size());
    
    for(int i=1;i<=n-k;i++){
        mp[arr[i-1]]--;
        
        if(mp[arr[i-1]]==0)
            mp.erase(arr[i-1]);
            
        mp[arr[i+k-1]]++;
        
        ans.push_back(mp.size());
    }
    
    return ans;
}
