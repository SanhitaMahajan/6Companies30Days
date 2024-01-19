/*  Question 3 - 
462. Minimum Moves to Equal Array Elements II
*/

/* Problem Statement - 
Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.
In one move, you can increment or decrement an element of the array by 1.
Test cases are designed so that the answer will fit in a 32-bit integer.
*/

/* Example 1 - 
Input: nums = [1,2,3]
Output: 2
Explanation:
Only two moves are needed (remember each move increments or decrements one element):
[1,2,3]  =>  [2,2,3]  =>  [2,2,2]
*/

/* Example 2 - 
Input: nums = [1,10,2,9]
Output: 16
*/

#include<iostream>
using namespace std;
#include<vector>

    int minMoves2(vector<int>& nums) {
       int n = nums.size();
       sort(nums.begin(), nums.end());
       int ans=0;
       int mid = nums[n/2];

       for(int i=0;i<n;i++){
          ans+=abs(nums[i]-mid);
       } 
       return ans;
    }


int main() {

    vector<int> arr;
    arr.push_back(1);
    arr.push_back(10);
    arr.push_back(2);
    arr.push_back(9);

    int ans = minMoves2(arr);
    
    cout<<"The minimum numbers of move required are "<<ans<<endl;

    return 0;
}

/*
Practice Problem link - 
https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/
*/