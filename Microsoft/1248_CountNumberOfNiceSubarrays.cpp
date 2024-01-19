/*  Question 4 - 
1248. Count Number of Nice Subarrays
*/

/* Problem Statement - 
Given an array of integers nums and an integer k. 
A continuous subarray is called nice if there are k odd numbers on it.
Return the number of nice sub-arrays.
*/

/* Example 1 - 
Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There is no odd numbers in the array.
*/

/* Example 2 - 
Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
*/

#include<iostream>
using namespace std;
#include<vector>

    int atMost(vector<int>& nums, int k){
        int left = 0;
        int right = 0;
        int ans = 0;

        for(right = 0; right < nums.size(); right++){
            k -= nums[right];
            while(k < 0){
                k += nums[left];
                left++;
            }
            ans += right - left + 1;
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        //  treat odd numbers as 1 and even numbers as 0 ,
        //  calculate number of subarray having sum = k 

        // step 1 - replace all the odd elements with 1 & all the even elements with 0 
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 == 1) {
               nums[i] = 1;
            }
            else{
               nums[i] = 0;
            } 
        }
        
        // Now calculate the subarrays with sum = k.
        // This can be done by finding the subarrays with sum <= k and finding subarrays
        //  with sum <= k - 1 and subtrack later from the previous one.

        return atMost(nums, k) - atMost(nums, k - 1);
    }


int main() {

    vector<int> arr;
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(1);

    int k = 3;

    int ans = numberOfSubarrays(arr,k);
    
    cout<<"The number of nice sub-arrays are - "<<ans<<endl;

    return 0;
}

/*
Practice Problem link - 
https://leetcode.com/problems/count-number-of-nice-subarrays/
*/