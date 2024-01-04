/* Question 4 - 2261. K Divisible Elements Subarrays
*/

#include<iostream>
#include<vector>
#include <set>

using namespace std;

int countDistinct(vector<int>& nums, int k, int p) {
        int i=0,j=0;
        int n = nums.size();
        int count=0;

        set<vector<int> > distinctSubArrays;
        vector<int> subArray;

        while(i<n){
            if(j<n){

                subArray.push_back(nums[j]); // pushing current element 
                if(nums[j]%p==0){ // chcek for atmost k condition 
                   count ++;
                }

                if(count<=k){
                    distinctSubArrays.insert(subArray);
                }
                j++;
            }

            if(count>k || j==n){ // update window 
               subArray.clear();
               i++;
               j=i;
               count =0;
            }
        }
        return distinctSubArrays.size(); 
}

int main() {
    
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(2);

    int  k = 2, p = 2;

    int distinctCount = countDistinct(arr, k, p);
    cout << "The number of distinct subarrays: " << distinctCount << endl;
  

    return 0;
}

/*
Practice Problem link - 
https://leetcode.com/problems/k-divisible-elements-subarrays/
*/

