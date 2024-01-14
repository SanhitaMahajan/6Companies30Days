/*
Question 2 - 
532. K-diff Pairs in an Array
*/

/*
Problem Statement - 
Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.
A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:
0 <= i, j < nums.length
i != j
|nums[i] - nums[j]| == k
Notice that |val| denotes the absolute value of val.
*/


/* Example 1 - 
Input: nums = [1,2,3,4,5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
*/

/* Example 2 - 
Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.
*/

#include<iostream>
#include<vector>
using namespace std;

  int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count=0;

        for(int i=0,j=1;i<nums.size(), j<nums.size();){
            if(i==j || nums[j]-nums[i]<k){
                j++;
            }
            else{
                if(nums[j]-nums[i]==k){
                    count++;
                    j++;
                    while(j<nums.size() && nums[j]==nums[j-1]){
                        j++;
                    }
                }
                i++;
                while(i<j && nums[i]==nums[i-1]){
                    i++;
                }
            }
        }
        return count;
    }

int main() {
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);

    int k = 1;

    int ans = findPairs(arr,k);
    
    cout<<"The number of unique k-diff pairs in the array are : "<<ans<<endl;
    

    return 0;
}

/*
Practice Problem link - 
https://leetcode.com/problems/k-diff-pairs-in-an-array/description/
*/