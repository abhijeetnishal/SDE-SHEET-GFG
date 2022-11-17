/*
Given an infinite supply of each denomination of Indian currency { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 } 
and a target value N.
Find the minimum number of coins and/or notes needed to make the change for Rs N. 
You must return the list containing the value of coins required.

Input: N = 43
Output: 20 20 2 1
Explaination: 
Minimum number of coins and notes needed to make 43. 

TC : O()   SC : O()
*/

vector<int> minPartition(int N)
{
    int cur[10]={1,2,5,10,20,50,100,200,500,2000};
    vector<int> ans;
    
    while(N){
        for(int i=9;i>=0;i--){
            if(cur[i]<=N){
                N-=cur[i];
                ans.push_back(cur[i]);
                break;
            }
        }
    }
    
    return ans;
}