/*  Question 2 - 
455. Assign Cookies
*/

/* Problem Statement - 
Assume you are an awesome parent and want to give your children some cookies. 
But, you should give each child at most one cookie.
Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; 
and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, 
and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.
*/

/* Example 1 - 
Input: g = [1,2,3], s = [1,1]
Output: 1
Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.
*/

/* Example 2 - 
Input: g = [1,2], s = [1,2,3]
Output: 2
Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 
You have 3 cookies and their sizes are big enough to gratify all of the children, 
You need to output 2.
*/

#include<iostream>
using namespace std;
#include<vector>

    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Sort the greed factors and cookie sizes
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        // Initialize pointers and count
        int i = 0, j = 0, count = 0;
        
        // Iterate through both arrays
        
        while (i < g.size() && j < s.size()) {
            // If the current cookie is large enough, satisfy the child
            if (s[j] >= g[i]) {
            count++;
            i++;
        }
        // Move to the next cookie, regardless of whether it satisfies the current child
        j++;
        }
        
        return count;
    }


int main() {

    vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(3);  

    vector<int> nums2;
    nums2.push_back(1);
    nums2.push_back(1);


    int ans = findContentChildren(nums1,nums2);
    
    cout<<"Maximum content : "<<ans<<endl;

    return 0;
}

/*
Practice Problem link - 
https://leetcode.com/problems/assign-cookies/description/
*/