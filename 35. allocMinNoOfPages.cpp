/*
You are given N number of books. Every ith book has Ai number of pages. 
You have to allocate contiguous books to M number of students. There can be many ways or permutations to do so. 
In each permutation, one of the M students will be allocated the maximum number of pages. Out of all these permutations, 
the task is to find that particular permutation in which the maximum number of pages allocated to a student is the minimum 
of those in all the other permutations and print this minimum value.

Each book will be allocated to exactly one student. Each student has to be allocated at least one book.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

Input:
N = 4
A[] = {12,34,67,90}
M = 2
Output:113
Explanation:Allocation can be done in 
following ways:{12} and {34, 67, 90} 
Maximum Pages = 191{12, 34} and {67, 90} 
Maximum Pages = 157{12, 34, 67} and {90} 
Maximum Pages =113. Therefore, the minimum 
of these cases is 113, which is selected 
as the output.

TC:O(N*Log(N))   SC:O(1)

Approach:
1. select max_limit=(sum of all elements)
2. if max_limit valid-> high=mid-1
3. else  low=mid-1

*/

bool isValid(int A[],int N,int max_limit, int M){
    int ctr=1;
    int curSum=0;
    
    for(int i=0;i<N;i++){
        if(curSum+A[i]<=max_limit)
            curSum+=A[i];
        else{
            ctr++;
            curSum=A[i];
        }
        if(ctr>M)
            return false;
    }
    return true;
}

int findPages(int A[], int N, int M) 
{
    if(N<M)
        return -1;
        
    int res;
    int str=*max_element(A,A+N);
    int end=0;
    
    for(int i=0;i<N;i++)
        end+=A[i];
        
    while(str<=end){
        int mid=str+(end-str)/2;
        
        if(isValid(A,N,mid,M)){
            res=mid;
            end=mid-1;
        }
        else
            str=mid+1;
    }
    
    return res;
}


