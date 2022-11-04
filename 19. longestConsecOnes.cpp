/*
Given a number N. 
Find the length of the longest consecutive 1s in its binary representation.

Input: N = 222
Output: 4
Explanation: 
Binary representation of 222 is 11011110, in which 1111 is the 
longest consecutive set bits of length 4.

*/

//TC : O(Log(N))  SC : O(Log(N))
int maxConsecutiveOnes(int n)
{
    // code here
    vector<int> bits;
    
    while(n>0){
        int rem=n%2;
        bits.push_back(rem);
        n/=2;
    }
    
    reverse(bits.begin(),bits.end());
    int mxmConsBits=0,cnt=0;
    
    for(int i=0;i<bits.size();i++){
        if(bits[i]==1){
            cnt++;
        }
        else{
            cnt=0;
        }
        mxmConsBits=max(mxmConsBits,cnt);
    }
    
    return mxmConsBits;
}


//TC : O(Log(N))  SC : O(1)
int maxConsecutiveOnes(int n)
{
    // code here
    int mxmConsBits=0,cnt=0;
    
    while(n>0){
        int rem=n%2;
        
        if(rem==1){
            cnt++;
        }
        else{
            cnt=0;
        }
        mxmConsBits=max(mxmConsBits,cnt);
        
        n/=2;
    }
    
    return mxmConsBits;
}

