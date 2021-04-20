#include<bits/stdc++.h>
using namespace std;

class Process{
    public:
    string pro_name;
    int arr_time;
    int burst_time;
    Process() = default;
    Process(string n,int a, int b): pro_name{n},arr_time{a}, burst_time{b}{}
    bool operator<(const Process &rhs){
        return this->arr_time < rhs.arr_time;
    }
    friend istream& operator>>(istream &din, Process &rhs);
};

istream& operator>>(istream &din, Process &rhs){
    din>>rhs.pro_name>>rhs.arr_time>>rhs.burst_time;
    return din;
}

int main(){
    cout<<"Enter the number of processes: "<<endl;
    int n; cin>>n;
    vector<Process> processes(n);
    for(auto &s: processes){
        cin>>s;
    }
    sort(processes.begin(), processes.end());
    map<string, pair<int,int>> gant_chart;
    int previous_finish_time = processes[0].arr_time;
    for(auto s: processes){
        gant_chart[s.pro_name].first = previous_finish_time;
        gant_chart[s.pro_name].second = previous_finish_time+s.burst_time;
        previous_finish_time+=s.burst_time;
    }
    for(auto it=gant_chart.begin(); it!=gant_chart.end();it++){
        cout<<it->first<<" "<<it->second.first<<" "<<it->second.second<<endl;
    }
    return 0;
}