/*  Question 2 - 
1401. Circle and Rectangle Overlapping
*/

/* Problem Statement - 
You are given a circle represented as (radius, xCenter, yCenter) and 
an axis-aligned rectangle represented as (x1, y1, x2, y2), where (x1, y1) 
are the coordinates of the bottom-left corner, and (x2, y2) are the coordinates of the top-right corner of the rectangle.
Return true if the circle and rectangle are overlapped otherwise return false. 
In other words, check if there is any point (xi, yi) that belongs to the circle and the rectangle at the same time.
*/

/* Example 1 - 
Input: radius = 1, xCenter = 0, yCenter = 0, x1 = -1, y1 = 0, x2 = 0, y2 = 1
Output: true
*/

/* Example 2 - 
Input: radius = 1, xCenter = 1, yCenter = 1, x1 = 1, y1 = -3, x2 = 2, y2 = -1
Output: false
*/

#include<iostream>
using namespace std;

   bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // we have to find the nearest X co-ordinate which is lying near to circle 
        int nearestX = max(x1,min(x2,xCenter));

        // similary find Y co-ordinate which is lying near to circle 
        int nearestY = max(y1, min(y2,yCenter));

        // find distance between circle & rectangle 
        int distX = xCenter - nearestX;
        int distY = yCenter - nearestY;

        // circle & rectangle will overlap -> 
        // when radius is greater than distance between circle & rectangle 

        if(distX*distX + distY*distY<=radius*radius){
            return 1;
        }
        else{
            return 0;
        }
        
    }


int main() {

    int radius = 1, xCenter = 0, yCenter = 0, x1 = -1, y1 = 0, x2 = 0, y2 = 1;
    bool ans = checkOverlap(radius,xCenter,yCenter, x1,  y1,  x2, y2);

    if(ans==true){
        cout<<"Circle & Rectangle overlap each other";
    }
    else{
        cout<<"Circle & Rectangle don't overlap each other";
    }

    return 0;
}

/*
Practice Problem link - 
https://leetcode.com/problems/circle-and-rectangle-overlapping/
*/