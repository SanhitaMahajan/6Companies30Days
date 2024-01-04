/* Question 5 - Number following a pattern
*/
/* Problem Statement - Given a pattern containing only I's and D's. 
I for increasing and D for decreasing. Devise an algorithm to print the minimum number following that pattern. 
Digits from 1-9 and digits can't repeat.
*/

/* Example - 
Input:
IIDDD
Output:
126543
Explanation:
Above example is self- explanatory,
1 < 2 < 6 > 5 > 4 > 3
  I - I - D - D - D
*/

/* Constraints:
1 ≤ Length of String ≤ 8
*/

#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

string printMinNumberForPattern(string S){
        // code here 
        stack<int> st;
        int num=1;
        string ans;
        
        for(int i=0;i<S.length();i++){
            st.push(num++);
            if(S[i]=='I'){
                while(!st.empty()){
                    ans+=to_string(st.top());
                    st.pop();
                }
            }
        }
        
        st.push(num++);
        while(!st.empty()){
            ans+=to_string(st.top());
            st.pop();
        }
        return ans;
}

int main() {
    
    string str="IIDDD";
    string ans = printMinNumberForPattern(str);
    cout << "The minimum number of pattern: " << ans << endl;
  

    return 0;
}

/*
Practice Problem link - 
https://www.geeksforgeeks.org/problems/number-following-a-pattern3126/1
*/

