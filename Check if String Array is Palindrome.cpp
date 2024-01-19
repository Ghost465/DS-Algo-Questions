/*
An array is called palindromic if it remains the same after reversing the order of its elements.

You have an array of strings arr. For each i, arr[i] consists of at least two characters. For each pair of consecutive elements arr[i] and arr[i + 1], you can:

Move the rightmost character of arr[i] to the leftmost position in arr[i + 1]. For instance, "abc" and "def" will become "ab" and "cdef". This operation can be applied only once to any pair of consecutive elements.
Move the leftmost character of arr[i + 1] to the rightmost position in arr[i]. For instance, "abc" and "def" will become "abcd" and "ef". Again, this operation can be applied only once to any pair of consecutive elements.
Do nothing to the pair of consecutive elements.
Is it possible to obtain a palindromic array from arr by performing these operations?

Example

For arr = ["aa", "bab", "cde", "aba", "ab"], the output should be
solution(arr) = true.

Apply the second operation to "aa" and "bab".
Apply the first operation to "aba" and "ab".
This gives us the following array: ["aab", "ab", "cde", "ab", "aab"], which is palindromic.
For arr = ["palindrome"], the output should be
solution(arr) = true.

The given array is already palindromic, so no operations are needed.

For arr = ["aaaaaa", "aa"], the output should be
solution(arr) = false.

If moving two characters between two consecutive array elements was allowed, the array could have been made palindromic, but this is impossible given the actual rules.

Input/Output

[execution time limit] 0.5 seconds (cpp)

[memory limit] 1 GB

[input] array.string arr

An array of strings.

Guaranteed constraints:
1 ≤ arr.length ≤ 105,
2 ≤ arr[i].length ≤ 10.

[output] boolean

Return true if the given array can be turned into a palindromic array, otherwise return false.

*/



#include<bits/stdc++.h>
using namespace std;

void printVector(vector<string> arr1){
    for(int j=0 ; j<arr1.size() ; j++){
        cout<<arr1[j]<<" ";
    }
    cout<<endl;
}

void operation1(vector<string> &A, int i, int j){
    string s = A[i];
    A[i]=s.substr(0,s.length()-1);
    A[j]=s.substr(s.length()-1,s.length()) + A[j];
    // printVector(A);
}

void operation2(vector<string> &A, int i, int j){
    string s = A[j];
    A[i]=A[i] + s.substr(0,1);
    A[j]=s.substr(1,s.length());
    // printVector(A);
}

bool checkPalindromeArrays(vector<string> arr, int i, int j) {
    if (j==arr.size()){
        bool isPalindromeArray = true;
        for(int a=0 ; a<arr.size()/2 && isPalindromeArray ; a++){
            if (arr[a].compare(arr[arr.size()-1-a])!=0){
                isPalindromeArray = false;
            }
        }
        return isPalindromeArray;
    }
    vector<string> arr1 = arr;
    operation1(arr1, i, j);
    vector<string> arr2 = arr;
    operation2(arr2, i, j);
    return checkPalindromeArrays(arr1, i+1, j+1) || checkPalindromeArrays(arr2, i+1, j+1) || checkPalindromeArrays(arr, i+1, j+1);
}

bool solution(vector<string> arr) {
    return checkPalindromeArrays(arr, 0, 1);
}
