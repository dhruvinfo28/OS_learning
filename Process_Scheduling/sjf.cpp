#include<bits/stdc++.h>
using namespace std;

//Assuming all processes arrival time was 0

class Process{
    public:
    string pro_name;
    int burst_time;
    Process()=default;
    Process(string a, int b): pro_name{a}, burst_time{b}{}
    friend istream& operator>>(istream& din, Process &rhs);
};
istream& operator>>(istream& din, Process &rhs){
        din>>rhs.pro_name>>rhs.burst_time;
        return din;
}
class comparison{
    public:
    bool operator()(const Process &p1, const Process &p2){
        return p1.burst_time<p2.burst_time;
    }
};

int main(){
    int n; cin>>n;
    priority_queue<Process,vector<Process>,comparison> q;
    Process temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        q.push(temp);
    }
    unordered_map<string,pair<int,int>> gant_chart;
    int prev_finish = 0;
    while(!q.empty()){
        temp = q.top();
        q.pop();
        gant_chart[temp.pro_name].first = prev_finish;
        gant_chart[temp.pro_name].second = prev_finish+temp.burst_time;
        prev_finish +=temp.burst_time;
    }
    for(auto it=gant_chart.begin(); it!=gant_chart.end(); it++){
        cout<<it->first<<" "<<it->second.first<<" "<<it->second.second<<endl;
    }
    return 0;
}