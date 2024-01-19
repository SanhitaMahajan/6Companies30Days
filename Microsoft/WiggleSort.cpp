/*  Question 5 - 
324. Wiggle Sort II
*/

/* Problem Statement - 
Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
You may assume the input array always has a valid answer.
*/

/* Example 1 - 
Input: nums = [1,5,1,1,6,4]
Output: [1,6,1,5,1,4]
Explanation: [1,4,1,5,1,6] is also accepted.
*/

/* Example 2 - 
Input: nums = [1,3,2,2,3,1]
Output: [2,3,1,3,1,2]
*/

#include<iostream>
using namespace std;
#include<vector>

    void wiggleSort(vector<int>& nums) {
        vector<int>v = nums;

        sort(v.begin(),v.end());

        int j = v.size()-1;
        for(int i=1;i<nums.size();i+=2){
            nums[i]=v[j];
            j--;
        }

        for(int i=0;i<nums.size();i+=2){
            nums[i]=v[j];
            j--;
        }
    }


int main() {

    vector<int> arr;
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(1);

    wiggleSort(arr);

    cout<<endl;
    cout<<"Array after wiggle sort : "<<"[ ";

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }

    cout<<"]"<<endl;

    return 0;
}

/*
Practice Problem link - 
https://leetcode.com/problems/wiggle-sort-ii/description/
*/