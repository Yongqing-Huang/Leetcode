#include<vector>

using namespace std;

// TODO: Improve
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector <int> seat; // vector storing the leaving time
        int size = times.size();
        bool seated;
        int arrival_time, leaving_time, friend_id;

        // Add index to friend
        for (int i = 0; i < times.size(); ++i) {
           times[i].push_back(i); 
        }

        // Sort by the arrival time (times[i][0])
        sort(times.begin(), 
            times.end(), 
            [](const vector<int>& a, const vector<int>& b) {
                return a[0] < b[0];
            });
        
        for (vector<int> v : times){
            arrival_time = v[0];
            leaving_time = v[1];
            friend_id = v[2];
            seated = false;

            for (int j = 0; j < seat.size(); j++){
                if (seat[j] <= arrival_time){
                    seat[j] = leaving_time;
                    seated = true;
                    if (friend_id == targetFriend){
                        return j;
                    }
                    break; 
                }
            }
            if (!seated){
                seat.push_back(leaving_time);
                if (friend_id == targetFriend) {
                    return seat.size() - 1;
                }
            }
        }
        return seat.size();
    }
};