/*  Question 1 - 
1385. Find the Distance Value Between Two Arrays
*/

/* Problem Statement - 
Given two integer arrays arr1 and arr2, and the integer d, return the distance value between the two arrays.
The distance value is defined as the number of elements arr1[i] such that 
there is not any element arr2[j] where |arr1[i]-arr2[j]| <= d.
*/

/* Example 1 - 
Input: arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2
Output: 2
Explanation: 
For arr1[0]=4 we have: 
|4-10|=6 > d=2 
|4-9|=5 > d=2 
|4-1|=3 > d=2 
|4-8|=4 > d=2 
For arr1[1]=5 we have: 
|5-10|=5 > d=2 
|5-9|=4 > d=2 
|5-1|=4 > d=2 
|5-8|=3 > d=2
For arr1[2]=8 we have:
|8-10|=2 <= d=2
|8-9|=1 <= d=2
|8-1|=7 > d=2
|8-8|=0 <= d=2
*/

/* Example 2 - 
Input: arr1 = [2,1,100,3], arr2 = [-5,-2,10,-3,7], d = 6
Output: 1
*/

#include<iostream>
using namespace std;
#include<vector>

    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0;
        bool flag = 0;
        for(int i=0;i<arr1.size();i++){
            flag=0;
            for(int j=0;j<arr2.size();j++){
                if(abs(arr1[i]-arr2[j])<=d){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                count++;
            }
        }
        return count;
    }


int main() {

    vector<int> nums1;
    nums1.push_back(4);
    nums1.push_back(5);
    nums1.push_back(8);  

    vector<int> nums2;
    nums2.push_back(10);
    nums2.push_back(9);
    nums2.push_back(1);
    nums2.push_back(8);

    int d =2;

    int ans = findTheDistanceValue(nums1,nums2,d);
    
    cout<<"The distance value between the two arrays : "<<ans<<endl;

    return 0;
}

/*
Practice Problem link - 
https://leetcode.com/problems/find-the-distance-value-between-two-arrays/
*/