/*
Google round 3

Its Easter time and you have a nephew that wants you to buy him gifts. However he doesn't want all the gifts at once. He wants them gifted on n separate days.
He prepares a list for you to buy - he provides the price of item as well as the day to buy.
You however cannot immediately afford to buy all the gifts on day 0 itself, however you keep adding 1 dollar to your pocket change everyday from day 0.

Your task is to maximize the number of gifts your nephew can receive by the end.

Input : n -> integer -> number of gifts in the list
every list entry -> two integers x,y ->   x : day number, y: price of item to buy on x

Example
Input:
3
3 2
5 4
6 3
Output:
2

Explanation: You can buy gift on day 3 (element-0) and day 6 (element-2) to maximize your gifts count to 2.

*/


#include <bits/stdc++.h>
using namespace std;

int amountRemainingAfterIBuyGift(vector<vector<int>> &giftSchedule, vector<pair<int,int>> &DP, int i, int j) {
    return DP[j].second + giftSchedule[i][0] - giftSchedule[j][0] - giftSchedule[i][1];
}

bool canIAffordToBuyGiftTodayAfterPrevDay(vector<vector<int>> &giftSchedule, vector<pair<int,int>> &DP, int i, int j) {
    return amountRemainingAfterIBuyGift(giftSchedule, DP, i, j)>=0;
}

int getMaxNumberOfGiftsForNephew(vector<vector<int>> &giftSchedule) {
    vector<pair<int,int>> DP;
    int N=giftSchedule.size();
    for(int i=0 ; i<N ; i++) {
        DP.push_back(make_pair(1,giftSchedule[i][0]-giftSchedule[i][1]));
    }
    
    for(int i=0 ; i<N ; i++) {
        for(int j=0 ; j<i ; j++) {
            if (DP[i].first<DP[j].first+1 && canIAffordToBuyGiftTodayAfterPrevDay(giftSchedule, DP, i, j)) {
                DP[i] = make_pair(DP[j].first+1, amountRemainingAfterIBuyGift(giftSchedule, DP, i, j));
            } else if (DP[i].first==DP[j].first && amountRemainingAfterIBuyGift(giftSchedule, DP, i, j) > DP[i].second) {
                DP[i].second = amountRemainingAfterIBuyGift(giftSchedule, DP, i, j);
            }
        }
    }
    
    int maxGiftsICanBuy=0;
    for(int i=0 ; i<N ; i++) {
        cout<<DP[i].first<<","<<DP[i].second<<endl;
        maxGiftsICanBuy = max(maxGiftsICanBuy, DP[i].first);
    }
    cout<<endl;
    return maxGiftsICanBuy;
}

int main() {
    int n = 3;
    vector<vector<int>> giftSchedule = {{3,2},{5,4},{6,3}};
    cout<<getMaxNumberOfGiftsForNephew(giftSchedule);
    return 0;
}
