/* Question 2 - 216. Combination Sum III
*/

#include<iostream>
#include<vector>
using namespace std;

void printVectorOfVectors(vector<vector<int> > &result) {
    cout << "[";
    for (int i = 0; i < result.size(); ++i) {
        cout << "[";
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j];
            if (j != result[i].size() - 1) {
                cout << ",";
            }
        }
        cout << "]";
        if (i != result.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
}

void helper(int index, int sum, int n, vector<int> &combination, vector<vector<int> > &ans, int k){

    if(sum==n && k==0){
        ans.push_back(combination);
        return;
    }

    if(sum>n){
        return;
    }

    for(int i=index;i<=9;i++){
        if(i>n){
            break;
        }
        combination.push_back(i);
        helper(i+1,sum+i,n,combination,ans,k-1);
        combination.pop_back();
    }
}

vector<vector<int> > combinationSum3(int k, int n) {
        vector<int> combination;
        vector<vector<int> > ans;

        helper(1,0,n,combination,ans,k);

        return ans;
    }


int main() {
    int k = 3;
    int n = 9;

    vector<vector<int> > result = combinationSum3(k, n);
    cout<<"Possible Combinations are - "<<endl;
    printVectorOfVectors(result);

    return 0;
}

/*
Practice Problem link - 
https://leetcode.com/problems/combination-sum-iii/
*/

