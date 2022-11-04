/*
Given a non-negative integer N. 
The task is to check if N is a power of 2. More formally, 
check if N can be expressed as 2x for some x.

Input: N = 1
Output: YES
Explanation:1 is equal to 2 
raised to 0 (20 = 1).

Input: N = 98
Output: NO

*/

//TC : O(Log(n)) SC : O(1)
bool isPowerofTwo(long long n)
{   
    bool check=false;
    
    while(n>0){
        if(n==1)
            check=true;
        else if(n%2==1)
            break;
        n/=2;
    }
    
    return check;
}


/*
TC : O(1) SC : O(1)
As we know that the number which will be the power of two have only one set bit , 
therefore when we do bitwise and with the number which is just less than the number
which can be represented as the power of (2) then the result will be 0 . 
*/

bool isPowerofTwo(long long n){ 
    if(n==0)
        return false;
    else if((n&(n-1))==0)
        return true;
    else
        return false;
}
