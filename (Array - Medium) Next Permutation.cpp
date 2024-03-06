/*
Leetcode : Next Permutation
https://leetcode.com/problems/next-permutation/description/?envType=featured-list&envId=top-google-questions?envType=featured-list&envId=top-google-questions
*/
class Comparator{
    public:
    bool operator() (pair<int,int> p1, pair<int,int> p2) {
        return p1.first<p2.first || (p1.first==p2.first && p1.second>p2.second);
    }
};

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int N = nums.size();
        
        // starting from right, find the first element (pivot) that has a greater element to its right
        // then swap it with next greater element (min element that is greater than pivot)
        // follow it up with sorting the rest of elements after pivot (smart sort, just reverse the list)

        int findPivotIdx=N-1;
        priority_queue<pair<int,int>,vector<pair<int,int>>, Comparator> PQ;
        PQ.push(make_pair(nums[findPivotIdx],findPivotIdx));
        findPivotIdx--;
        while(findPivotIdx>=0 && nums[findPivotIdx]>=PQ.top().first) {
            PQ.push(make_pair(nums[findPivotIdx],findPivotIdx));
            findPivotIdx--;
        }
        if (findPivotIdx<0) {
            for(int i=0 ; i<N/2 ; i++) {
                swap(nums[i], nums[N-1-i]);
            }
            return;
        }
        while(!PQ.empty() && PQ.top().first>nums[findPivotIdx]) {
            int replaceIdx = PQ.top().second;
            PQ.pop();
            if (PQ.empty() || PQ.top().first<=nums[findPivotIdx]) {
                swap(nums[findPivotIdx], nums[replaceIdx]);
                break;
            }
        }
        int left = findPivotIdx+1;
        int right = N-1;
        while(left<right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
};
