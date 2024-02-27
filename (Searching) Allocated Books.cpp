/*
You have N books, each with A[i] number of pages. M students need to be allocated contiguous books, with each student getting at least one book.
Out of all the permutations, the goal is to find the permutation where the sum of maximum number of pages in a book allotted to a student should be minimum, out of all possible permutations.
*/

#include <bits/stdc++.h>
using namespace std;

int studentsCoveredByAssignedPageCount(vector<int> &A, int maxPagesAStudentCanCount) {
    cout<<"For page count:"<<maxPagesAStudentCanCount<<", ";
    int studentsNeeded=1;
    int pagesRemainingForCurrStudent=maxPagesAStudentCanCount;
    for(int i=0 ; i<A.size() ; i++) {
        pagesRemainingForCurrStudent-=A[i];
        if(pagesRemainingForCurrStudent==0) {
            studentsNeeded++;
            pagesRemainingForCurrStudent = maxPagesAStudentCanCount;
        } else if (pagesRemainingForCurrStudent<0) {
            studentsNeeded++;
            pagesRemainingForCurrStudent = maxPagesAStudentCanCount - A[i];
        }
    }
    cout<<"students needed : "<<studentsNeeded<<endl;
    return studentsNeeded;
}

int binarySearchForNumberOfPagesChecked(vector<int> &A, int m, int left, int right) {
    cout<<"left:"<<left<<" right:"<<right<<endl;
    if (left<=right) {
        if (left==right) {
            return left;
        }
        if (right-left==1) {
            if (studentsCoveredByAssignedPageCount(A, left)==m) {
                return left;
            } else {
                return right;
            }
        }
        int mid = left + (right - left)/2;
        int studentsCoveredForMid = studentsCoveredByAssignedPageCount(A, mid);
        int studentsCoveredForMid1 = studentsCoveredByAssignedPageCount(A, mid-1);
        if (studentsCoveredForMid==m && studentsCoveredForMid1>m) {
            return mid;
        } else if (studentsCoveredForMid<=m) {
            return binarySearchForNumberOfPagesChecked(A, m, left, mid);
        } else if (studentsCoveredForMid>=m) {
            return binarySearchForNumberOfPagesChecked(A, m, mid, right);
        }
    }
    return -1;
}

int getMinValueOfMaxPagesReadByAStudent(vector<int> &A, int m) {
    int N = A.size();
    int minPages = A[N-1];
    int maxBooksForPerson = (N-1)/m + 1;
    int maxPages = 0;
    for(int i=1 ; i<=maxBooksForPerson ; i++) {
        maxPages+=A[N-i];
    }
    return binarySearchForNumberOfPagesChecked(A, m, minPages, maxPages);
}

int main() {
    vector<int> A = {12, 34, 67, 90};
    // {3, 5, 12, 16, 33, 39, 65, 67, 76, 90, 93}
    int m = 2;
    
    cout<<getMinValueOfMaxPagesReadByAStudent(A, 1)<<endl;
    cout<<getMinValueOfMaxPagesReadByAStudent(A, 2)<<endl;
    cout<<getMinValueOfMaxPagesReadByAStudent(A, 3)<<endl;
    cout<<getMinValueOfMaxPagesReadByAStudent(A, 4)<<endl;

    return 0;
}
