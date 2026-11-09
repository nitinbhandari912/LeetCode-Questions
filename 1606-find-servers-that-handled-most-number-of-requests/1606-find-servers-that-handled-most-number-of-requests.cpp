class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> request_handled(k,0);
        set<int> free_server;
        for(int i=0;i<k;i++){
            free_server.insert(i);
        }
        set<pair<int,int>> busy;
        for(int i=0;i<arrival.size();i++){
            int currentTime= arrival[i];
            int finishTime= arrival[i]+load[i];
            while(!busy.empty() && busy.begin()->first <=currentTime){
                int freeSer=busy.begin()->second;
                free_server.insert(freeSer);
                busy.erase(busy.begin());
            }
            if(free_server.empty()){
                continue;
            }
            int perfered= i%k;
            auto next_server=free_server.lower_bound(perfered);
            if(next_server==free_server.end()){
                next_server=free_server.begin();
            }
            int chosen_chair = *next_server;
            request_handled[chosen_chair] += 1;
            free_server.erase(next_server);
            busy.insert({finishTime, chosen_chair});
        }
        int max_requests = 0;
        for(int i = 0; i < k; i++){
            if(request_handled[i] > max_requests){
                max_requests = request_handled[i];
            }
        }
        vector<int> busiest;
        for(int i = 0; i < k; i++){
            if(request_handled[i] == max_requests){
                busiest.push_back(i);
            }
        }
        return busiest;
    }
};