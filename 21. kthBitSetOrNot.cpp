/*
Given a number N and a bit number K, check if Kth bit of N is set or not. 
A bit is called set if it is 1. Position of set bit '1' should be indexed 
starting with 0 from LSB side in binary representation of the number.

Input: N = 4, K = 0
Output: No
Explanation: Binary representation of 4 is 100, in which 0th bit from LSB is not set. 
So, return false.

*/

// TC : O(Log(N)) SC : O(1)
bool checkKthBit(int n, int k)
{
    int cnt=0;
    while(n>0){
        int rem=n%2;
        
        if(cnt==k){
            if(rem==1)
                return true;
            else
                return false;
        }
        
        cnt++;
        n/=2;
    }
}

// TC : O(1) SC : O(1)
bool checkKthBit(int n, int k)
{
    if((n&(1<<k))==0)
        return false;
    else
        return true;
}

