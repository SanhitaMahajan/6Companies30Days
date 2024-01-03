/* Question 3 - Find Missing And Repeating
*/

/* Problem Statement - 
Given an unsorted array Arr of size N of positive integers. 
One number 'A' from set {1, 2,....,N} is missing and one number 'B' occurs twice in array. 
Find these two numbers
*/

/* Example - 
Input:
N = 3
Arr[] = {1, 3, 3}
Output: 3 2
Explanation: Repeating number is 3 and smallest positive missing number is 2.
*/

#include<iostream>
#include<vector>
using namespace std;

    vector<int> findTwoElement(vector<int> arr, int n) {
        sort(arr.begin(),arr.end());
        
        int repeated=0, missing=0;
        vector<int> ans;
        
        // finding repeated number 
        for(int i=1;i<n;i++){
            if(arr[i-1]==arr[i]){
                repeated = arr[i-1];
                break;
            }
        }
        
        //  finding missing number - 
        //  numbers are in range - [1 to 9] , 
        //  so difference bewteen two adjacent numbers will be always one 
        //  if difference is greater than 1 i.e 2 then number is missing 
         for(int i=0;i<n-1;i++){
            if(arr[i+1]-arr[i] > 1){
                missing = arr[i]+1;
            }
        }
        
        //  checking if first or last number is missing 
        if(missing == 0){
            if(arr[0]!=1){
            missing = 1;
        }
        else{
            missing = n;
        }
        }

        ans.push_back(missing);
        ans.push_back(repeated);
        return ans;
        
    }


int main() {
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(3);

    int n = arr.size();

    vector<int> result;
    result = findTwoElement(arr,n);
    
    cout<<"The number missing & repeated are : "<<endl;
    
    for(int i=0;i<2;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;

    return 0;
}

/*
Practice Problem link - 
https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/0
*/