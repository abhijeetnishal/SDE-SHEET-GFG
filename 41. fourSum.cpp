/*
You are given an array of n integers and an integer value 'Target'. you need to 
check whether there exist four numbers(arr[i],arr[j],arr[k],arr[l]) such that 
(0<=i<j<k<l<N) and arr[i]+arr[j]+arr[k]+arr[l]='Target'.

Sample Input 1:
2
5 9
1 3 3 10 2
6 20
2 4 6 3 1 1
Sample Output 1:
Yes
No
*/

//TC: O(N^4) ->Brute Force

//TC: O(N^3) using sorting  SC:O(1)
string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.
    sort(arr.begin(),arr.end());
    
    for(int i=0;i<=n-4;i++){
        int s1=arr[i];
        for(int j=i+1;j<=n-3;j++){
            int s2=arr[j];
            
            int str=j+1,end=n-1;
            while(str<end){
                int totalSum=s1+s2+arr[str]+arr[end];
                if(totalSum==target)
                    return "Yes";
                else if(totalSum>target)
                    end--;
                else
                    str++;
            }
        }
    }
    return "No";
}

//TC: O(N*N*Log(N))  SC: O(N*N)
/*
Two Pointers With Sorting
1. We will create a temporary array temp[] to store the sum of all possible pairs.
2. Now we sort this temp[] array. As each element of temp[] contains the sum of two 
elements so the problem reduces to finding the two pairs in the temp[] such that their 
sum is equal to ‘target’.
3. We can use two pointer technique to check whether there exist two pairs in the temp[] 
array that gives the sum = ‘target’. Similar to the above approach we will put the first 
pointer (left) at the starting and the second pointer (right) at end of temp[] array.
 
Now if temp[left] + temp[right] = target that means we found a pair but we also need to 
check whether these two elements of temp have an element of arr[] in common or not for ensuring
that the elements we pick have distinct indexes.

1. To check the distinct indexes we need to declare the type of temp as a structure in which we can 
store sum and both indexes as separate fields.
2. We just access both indexes of temp[left] and temp[right] and if they have any common index then 
this can not be a valid pair.
If temp[left] + temp[right] < target so similar to the above approach we will move our ‘left’ pointer 
to right else we move the ‘right’ pointer to the left.

*/

// Custom Pair class to store sum and indexes.
class Pair {
    public:
    int sum;
    int idx1;
    int idx2;
};

int compare(const void * a,
    const void * b) {
    return (( * (Pair * ) a).sum - ( * (Pair * ) b).sum);
}

bool commonIdx(Pair p1, Pair p2) {
    return p1.idx1 == p2.idx1 || p1.idx1 == p2.idx2 || p1.idx2 == p2.idx1 || p1.idx2 == p2.idx2;
}

string fourSum(vector < int > arr, int target, int n) {
    int size = n * (n - 1) / 2;
    Pair temp[size];
    int k = 0;
    /* 
        Preparing temp[] array which will store sum of 
        two elements of array arr[] with their indexes.
    */
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            temp[k].sum = arr[i] + arr[j];
            temp[k].idx1 = i;
            temp[k].idx2 = j;
            ++k;
        }
    }
    // Sort the temp[] array on the basis of sum.
    qsort(temp, size, sizeof(temp[0]), compare);
    int left = 0;
    int right = size - 1;

    /*
        As array is sorted we will apply two pointer technique
        To find pair of elements in temp[] array 
        having their sum equal to target sum.
    */

    while (left < size && right >= 0) {
        int sum = temp[left].sum + temp[right].sum;
        if (sum == target && !commonIdx(temp[left], temp[right])) {
            return "Yes";
        } else if (sum < target) {
            ++left;
        } else {
            --right;
        }
    }
    // If we can not found the target sum then we return No.
    return "No";
}