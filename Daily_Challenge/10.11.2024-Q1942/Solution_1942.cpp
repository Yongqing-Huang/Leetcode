#include<vector>

using namespace std;

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector <int> seat; // vector storing the leaving time
        int size = times.size();
        bool seated;
        int arrival_time, leaving_time;
        
        for (int i = 0; i <= targetFriend; i++){
            seated = false;
            arrival_time = times[i][0];
            leaving_time = times[i][1];
            for (int j = 0; j < seat.size(); j++){ // Check from the beginning of seat, check if seat is available at the time of 
                if (seat[j] <= arrival_time){
                    seat[j] = leaving_time;
                    seated = true;
                    if (i == targetFriend){
                        return j;
                    }
                }
            }
            if (!seated){
                seat.insert(seat.end(), leaving_time);
            }
        }
        return (seat.size());
    }
};