/*
Leetcode : https://leetcode.com/problems/minimum-window-substring/description/

Minimum Window Substring

Given two strings s and t of lengths m and n respectively, return the minimum window 
substring
 of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.


Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
*/

class Solution {
public:
    string minWindow(string s, string t) {
        // place characters in minimum unoccupied matching positions

        // pick and drop the lowest index character to its next unoccupied matching position
      
        unordered_map<char, priority_queue<int, vector<int>, greater<int>>> charNextIndexLookup;
        for(int i=0 ; i<s.length() ; i++) {
            charNextIndexLookup[s[i]].push(i);
        }
        priority_queue<int, vector<int>, greater<int>> charsCurrentPlacedPositions;
        int maxIdx=-1;
        for(int i=0 ; i<t.length() ; i++) {
            if (charNextIndexLookup[t[i]].size()==0) {
                return "";
            } else {
                int foundIdx = charNextIndexLookup[t[i]].top();
                charNextIndexLookup[t[i]].pop();
                maxIdx = max(maxIdx, foundIdx);
                charsCurrentPlacedPositions.push(foundIdx);
            }
        }
        int minIdx = charsCurrentPlacedPositions.top();
        int minLen = maxIdx - minIdx;
        int currMinIdx = minIdx;
        int currMaxIdx = maxIdx;
        while(true){
            int charToBePickedIdx = charsCurrentPlacedPositions.top();
            charsCurrentPlacedPositions.pop();
            if (charNextIndexLookup[s[charToBePickedIdx]].size()==0) {
                return s.substr(minIdx, maxIdx-minIdx+1);
            } else {
                // get lookup index of current character and then delete it from heap
                int foundIdx = charNextIndexLookup[s[charToBePickedIdx]].top();
                charNextIndexLookup[s[charToBePickedIdx]].pop();
                charsCurrentPlacedPositions.push(foundIdx);
                
                currMinIdx = charsCurrentPlacedPositions.top();
                currMaxIdx = max(currMaxIdx, foundIdx);
                if (minLen > (currMaxIdx-currMinIdx)) {
                    minLen = currMaxIdx-currMinIdx;
                    minIdx = currMinIdx;
                    maxIdx = currMaxIdx;
                }
            }
        }
        return "";
    }
};
