/*
Given an unsigned integer N. The task is to swap all odd bits with even bits. 
For example, if the given number is 23 (00010111), it should be converted to 43(00101011). 
Here, every even position bit is swapped with an adjacent bit on the right side(even position 
bits are highlighted in the binary representation of 23), and every odd position bit is swapped 
with an adjacent on the left side.

Approach:
Store bits and then Swap Them.

TC : O(1)  SC : O(1)
*/

unsigned int swapBits(unsigned int n)
{
	vector<int> bits(32,0);
	
	for(int i=0;i<32;i++){
	    if(n&(1<<i))
	        bits[i]=1;
	}
	
	for(int i=0;i<32;i+=2){
	    swap(bits[i],bits[i+1]);
	}
	
	int ans=0;
	for(int i=0;i<32;i++){
	    ans+=((1<<i)*bits[i]);
	}
	
	return ans;
}
