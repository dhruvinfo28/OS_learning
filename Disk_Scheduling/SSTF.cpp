//Shortest seek time first
#include<bits/stdc++.h>
using namespace std;
bool check_if_all_done(vector <pair<int,bool>> ready_queue){
    for(auto s:ready_queue){
        if(!s.second){
            return false;
        }
    }
    return true;
}
int find_closest(vector <pair<int,bool>> ready_queue, int key){
    for(int i=0;i<ready_queue.size();i++){
        ready_queue[i].first = abs(ready_queue[i].first-key);
    }
    int min_ = INT_MAX;
    int min_index = 0;
    for(int i=0;i<ready_queue.size();i++){
        if(!ready_queue[i].second && ready_queue[i].first < min_){
            min_ = ready_queue[i].first;
            min_index = i;
        }
    }

    return min_index;
}
int main(){
    //Position of read and write header and number of requests in the ready queue
    int curr_pos, n; cin>>curr_pos>>n;
    vector<pair<int,bool>> ready_queue(n);
    for(auto &s: ready_queue){
        cin>>s.first;
        s.second = false;
    }
    int seek_time = 0;
    while(!check_if_all_done(ready_queue)){
        int visit_next = find_closest(ready_queue, curr_pos);
        seek_time+= abs(ready_queue[visit_next].first - curr_pos);
        curr_pos = ready_queue[visit_next].first;
        ready_queue[visit_next].second = true;
    }
    cout<<seek_time<<endl;
    return 0;
}
//Input
// 50 7
// 82 170 43 140 24 16 190
//output
//208