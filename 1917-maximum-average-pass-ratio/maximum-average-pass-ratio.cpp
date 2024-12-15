#define pdpii pair<double,pair<int,int>>

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pdpii>pq;
        
        auto gain_score = [](int passed,int total){
            return (double)(passed+1)/(total+1) - (double)passed/total;
        };

        for(auto it : classes){
            pq.push({gain_score(it[0],it[1]),{it[0],it[1]}});
        }

        while(extraStudents--){
            pair<int,int>p = pq.top().second;  pq.pop();
            pq.push({gain_score(p.first+1,p.second+1),{p.first+1,p.second+1}});
        }

        double sum = 0;
        while(pq.size()){
            // cout<<pq.top().second.first<<" "<<pq.top().second.second<<"\n";
            sum += (double)pq.top().second.first/pq.top().second.second;
            pq.pop();
        }

        return sum/classes.size();
    }
};