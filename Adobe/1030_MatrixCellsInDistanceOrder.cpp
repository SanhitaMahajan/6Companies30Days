/*
Question 1 - 
1030. Matrix Cells in Distance Order
*/

/*
Problem Statement - 
You are given four integers row, cols, rCenter, and cCenter. 
There is a rows x cols matrix and you are on the cell with the coordinates (rCenter, cCenter).
Return the coordinates of all cells in the matrix, sorted by their distance from (rCenter, cCenter)
from the smallest distance to the largest distance. You may return the answer in any order that satisfies this condition.
The distance between two cells (r1, c1) and (r2, c2) is |r1 - r2| + |c1 - c2|.
*/

/* Example 1 - 
Input: rows = 1, cols = 2, rCenter = 0, cCenter = 0
Output: [[0,0],[0,1]]
Explanation: The distances from (0, 0) to other cells are: [0,1]
*/

/* Example 2 - 
Input: rows = 2, cols = 3, rCenter = 1, cCenter = 2
Output: [[1,2],[0,2],[1,1],[0,1],[1,0],[0,0]]
Explanation: The distances from (1, 2) to other cells are: [0,1,1,2,2,3]
There are other answers that would also be accepted as correct, such as [[1,2],[1,1],[0,2],[1,0],[0,1],[0,0]].
*/

#include<iostream>
#include<vector>
#include <map>
using namespace std;

  vector<vector<int> > allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int> > ans;
        map<int, vector<vector<int> > > mp;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                int diff = abs(i-rCenter)+abs(j-cCenter);
                vector<int> temp;
                temp.push_back(i);
                temp.push_back(j);
                mp[diff].push_back(temp);
            }
        }

        for(auto i:mp){
            for(auto x : i.second){
                ans.push_back(x);
            }
        }
        return ans;
}

int main() {
    int rows = 1, cols = 2, rCenter = 0, cCenter = 0;
    
    vector<vector<int> > result = allCellsDistOrder(rows, cols, rCenter, cCenter);

    cout << "Output: [";
    for (const auto &cell : result) {
        cout << "[" << cell[0] << "," << cell[1] << "]";
        if (&cell != &result.back()) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    return 0;
}

/*
Practice Problem link - 
https://leetcode.com/problems/matrix-cells-in-distance-order/description/
*/