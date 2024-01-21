/*  Question 6 - 
187. Repeated DNA Sequences
*/

/* Problem Statement - 
The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.
For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.
Given a string s that represents a DNA sequence, return all the 10-letter-long sequences 
(substrings) that occur more than once in a DNA molecule. You may return the answer in any order.
*/

/* Example 1 - 
Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]
*/

/* Example 2 - 
Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]
*/

#include<iostream>
#include<map>
#include<vector>
using namespace std;

   // The idea is to iterate through the string, extract all possible 10-character substrings, 
   // and count the occurrences of each substring using a map. Finally, the substrings that occur more than 
   // once are added to the resultant vector.

    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> mp;
        vector<string> repeated;

        if(s.size()<10){
            return repeated;
        }

        for(int i=0;i<s.size()-9;i++){
            string subString = s.substr(i,10);
            mp[subString]++;
        }

        for(auto j:mp){
            if(j.second>1){
                repeated.push_back(j.first);
            }
        }

        return repeated;
    }


int main() {

    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> output = findRepeatedDnaSequences(s);

    cout << "Output: [";
    for (int i = 0; i < output.size(); ++i) {
        cout << "\"" << output[i] << "\"";
        if (i < output.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    return 0;
}

/*
Practice Problem link - 
https://leetcode.com/problems/repeated-dna-sequences/
*/