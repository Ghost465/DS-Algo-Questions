


// You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.
// For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
// You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. You can travel between bus stops by buses only.
// Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.
 
// Example 1:
// Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6Output: 2Explanation: The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.
// Example 2:
// Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12Output: -1



#include<bits/stdc++.h>
using namespace std;

struct BusStop{
    int num;
    vector<pair<BusStop*, int>> next;
    BusStop(int num) : num(num), next(vector<pair<BusStop*, int>>()) {}
};

BusStop* createBusStop(int val, int busNumber, vector<BusStop*> &busStopRef) {
    if (busStopRef[val]==NULL){
        BusStop* newBusStop  = new BusStop(val);
        busStopRef[val] = newBusStop;
    }
    return busStopRef[val];
}

void constructBusRouteGraph(vector<vector<int>> busRoutes, vector<BusStop*> &busStopRef){
    for(int i=0 ; i<busRoutes.size() ; i++){
        // add bus stops for the bus route
        for(int j=0 ; j<busRoutes[i].size() ; j++){
            createBusStop(busRoutes[i][j], i, busStopRef);
        }
        // connect bus routes
        for(int j=0 ; j<busRoutes[i].size() ; j++){
            int currBusStopVal = busRoutes[i][j];
            int nextBusStopVal = busRoutes[i][(j+1)%busRoutes[i].size()];
            busStopRef[currBusStopVal]->next.push_back(make_pair(busStopRef[nextBusStopVal], i));
        }
    }
}

int getLeastBusesCount(int currStopIndex, int endStopIndex, int currBusRoute, vector<BusStop*> &busStopRef, vector<bool> &visited, int busesTaken, int minBusesTaken) {
    if (visited[currStopIndex]) {
        return INT_MAX;
    }
    cout<<"On route : "<<currBusRoute<<" , Visiting bus stop : "<<currStopIndex<<" , Buses taken = "<<busesTaken<<endl;
    visited[currStopIndex] = true;
    if (currStopIndex == endStopIndex) {
        return min(minBusesTaken, busesTaken);
    }
    BusStop* currStop = busStopRef[currStopIndex];
    vector<pair<BusStop*, int>> availableBuses = currStop->next;
    for(int i=0 ; i<availableBuses.size() ; i++){
        BusStop* nextStop = availableBuses[i].first;
        int busRoute = availableBuses[i].second;
        
        minBusesTaken = min(minBusesTaken, getLeastBusesCount(nextStop->num, endStopIndex, busRoute, busStopRef, visited, busesTaken + ((busRoute == currBusRoute) ? 0:1), minBusesTaken));
    }
    return minBusesTaken;
}

int main() {
    
    vector<vector<int>> busRoutes = {{1,2,7},{3,6,7}};
    int startStop = 1;
    int endStop = 3;
    
    vector<BusStop*> busStopRef(10, NULL);
    vector<bool> visited(10, false);
    
    constructBusRouteGraph(busRoutes, busStopRef);
    
    for(int i=0 ; i<10 ; i++){
        if (busStopRef[i] == NULL) {
            continue;
        }
        cout<<busStopRef[i]->num<<"-->";
        vector<pair<BusStop*, int>> availableBuses = busStopRef[i]->next;
        for(int j=0 ; j<availableBuses.size() ; j++){
            cout<<"("<<availableBuses[j].first->num<<","<<availableBuses[j].second<<")"<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    cout<<getLeastBusesCount(startStop, endStop, -1, busStopRef, visited, 0, INT_MAX);
    cout<<endl;

    return 0;
}

/*
OUTPUT
------
1-->(2,0) 
2-->(7,0) 
3-->(6,1) 
6-->(7,1) 
7-->(1,0) (3,1) 

On route : -1 , Visiting bus stop : 1 , Buses taken = 0
On route : 0 , Visiting bus stop : 2 , Buses taken = 1
On route : 0 , Visiting bus stop : 7 , Buses taken = 1
On route : 1 , Visiting bus stop : 3 , Buses taken = 2
2
*/
