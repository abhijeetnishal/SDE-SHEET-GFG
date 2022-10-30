/*
The span Si of the stocks price on a given day i is defined as the maximum number of consecutive days 
just before the given day, for which the price of the stock on the current day is less than or equal 
to its price on the given day.

Input: 
N = 7, price[] = [100 80 60 70 60 75 85]
Output:
1 1 1 2 1 4 6
Explanation:
Traversing the given input span for 100 
will be 1, 80 is smaller than 100 so the 
span is 1, 60 is smaller than 80 so the 
span is 1, 70 is greater than 60 so the 
span is 2 and so on. Hence the output will 
be 1 1 1 2 1 4 6.

TC : O(N)
SC : O(N)

Approach:
We see that S[i] on the day i can be easily computed if we know the closest day preceding i,
such that the price is greater than on that day than the price on the day i. If such a day 
exists, let’s call it h(i), otherwise, we define h(i) = -1. 
The span is now computed as S[i] = i - h(i).

*/

vector<int> calculateSpan(int price[], int n)
{
   // Your code here
   stack<int> st;
   st.push(0);
   
   vector<int> ans;
   ans.push_back(1);
   
   for(int i=1;i<n;i++){
        while(!st.empty() && price[st.top()]<=price[i]){
            st.pop();
        }
       
        int span;
        if(st.empty())
            span=i+1;
        else
            span=i-st.top();
        
        ans.push_back(span);
        
        st.push(i);
   }
   
   return ans;
}
