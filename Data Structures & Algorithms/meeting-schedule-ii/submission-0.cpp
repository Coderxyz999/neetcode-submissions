/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int,int>mp;
        int overlap=0;
        int ans=0;
        for(int i=0;i<intervals.size();i++)
        {
            mp[intervals[i].start]++;
            mp[intervals[i].end]--;
        }
        for(auto &i:mp)
        {
            overlap+=i.second;
            ans=max(ans,overlap);
        }
        return ans;
    }
};
