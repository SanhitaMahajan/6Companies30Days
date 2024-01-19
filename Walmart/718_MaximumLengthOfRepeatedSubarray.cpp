
/*  Question 3 - 
718. Maximum Length of Repeated Subarray
*/

/* Problem Statement - 
Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.
*/

/* Example 1 - 
Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].
*/

/* Example 2 - 
Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
Output: 5
Explanation: The repeated subarray with maximum length is [0,0,0,0,0].
*/

#include<iostream>
using namespace std;
#include<vector>

    int solve(vector<int> &nums1, vector<int> nums2){
        int result = 0;
        for(int start=0;start<nums2.size();start++){
            int count=0;
            for(int i=0;i<nums1.size() && start+i<nums2.size();i++){
                if(nums1[i]==nums2[start+i]){
                    count ++;
                }
                else{
                    count =0;
                }
                result = max(result,count);
            }
        }

        return result;
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        //  try slide on both side 
        return max(solve(nums1,nums2), solve(nums2,nums1));
    }


int main() {

    vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(3);
    nums1.push_back(2);
    nums1.push_back(1);

    vector<int> nums2;
    nums2.push_back(3);
    nums2.push_back(2);
    nums2.push_back(1);
    nums2.push_back(4);
    nums2.push_back(2);

    int ans = findLength(nums1,nums2);
    
    cout<<"Maximum length of repeating sub-array : "<<ans<<endl;

    return 0;
}

/*
Practice Problem link - 
https://leetcode.com/problems/maximum-length-of-repeated-subarray/
*/