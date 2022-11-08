/*
Given two numbers M and N. The task is to find the position of the 
rightmost different bit in the binary representation of numbers.

Input: M = 11, N = 9
Output: 2
Explanation: Binary representation of the given 
numbers are: 1011 and 1001, 2nd bit from right is different.

TC : O(max(Log m, Log n))  SC : O(1)
*/

int posOfRightMostDiffBit(int m, int n)
{
    // Your code here
    int cnt=1;
    while(m>0 || n>0){
        int remM=m%2, remN=n%2;
        if(remM!=remN){
            return cnt;
        }
        cnt++;
        m/=2;
        n/=2;
    }
    
    return -1;
}
