/*
Given an array of size n that has the following specifications: 

Each element in the array contains either a policeman or a thief.
Each policeman can catch only one thief.
A policeman cannot catch a thief who is more than K units away from the policeman.

We need to find the maximum number of thieves that can be caught.
*/

#include<bits/stdc++.h>
using namespace std;

int getNextPerson(int currPersonAt, vector<int> &A, int personValue) {
  currPersonAt++;
  while(currPersonAt<A.size()) {
    if (A[currPersonAt]==personValue) {
      return currPersonAt;
    }
    currPersonAt++;
  }
  return currPersonAt;
}

int getNextPolice(int currPoliceAt, vector<int> &A) {
  return getNextPerson(currPoliceAt, A, 0);
}

int getNextThief(int currThiefAt, vector<int> &A) {
  return getNextPerson(currThiefAt, A, 1);
}

int findNumberOfThievesCaught(vector<int> &A, int K) {
  int N = A.size();
  int count=0;
  int currPoliceAt = -1;
  currPoliceAt = getNextPolice(currPoliceAt, A);
  int currThiefAt = -1;
  currThiefAt = getNextThief(currThiefAt, A);
  while(currPoliceAt!=N && currThiefAt!=N) {
    if (abs(currPoliceAt - currThiefAt)<=K) {
      count++;
      currPoliceAt = getNextPolice(currPoliceAt, A);
      currThiefAt = getNextThief(currThiefAt, A);
    } else if (currPoliceAt < currThiefAt) {
      currPoliceAt = getNextPolice(currPoliceAt, A);
    } else if (currThiefAt < currPoliceAt) {
      currThiefAt = getNextThief(currThiefAt, A);
    }
  }
  return count;
}

int main() {
  // 0 => Police, 1 => Thief
  vector<int> A = {0,1,1,1,1,0,1,0,0};
  cout<<findNumberOfThievesCaught(A,1)<<endl;
  cout<<findNumberOfThievesCaught(A,2)<<endl;
  cout<<findNumberOfThievesCaught(A,3)<<endl;
}
