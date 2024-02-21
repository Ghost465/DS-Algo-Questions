/*
https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/description/

You are given an integer array nums. In one operation, you can replace any element in nums with any integer.

nums is considered continuous if both of the following conditions are fulfilled:

All elements in nums are unique.
The difference between the maximum element and the minimum element in nums equals nums.length - 1.
For example, nums = [4, 2, 5, 3] is continuous, but nums = [1, 2, 3, 5, 6] is not continuous.

Return the minimum number of operations to make nums continuous.

 

Example 1:

Input: nums = [4,2,5,3]
Output: 0
Explanation: nums is already continuous.
Example 2:

Input: nums = [1,2,3,5,6]
Output: 1
Explanation: One possible solution is to change the last element to 4.
The resulting array is [1,2,3,5,4], which is continuous.
Example 3:

Input: nums = [1,10,100,1000]
Output: 3
Explanation: One possible solution is to:
- Change the second element to 2.
- Change the third element to 3.
- Change the fourth element to 4.
The resulting array is [1,2,3,4], which is continuous.
*/

#include<bits/stdc++.h>
using namespace std;

    vector<int> removeDuplicates(vector<int>& nums, int &duplicates) {
        vector<int> redc;
        redc.push_back(nums[0]);
        int timesReduced=0;
        for(int i=1 ; i<nums.size() ; i++) {
            // remove duplicates
            while(i<nums.size() && nums[i]==redc[redc.size()-1]) {
                i++;
                duplicates++;
            }
            if (i<nums.size()) {
                redc.push_back(nums[i]);
            }
        }
        return redc;
    }

    vector<int> reduce(vector<int>& redc, int N) {
        vector<int> newr;
        newr.push_back(redc[0]);
        for(int i=1 ; i<redc.size() ; i++) {
            // bring down the gap
            if (redc[i]-redc[i-1] > redc.size()) {
                newr.push_back(newr[i-1]+N);
            } else {
                newr.push_back(newr[i-1]+(redc[i]-redc[i-1]));
            }
        }
        return newr;
    }

    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int duplicates=0;
        vector<int> nums1 = removeDuplicates(nums, duplicates);
        nums1 = reduce(nums1, nums.size());
        int N = nums1.size();
        for(int i=0 ; i<N ; i++) {
            cout<<nums1[i]<<" ";
        }
        cout<<endl;
        if(N==1) {
            return duplicates;
        }
        int currElement = nums1[0]-nums.size();
        int minElementsNotPresent = N;
        int idx = 0;
        int prevIdx=0;
        int elementsPresent=0;
        for(int val=currElement ; val<=nums1[N-1] ; val++) {
            if(prevIdx<N && val-nums.size()==nums1[prevIdx]){
                prevIdx++;
                elementsPresent--;
            }
            if (idx<N && val==nums1[idx]){
                idx++;
                elementsPresent++;
            }
            minElementsNotPresent = min(minElementsNotPresent, N-elementsPresent);
        }
        return minElementsNotPresent + duplicates;
    }
    
int main() {
//   vector<int> A = {3,8,24,47,2,5,2};
//   vector<int> A = {4,2,5,3};
  vector<int> A = {8,5,9,9,8,4};
  cout<<minOperations(A)<<endl;
}
