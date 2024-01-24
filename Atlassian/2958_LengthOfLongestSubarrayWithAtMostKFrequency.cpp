/*  Question 3 - 
2958. Length of Longest Subarray With at Most K Frequency
*/

/* Problem Statement - 
You are given an integer array nums and an integer k.
The frequency of an element x is the number of times it occurs in an array.
An array is called good if the frequency of each element in this array is less than or equal to k.
Return the length of the longest good subarray of nums.
A subarray is a contiguous non-empty sequence of elements within an array.
*/

/* Example 1 - 
Input: nums = [1,2,3,1,2,3,1,2], k = 2
Output: 6
Explanation: The longest possible good subarray is [1,2,3,1,2,3] since the values 1, 2, and 3 
occur at most twice in this subarray. Note that the subarrays [2,3,1,2,3,1] and [3,1,2,3,1,2] are also good.
It can be shown that there are no good subarrays with length more than 6.
*/

/* Example 2 - 
Input: nums = [1,2,1,2,1,2,1,2], k = 1
Output: 2
Explanation: The longest possible good subarray is [1,2] since the values 1 and 2 occur at most once in this subarray. 
Note that the subarray [2,1] is also good.
It can be shown that there are no good subarrays with length more than 2.

*/

#include<iostream>
#include<map>
#include<vector>
using namespace std;

   int maxSubarrayLength(vector<int> &nums, int k){
        int l = 0;
        int j = 0;
        int n = nums.size();
        int mx = 0;
        map<int, int> mp;
        //   Always remebere there is only two step in sliding window problems  
        //  Step 1 is to make a i pointer move 
        for (int i = 0; i < n; i++){
            mp[nums[i]]++;
        
        //  Step 2: for j pointer to move  
            while(mp[nums[i]]>k){
                mp[nums[j]]--;
                j++;
            }
            mx=max(mx,i-j+1);
        }
        return mx;
    }


int main() {

    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(2);

    int k=2;

    int ans = maxSubarrayLength(arr,k);

    cout<<endl;
    cout<<" Length of Longest Subarray With at Most K Frequency is : "<<ans<<endl;

    return 0;
}

/*
Practice Problem link - 
https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/
*/