/*  Question 1 - 
2099. Find Subsequence of Length K With the Largest Sum
*/


/* Problem Statement - 
You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.
Return any such subsequence as an integer array of length k.
A subsequence is an array that can be derived from another array by deleting some or no elements 
without changing the order of the remaining elements.
*/

/* Example - 
Input: nums = [-1,-2,3,4], k = 3
Output: [-1,3,4]
Explanation: 
The subsequence has the largest sum of -1 + 3 + 4 = 6.
*/

/* Example - 
Input: nums = [3,4,3,3], k = 2
Output: [3,4]
Explanation:
The subsequence has the largest sum of 3 + 4 = 7. 
Another possible subsequence is [4, 3].
*/

#include<iostream>
#include<vector>
using namespace std;

   vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();

    //  first copy the given array into another array of pair along with index
    vector<pair<int,int> > numsWithIndex(n);
    for(int i=0;i<n;i++){
        numsWithIndex[i].first = nums[i];
        numsWithIndex[i].second = i;
    }

    //  sort them in decreasing order 
    sort(numsWithIndex.begin(), numsWithIndex.end(), greater<pair<int,int> >()); 

    // traverse the first k values and mark their indexes in a boolean taken array 

    vector<bool> taken(n,false);
    for(int i=0;i<k;i++){
        taken[numsWithIndex[i].second] = true;
    }

    // now traverse the original array again and keep the elements marked in previous step into our result array sequentially
    vector<int> result;
    for(int i=0;i<n;i++){
        if(taken[i]){
            result.push_back(nums[i]);
        }
    }

    return result;
    }


int main() {
    vector<int> arr;
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(3);
    arr.push_back(3);

    int k = 2;

    vector<int> result;
    result = maxSubsequence(arr,k);
    
    cout<<"The subsequence : "<<endl;
       cout<<"[ ";
    for(int i=0;i<k;i++){
     
        cout<<result[i]<<" ";
       
    }
     cout<<"]";

    cout<<endl;

    return 0;
}

/*
Practice Problem link - 
https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/description/
*/